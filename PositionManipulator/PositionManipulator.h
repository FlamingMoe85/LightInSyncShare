#ifndef POSITIONMANIPULATOR_H
#define POSITIONMANIPULATOR_H

#include <list>
using namespace std;

#include "../BrokerClientServer/ClientServerBase.hpp"
#include "../Functions/FunctionSection_Base.h"

class PositionManipulator : public ClientServerBase
{
public:
    PositionManipulator();
    void AddFunction(Function_Base* _func){ myFunctions.push_back(_func);};

private:
    list<Function_Base*> myFunctions;
    void Calculate(rangePosition_t& _pos) override;
};

#endif // POSITIONMANIPULATOR_H
