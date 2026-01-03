#ifndef MOVINGHEAD_RGBW_7X40_BEEEYE_51CH_HPP
#define MOVINGHEAD_RGBW_7X40_BEEEYE_51CH_HPP

#include "../../Mapper/Mapper_Channel.h"
#include "../Channel/Channel_8Bit.hpp"
#include "../../Mapper/Mapper_Channel_16b.h"
#include "../Channel/Channel_16Bit.hpp"
#include "../Interfaces/I_RGB.hpp"


#include "RgbDevice.hpp"

class MovingHead_RGBW_7x40_BeeEye_51Ch
{
public:
MovingHead_RGBW_7x40_BeeEye_51Ch(std::vector<uint8_t*>& _universum) :
    channel_Pan(_universum), /*channel_PanFine(_universum),*/ channel_Tilt(_universum), /*channel_TiltFine(_universum),*/
    channel_PanTiltSpeed(_universum), channel_Zoom(_universum), channel_Rotate(_universum), channel_Dimmer(_universum),
    channel_Strobe(_universum), channel_RedDimm(_universum), channel_GreenDimm(_universum), channel_BlueDimm(_universum),
    channel_WhiteDimm(_universum), channel_CT(_universum), channel_Wash(_universum), channel_StaticEff(_universum),
    channel_DynEff(_universum), channel_DynEffSpeed(_universum),
    channel_BkGrndRed(_universum), channel_BkGrndGreen(_universum), channel_BkGrndBlue(_universum), channel_BkGrndWhite(_universum),
    channel_Reset(_universum),
                    channel_Red_1(_universum), channel_Green_1(_universum), channel_Blue_1(_universum), channel_White_1(_universum),
                    channel_Red_2(_universum), channel_Green_2(_universum), channel_Blue_2(_universum), channel_White_2(_universum),
                    channel_Red_3(_universum), channel_Green_3(_universum), channel_Blue_3(_universum), channel_White_3(_universum),
                    channel_Red_4(_universum), channel_Green_4(_universum), channel_Blue_4(_universum), channel_White_4(_universum),
                    channel_Red_5(_universum), channel_Green_5(_universum), channel_Blue_5(_universum), channel_White_5(_universum),
                    channel_Red_6(_universum), channel_Green_6(_universum), channel_Blue_6(_universum), channel_White_6(_universum),
                    channel_Red_7(_universum), channel_Green_7(_universum), channel_Blue_7(_universum), channel_White_7(_universum),

    mapper_Pan(channel_Pan, 65535, 1), /*mapper_PanFine(channel_PanFine, 255, 1),*/ mapper_Tilt(channel_Tilt, 65535, 1),
    /*mapper_TiltFine(channel_TiltFine, 255, 1),*/ mapper_PanTiltSpeed(channel_PanTiltSpeed, 255, 1), mapper_Zoom(channel_Zoom, 255, 1),
    mapper_Rotate(channel_Rotate, 255, 1), mapper_Dimmer(channel_Dimmer, 255, 1),mapper_Strobe(channel_Strobe, 255, 1),
    mapper_RedDimm(channel_RedDimm, 255, 1), mapper_GreenDimm(channel_GreenDimm, 255, 1), mapper_BlueDimm(channel_BlueDimm, 255, 1),
    mapper_WhiteDimm(channel_WhiteDimm, 255, 1), mapper_CT(channel_CT, 255, 1), mapper_Wash(channel_Wash, 255, 1),
    mapper_StaticEff(channel_StaticEff, 255, 1), mapper_DynEff(channel_DynEff, 255, 1), mapper_DynEffSpeed(channel_DynEffSpeed, 255, 1),
    mapper_BkGrndRed(channel_BkGrndRed, 255, 1), mapper_BkGrndGreen(channel_BkGrndGreen, 255, 1),
    mapper_BkGrndBlue(channel_BkGrndBlue, 255, 1), mapper_BkGrndWhite(channel_BkGrndWhite, 255, 1), mapper_Reset(channel_Reset, 255, 1),
    mapper_Red_1(channel_Red_1, 255, 1), mapper_Green_1(channel_Green_1, 255, 1), mapper_Blue_1(channel_Blue_1, 255, 1), mapper_White_1(channel_White_1, 255, 1),
    mapper_Red_2(channel_Red_2, 255, 1), mapper_Green_2(channel_Green_2, 255, 1), mapper_Blue_2(channel_Blue_2, 255, 1), mapper_White_2(channel_White_2, 255, 1),
    mapper_Red_3(channel_Red_3, 255, 1), mapper_Green_3(channel_Green_3, 255, 1), mapper_Blue_3(channel_Blue_3, 255, 1), mapper_White_3(channel_White_3, 255, 1),
    mapper_Red_4(channel_Red_4, 255, 1), mapper_Green_4(channel_Green_4, 255, 1), mapper_Blue_4(channel_Blue_4, 255, 1), mapper_White_4(channel_White_4, 255, 1),
    mapper_Red_5(channel_Red_5, 255, 1), mapper_Green_5(channel_Green_5, 255, 1), mapper_Blue_5(channel_Blue_5, 255, 1), mapper_White_5(channel_White_5, 255, 1),
    mapper_Red_6(channel_Red_6, 255, 1), mapper_Green_6(channel_Green_6, 255, 1), mapper_Blue_6(channel_Blue_6, 255, 1), mapper_White_6(channel_White_6, 255, 1),
    mapper_Red_7(channel_Red_7, 255, 1), mapper_Green_7(channel_Green_7, 255, 1), mapper_Blue_7(channel_Blue_7, 255, 1), mapper_White_7(channel_White_7, 255, 1),

    rgbDevice_1(channel_Red_1, channel_Green_1, channel_Blue_1),
    rgbDevice_2(channel_Red_2, channel_Green_2, channel_Blue_2),
    rgbDevice_3(channel_Red_3, channel_Green_3, channel_Blue_3),
    rgbDevice_4(channel_Red_4, channel_Green_4, channel_Blue_4),
    rgbDevice_5(channel_Red_5, channel_Green_5, channel_Blue_5),
    rgbDevice_6(channel_Red_6, channel_Green_6, channel_Blue_6),
    rgbDevice_7(channel_Red_7, channel_Green_7, channel_Blue_7)

{
    mapper_Pan.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    //mapper_PanFine.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Tilt.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    //mapper_TiltFine.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_PanTiltSpeed.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Zoom.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Rotate.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,0.5,0.0);
    mapper_Dimmer.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Strobe.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_RedDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_GreenDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BlueDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_WhiteDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_CT.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Wash.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_StaticEff.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_DynEff.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_DynEffSpeed.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BkGrndRed.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BkGrndGreen.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BkGrndBlue.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BkGrndWhite.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Reset.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_1.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_1.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_1.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_1.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_2.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_2.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_2.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_2.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_3.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_3.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_3.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_3.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_4.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_4.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_4.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_4.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_5.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_5.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_5.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_5.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_6.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_6.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_6.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_6.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Red_7.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Green_7.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Blue_7.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_White_7.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);

}


    void SetPanVal(uint8_t _val){channel_Pan.SetChnlVal(_val);};
    void SetTiltVal(uint8_t _val){channel_Tilt.SetChnlVal(_val);};

    RGB_Device* GetRgbDevice(int _device)
    {
        switch(_device)
        {
            case 0:
                return &rgbDevice_1;
            case 1:
                return &rgbDevice_2;
            case 2:
                return &rgbDevice_3;
            case 3:
                return &rgbDevice_4;
            case 4:
                return &rgbDevice_5;
            case 5:
                return &rgbDevice_6;
            default:
                return &rgbDevice_7;
        }

     }

    void Init (int _adr)
    {
        channel_Pan.SetChannel(	0	+ _adr);
        //channel_PanFine.SetChannel(	1	+ _adr);
        channel_Tilt.SetChannel(	2	+ _adr);
        //channel_TiltFine.SetChannel(	3	+ _adr);
        channel_PanTiltSpeed.SetChannel(	4	+ _adr);
        channel_Zoom.SetChannel(	5	+ _adr);
        channel_Rotate.SetChannel(	6	+ _adr);
        channel_Dimmer.SetChannel(	7	+ _adr);
        channel_Strobe.SetChannel(	8	+ _adr);
        channel_RedDimm.SetChannel(	9	+ _adr);
        channel_GreenDimm.SetChannel(	10	+ _adr);
        channel_BlueDimm.SetChannel(	11	+ _adr);
        channel_WhiteDimm.SetChannel(	12	+ _adr);
        channel_CT.SetChannel(	13	+ _adr);
        channel_Wash.SetChannel(	14	+ _adr);
        channel_StaticEff.SetChannel(	15	+ _adr);
        channel_DynEff.SetChannel(	16	+ _adr);
        channel_DynEffSpeed.SetChannel(	17	+ _adr);
        channel_BkGrndRed.SetChannel(	18	+ _adr);
        channel_BkGrndGreen.SetChannel(	19	+ _adr);
        channel_BkGrndBlue.SetChannel(	20	+ _adr);
        channel_BkGrndWhite.SetChannel(	21	+ _adr);
        channel_Reset.SetChannel(	22	+ _adr);
        channel_Red_1.SetChannel(	23	+ _adr);
        channel_Green_1.SetChannel(	24	+ _adr);
        channel_Blue_1.SetChannel(	25	+ _adr);
        channel_White_1.SetChannel(	26	+ _adr);
        channel_Red_2.SetChannel(	27	+ _adr);
        channel_Green_2.SetChannel(	28	+ _adr);
        channel_Blue_2.SetChannel(	29	+ _adr);
        channel_White_2.SetChannel(	30	+ _adr);
        channel_Red_3.SetChannel(	31	+ _adr);
        channel_Green_3.SetChannel(	32	+ _adr);
        channel_Blue_3.SetChannel(	33	+ _adr);
        channel_White_3.SetChannel(	34	+ _adr);
        channel_Red_4.SetChannel(	35	+ _adr);
        channel_Green_4.SetChannel(	36	+ _adr);
        channel_Blue_4.SetChannel(	37	+ _adr);
        channel_White_4.SetChannel(	38	+ _adr);
        channel_Red_5.SetChannel(	39	+ _adr);
        channel_Green_5.SetChannel(	40	+ _adr);
        channel_Blue_5.SetChannel(	41	+ _adr);
        channel_White_5.SetChannel(	42	+ _adr);
        channel_Red_6.SetChannel(	43	+ _adr);
        channel_Green_6.SetChannel(	44	+ _adr);
        channel_Blue_6.SetChannel(	45	+ _adr);
        channel_White_6.SetChannel(	46	+ _adr);
        channel_Red_7.SetChannel(	47	+ _adr);
        channel_Green_7.SetChannel(	48	+ _adr);
        channel_Blue_7.SetChannel(	49	+ _adr);
        channel_White_7.SetChannel(	50	+ _adr);

    }

    Mapper_Base* GetMapperPan(){ return &mapper_Pan;}
    //Mapper_Base* GetMapperPanFine(){ return &mapper_PanFine;}
    Mapper_Base* GetMapperTilt(){ return &mapper_Tilt;}
    //Mapper_Base* GetMapperTiltFine(){ return &mapper_TiltFine;}
    Mapper_Base* GetMapperPanTiltSpeed(){ return &mapper_PanTiltSpeed;}
    Mapper_Base* GetMapperZoom(){ return &mapper_Zoom;}
    Mapper_Base* GetMapperRotate(){ return &mapper_Rotate;}
    Mapper_Base* GetMapperDimmer(){ return &mapper_Dimmer;}
    Mapper_Base* GetMapperStrobe(){ return &mapper_Strobe;}
    Mapper_Base* GetMapperRedDimm(){ return &mapper_RedDimm;}
    Mapper_Base* GetMapperGreenDimm(){ return &mapper_GreenDimm;}
    Mapper_Base* GetMapperBlueDimm(){ return &mapper_BlueDimm;}
    Mapper_Base* GetMapperWhiteDimm(){ return &mapper_WhiteDimm;}
    Mapper_Base* GetMapperCT(){ return &mapper_CT;}
    Mapper_Base* GetMapperWash(){ return &mapper_Wash;}
    Mapper_Base* GetMapperStaticEff(){ return &mapper_StaticEff;}
    Mapper_Base* GetMapperDynEff(){ return &mapper_DynEff;}
    Mapper_Base* GetMapperDynEffSpeed(){ return &mapper_DynEffSpeed;}
    Mapper_Base* GetMapperBkGrndRed(){ return &mapper_BkGrndRed;}
    Mapper_Base* GetMapperBkGrndGreen(){ return &mapper_BkGrndGreen;}
    Mapper_Base* GetMapperBkGrndBlue(){ return &mapper_BkGrndBlue;}
    Mapper_Base* GetMapperBkGrndWhite(){ return &mapper_BkGrndWhite;}
    Mapper_Base* GetMapperReset(){ return &mapper_Reset;}
    Mapper_Base* GetMapperRed_1(){ return &mapper_Red_1;}
    Mapper_Base* GetMapperGreen_1(){ return &mapper_Green_1;}
    Mapper_Base* GetMapperBlue_1(){ return &mapper_Blue_1;}
    Mapper_Base* GetMapperWhite_1(){ return &mapper_White_1;}
    Mapper_Base* GetMapperRed_2(){ return &mapper_Red_2;}
    Mapper_Base* GetMapperGreen_2(){ return &mapper_Green_2;}
    Mapper_Base* GetMapperBlue_2(){ return &mapper_Blue_2;}
    Mapper_Base* GetMapperWhite_2(){ return &mapper_White_2;}
    Mapper_Base* GetMapperRed_3(){ return &mapper_Red_3;}
    Mapper_Base* GetMapperGreen_3(){ return &mapper_Green_3;}
    Mapper_Base* GetMapperBlue_3(){ return &mapper_Blue_3;}
    Mapper_Base* GetMapperWhite_3(){ return &mapper_White_3;}
    Mapper_Base* GetMapperRed_4(){ return &mapper_Red_4;}
    Mapper_Base* GetMapperGreen_4(){ return &mapper_Green_4;}
    Mapper_Base* GetMapperBlue_4(){ return &mapper_Blue_4;}
    Mapper_Base* GetMapperWhite_4(){ return &mapper_White_4;}
    Mapper_Base* GetMapperRed_5(){ return &mapper_Red_5;}
    Mapper_Base* GetMapperGreen_5(){ return &mapper_Green_5;}
    Mapper_Base* GetMapperBlue_5(){ return &mapper_Blue_5;}
    Mapper_Base* GetMapperWhite_5(){ return &mapper_White_5;}
    Mapper_Base* GetMapperRed_6(){ return &mapper_Red_6;}
    Mapper_Base* GetMapperGreen_6(){ return &mapper_Green_6;}
    Mapper_Base* GetMapperBlue_6(){ return &mapper_Blue_6;}
    Mapper_Base* GetMapperWhite_6(){ return &mapper_White_6;}
    Mapper_Base* GetMapperRed_7(){ return &mapper_Red_7;}
    Mapper_Base* GetMapperGreen_7(){ return &mapper_Green_7;}
    Mapper_Base* GetMapperBlue_7(){ return &mapper_Blue_7;}
    Mapper_Base* GetMapperWhite_7(){ return &mapper_White_7;}

    Mapper_Base* GetMapperRedByIndex(int _i)
    {
        switch(_i)
        {
            case 0:
                return GetMapperRed_1();
            case 1:
                return GetMapperRed_2();
            case 2:
                return GetMapperRed_3();
            case 3:
                return GetMapperRed_4();
            case 4:
                return GetMapperRed_5();
            case 5:
                return GetMapperRed_6();
            default:
                return GetMapperRed_7();
        }
    }

    Mapper_Base* GetMapperGreenByIndex(int _i)
    {
        switch(_i)
        {
            case 0:
                return GetMapperGreen_1();
            case 1:
                return GetMapperGreen_2();
            case 2:
                return GetMapperGreen_3();
            case 3:
                return GetMapperGreen_4();
            case 4:
                return GetMapperGreen_5();
            case 5:
                return GetMapperGreen_6();
            default:
                return GetMapperGreen_7();
        }
    }

    Mapper_Base* GetMapperBlueByIndex(int _i)
    {
        switch(_i)
        {
            case 0:
                return GetMapperBlue_1();
            case 1:
                return GetMapperBlue_2();
            case 2:
                return GetMapperBlue_3();
            case 3:
                return GetMapperBlue_4();
            case 4:
                return GetMapperBlue_5();
            case 5:
                return GetMapperBlue_6();
            default:
                return GetMapperBlue_7();
        }
    }

    Mapper_Base* GetMapperWhiteByIndex(int _i)
    {
        switch(_i)
        {
            case 0:
                return GetMapperWhite_1();
            case 1:
                return GetMapperWhite_2();
            case 2:
                return GetMapperWhite_3();
            case 3:
                return GetMapperWhite_4();
            case 4:
                return GetMapperWhite_5();
            case 5:
                return GetMapperWhite_6();
            default:
                return GetMapperWhite_7();
        }
    }

private:

    Channel_16Bit channel_Pan, channel_Tilt;

Channel_8Bit    channel_PanTiltSpeed, channel_Zoom, channel_Rotate, channel_Dimmer,
                channel_Strobe, channel_RedDimm, channel_GreenDimm, channel_BlueDimm, channel_WhiteDimm, channel_CT, channel_Wash, channel_StaticEff,
                channel_DynEff, channel_DynEffSpeed,
                channel_BkGrndRed, channel_BkGrndGreen, channel_BkGrndBlue, channel_BkGrndWhite, channel_Reset,
                channel_Red_1, channel_Green_1, channel_Blue_1, channel_White_1,
                channel_Red_2, channel_Green_2, channel_Blue_2, channel_White_2,
                channel_Red_3, channel_Green_3, channel_Blue_3, channel_White_3,
                channel_Red_4, channel_Green_4, channel_Blue_4, channel_White_4,
                channel_Red_5, channel_Green_5, channel_Blue_5, channel_White_5,
                channel_Red_6, channel_Green_6, channel_Blue_6, channel_White_6,
                channel_Red_7, channel_Green_7, channel_Blue_7, channel_White_7;



Mapper_Channel  mapper_PanTiltSpeed, mapper_Zoom, mapper_Rotate, mapper_Dimmer,
                mapper_Strobe, mapper_RedDimm, mapper_GreenDimm, mapper_BlueDimm, mapper_WhiteDimm, mapper_CT, mapper_Wash,
                mapper_StaticEff, mapper_DynEff, mapper_DynEffSpeed,
                mapper_BkGrndRed, mapper_BkGrndGreen, mapper_BkGrndBlue, mapper_BkGrndWhite, mapper_Reset,
                mapper_Red_1, mapper_Green_1, mapper_Blue_1, mapper_White_1,
                mapper_Red_2, mapper_Green_2, mapper_Blue_2, mapper_White_2,
                mapper_Red_3, mapper_Green_3, mapper_Blue_3, mapper_White_3,
                mapper_Red_4, mapper_Green_4, mapper_Blue_4, mapper_White_4,
                mapper_Red_5, mapper_Green_5, mapper_Blue_5, mapper_White_5,
                mapper_Red_6, mapper_Green_6, mapper_Blue_6, mapper_White_6,
                mapper_Red_7, mapper_Green_7, mapper_Blue_7, mapper_White_7;

Mapper_Channel_16b mapper_Pan, mapper_Tilt;

RGB_Device rgbDevice_1, rgbDevice_2, rgbDevice_3, rgbDevice_4, rgbDevice_5, rgbDevice_6, rgbDevice_7;
};


#endif // MOVINGHEAD_RGBW_7X40_BEEEYE_51CH_HPP
