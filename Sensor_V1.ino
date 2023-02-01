#include "SparkFun_AS7265X.h" 
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define MoisturePin A0
#define dhtPin A1
#define GasSensor A4
AS7265X sensor;
 
void setup() {
  Serial.begin(9600);
  Serial.println("AS7265x Spectral Triad Example");
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  pinMode(dhtPin, INPUT); //DHT11 Sensor 
  pinMode(GasSensor, INPUT); //Gas Sensor 
   
  if(sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check the wiring. Freezing...");
    while(1);
  }
  
  Serial.println("A,B,C,D,E,F,G,H,I,J,K,L,R,S,T,U,V,W");
}
 
void loop() {
  sensor.takeMeasurements(); //This is a hard wait while all 18 channels are measured
  int MoistureValue= analogRead(MoisturePin); 
  int GasSensorVal= analogRead(GasSensor);
  DHT.read(dhtPin);
  Serial.print("Moisture Reading: ");
  Serial.println(MoistureValue);//reading moisture value
  Serial.print("Gas Sensor Reading: ");
  Serial.println(GasSensorVal);//reading gas sensor value
  Serial.print("Temperature Reading: ");
  Serial.println(DHT.temperature);//reading dht11 temperature reading
  Serial.print("Humidity Reading: ");
  Serial.println(DHT.humidity);//reading dht11 humidity reading
  Serial.print("Spectral Sensor Reading: ");
  Serial.print(sensor.getCalibratedA());
  Serial.print(",");
  Serial.print(sensor.getCalibratedB());
  Serial.print(",");
  Serial.print(sensor.getCalibratedC());
  Serial.print(",");
  Serial.print(sensor.getCalibratedD());
  Serial.print(",");
  Serial.print(sensor.getCalibratedE());
  Serial.print(",");
  Serial.print(sensor.getCalibratedF());
  Serial.print(",");
 
  Serial.print(sensor.getCalibratedG());
  Serial.print(",");
  Serial.print(sensor.getCalibratedH());
  Serial.print(",");
  Serial.print(sensor.getCalibratedI());
  Serial.print(",");
  Serial.print(sensor.getCalibratedJ());
  Serial.print(",");
  Serial.print(sensor.getCalibratedK());
  Serial.print(",");
  Serial.print(sensor.getCalibratedL());
  Serial.print(",");
 
  Serial.print(sensor.getCalibratedR());
  Serial.print(",");
  Serial.print(sensor.getCalibratedS());
  Serial.print(",");
  Serial.print(sensor.getCalibratedT());
  Serial.print(",");
  Serial.print(sensor.getCalibratedU());
  Serial.print(",");
  Serial.print(sensor.getCalibratedV());
  Serial.print(",");
  Serial.println(sensor.getCalibratedW()); 
  Serial.println();

  delay(1000);// 1 sec delay

}
