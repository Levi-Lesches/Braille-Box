#include <ESP8266mDNS.h>

#include <Servo.h>
// #include "braille"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define FLAT 90
#define RAISED 0
#define WIFISSID "9BA5CE_5G"
#define PASSWORD "joschameilevdav12345"

Servo servo1, servo2, servo3, servo4, servo5, servo6;
Servo servos[6];

int pins[6] = {16, 5, 4, 12, 13, 15};

ESP8266WebServer server (80);

const String HTML = ""
  "<form action='/login' method='POST'>"
    "<input type='text' name='message' placeholder='Enter your message'>"
    "<input type='submit'>"
    "<input type='reset'>"
  "</form>";

const bool A[6] = {true, false, false, false, false, false};
const bool B[6] = {true, true, false, false, false, false};
const bool C[6] = {true, false, false, true, false, false};
const bool D[6] = {true, false, false, true, true, false};
const bool E[6] = {true, false, false, false, true, false};
const bool F[6] = {true, true, false, true, false, false};
const bool G[6] = {true, true, false, true, true, false};
const bool H[6] = {true, true, false, false, true, false};
const bool I[6] = {false, true, false, true, false, false};
const bool J[6] = {false, true, false, true, true, false};
const bool K[6] = {true, false, true, false, false, false};
const bool L[6] = {true, true, true, false, false, false};
const bool M[6] = {true, false, true, true, false, false};
const bool N[6] = {true, false, true, true, true, false};
const bool O[6] = {true, false, true, false, true, false};
const bool P[6] = {true, true, true, true, false, false};
const bool Q[6] = {true, true, true, true, true, false};
const bool R[6] = {true, true, true, false, true, false};
const bool S[6] = {false, true, true, true, false, false};
const bool T[6] = {false, true, true, true, true, false};
const bool U[6] = {true, false, true, false, false, true};
const bool V[6] = {true, true, true, false, false, true};
const bool W[6] = {false, true, false, true, true, true};
const bool X[6] = {true, false, true, true, false, true};
const bool Y[6] = {true, false, true, true, true, true};
const bool Z[6] = {true, false, true, false, true, true};
const bool EXCLAIM[6] = {false, true, true, false, true, false};
const bool QUESTION[6] = {true, false, false, true, false, true};
const bool COMMA[6] = {false, true, false, false, false, false};
const bool PERIOD[6] = {false, true, false, false, true, true};
const bool ALEPH[6] = {true, false, false, false, false, false};
const bool BET[6] = {true, true, true, false, false, true};
const bool GIMMEL[6] = {true, true, false, true, true, false};
const bool DALED[6] = {true, false, false, true, true, false};
const bool HAY[6] = {true, true, false, false, true, false};
const bool VAV[6] = {false, true, false, true, true, true};
const bool ZAYIN[6] = {true, false, true, false, true, true};
const bool CHET[6] = {true, false, true, true, false, true};
const bool TET[6] = {false, true, true, true, true, false};
const bool YUD[6] = {false, true, false, true, true, false};
const bool KAF[6] = {true, false, false, false, false, true};
const bool LAMED[6] = {true, true, true, false, false, false};
const bool MEM[6] = {true, false, true, true, false, false};
const bool NUN[6] = {true, false, true, true, true, false};
const bool SAMECH[6] = {false, true, true, true, false, false};
const bool AYIN[6] = {true, true, false, true, false, true};
const bool PAY[6] = {true, true, false, true, false, false};
const bool TZADIK[6] = {false, true, true, true, false, true};
const bool KUF[6] = {true, true, true, true, true, false};
const bool RAISH[6] = {true, true, true, false, true, false};
const bool SHIN[6] = {true, false, false, true, false, true};
const bool TAF[6] = {true, false, false, true, true, true};

void initServos() {
  for (int index = 0; index < 6; index++) {
    servos [index].attach(pins[index]);
    servos[index].write(FLAT);
  }
}

void braille(String message) {
  Serial.print ("Received: ");
  Serial.println (message);
  for (int index = 0; index < message.length(); index++) {
    brailleLetter (message [index]);
    delay (1000);
  }
}

void moveServos (const bool instructions[6]) {
  Serial.println ("Moving for a letter");
  for (int index = 0; index < 6; index++) {
    Serial.print ("Moving servo ");
    Serial.print (index + 1);
    Serial.println (instructions[index] ? " Up" : " down");
    if (instructions[index]) servos[index].write(RAISED);
    else servos[index].write(FLAT);
  }
}

//void moveServo (Servo servo, bool instruction) {
//  servo.write (instruction ? RAISED : FLAT);
//}

void brailleLetter (char letter) {
  switch (letter) {
    case char ('A'): moveServos (A); break;
    case char ('B'): moveServos (B); break;
    case char ('C'): moveServos (C); break;
    case char ('D'): moveServos (D); break;
    case char ('E'): moveServos (E); break;
    case char ('F'): moveServos (F); break;
    case char ('G'): moveServos (G); break;
    case char ('H'): moveServos (H); break;
    case char ('I'): moveServos (I); break;
    case char ('J'): moveServos (J); break;
    case char ('K'): moveServos (K); break;
    case char ('L'): moveServos (L); break;
    case char ('M'): moveServos (M); break;
    case char ('N'): moveServos (N); break;
    case char ('O'): moveServos (O); break;
    case char ('P'): moveServos (P); break;
    case char ('Q'): moveServos (Q); break;
    case char ('R'): moveServos (R); break;
    case char ('S'): moveServos (S); break;
    case char ('T'): moveServos (T); break;
    case char ('U'): moveServos (U); break;
    case char ('V'): moveServos (V); break;
    case char ('W'): moveServos (W); break;
    case char ('X'): moveServos (X); break;
    case char ('Y'): moveServos (Y); break;
    case char ('Z'): moveServos (Z); break;
    case char ('!'): moveServos (EXCLAIM); break;
    case char ('?'): moveServos (QUESTION); break;
    case char (','): moveServos (COMMA); break;
    case char ('.'): moveServos (PERIOD); break;
    case char ('א'): moveServos (ALEPH); break;
    case char ('ב'): moveServos (BET); break;
    case char ('ג'): moveServos (GIMMEL); break;
    case char ('ד'): moveServos (DALED); break;
    case char ('ה'): moveServos (HAY); break;
    case char ('ו'): moveServos (VAV); break;
    case char ('ז'): moveServos (ZAYIN); break;
    case char ('ח'): moveServos (CHET); break;
    case char ('ט'): moveServos (TET); break;
    case char ('י'): moveServos (YUD); break;
    case char ('כ'): moveServos (KAF); break;
    case char ('ל'): moveServos (LAMED); break;
    case char ('מ'): moveServos (MEM); break;
    case char ('נ'): moveServos (NUN); break;
    case char ('ס'): moveServos (SAMECH); break;
    case char ('ע'): moveServos (AYIN); break;
    case char ('פ'): moveServos (PAY); break;
    case char ('צ'): moveServos (TZADIK); break;
    case char ('ק'): moveServos (KUF); break;
    case char ('ר'): moveServos (RAISH); break;
    case char ('ש'): moveServos (SHIN); break;
    case char ('ת'): moveServos (TAF); break;
  }
}

void serveRoot() {server.send (200, "text/html", HTML);}

void serveMessage() {
  serveRoot();
//  if (!(server.hasArg ("message") && server.arg ("message") != NULL))
  braille (server.arg ("message"));
//  else 
//    Serial.println ("Website didn't have data");
}

void serve404() {server.send (404, "text/plain", "404: Not found");}

void initServer() {
  WiFi.begin (WIFISSID, PASSWORD);
  Serial.println ("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay (250);
    Serial.print (".");
  }
  Serial.println("");
  Serial.print ("Connected to ");
  Serial.println (WiFi.SSID());
  Serial.print ("IP adress: ");
  Serial.println (WiFi.localIP());
  
//   if (MDNS.begin ("esp8266")) Serial.println ("mDNS responder started");
//   else Serial.println ("mDNS not responding");

  server.on ("/", HTTP_GET, serveRoot);
  server.on ("/login", HTTP_POST, serveMessage);
  server.on ("/message", HTTP_GET, serveRoot);
  server.onNotFound (serve404);

  server.begin();
  Serial.println ("Server started");
}

void setup() {
  Serial.begin(74880);
  initServos();

//  initServer();
}

void temp(Servo servo, int angle) {
  servo.write(angle);
}

void loop() {
//  server.handleClient();
//  
  braille ("HEY");
  delay (2000);
//  Serial.println("Displaying HELLO");
//  braille ("HELLO");
//  delay (1000);
  
}
