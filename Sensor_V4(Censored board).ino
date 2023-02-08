#include <DFRobot_DHT11.h>


#define MoisturePin A0
#define dhtPin A1
#define GasSensor A4
#define pHpin A8
#define ldrPin A12

DFRobot_DHT11 DHT;

float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;

void setup() {
  // put your setup code here, to run once:
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  pinMode(dhtPin, INPUT); //DHT11 Sensor 
  pinMode(GasSensor, INPUT); //Gas Sensor 
  pinMode(pHpin, INPUT);//pH sensor
  pinMode(ldrPin, INPUT); //ldr Sensor

  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
   int MoistureValue= analogRead(MoisturePin); 
   int GasSensorVal= analogRead(GasSensor);
   float ldr = analogRead(ldrPin);

  DHT.read(dhtPin);
   for(int i=0;i<10;i++){ 
  buffer_arr[i]=analogRead(pHpin);
  delay(30);
  }
 for(int i=0;i<9;i++){
  for(int j=i+1;j<10;j++){
  if(buffer_arr[i]>buffer_arr[j]){
  temp=buffer_arr[i];
  buffer_arr[i]=buffer_arr[j];
  buffer_arr[j]=temp;
      }
    }
  }
 avgval=0;
 for(int i=2;i<8;i++)
 avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6;
 float ph_act = -5.70 * volt + calibration_value;
   Serial.print("Moisture Reading: ");
   Serial.println(MoistureValue);//reading moisture value
   Serial.print("Gas Sensor Reading: ");
   Serial.println(GasSensorVal);//reading gas sensor value
   
  Serial.print("Temperature Reading: ");
  Serial.println(DHT.temperature);//reading dht11 temperature reading
  Serial.print("Humidity Reading: ");
  Serial.println(DHT.humidity);//reading dht11 humidity reading   
   Serial.print("pH Sensor Reading: ");//pH Sensor reading
 Serial.println(ph_act);
 Serial.print("Ldr reading in percentage: ");
 Serial.println((ldr/1023)*100);

  Serial.println();

   delay(1000);// 1 sec delay
}
