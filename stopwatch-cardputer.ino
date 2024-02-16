#include <M5GFX.h>

#include <M5Cardputer.h>

unsigned long prevMillis = 0;
const long interval = 1000;
int timerSec = 0;
int timerMin = 0;
bool active = false;

void setup() {
  String strTimerMin = String(timerMin);
  String strTimerSec = String(timerSec);
  // put your setup code here, to run once:
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  M5Cardputer.Display.setRotation(1);
  M5Cardputer.Display.setTextSize(2);
  M5Cardputer.Display.setTextFont(&fonts::FreeSans18pt7b);
  M5Cardputer.Display.setTextColor(BLUE);
  M5Cardputer.Display.setTextDatum(middle_center);
  M5Cardputer.Display.drawString(strTimerMin + ":0" + strTimerSec, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
}

void loop() {
  M5Cardputer.update();
  unsigned long currMillis = millis();
  // put your main code here, to run repeatedly
  if (M5Cardputer.Keyboard.isChange()) {
  if (M5Cardputer.Keyboard.isPressed() && active == false) {
    active = true;
    M5Cardputer.Speaker.tone(4000, 20);
  } else if (M5Cardputer.Keyboard.isPressed() && active == true) {
    active = false;
    M5Cardputer.Speaker.tone(4000, 20);
  }}

  if (M5Cardputer.BtnA.wasPressed()) {
    String strTimerMin = String(timerMin);
    String strTimerSec = String(timerSec);

    timerSec = 0;
    timerMin = 0;
    active = false;
    M5Cardputer.Speaker.tone(2000, 20);
  }

  if (active == true) {
  if (currMillis - prevMillis >= interval) {
    prevMillis = currMillis;

    timerSec++;

    String strTimerMin = String(timerMin);
    String strTimerSec = String(timerSec);

    M5Cardputer.Display.clear();
    if (timerSec < 10) {
      M5Cardputer.Display.drawString(strTimerMin + ":0" + strTimerSec, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    } else {
      M5Cardputer.Display.drawString(strTimerMin + ":" + strTimerSec, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2); }
  }
  

  if (timerSec == 60) {
    timerSec = 0;
    timerMin++;

    String strTimerMin = String(timerMin);
    String strTimerSec = String(timerSec);

    M5Cardputer.Display.clear();
    if (timerSec < 10) {
      M5Cardputer.Display.drawString(strTimerMin + ":0" + strTimerSec, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    } else {
      M5Cardputer.Display.drawString(strTimerMin + ":" + strTimerSec, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2); }  }
} }
