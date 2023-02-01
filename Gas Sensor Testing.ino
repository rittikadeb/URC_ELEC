#define GasSensor A4
void setup() {
  // put your setup code here, to run once:
  pinMode(GasSensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int GasValue = analogRead(GasSensor);
  Serial.println(GasValue);
  delay(1000);//1 sec delay
}
