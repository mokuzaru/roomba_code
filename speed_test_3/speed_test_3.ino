const int motI = 22; //pwm1
const int motD = 23;  //pwm2
const int dirI = 12;
const int dirD = 13;

int t = 500;
int maxSpeed = 40;
int x = 60;
int y = 80;

const int freq = 5000;
const int miChanel = 0;
const int mdChanel = 1;
const int resolution = 10;

void setup() {
  Serial.begin(9600);
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
  if(Serial.available()>0){
    char a = Serial.read();
    if( a == 'a'){
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,LOW);
      ledcWrite(miChanel, 260);
      ledcWrite(mdChanel, 260);
      delay(500);
      Serial.println("fordware");
    }
    if( a == 'b'){
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,LOW);
      ledcWrite(miChanel, 320);
      ledcWrite(mdChanel, 320);
      delay(500);
      Serial.println("faster");
    }
    if( a == 'c'){
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,HIGH);
      ledcWrite(miChanel, 300);
      ledcWrite(mdChanel, 300);
      delay(500);
      Serial.println("Left");
    }
    if( a == 'd'){
      digitalWrite(dirD,LOW);
      digitalWrite(dirI,LOW);
      ledcWrite(miChanel, 300);
      ledcWrite(mdChanel, 300);
      delay(500);
      Serial.println("right");
    }
    if( a == 'e'){
      ledcWrite(miChanel, 0);
      ledcWrite(mdChanel, 0);
      delay(500);
      Serial.println("stop");
    }
  }
}
