/* 2022-07-09 Yang-Rui Li */

#include <Arduino.h>
#include "Filter1.h"

double data = 0.0, data_f = 0.0;
double data_n = 0.0;
double t = 0.0;
double Cutoff_Freq = 10.0;
double T = 0.001;
FILTER1 Filter;

void setup()
{
  Serial.begin(115200);
  while (!Serial) {};

  Filter.Init(FILTER1::LPF, Cutoff_Freq, T);

  randomSeed(0);
}

void loop()
{
  static int i;

  data_n = (double)(random(-1000, 1000)) / 1000.0;
  t = (double)(i) * T;
  data = sin(2.0 * PI * 1.0 * t) + data_n;
  Filter.Update(&data, &data_f);

  i++;

  Serial.print(String() + data + " " + data_f);
  Serial.println();
  Serial.flush();

  delay(1);
}

