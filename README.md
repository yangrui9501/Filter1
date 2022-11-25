# First-Order IIR Filters

## Example

```cpp
#include <Arduino.h>
#include <first_order_iir_filters.h>

double data = 0.0;
double data_f = 0.0;
double data_n = 0.0;
double t = 0.0;
double Cutoff_Freq = 10.0;
double T = 0.001;

FirstOrderIIR LPF;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
    }

    LPF.init(FirstOrderIIR::TYPE_LPF, Cutoff_Freq, T);

    randomSeed(0);
}

void loop()
{
    static int i;

    data_n = (double)(random(-1000, 1000)) / 1000.0;
    t = (double)(i)*T;
    data = sin(2.0 * PI * 1.0 * t) + data_n;
    LPF.update(&data, &data_f);

    i++;

    Serial.print(String() + data + " " + data_f);
    Serial.println();
    Serial.flush();

    delay(1);
}
```
