#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE          7
#define CSN         8

RF24 radio(CE, CSN);

const byte address[6] = "00001";

void setup_transceiver()
{
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void setup_serial()
{
  Serial.begin(9600);
  Serial.println("Serial begin - RECEIVER");
}

void setup() {
  setup_serial();
  setup_transceiver();

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

bool receive_test()
{
  while (!radio.available()) 
  {}

  char text[32] = "";
  radio.read(&text, sizeof(text));
  
  return true;
}

void create_signal(int numSeconds)
{
  for (int i=0; i<numSeconds*5; i++)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(100);
  }
}

bool state = false;

void loop() {
  if (receive_test())
  {
    create_signal(1);
    state = !state;
    Serial.println(state);
  }

  if (state)
  {
    
  }
}
