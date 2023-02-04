#define pHpin A0
float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;
void setup() 
{
 Serial.begin(19200);
 pinMode(pHpin, INPUT);
}
void loop() {
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
 float ph_act = -5.70 * volt + calibration_value-3.3;
 Serial.print("pH Sensor Reading: ");
 Serial.println(ph_act);
 delay(1000);
}