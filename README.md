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
  <a href="https://community.dfrobot.com/user-13435.html" target="_blank" rel="noopener noreferrer">
    <img src="https://img.shields.io/badge/DFRobot-FF6C00?style=flat&logo=dfrobot&logoColor=white" alt="DFRobot Community"/>
  </a>
</p>

---

# 🔐 AI Face Recognition IoT Smart Door Lock System

### *ESP32-C6 + HuskyLens + Telegram Notifications*

Have you ever wanted a home security system that feels smarter, faster, and more secure than traditional locks?
This project makes that idea a reality.

**This AI-powered Face Recognition Door Lock** combines:

✔️ **On-device AI (HuskyLens)**
✔️ **Instant unlocking for authorized faces**
✔️ **Immediate Telegram alerts to your phone**
✔️ **Silent rejection for unknown visitors**
✔️ **Secure, elegant, and modern design**

Built with the **DFRobot HuskyLens** at its core, the system delivers reliable, real-time facial recognition without heavy code or cloud dependency.
The **ESP32-C6** manages communication, logic, notifications, and secure unlocking — all efficiently and at the edge.

When an authorized person approaches:
➡️ HuskyLens instantly recognizes them
➡️ ESP32-C6 triggers the **12V Solenoid Lock**
➡️ You receive a **Telegram message** confirming access

When an unknown face is detected:
❌ The lock stays engaged
❌ No alerts are triggered locally
✔️ A silent layer of security is maintained

The result is a **professional-grade IoT security system** that blends edge AI + microcontrollers into a powerful and practical solution.

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

# 🔧 Tools Used

* Soldering Iron
* Soldering Wire
* T-7000 Glue
* Screwdrivers
* 3D Printer (for enclosure)
* Fusion 360 (enclosure design)

---

# 📁 Repository Structure

```
SMART-DOOR-LOCK/
│
├── /hardware/
│   ├── schematic.pdf
│   ├── pcb_design/
│   └── wiring_diagram.png
│
├── /firmware/
│   ├── esp32_c6_code.ino
│   ├── huskylens_config/
│   └── telegram_bot_setup/
│
├── /3d-print/
│   ├── enclosure_body.stl
│   ├── faceplate.stl
│   └── mounting_bracket.stl
│
├── /images/
│   ├── final_build.jpg
│   ├── wiring.jpg
│   └── design_render.png
│
├── LICENSE
└── README.md
```

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

