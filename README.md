Environmental Data Logger Using BMP280, BH1750, LCD & SD Card (Arduino)

📋 Project Description:
This Arduino project is a compact environmental data logger that collects, displays, and logs sensor data for temperature, pressure, and ambient light intensity using:

BMP280 for temperature and atmospheric pressure (via SPI)

BH1750 for light intensity (via I2C)

16x2 I2C LCD to display real-time sensor readings

SD Card Module to log data persistently

🚀 Features:
📈 Logs temperature (°C), pressure (hPa), and light intensity (lux)

💾 Saves data to an SD card in datalog.txt

📟 Displays live sensor values on an LCD screen

❗ Handles initialization errors for all modules

⏱️ Takes readings at regular 2-second intervals (modifiable)

🔌 Hardware Setup Summary:
The BMP280 sensor connects using the SPI interface, with its CS pin connected to D9

The BH1750 and the LCD share the I2C interface, using the standard SDA and SCL lines

The SD card module is also on the SPI bus, with its CS pin connected to D10

Make sure to connect all modules to appropriate power (3.3V or 5V depending on your board and sensor version) and common ground.

🧰 Libraries Used:
Adafruit_BMP280

BH1750

LiquidCrystal_I2C

Wire

SPI, SD

📁 Files Included:
main.ino: Arduino sketch for reading, displaying, and logging sensor data

datalog.txt: Log file (auto-generated)

README file with setup guide and overview

