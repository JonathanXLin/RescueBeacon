#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE          7
#define CSN         8

#define motionOut   3

RF24 radio(CE, CSN);

const byte address[6] = "00001";

void setup_transceiver()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}

void setup_serial()
{
  Serial.begin(9600);
  Serial.println("Serial begin - TRANSMITTER");
}

void setup()
{
  setup_serial();
  setup_transceiver();

  pinMode(A7, INPUT);
}

void transmit_test(int numTests)
{
  for (int i=0; i<numTests; i++)
  {
    const char text[] = "Test";
    radio.write(&text, sizeof(text));
    delay(1000);
  }
}

bool switchState = false;

void loop() {
  if (analogRead(A7) > 1000)
    switchState = true;
  else
    switchState = false;
 
  if (switchState)
  {
    transmit_test(1);
    Serial.println("On");
  }
  else
    Serial.println("Off");
}
