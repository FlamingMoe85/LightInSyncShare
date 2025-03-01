#ifndef BUNDLESERIESMANAGER_H
#define BUNDLESERIESMANAGER_H

#include "BundleSeries.h"

#include <vector>
using namespace std;

class BundleSeriesManager
{
public:
    BundleSeriesManager();

    void GenerateBundleSeries(unsigned int _amt);
    void SetMaxShift(float _maxShift);

    int RegisterClientToItem(unsigned int _item, I_Client *_c);
    int SetSerPosToItem(unsigned int _item, I_Server *_s);
    void SetSerPosToItems(I_Server *_s);

    void SetSerParamSpeedToItems(I_Server *_s);
    void SetSerParamShiftToItems(I_Server *_s);
    void SetSerParamSpanNotchToItems(I_Server* _s);
    void SetSerParamSpanMinToItems(I_Server* _s);
    void SetSerParamSpanMaxToItems(I_Server* _s);
    void SetSerParamSpanOffsetToItems(I_Server* _s);

    BundleSeries* GetBundleSeries(int _item){return bundleSeriesVec[_item];}


private:
    vector<BundleSeries*> bundleSeriesVec;
};

#endif // BUNDLESERIESMANAGER_H
