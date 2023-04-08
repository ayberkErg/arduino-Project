int x = 19;
int y = 19;

void setup() {
  Serial.begin(9600);

}

void loop() {
 
  
  
  
  
  if(x > y ){
    Serial.println("x büyüktür y");
    delay(500);
    }
   else if(y > x){
     Serial.println("y büyüktür x");
    delay(500);
    } 
    
  else if(y == x) {
    Serial.println("y = x");  
     delay(500);
  }
}
