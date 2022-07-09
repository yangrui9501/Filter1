/**
 * @file Filter1.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

class FILTER1
{
public:
    // Initialize type of filter, cut-off frequency, and sample time
    enum FilterType
    {
        LPF,
        HPF,
        APD
    };
    
    void Init(FilterType Type, double Cutoff_Freq, double Sample_Time)
    {
        u_out = 0.0;
        u_in = 0.0;
        u_in_pre = 0.0;

        fc = Cutoff_Freq;
        T = Sample_Time;

        switch (Type)
        {
        case LPF:
            A1C = 1.0 / (2.0 * PI * fc);
            A2C = 1.0;
            B1C = 0.0;
            B2C = 1.0;
            break;
        case HPF:
            A1C = 1.0 / (2.0 * PI * fc);
            A2C = 1.0;
            B1C = 1.0 / (2.0 * PI * fc);
            B2C = 0.0;
            break;
        case APD:
            A1C = 1.0 / (2.0 * PI * fc);
            A2C = 1.0;
            B1C = 1.0;
            B2C = 0.0;
            break;
        }
        A1D = 2.0 * A1C + A2C * T;
        A2D = A2C * T - 2.0 * A1C;
        B1D = 2.0 * B1C + B2C * T;
        B2D = B2C * T - 2.0 * B1C;
    }

    // Use this function filtering the 'input_data'
    void Update(double *Input_Data, double *Filtered_Data);

private:
    double u_in, u_in_pre, u_out;
    double A1D, A2D, B1D, B2D;
    double A1C, A2C, B1C, B2C;
    double fc, T;
};
