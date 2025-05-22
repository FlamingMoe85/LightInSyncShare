#ifndef DIMM_MAPPER_HPP
#define DIMM_MAPPER_HPP

#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../Devices/Interfaces/I_Dimm.hpp"
#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"

class Dimm_Mapper : public ClientServerBase, public FunctionOwners
{
public:
    Dimm_Mapper();

    void Consume(int& _itterationCntr, float _pos) override;

    void SetDimmDevice(I_Dimm* _dimmDev){dimmDev = _dimmDev;};
    int GetTypeId() override {return  FUNC_OWNER_IDS::DIMM_MAPPER;}

private:

    I_Dimm* dimmDev;
};

#endif // WHITE_MAPPER_HPP
