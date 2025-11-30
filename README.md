---

# ⭐ Socials

<a href="https://www.digikey.com/" target="_blank" rel="noopener noreferrer">
  <img src="https://img.shields.io/badge/DigiKey-BE1E2D?style=flat&logo=digikey&logoColor=white" alt="DigiKey"/>
</a>
<p align="center">
  <a href="https://youtube.com/@next.builder?si=CYdRbQAZveyQLm3W" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/YouTube-FF0000?style=flat&logo=youtube&logoColor=white" alt="YouTube"/>
  </a>
  
  <a href="https://www.instructables.com/member/Next%20Builder%20DIY/" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/Instructables-FDBA12?style=flat&logo=instructables&logoColor=black" alt="Instructables"/>
  </a>
  
  <a href="https://hackster.io/NEXTBUILDER" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/Hackster.io-2C9AB7?style=flat&logo=hackster&logoColor=white" alt="Hackster.io"/>
  </a>
  
  <a href="https://hackaday.io/NextBuilder" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/Hackaday-1A1A1A?style=flat&logo=hackaday&logoColor=white" alt="Hackaday"/>
  </a>
  
  <a href="https://instagram.com/next_builder" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=flat&logo=instagram&logoColor=white" alt="Instagram"/>
  </a>

---

# 🔐 AI Face Recognition IoT Smart Door Lock System

### *ESP32-C6 + HuskyLens + Telegram Notifications*

Have you ever wanted a home security system that feels smarter, faster, and more secure than traditional locks?
This project makes that idea a reality. Built with the **DFRobot HuskyLens** at its core, the system delivers reliable, real-time facial recognition without heavy code or cloud dependency.
The **ESP32-C6** manages communication, logic, notifications, and secure unlocking — all efficiently and at the edge. The result is a **professional-grade IoT security system** that blends edge AI + microcontrollers into a powerful and practical solution.

---

# 🛰️ Features

* ✔ **AI Face Recognition (HuskyLens)**
* ✔ **ESP32-C6 high-speed logic processing**
* ✔ **Telegram notifications for each access event**
* ✔ **Supports multiple authorized users**
* ✔ **12V solenoid door lock control**
* ✔ **Secure power delivery with MP1584 buck converter**
* ✔ **Edge processing (no cloud required)**
* ✔ **Modern, compact enclosure design**
* ✔ **Highly reliable for real-world use**

---

# 🧰 Components Used

| Component                       | Purpose                                              |
| ------------------------------- | ---------------------------------------------------- |
| **Espressif ESP32-C6**          | Controls logic, lock control, Wi-Fi, Telegram alerts |
| **DFRobot HuskyLens**           | Facial recognition engine                            |
| **12V Solenoid Door Lock**      | Mechanical lock system                               |
| **MP1584 Buck Converter**       | 12V → 5V/3.3V power regulation                       |
| **10kΩ Resistor**               | Pull-up / signal conditioning                        |
| **DC Female Socket**            | Power input                                          |
| **Wires, connectors, hardware** | Assembly                                             |

---
# 🛠 How It Works

1. **HuskyLens scans for faces continuously**
2. **Identifies stored/authorized faces locally**
3. ESP32-C6 reads the result (via UART / I2C)
4. If authorized →

   * Unlock solenoid
   * Send Telegram alert
5. If unauthorized →

   * Keep lock engaged
   * No noise / no hint

Fast, clean, and secure.

---
# 💬 Want me to also create:

