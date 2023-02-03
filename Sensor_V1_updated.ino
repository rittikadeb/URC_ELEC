#include "SparkFun_AS7265X.h" 
#include <DFRobot_DHT11.h>
#include <Wire.h>
#include "I2Cdev.h"     
#include "MPU6050.h"    



DFRobot_DHT11 DHT;
#define MoisturePin A0
#define dhtPin A1
#define GasSensor A4
#define TCAADDR 0x70

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;
  

AS7265X spectral;

void displaySpectraldetails(AS7265X spectral){
  Serial.print("Spectral Sensor Reading: ");
  Serial.print(spectral.getCalibratedA());
  Serial.print(",");
  Serial.print(spectral.getCalibratedB());
  Serial.print(",");
  Serial.print(spectral.getCalibratedC());
  Serial.print(",");
  Serial.print(spectral.getCalibratedD());
  Serial.print(",");
  Serial.print(spectral.getCalibratedE());
  Serial.print(",");
  Serial.print(spectral.getCalibratedF());
  Serial.print(",");
 
  Serial.print(spectral.getCalibratedG());
  Serial.print(",");
  Serial.print(spectral.getCalibratedH());
  Serial.print(",");
  Serial.print(spectral.getCalibratedI());
  Serial.print(",");
  Serial.print(spectral.getCalibratedJ());
  Serial.print(",");
  Serial.print(spectral.getCalibratedK());
  Serial.print(",");
  Serial.print(spectral.getCalibratedL());
  Serial.print(",");
 
  Serial.print(spectral.getCalibratedR());
  Serial.print(",");
  Serial.print(spectral.getCalibratedS());
  Serial.print(",");
  Serial.print(spectral.getCalibratedT());
  Serial.print(",");
  Serial.print(spectral.getCalibratedU());
  Serial.print(",");
  Serial.print(spectral.getCalibratedV());
  Serial.print(",");
  Serial.println(spectral.getCalibratedW()); 
}

void displayMPUdetails(MPU6050 mpu){
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
  delay(500);
  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.print(data.Y);
  Serial.print("  ");
  Serial.print("Axis Z  = ");
  Serial.println(data.Z);

}

void TCA9548A(uint8_t bus){
  if (bus>7) return;
  
  Wire.beginTransmission(TCAADDR);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
  
}
 
void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  pinMode(dhtPin, INPUT); //DHT11 Sensor 
  pinMode(GasSensor, INPUT); //Gas Sensor 
  TCA9548A(0);// Spectrometer
  TCA9548A(1);// MPU6050 Sensor
}
 
void loop() {
  spectral.takeMeasurements(); //This is a hard wait while all 18 channels are measured
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
  TCA9548A(0);//selecting specctral sensor
  displaySpectraldetails(spectral); // displaying spectral sensor
  Serial.println();
  delay(500); //0.5 sec delay
  TCA9548A(1);//selecting mpu6050 sensor
  displayMPUdetails(mpu); //displaying MPU6050 details
  delay(1000);// 1 sec delay

}