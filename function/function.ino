int E = 2;
int D = 3; 
int C = 4; 
int B = 5;
int A = 6;
int F = 7;
int G = 8;
 
void setup() {
  pinMode(E , OUTPUT);
  pinMode(D , OUTPUT);
  pinMode(C , OUTPUT);
  pinMode(B , OUTPUT);
  pinMode(A , OUTPUT);
  pinMode(F , OUTPUT);
  pinMode(G , OUTPUT);
 Serial.begin(9600);
  }
void loop() {
Serial.println("fonksiyon çalışmıyor");
   delay(1000);

  forYaz();

  Serial.println("fonksiyon bitti");
   delay(1000);
}

void forYaz(){
  Serial.println("fonksiyon çalışmaya başladı");

    for(int p = 2 ; p <= 8 ; p++){
   Serial.println("Atatürk");
   delay(1000);
  }
  Serial.println("fonksiyon bitti");

   delay(1000);
  while(1);
}
  
  
