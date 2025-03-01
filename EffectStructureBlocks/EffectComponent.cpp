#include "EffectComponent.h"

EffectComponent::EffectComponent()
{

}

void EffectComponent::Consume(int& _itterationCntr, float _pos)
{
    Serve(_itterationCntr, functContainer.Calc(_pos));
}
