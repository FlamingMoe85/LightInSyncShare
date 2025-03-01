#include "BundleSeriesManager.h"

BundleSeriesManager::BundleSeriesManager()
{

}

void BundleSeriesManager::GenerateBundleSeries(unsigned int _amt)
{
    bundleSeriesVec.reserve(_amt);
    for(unsigned int i=0; i<_amt; i++)
    {
        bundleSeriesVec.push_back(new BundleSeries);
        bundleSeriesVec.back()->SetShiftStepSize((float)i / (float)(_amt));
    }
}

int BundleSeriesManager::RegisterClientToItem(unsigned int _item, I_Client *_c)
{
    if(_item >= bundleSeriesVec.size()) return -1;
    bundleSeriesVec[_item]->RegisterClient(_c);
    return 0;
}

int BundleSeriesManager::SetSerPosToItem(unsigned int _item, I_Server *_s)
{
    if(_item >= bundleSeriesVec.size()) return -1;
    bundleSeriesVec[_item]->SetServer(_s);
    return 0;
}

void BundleSeriesManager::SetSerPosToItems(I_Server *_s)
{
    for(BundleSeries *bs : bundleSeriesVec)
    {
        //bs->SetServer(_s);
        _s->RegisterClient(bs);
    }
}

void BundleSeriesManager::SetSerParamSpeedToItems(I_Server *_s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamSpeed(_s);
    }
}

void BundleSeriesManager::SetSerParamShiftToItems(I_Server *_s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamShift(_s);
    }
}

void BundleSeriesManager::SetSerParamSpanNotchToItems(I_Server* _s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamShift(_s);
    }
}

void BundleSeriesManager::SetSerParamSpanMinToItems(I_Server* _s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamSpanMin(_s);
    }
}

void BundleSeriesManager::SetSerParamSpanMaxToItems(I_Server* _s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamSpanMax(_s);
    }
}

void BundleSeriesManager::SetSerParamSpanOffsetToItems(I_Server* _s)
{
    for(BundleSeries* bs : bundleSeriesVec)
    {
        bs->SetSerParamSpanOffset(_s);
    }
}
