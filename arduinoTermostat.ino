void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //Making the first printout
  Serial.println("test 1");

  //trying to make methods and use them
  blinkLoop(1000);
  delay(1000000);  
}

// Method to loop 10 times with a set delay
void blinkLoop(int period) {
  //More print
  Serial.println("test inside loop");

  for (int i = 0; i < 5; i++)
  {
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(period);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(period);                       // wait for a second
  }
  
}
