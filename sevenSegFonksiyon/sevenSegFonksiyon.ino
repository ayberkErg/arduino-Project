int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int dot = 9;

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(dot,OUTPUT); 

}

void loop() {
  sevenSeg(0);
  delay(200);
  sevenSeg(1);
  delay(200);
  sevenSeg(2);
  delay(200);
  sevenSeg(3);
  delay(200);
  sevenSeg(4);
  delay(200);
  sevenSeg(5);
  delay(200);
  sevenSeg(6);
  delay(200);
  sevenSeg(7);
  delay(200);
  sevenSeg(8);
  delay(200);
  sevenSeg(9);
  delay(200);
  sevenSeg(10);
  delay(1000);
  sevenSeg(11);
  delay(1000);  
}

void sevenSeg(int rakam){
  
  switch(rakam){
    case 0:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,HIGH);
        digitalWrite(F,HIGH);
        digitalWrite(G,LOW);
        digitalWrite(dot,LOW);
    break;
    case 1:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,LOW);
        digitalWrite(dot,LOW);
    break;
    case 2:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        digitalWrite(E,HIGH);
        digitalWrite(F,LOW);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 3:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 4:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,HIGH);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 5:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,LOW);
        digitalWrite(F,HIGH);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 6:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,HIGH);
        digitalWrite(F,HIGH);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 7:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,LOW);
        digitalWrite(dot,LOW);
    break;
    case 8:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,HIGH);
        digitalWrite(F,HIGH);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 9:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,LOW);
        digitalWrite(F,HIGH);
        digitalWrite(G,HIGH);
        digitalWrite(dot,LOW);
    break;
    case 10:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,LOW);
        digitalWrite(dot,HIGH);
    break;
    case 11:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,LOW);
        digitalWrite(dot,LOW);
    break;
  }
}
