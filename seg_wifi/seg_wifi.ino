#include <WiFi.h>

const int trig = 2;
const int trig2 = 4;
const int trig3 = 18;
const int eco = 34;
const int eco2 = 35;
const int eco3 = 32;

const int motI = 22; //pwm1
const int motD = 23;  //pwm2
const int dirI = 12;
const int dirD = 13;

long duration;
int distance;

const int freq = 5000;
const int miChanel = 0;
const int mdChanel = 1;
const int resolution = 10;

const char* ssid     = "Misael";
const char* password = "Kenny123";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
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
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(dirD,HIGH);
          digitalWrite(dirI,LOW);
          ledcWrite(miChanel, 260);
          ledcWrite(mdChanel, 260);
          dist(trig,eco);
          if(distance < 90){
            dist(trig3,eco3);
            if(distance < 80){
              digitalWrite(dirD,LOW);
              digitalWrite(dirI,LOW);
              ledcWrite(miChanel, 300);
              ledcWrite(mdChanel, 300);
            }else{
              digitalWrite(dirD,HIGH);
              digitalWrite(dirI,HIGH);
              ledcWrite(miChanel, 300);
              ledcWrite(mdChanel, 300);
            }
          }
          dist(trig2,eco2);
          if(distance < 90){
            digitalWrite(dirD,HIGH);
            digitalWrite(dirI,HIGH);
            ledcWrite(miChanel, 240);
            ledcWrite(mdChanel, 300);
          }  
          delay(500);
          
        }
        if (currentLine.endsWith("GET /L")) {
          ledcWrite(miChanel, 0);
          ledcWrite(mdChanel, 0);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
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
