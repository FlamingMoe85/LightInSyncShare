#include "ComponentBundle.h"

ComponentBundle::ComponentBundle()
{

}

void ComponentBundle::Consume(int& _itterationCntr, float _pos)
{
    Serve(_itterationCntr, _pos);
}


