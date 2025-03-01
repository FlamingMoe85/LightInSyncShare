#ifndef I_FUNCTIONSECTION_H
#define I_FUNCTIONSECTION_H

typedef struct
{
    float minX;
    float maxX;
    float minY;
    float maxY;
}funcSection_t;


class I_FunctionSection
{
public:
    virtual float Calc(float arg)=0;

    virtual int SetTopX(float _topX)=0;
    virtual int SetBottomX(float _bottomX)=0;
    virtual float GetTopX()=0;
    virtual float GetBottomX()=0;
};

#endif // I_FUNCTIONSECTION_H
