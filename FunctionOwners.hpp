#ifndef FUNCTION_OWNERS_HPP
#define FUNCTION_OWNERS_HPP

#include <string>
using namespace std;

#include "Functions/FunctionContainer.h"

class I_FunctionOwners
{
    virtual string* GetType() = 0;
    virtual FunctionContainer* GetFuncCont() = 0;
};

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


class FunctionOwners : public I_FunctionOwners
{
public:
    //virtual int GetTypeId() = 0;
    virtual string* GetType() override {return &type;}
    string* GetDescription(){return &description;}
    virtual FunctionContainer* GetFuncCont() override {return &functionContainer;}

    string type, description;
    FunctionContainer functionContainer;


};

#endif // FUNCTION_OWNERS_HPP
