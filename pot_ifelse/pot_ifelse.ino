int led1 = 9 ;
int led2 = 10;
int potPin = A0;

int deger;

void setup() {
  Serial.begin(9600);
 pinMode(led1 , OUTPUT);
 pinMode(led2 , INPUT);
}

void loop() {
  
deger = analogRead(potPin);
Serial.println(deger);

if(deger < 500){
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , LOW);
  }

else if(deger > 501) {
   digitalWrite(led1 , LOW);
   digitalWrite(led2 , HIGH);
  }
}
