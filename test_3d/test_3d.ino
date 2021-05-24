const int trig = 2;
const int trig2 = 4;
const int trig3 = 18;
const int eco = 34;
const int eco2 = 35;
const int eco3 = 32;
const int out1 = 19;
const int out2 = 21;

const int motI = 22; //pwm1
const int motD = 23;  //pwm2
const int dirI = 12;
const int dirD = 13;

int t = 500;
int maxSpeed = 40;
int x = 60;
int y = 80;

long duration;
int distance;

const int freq = 5000;
const int miChanel = 0;
const int mdChanel = 1;
const int resolution = 10;

void setup() {
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

  
  ledcSetup(miChanel, freq, resolution);
  ledcSetup(mdChanel, freq, resolution);

  ledcAttachPin(motI, miChanel);
  ledcAttachPin(motD, mdChanel);
  Serial.begin(115200);
}

void loop() {
  
  digitalWrite(dirD,HIGH);
  digitalWrite(dirI,LOW);
  ledcWrite(miChanel, 260);
  ledcWrite(mdChanel, 260);
  dist(trig,eco);
  if(distance < 90){
    dist(trig3,eco3);
    if(distance < 80){
      Serial.println("c");
      digitalWrite(dirD,LOW);
      digitalWrite(dirI,LOW);
      ledcWrite(miChanel, 300);
      ledcWrite(mdChanel, 300);
    }else{
     Serial.println("A");
      digitalWrite(dirD,HIGH);
      digitalWrite(dirI,HIGH);
      ledcWrite(miChanel, 300);
      ledcWrite(mdChanel, 300);
    }
  }
  dist(trig2,eco2);
  if(distance < 90){
    Serial.println("B");
    digitalWrite(dirD,HIGH);
    digitalWrite(dirI,HIGH);
    ledcWrite(miChanel, 240);
    ledcWrite(mdChanel, 300);
  }  
  delay(500);
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
