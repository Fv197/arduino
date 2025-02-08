bool ledState = false;
int BUTTON_PIN1 = 2;
int BUTTON_PIN2 = 7;
int LED_PIN    = 13;

void setup() {
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  if (digitalRead(BUTTON_PIN1) == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(250);
  }
  if (digitalRead(BUTTON_PIN2) == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(250);
  }
}
