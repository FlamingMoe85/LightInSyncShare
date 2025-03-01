#ifndef GLOBALDEFINES_SHARED_H
#define GLOBALDEFINES_SHARED_H


struct rangePosition_t
{
    float relPos;
    float min;
    float max;

    rangePosition_t& operator=(rangePosition_t const& operand)
    {
        max = operand.max;
        min = operand.min;
        relPos = operand.relPos;
        return *this;
    }
};
/**/

/*
rangePosition_t operator=(rangePosition_t const& operand)
{

}
*/

/*
Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
*/
#endif // GLOBALDEFINES_SHARED_H
