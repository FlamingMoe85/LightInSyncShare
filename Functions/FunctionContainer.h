#ifndef FUNCTIONCONTAINER_H
#define FUNCTIONCONTAINER_H

#include <list>
#include <vector>
using std::list;
using std::vector;

#include "I_FunctionSection.hpp"

class FunctionContainer
{
public:
    FunctionContainer();

    int AddFuncSeg(I_FunctionSection* funcSeg){funcSegments.push_back(funcSeg); return 0;};
    void SetFunctionSections(vector<funcSection_t> &funcSecs);
    void ClearSections();
    float Calc(float arg);
    list<I_FunctionSection*>& GetSegmentList(){return funcSegments;};

private:
    list<I_FunctionSection*> funcSegments;
};

#endif // FUNCTIONCONTAINER_H
