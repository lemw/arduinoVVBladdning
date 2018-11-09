// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 


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
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  // Start up the library 
  sensors.begin(); 

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

   // call sensors.requestTemperatures() to issue a global temperature 
   // request to all devices on the bus 
  /********************************************************************/
   Serial.print(" Requesting temperatures..."); 
   sensors.requestTemperatures(); // Send the command to get temperature readings 
   Serial.println("DONE"); 
  /********************************************************************/
   Serial.print("Temperature is: "); 
   Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
     // You can have more than one DS18B20 on the same bus.  
     // 0 refers to the first IC on the wire 
     delay(1000); 

  


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
