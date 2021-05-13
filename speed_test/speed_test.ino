int motI = 10;
int motD = 5;
int dirI = 9;
int dirD = 6;
int t = 1000;
int maxSpeed = 40;
void setup() {
  Serial.begin(9600);
  for (int i = 5; i < 11; i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,LOW);
}

void loop() {
  if(Serial.available()>0){
    char a = Serial.read();
    if( a == 'a'){
      analogWrite(5,0);
      analogWrite(10,0);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      delay(50);
      analogWrite(5,21);
      analogWrite(10,21);
      delay(t);
      analogWrite(5,0);
      analogWrite(10,0);
      Serial.println("fordware");
    }
    if( a == 'b'){
      analogWrite(5,0);
      analogWrite(10,0);
      digitalWrite(6,HIGH);
      digitalWrite(9,LOW);
      delay(50);
      analogWrite(5,21);
      analogWrite(10,21);
      delay(t);
      analogWrite(5,0);
      analogWrite(10,0);
      Serial.println("back");
    }
    if( a == 'c'){
      analogWrite(5,0);
      analogWrite(10,0);
      digitalWrite(6,HIGH);
      digitalWrite(9,HIGH);
      delay(50);
      analogWrite(5,21);
      analogWrite(10,21);
      delay(t/2);
      analogWrite(5,0);
      analogWrite(10,0);
      Serial.println("Left");
    }
    if( a == 'd'){
      analogWrite(5,0);
      analogWrite(10,0);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      delay(50);
      analogWrite(5,21);
      analogWrite(10,21);
      delay(t);
      analogWrite(5,0);
      analogWrite(10,0);
      Serial.println("right");
    }
    if( a == 'e'){
      analogWrite(5,0);
      analogWrite(10,0);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      delay(50);
      Serial.println("stop");
    }
  }
}
