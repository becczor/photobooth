// https://www.arduino.cc/en/Tutorial/Button

const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (debounceButton(buttonState) == HIGH) 
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

bool debounceButton(bool state) {
  bool stateNow = digitalRead(buttonPin);
  if(state != stateNow) {
    delay(20);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}

