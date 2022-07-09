#include <Arduino.h>
#include "Filter1.h"

void FILTER1::Update(double *Input_Data, double *Filtered_Data)
{
    u_in = *Input_Data;

    u_out = 1.0 / A1D * (-A2D * u_out + B1D * u_in + B2D * u_in_pre);
    u_in_pre = u_in;

    *Filtered_Data = u_out;
}
