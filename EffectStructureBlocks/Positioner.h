#ifndef POSITIONER_H
#define POSITIONER_H

#include "../BrokerClientServer/ClientServerBase.hpp"
#include "../FunctionOwners.hpp"

class Positioner : public ClientServerBase, public FunctionOwners
{
public:
    Positioner();

    void Consume(int& _itterationCntr, float _pos) override;
    void Serve(int& _itterration, float pos) override;

    int GetTypeId() override {return  FUNC_OWNER_IDS::POSITIONER;}

private:
    int itterration;
};

#endif // POSITIONER_H
