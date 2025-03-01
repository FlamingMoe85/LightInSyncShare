#ifndef FUNCTIONSECTION_LINEAR_H
#define FUNCTIONSECTION_LINEAR_H

#include "FunctionSection_Base.h"

class FunctionSection_Linear : public FunctionSection_Base
{
public:
    FunctionSection_Linear();
    FunctionSection_Linear(float _bottomX, float _topX, float _bottomY, float _topY);
    FunctionSection_Linear(funcSection_t &fs);

    float Calc(float arg) override;

    void SetTopY(float _topY){ topY = _topY;};
    void SetBottomY(float _bottomY){bottomY = _bottomY;};
    float GetTopY(){return topY;};
    float GetBottomY(){return bottomY;};

    static void SetFuncArea(FunctionSection_Linear* sec, float _bottomX, float _topX, float _bottomY, float _topY)
    {
        sec->SetTopX(_topX);
        sec->SetBottomX(_bottomX);
        sec->SetTopY(_topY);
        sec->SetBottomY(_bottomY);
    }

    static void SetFuncArea(FunctionSection_Linear* _secLin, funcSection_t &_sec)
    {
        _secLin->SetTopX(_sec.maxX);
        _secLin->SetBottomX(_sec.minX);
        _secLin->SetTopY(_sec.maxY);
        _secLin->SetBottomY(_sec.minY);
    }

private:
    float topY, bottomY;
};



#endif // FUNCTIONSECTION_LINEAR_H
