/**
 * @file iir_filter1.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-05, 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#ifdef ENV_PC

#ifndef PI
#define PI 3.141592653589793
#endif

#else
#include <Arduino.h>
#endif 

class IIRFilter1
{
public:
    // Initialize type of filter, cut-off frequency, and sample time
    enum FilterType
    {
        TYPE_LPF,
        TYPE_HPF,
        TYPE_APD
    };

    void init(FilterType Type, double Cutoff_Freq, double Sample_Time);
    void update(double *Input_Data, double *Filtered_Data);

private:
    double u_in, u_in_pre, u_out;
    double A1D, A2D, B1D, B2D;
    double A1C, A2C, B1C, B2C;
    double fc, T;
};
