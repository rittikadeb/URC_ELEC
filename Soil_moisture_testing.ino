#define MoisturePin A0
void setup() {
  // put your setup code here, to run once:
  pinMode(MoisturePin, INPUT); // soil moisture reader pin
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int MoistureValue= analogRead(MoisturePin); 
   if(MoistureValue>=100){
     Serial.println(MoistureValue);
   }
   else{
     Serial.println("Moisture is less than 40%");
   }
  delay(2000);// 2 sec delay
}