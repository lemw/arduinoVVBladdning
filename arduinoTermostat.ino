int LEDPin = 12;
int inPin = 11;
int buttonPressed = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  //Making the first printout
  Serial.println("First printout");

  //Read the button Input
  buttonPressed = digitalRead(inPin);

  //Check if the button is pressed
  if (buttonPressed == 0)
  {
    //If it was pressed, then toggle the LEDs each 100 ms
    blinkLoop(100);
  } else {
    //If it was pressed, then toggle the LEDs each 500 ms
    //blinkLoop(500);
  }


}

// Method to loop 10 times with a set delay
void blinkLoop(int period) {
  //More print
  Serial.println("test inside loop");

  for (int i = 0; i < 5; i++)
  {
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LEDPin, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(period);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LEDPin, HIGH);    // turn the LED off by making the voltage LOW
    delay(period);                       // wait for a second
  }
  
}
