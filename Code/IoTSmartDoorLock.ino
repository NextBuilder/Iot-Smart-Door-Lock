#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SoftwareSerial.h>

// WiFi credentials - REPLACE WITH YOUR ACTUAL CREDENTIALS
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Telegram Bot Token and Chat ID - REPLACE WITH YOUR ACTUAL CREDENTIALS
const char* telegramToken = "YOUR_TELEGRAM_BOT_TOKEN";
const char* chatID = "YOUR_CHAT_ID";

// HuskyLens setup
SoftwareSerial huskyLens(4, 5); // RX, TX

// Solenoid lock control
const int lockPin = 6; // GPIO pin for solenoid lock
bool isLocked = true;
unsigned long unlockStartTime = 0;
const unsigned long unlockDuration = 5000; // 5 seconds

// WiFi secure client for Telegram
WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  huskyLens.begin(9600);
  
  // Initialize lock pin
  pinMode(lockPin, OUTPUT);
  digitalWrite(lockPin, LOW); // Start locked
  
  // Connect to WiFi
  connectToWiFi();
  
  // Configure HTTPS for Telegram
  client.setInsecure();
  
  Serial.println("IoT Door Lock System Started");
  sendTelegramMessage("🚪 Door Lock System Activated and Ready");
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Connected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ Failed to connect to WiFi!");
  }
}

bool readHuskyLens() {
  if (huskyLens.available()) {
    byte buffer[20];
    int bytesRead = 0;
    
    // Read available data
    while (huskyLens.available() && bytesRead < 20) {
      buffer[bytesRead] = huskyLens.read();
      bytesRead++;
    }
    
    // Check if we have a valid frame (HuskyLens protocol starts with 0x55 0xAA)
    if (bytesRead >= 4 && buffer[0] == 0x55 && buffer[1] == 0xAA) {
      int dataLength = buffer[2];
      
      if (bytesRead >= dataLength + 3) {
        // Parse the ID from the data (position may vary)
        int detectedID = buffer[5];
        
        Serial.print("Detected ID: ");
        Serial.println(detectedID);
        
        if (detectedID >= 1 && detectedID <= 5) {
          Serial.print("✅ Authorized face detected! ID: ");
          Serial.println(detectedID);
          return true;
        } else if (detectedID > 0) {
          Serial.print("❌ Unauthorized face detected! ID: ");
          Serial.println(detectedID);
          sendTelegramMessage("🚫 Unauthorized access attempt detected!");
        }
      }
    }
  }
  return false;
}

void unlockDoor() {
  if (isLocked) {
    Serial.println("🔓 Unlocking door...");
    digitalWrite(lockPin, HIGH); // Activate solenoid
    isLocked = false;
    unlockStartTime = millis();
    
    // Send Telegram notification
    sendTelegramMessage("✅ Door unlocked by authorized user");
  }
}

void lockDoor() {
  if (!isLocked) {
    Serial.println("🔒 Locking door...");
    digitalWrite(lockPin, LOW); // Deactivate solenoid
    isLocked = true;
    sendTelegramMessage("🔒 Door locked");
  }
}

void sendTelegramMessage(const char* message) {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Sending Telegram message: ");
    Serial.println(message);
    
    if (client.connect("api.telegram.org", 443)) {
      String url = "/bot" + String(telegramToken) + "/sendMessage";
      String postData = "chat_id=" + String(chatID) + "&text=" + String(message);
      
      client.println("POST " + url + " HTTP/1.1");
      client.println("Host: api.telegram.org");
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.print("Content-Length: ");
      client.println(postData.length());
      client.println();
      client.println(postData);
      
      // Wait for response
      unsigned long timeout = millis();
      while (client.connected() && millis() - timeout < 5000L) {
        if (client.available()) {
          String line = client.readStringUntil('\n');
          if (line == "\r") {
            break;
          }
        }
      }
      client.stop();
      Serial.println("Telegram message sent!");
    } else {
      Serial.println("Failed to connect to Telegram");
    }
  } else {
    Serial.println("WiFi not connected - cannot send Telegram message");
  }
}

void checkAutoLock() {
  if (!isLocked && (millis() - unlockStartTime >= unlockDuration)) {
    lockDoor();
  }
}

void loop() {
  // Check WiFi connection
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected! Reconnecting...");
    connectToWiFi();
  }
  
  // Check HuskyLens for recognized faces
  if (readHuskyLens()) {
    unlockDoor();
  }
  
  // Check if it's time to auto-lock
  checkAutoLock();
  
  delay(100);
}

// Manual control via Serial Monitor
void serialEvent() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    if (command == "unlock") {
      unlockDoor();
    } else if (command == "lock") {
      lockDoor();
    } else if (command == "status") {
      Serial.println(isLocked ? "Status: 🔒 Locked" : "Status: 🔓 Unlocked");
    } else if (command == "wifi") {
      Serial.println(WiFi.status() == WL_CONNECTED ? "WiFi: Connected" : "WiFi: Disconnected");
    } else if (command == "test") {
      sendTelegramMessage("🔧 Test message from door lock system");
    }
  }
}