#include "iir_filter1.h"

void IIRFilter1::init(FilterType filter_type, double _fc, double _T)
{
    u_out = 0.0;
    u_in = 0.0;
    u_in_pre = 0.0;

    fc = _fc;
    T = _T;

    switch (filter_type)
    {
    case TYPE_LPF:
        A1C = 1.0 / (2.0 * PI * fc);
        A2C = 1.0;
        B1C = 0.0;
        B2C = 1.0;
        break;
    case TYPE_HPF:
        A1C = 1.0 / (2.0 * PI * fc);
        A2C = 1.0;
        B1C = 1.0 / (2.0 * PI * fc);
        B2C = 0.0;
        break;
    case TYPE_APD:
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

const double& IIRFilter1::update(const double& input_data)
{
    u_in = input_data;

    u_out = 1.0 / A1D * (-A2D * u_out + B1D * u_in + B2D * u_in_pre);
    u_in_pre = u_in;

    return u_out;
}