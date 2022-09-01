//Programa : RFID - Controle de Acesso leitor RFID
//Autor : FILIPEFLOP

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <ArduinoJson.h>
#include <Servo.h>
#define SERVO 6 // Porta Digital 6 PWM

const int TAMANHO = 50;  //define o tamanho do buffer para o json
Servo s; // Variável Servo
int pos; // Posição Servo
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

char st[20];

void setup()
{

  s.attach(SERVO);
  s.write(0); // Inicia motor posição zero
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
}

void loop()
{

  if (Serial.available() > 0) {
    //Lê o JSON disponível na porta serial:
    StaticJsonDocument<TAMANHO> json;
    deserializeJson(json, Serial);
    if(json.containsKey("s")) {
      int valor = json["s"];
      
      s.write(valor);
      digitalWrite(LED_BUILTIN, HIGH);
    }
     digitalWrite(LED_BUILTIN, LOW);
  } 
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {

    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


  

  
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "B9 78 F0 98")
  {
    
    delay(3000);
    StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json

    json["tag"] = conteudo.substring(1);
    serializeJson(json, Serial);
    Serial.println();
    delay(3000);
  }
}
