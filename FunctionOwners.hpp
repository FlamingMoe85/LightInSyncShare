#ifndef FUNCTION_OWNERS_HPP
#define FUNCTION_OWNERS_HPP

#include <string>
using namespace std;

#include "Functions/FunctionContainer.h"

enum FUNC_OWNER_IDS
{
    HAND_TRHOUGH,
    BUNDLE_SERIES,
    COLOR_WHEEL
};


class FunctionOwners
{
friend class HandThroughMapper;
friend class BundleSeries;
friend class ColorWheelMapper;

public:
    virtual int GetTypeId() = 0;
    string* GetType(){return &type;}
    string* GetDescription(){return &description;}
    FunctionContainer* GetFuncCont(){return &functionContainer;}

    string type, description;
    FunctionContainer functionContainer;


};

#endif // FUNCTION_OWNERS_HPP
