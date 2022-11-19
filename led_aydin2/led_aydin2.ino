   
#include "IRremote.h" 
int receiver = 10;

int r1 = 2;
int r2 = 3;

IRrecv irrecv(receiver);

decode_results results;  
#define BUT1 0xFFA25D
#define BUT2 0xFF629D
#define BUT3 0xFFE21D
#define BUT4 0xFF22DD
#define BUT5 0xFF02FD
#define BUT6 0xFFC23D
#define BUT7 0xFFE01F
#define BUT8 0xFFA857
#define BUT9 0xFF906F
#define BUT* 0xFF6897
#define BUT0 0xFF9867
#define BUT# 0xFFB04F
#define yukari 0xFF18E7
#define asagi 0xFF4AB5
#define sol 0xFF10EF
#define sag 0xFF5AA5
#define ok 0xFF38C7  


void setup()

{

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);

  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);


  Serial.begin(9600);
  Serial.println("Program Baslıyor..."); 
  irrecv.enableIRIn(); 
}
void loop(){
  if (irrecv.decode(&results)) {translateIR(); irrecv.resume();}  
  if (digitalRead(r1) == HIGH && results.value == BUT4){
    digitalWrite(r1, LOW);
  ; results.value=0;}
  if (digitalRead(r1) == LOW && results.value == BUT4){
    digitalWrite(r1,HIGH);
  results.value=0;}
  if (digitalRead(r2) == HIGH && results.value == BUT5){
    digitalWrite(r2, LOW);
  ; results.value=0;}
  if (digitalRead(r2) == LOW && results.value == BUT5){
    digitalWrite(r2, HIGH);
    results.value=0;}


  if (results.value == BUT4){
     digitalWrite(r1, LOW); 
  digitalWrite(r2, HIGH); 
  results.value=0;} 
  if (results.value == BUT5){
     digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  results.value=0;} 
  if (results.value == BUT6){
     digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  results.value=0;} 
  if (results.value == BUT7){
     digitalWrite(r1, HIGH); 
  digitalWrite(r2, HIGH); 
  results.value=0;}   
}
void translateIR(){switch(results.value) 
  { 
  case BUT4: Serial.println(" 4"); break;
  case BUT5: Serial.println(" 5"); break;
  case BUT6: Serial.println(" 6"); break;
  case BUT7: Serial.println(" 7"); break;

  default: 
    Serial.println(" baska bir buton   ");
   }
   delay(500); 
} 
