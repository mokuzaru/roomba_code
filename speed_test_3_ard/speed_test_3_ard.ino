const int motI = 10; //pwm1
const int motD = 5;  //pwm2
const int dirI = 9;
const int dirD = 6;

int trig = 2;
int eco = 3;
int trig2 = 4;
int eco2 = 7;
int trig3 = 8;
int eco3 = 11;

long duration;
int distance;

int t = 500;
int maxSpeed = 40;
int x = 60;
int y = 60;

void setup() {
  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(eco2, INPUT);
  pinMode(eco3, INPUT);
  
  pinMode(motI, OUTPUT);
  pinMode(motD, OUTPUT);
  pinMode(dirI, OUTPUT);
  pinMode(dirD, OUTPUT);
  
  digitalWrite(motI,LOW);
  digitalWrite(motD,LOW);
  digitalWrite(dirI, HIGH);
  digitalWrite(dirD,LOW);


}

void loop() {
  digitalWrite(motI,LOW);
  digitalWrite(motD,LOW); 
  if(Serial.available()>0){
    char a = Serial.read();
    if( a == 'a'){        
      digitalWrite(dirD,LOW);
      digitalWrite(dirI,HIGH);
      delay(50);
      analogWrite(motI, x);
      analogWrite(motD, x);
      delay(500);
      Serial.println("fordware");
    }
    if( a == 'b'){
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,LOW);
      analogWrite(motI, y);
      analogWrite(motD, y);
      delay(500);
      Serial.println("faster");
    }
    if( a == 'c'){
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,HIGH);
      analogWrite(motI, y);
      analogWrite(motD, y);
      delay(500);
      Serial.println("Left");
    }
    if( a == 'd'){
      digitalWrite(dirD,LOW);
      digitalWrite(dirI,LOW);
      analogWrite(motI, y);
      analogWrite(motD, y);
      delay(500);
      Serial.println("right");
    }
    if( a == 'e'){
      analogWrite(motI, 0);
      analogWrite(motD, 0);
      delay(500);
      Serial.println("stop");
    }
  }

  digitalWrite(dirD,LOW);
  digitalWrite(dirI,HIGH);
  analogWrite(motI,x);
  analogWrite(motD,x);
  delay(2000);
  analogWrite(motI,0);
  analogWrite(motD,0);
  delay(1000);
  digitalWrite(dirD,HIGH);
  digitalWrite(dirI,HIGH);
  analogWrite(motI,x);
  analogWrite(motD,x);
  delay(250);
  analogWrite(motI,0);
  analogWrite(motD,0);
  delay(100);
  digitalWrite(dirD,HIGH);
  digitalWrite(dirI,HIGH);
  analogWrite(motI,x);
  analogWrite(motD,x);
  delay(250);
  analogWrite(motI,0);
  analogWrite(motD,0);
  delay(100);
  
  delay(1000);
  digitalWrite(dirD,LOW);
  digitalWrite(dirI,HIGH);
  analogWrite(motI,x);
  analogWrite(motD,x);
  delay(2000);
  
  
}

void dist (int a, int b){
  Serial.println("start medida");
  
  digitalWrite(a,HIGH);
  delayMicroseconds(2);
  digitalWrite(a,LOW);
  delayMicroseconds(5);
  digitalWrite(a,HIGH);

  duration = pulseIn(b, HIGH);

  distance = duration * 0.017;

  Serial.print("Distancia: ");
  Serial.println(distance);
}
