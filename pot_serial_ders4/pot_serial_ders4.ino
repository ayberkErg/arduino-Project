int potPin = A0;
int deger;
int led1 =9 ;

void setup() {
Serial.begin(9600);
pinMode(led1 , OUTPUT);
  
}
void loop() {

deger = analogRead(potPin);
//deger = deger / 4;
//serhat ve alpay
 analogWrite(led1 , deger);
Serial.println(deger);
}
