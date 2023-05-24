# DSP Library: First-Order IIR Filters

## Example: LPF

This example demonstrates how to intantiate a low-pass filter object and filter out the noise signal.

```cpp
// 2023-05-24
#include <Arduino.h>
#include <iir_filter1.h>

IIRFilter1 lpf;

double y = 0.0;
double n = 0.0;
double ym = 0.0;
double yf = 0.0;
double t = 0.0;
double fc = 10.0;
double T = 0.001;

void setup()
{
    Serial.begin(115200);

    lpf.init(IIRFilter1::TYPE_LPF, fc, T);

    randomSeed(0);
}

void loop()
{
    static int i;

    n = (double)(random(-1000, 1000)) / 1000.0;

    t = (double)(i)*T;
    y = sin(2.0 * PI * 1.0 * t);

    ym = y + n;

    yf = lpf.update(ym);

    i++;

    Serial.print(ym, 4);
    Serial.print(" ");
    Serial.print(y, 4);
    Serial.print(" ");
    Serial.print(yf, 4);
    Serial.println();
    Serial.flush();

    delay(10);
}
```

![image](https://github.com/yangrui9501/dsp_iir_filter1/assets/91120147/9267c2f2-bd7f-4df7-939c-109ad382334a)
