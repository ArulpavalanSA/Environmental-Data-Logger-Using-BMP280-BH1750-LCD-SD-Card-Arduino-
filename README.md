Environmental Data Logger Using BMP280, BH1750, LCD & SD Card (Arduino)

📋 Project Description:
This Arduino project is a compact environmental data logger that collects, displays, and logs sensor data for temperature, pressure, and ambient light intensity using:

BMP280 for temperature and atmospheric pressure (SPI interface)

BH1750 for light intensity (I2C interface)

16x2 I2C LCD to display live sensor readings

SD Card Module to store the data for later analysis

🚀 Features:
📈 Logs temperature (°C), pressure (hPa), and light intensity (lux)

💾 Stores data into datalog.txt on the SD card

📟 Displays live readings on the 16x2 LCD

🔍 Error handling for sensor or SD failures

⏱️ Takes readings every 2 seconds (can be modified)

🧰 Hardware Connections:

Module	Interface	Key Pins Used
BMP280 (SPI)	SPI	CS - D9, SPI Pins
BH1750	I2C	SDA/SCL (A4/A5)
16x2 LCD (I2C)	I2C	Addr: 0x27 (default)
SD Card Module	SPI	CS - D10, SPI Pins
🧪 Libraries Used:
Adafruit_BMP280

BH1750

LiquidCrystal_I2C

Wire

SPI, SD

📁 Files Included:
main.ino: Arduino sketch for reading, displaying, and logging sensor data

datalog.txt: Log file (generated at runtime)

README documentation with setup and explanation
