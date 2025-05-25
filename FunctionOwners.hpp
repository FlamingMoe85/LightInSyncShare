#ifndef FUNCTION_OWNERS_HPP
#define FUNCTION_OWNERS_HPP

#include <string>
using namespace std;

#include "Functions/FunctionContainer.h"

enum FUNC_OWNER_IDS
{
    HAND_TRHOUGH,
    BUNDLE_SERIES,
    COLOR_WHEEL,
    POSITIONER,
    WHITE_MAPPER,
    DIMM_MAPPER,
    WHITEDIMM_MAPPER
};


class FunctionOwners
{
friend class HandThroughMapper;
friend class BundleSeries;
friend class ColorWheelMapper;
friend class Positioner;
friend class White_Mapper;
friend class Dimm_Mapper;
friend class WhiteDimm_Mapper;

public:
    virtual int GetTypeId() = 0;
    string* GetType(){return &type;}
    string* GetDescription(){return &description;}
    FunctionContainer* GetFuncCont(){return &functionContainer;}

    string type, description;
    FunctionContainer functionContainer;


};

#endif // FUNCTION_OWNERS_HPP
