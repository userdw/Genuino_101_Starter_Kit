#define LED_MODULE 9
#define PUSH_BUTTON_MODULE 2
//#define INTERVAL_CLICK 1000
#define DEBOUNCE_DELAY 100
#define TOGGLE_EXECUTE_DELAY 1500

unsigned long lastDebounceTime = 0;
unsigned long lastBlinkExecuteDelay = 0;
byte blinkTimes = 0;

void toggleLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
  }
}

void setup() {
  pinMode(LED_MODULE, OUTPUT);
  pinMode(PUSH_BUTTON_MODULE, INPUT);
}

void loop() {
  if (!digitalRead(PUSH_BUTTON_MODULE)) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    lastDebounceTime = millis();
    lastBlinkExecuteDelay = millis();
    blinkTimes++;
    if (blinkTimes > 5) {
      blinkTimes = 5;
    }
  }

  if ((millis() - lastBlinkExecuteDelay) > TOGGLE_EXECUTE_DELAY) {
    toggleLED(blinkTimes);
    blinkTimes = 0;
    lastBlinkExecuteDelay = millis();
  }
}
