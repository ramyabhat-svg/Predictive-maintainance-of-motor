int vibratePin=7;
int MotorPin=3;
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 4


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);



void setup() {
  Serial.begin(9600); // put your setup code here, to run once:
 pinMode(vibratePin,INPUT);
 pinMode(MotorPin,OUTPUT);
 sensors.begin();
 
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  // put your main code here, to run repeatedly:
  int vibrate=digitalRead(vibratePin);
   String vibrationStatus = (vibrate == HIGH) ? "HIGH" : "LOW";

    Serial.print(tempC);
  Serial.print(",");
  Serial.println(vibrationStatus);
  

  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'R') {
      digitalWrite(MotorPin, HIGH);
    } else if (command == 'M') {
      digitalWrite(MotorPin, LOW);
      delay(5000);
    }
}
delay(100);

}
