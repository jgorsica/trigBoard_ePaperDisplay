#define OTA_DEBUG
#include "includes.h"

const char fwVersion[] = "11/29/21";

//ePaper library here:
//https://github.com/ZinggJM/GxEPD2
//DIN goes to 13
//CLK goes to 14
//the other signals
//CS to 15
//DC to 33
//RST to 32
//BUSY to 39
#include <SPI.h>
#include <GxEPD2.h>
#include <GxEPD2_3C.h>
#include "GxEPD2_display_selection_new_style.h"

//FreeFonts from Adafruit_GFX, make sure you install this library too from lib manager
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
void ePaperUpdate(int);
struct tm timeinfo;

void setup() {
  pinMode(ESPlatchPin, OUTPUT);
  digitalWrite(ESPlatchPin, HIGH);
  pinMode(LEDpin, OUTPUT);
  Serial.begin(115200);
  Wire.begin(SDApin, SCLpin);
  checkWakeupPins();
  loadConfiguration(filename, config);
  rtcInit(config.timerCountDown, false);
  Serial.println(getBattery(), 2);
  Serial.print("Time is ");
  Serial.print(String(getRtcHours()));
  Serial.print(":");
  Serial.println(String(getRtcMinutes()));
  if (pushLogic()) { //decide if push will occur or nt and what message will be
    timestampAppend();
    if (wiFiNeeded) {
      if (connectWiFi()) {
        nptUpdateTime();
        //pushOver();
        //pushSafer();
        //ifttt();
        //telegram();
        //mqtt();
      }
    //} else if (true) {
      
    }
    //udp();
    //tcp();
  }
  killPower();
  waitForButton();
  ePaperInstructions();
  initBluetooth();
}

void loop() {
  if (!OTAsetup)
    serviceBluetooth();
  else
    checkOTA();
}
