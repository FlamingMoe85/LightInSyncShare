#ifndef WHITE_MAPPER_HPP
#define WHITE_MAPPER_HPP

#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../Devices/Interfaces/I_White.hpp"
#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"

class White_Mapper : public ClientServerBase, public FunctionOwners
{
public:
    White_Mapper();

    void Consume(int& _itterationCntr, float _pos) override;

    void SetRgbDevice(I_White* _whiteDev){whiteDev = _whiteDev;};
    //int GetTypeId() override {return  FUNC_OWNER_IDS::WHITE_MAPPER;}

private:

    I_White* whiteDev;
};

#endif // WHITE_MAPPER_HPP
