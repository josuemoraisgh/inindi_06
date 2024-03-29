#include <Arduino.h>
#include <math.h>
#define NUMTHREADS 1 //Deve-se sempre declarar o NUMTHREADS antes de "inindThread.h"
#include "inindThread.h"

#define pinANALOG A5 // Configura o pino de leitura
#define Fs 100.0     // Sampling frequency = 100hz

const double Ts = (1.0 / Fs) * 1000; // Sampling Time = 1/Fs
double timeStamp = 0;

void analogReadFunc() // Faz a leitura do sinal Analogico
{
  timeStamp += Ts;
  Serial.print(">onda:");
  Serial.print(timeStamp);
  Serial.print(":");
  Serial.print(analogRead(pinANALOG));
  Serial.println("§Volts|g");
}

void setup() // Codigo de configuração
{
  Serial.begin(115200);
  pinMode(pinANALOG, INPUT);
  threadSetup(analogReadFunc, Ts); // parametros:funcão,intervalo,funcão,intervalo,...,
}

void loop() {}
