#ifndef WHITE_MAPPER_HPP
#define WHITE_MAPPER_HPP

#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../Devices/Interfaces/I_WhiteDimm.hpp"
#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"

class WhiteDimm_Mapper : public ClientServerBase, public FunctionOwners
{
public:
    WhiteDimm_Mapper();

    void Consume(int& _itterationCntr, float _pos) override;

    void SetRgbDevice(I_WhiteDimm* _whiteDimmDev){whiteDimmDev = _whiteDimmDev;};
    //int GetTypeId() override {return  FUNC_OWNER_IDS::WHITEDIMM_MAPPER;}

private:

    I_WhiteDimm* whiteDimmDev;
};

#endif // WHITE_MAPPER_HPP
