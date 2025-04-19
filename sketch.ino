#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP280.h>    // Library for BMP280 (SPI)
#include <BH1750.h>             // Library for BH1750 (I2C)
#include <LiquidCrystal_I2C.h>  // Library for 16x2 LCD (I2C)

// Define SPI Chip Select (CS) pins
#define BMP280_CS 9
#define SD_CS 10  

// Initialize components
Adafruit_BMP280 bmp(BMP280_CS); // Using SPI mode
BH1750 lightMeter;
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address 0x27

File logFile;  // File for storing data

void setup() {
    Serial.begin(9600);
    
    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");

    // Initialize SPI for BMP280
    if (!bmp.begin(BMP280_CS)) {  
        Serial.println("BMP280 (SPI) not found!");
        while (1);
    }

    // Initialize BH1750 Sensor
    Wire.begin();
    if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("BH1750 (I2C) not found!");
        while (1);
    }

    // Initialize SD Card
    if (!SD.begin(SD_CS)) {
        Serial.println("SD Card initialization failed!");
        lcd.setCursor(0, 1);
        lcd.print("SD Fail!");
        while (1);
    }
    Serial.println("SD Card initialized.");
    lcd.setCursor(0, 1);
    lcd.print("SD Ready!");
    delay(2000);
}

void loop() {
    // Read Sensor Data
    float temperature = bmp.readTemperature();  
    float pressure = bmp.readPressure() / 100.0;  // Convert to hPa
    float lightLevel = lightMeter.readLightLevel();  // Read light intensity in lux

    // Display Data on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature);
    lcd.print("C P:");
    lcd.print(pressure);
    
    lcd.setCursor(0, 1);
    lcd.print("L:");
    lcd.print(lightLevel);
    lcd.print(" lx");

    // Log Data to SD Card
    logFile = SD.open("datalog.txt", FILE_WRITE);
    if (logFile) {
        logFile.print("Temperature: ");
        logFile.print(temperature);
        logFile.print(" C, Pressure: ");
        logFile.print(pressure);
        logFile.print(" hPa, Light: ");
        logFile.print(lightLevel);
        logFile.println(" lx");
        logFile.close();  // Close file to save data
        Serial.println("Data logged.");
    } else {
        Serial.println("Error opening datalog.txt");
    }

    // Wait for 5 seconds before logging again
    delay(2000);
}
