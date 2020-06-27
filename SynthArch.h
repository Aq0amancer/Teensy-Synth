#ifndef SYNTHARCH_H
#define SYNTHARCH_H
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       LFO_PWM; //xy=73.5,684
AudioSynthWaveform       LFO_Pitch;      //xy=78,568.25
AudioMixer4              pitchmixer; //xy=263,579
AudioMixer4              pwmmixer1; //xy=263,671
AudioMixer4              pwmmixer2; //xy=264,740
AudioSynthNoiseWhite     noise1;         //xy=352,296
AudioSynthNoisePink      pink1;          //xy=353,261
AudioSynthWaveformModulated waveform3;   //xy=474.75000190734863,467.99999046325684
AudioSynthWaveformModulated waveform2;   //xy=474.99999618530273,430.2499966621399
AudioSynthWaveformModulated waveform1;   //xy=475.24999618530273,393.2499966621399
AudioSynthWaveformModulated waveform4;   //xy=477.2500171661377,501.74999237060547
AudioSynthWaveformModulated waveform5;   //xy=477.25000190734863,539.2499923706055
AudioSynthWaveformModulated waveform6;   //xy=478.50000190734863,575.4999923706055
AudioSynthWaveformModulated waveform14;  //xy=478.50000190734863,850.4999980926514
AudioSynthWaveformModulated waveform10;  //xy=479.25,716.5
AudioSynthWaveformModulated waveform8;   //xy=479.75,643
AudioSynthWaveformModulated waveform12;  //xy=480,784.75
AudioSynthWaveformModulated waveform15;  //xy=479.75,884.75
AudioSynthWaveformModulated waveform7;   //xy=481.00000190734863,609.2499942779541
AudioSynthWaveformModulated waveform11;  //xy=480.75,751
AudioSynthWaveformModulated waveform16;  //xy=481,922.25
AudioSynthWaveformModulated waveform9;   //xy=482,678.75
AudioSynthWaveformModulated waveform13;  //xy=481.5,819
AudioMixer4              noisemixer; //xy=488,290
AudioMixer4              mixer14;        //xy=631.75,793.5
AudioMixer4              mixer15;        //xy=631.75,860.5
AudioMixer4              mixer9;         //xy=633.75,410.5
AudioMixer4              mixer10;        //xy=633.75,475.5
AudioMixer4              mixer11;        //xy=633.75,540.5
AudioMixer4              mixer16;        //xy=632.75,925.5
AudioSynthWaveform       LFO_Filter; //xy=634,666
AudioMixer4              mixer13;        //xy=634.75,723.5
AudioMixer4              mixer12;        //xy=635.75,606.5
AudioMixer4              filtermixer; //xy=776,674
AudioFilterStateVariable filter2;        //xy=931.2499961853027,477.4999985694885
AudioFilterStateVariable filter4;        //xy=932.2499961853027,605.4999985694885
AudioFilterStateVariable filter7;        //xy=932.2499961853027,805.4999985694885
AudioFilterStateVariable filter3;        //xy=934.2499961853027,540.4999985694885
AudioFilterStateVariable filter8;        //xy=933.2499961853027,871.4999985694885
AudioFilterStateVariable filter5;        //xy=934.2499961853027,670.4999985694885
AudioFilterStateVariable filter6;        //xy=934.2499961853027,734.4999985694885
AudioFilterStateVariable filter1;        //xy=942.25,414.5
AudioMixer4              mixer1;         //xy=1061.25,414.5
AudioMixer4              mixer2;         //xy=1061.25,480.5
AudioMixer4              mixer3;         //xy=1061.25,546.5
AudioMixer4              mixer4;         //xy=1061.25,610.5
AudioMixer4              mixer5;         //xy=1061.25,676.5
AudioMixer4              mixer6;         //xy=1061.25,742.5
AudioMixer4              mixer7;         //xy=1061.25,809.5
AudioMixer4              mixer8;         //xy=1061.25,876.5
AudioEffectEnvelope      envelope5;      //xy=1247.25,670.5
AudioEffectEnvelope      envelope2;      //xy=1252.25,482.5
AudioEffectEnvelope      envelope3;      //xy=1253.25,552.5
AudioEffectEnvelope      envelope1;      //xy=1254.25,412.5
AudioEffectEnvelope      envelope4;      //xy=1254.25,615.5
AudioEffectEnvelope      envelope6;      //xy=1254.25,748.5
AudioEffectEnvelope      envelope8;      //xy=1256.25,880.5
AudioEffectEnvelope      envelope7;      //xy=1258.25,814.5
AudioMixer4              envmixer2;      //xy=1419.2500038146973,585.5000114440918
AudioMixer4              envmixer4;      //xy=1424.2500038146973,757.5000114440918
AudioMixer4              envmixer1;      //xy=1428.25,494.5
AudioMixer4              envmixer3;      //xy=1428.25,666.5
AudioMixer4              mixerL;         //xy=1641.2500038146973,523.5000114440918
AudioMixer4              mixerR;         //xy=1647.25,657.5
AudioEffectFlange        flangerL;       //xy=1823.25,520.5
AudioEffectFlange        flangerR;       //xy=1824.25,661.5
AudioEffectChorus        chorusL;        //xy=1992,521
AudioEffectChorus        chorusR; //xy=2003,661
AudioOutputI2S           i2s1;           //xy=2173.25,575.5
AudioConnection          patchCord1(LFO_PWM, 0, pwmmixer2, 0);
AudioConnection          patchCord2(LFO_PWM, 0, pwmmixer1, 0);
AudioConnection          patchCord3(LFO_Pitch, 0, pitchmixer, 0);
AudioConnection          patchCord4(pitchmixer, 0, waveform1, 0);
AudioConnection          patchCord5(pitchmixer, 0, waveform2, 0);
AudioConnection          patchCord6(pitchmixer, 0, waveform3, 0);
AudioConnection          patchCord7(pitchmixer, 0, waveform4, 0);
AudioConnection          patchCord8(pitchmixer, 0, waveform5, 0);
AudioConnection          patchCord9(pitchmixer, 0, waveform6, 0);
AudioConnection          patchCord10(pitchmixer, 0, waveform7, 0);
AudioConnection          patchCord11(pitchmixer, 0, waveform8, 0);
AudioConnection          patchCord12(pitchmixer, 0, waveform9, 0);
AudioConnection          patchCord13(pitchmixer, 0, waveform10, 0);
AudioConnection          patchCord14(pitchmixer, 0, waveform11, 0);
AudioConnection          patchCord15(pitchmixer, 0, waveform12, 0);
AudioConnection          patchCord16(pitchmixer, 0, waveform14, 0);
AudioConnection          patchCord17(pitchmixer, 0, waveform13, 0);
AudioConnection          patchCord18(pitchmixer, 0, waveform15, 0);
AudioConnection          patchCord19(pitchmixer, 0, waveform16, 0);
AudioConnection          patchCord20(pwmmixer1, 0, waveform1, 1);
AudioConnection          patchCord21(pwmmixer1, 0, waveform3, 1);
AudioConnection          patchCord22(pwmmixer1, 0, waveform5, 1);
AudioConnection          patchCord23(pwmmixer1, 0, waveform7, 1);
AudioConnection          patchCord24(pwmmixer1, 0, waveform9, 1);
AudioConnection          patchCord25(pwmmixer1, 0, waveform11, 1);
AudioConnection          patchCord26(pwmmixer1, 0, waveform13, 1);
AudioConnection          patchCord27(pwmmixer1, 0, waveform15, 1);
AudioConnection          patchCord28(pwmmixer2, 0, waveform2, 1);
AudioConnection          patchCord29(pwmmixer2, 0, waveform4, 1);
AudioConnection          patchCord30(pwmmixer2, 0, waveform6, 1);
AudioConnection          patchCord31(pwmmixer2, 0, waveform8, 1);
AudioConnection          patchCord32(pwmmixer2, 0, waveform10, 1);
AudioConnection          patchCord33(pwmmixer2, 0, waveform12, 1);
AudioConnection          patchCord34(pwmmixer2, 0, waveform14, 1);
AudioConnection          patchCord35(pwmmixer2, 0, waveform16, 1);
AudioConnection          patchCord36(noise1, 0, noisemixer, 1);
AudioConnection          patchCord37(pink1, 0, noisemixer, 0);
AudioConnection          patchCord38(waveform3, 0, mixer10, 0);
AudioConnection          patchCord39(waveform2, 0, mixer9, 1);
AudioConnection          patchCord40(waveform1, 0, mixer9, 0);
AudioConnection          patchCord41(waveform4, 0, mixer10, 1);
AudioConnection          patchCord42(waveform5, 0, mixer11, 0);
AudioConnection          patchCord43(waveform6, 0, mixer11, 1);
AudioConnection          patchCord44(waveform14, 0, mixer15, 1);
AudioConnection          patchCord45(waveform10, 0, mixer13, 1);
AudioConnection          patchCord46(waveform8, 0, mixer12, 1);
AudioConnection          patchCord47(waveform12, 0, mixer14, 1);
AudioConnection          patchCord48(waveform15, 0, mixer16, 0);
AudioConnection          patchCord49(waveform7, 0, mixer12, 0);
AudioConnection          patchCord50(waveform11, 0, mixer14, 0);
AudioConnection          patchCord51(waveform16, 0, mixer16, 1);
AudioConnection          patchCord52(waveform9, 0, mixer13, 0);
AudioConnection          patchCord53(waveform13, 0, mixer15, 0);
AudioConnection          patchCord54(noisemixer, 0, mixer9, 2);
AudioConnection          patchCord55(noisemixer, 0, mixer10, 2);
AudioConnection          patchCord56(noisemixer, 0, mixer11, 2);
AudioConnection          patchCord57(noisemixer, 0, mixer12, 2);
AudioConnection          patchCord58(noisemixer, 0, mixer13, 2);
AudioConnection          patchCord59(noisemixer, 0, mixer14, 2);
AudioConnection          patchCord60(noisemixer, 0, mixer15, 2);
AudioConnection          patchCord61(noisemixer, 0, mixer16, 2);
AudioConnection          patchCord62(mixer14, 0, filter6, 0);
AudioConnection          patchCord63(mixer15, 0, filter7, 0);
AudioConnection          patchCord64(mixer9, 0, filter1, 0);
AudioConnection          patchCord65(mixer10, 0, filter2, 0);
AudioConnection          patchCord66(mixer11, 0, filter3, 0);
AudioConnection          patchCord67(mixer16, 0, filter8, 0);
AudioConnection          patchCord68(LFO_Filter, 0, filtermixer, 0);
AudioConnection          patchCord69(mixer13, 0, filter5, 0);
AudioConnection          patchCord70(mixer12, 0, filter4, 0);
AudioConnection          patchCord71(filtermixer, 0, filter1, 1);
AudioConnection          patchCord72(filtermixer, 0, filter2, 1);
AudioConnection          patchCord73(filtermixer, 0, filter3, 1);
AudioConnection          patchCord74(filtermixer, 0, filter4, 1);
AudioConnection          patchCord75(filtermixer, 0, filter5, 1);
AudioConnection          patchCord76(filtermixer, 0, filter6, 1);
AudioConnection          patchCord77(filtermixer, 0, filter7, 1);
AudioConnection          patchCord78(filtermixer, 0, filter8, 1);
AudioConnection          patchCord79(filter2, 0, mixer2, 0);
AudioConnection          patchCord80(filter2, 1, mixer2, 1);
AudioConnection          patchCord81(filter2, 2, mixer2, 2);
AudioConnection          patchCord82(filter4, 0, mixer4, 0);
AudioConnection          patchCord83(filter4, 1, mixer4, 1);
AudioConnection          patchCord84(filter4, 2, mixer4, 2);
AudioConnection          patchCord85(filter7, 0, mixer7, 0);
AudioConnection          patchCord86(filter7, 1, mixer7, 1);
AudioConnection          patchCord87(filter7, 2, mixer7, 2);
AudioConnection          patchCord88(filter3, 0, mixer3, 0);
AudioConnection          patchCord89(filter3, 1, mixer3, 1);
AudioConnection          patchCord90(filter3, 2, mixer3, 2);
AudioConnection          patchCord91(filter8, 0, mixer8, 0);
AudioConnection          patchCord92(filter8, 1, mixer8, 1);
AudioConnection          patchCord93(filter8, 2, mixer8, 2);
AudioConnection          patchCord94(filter5, 0, mixer5, 0);
AudioConnection          patchCord95(filter5, 1, mixer5, 1);
AudioConnection          patchCord96(filter5, 2, mixer5, 2);
AudioConnection          patchCord97(filter6, 0, mixer6, 0);
AudioConnection          patchCord98(filter6, 1, mixer6, 1);
AudioConnection          patchCord99(filter6, 2, mixer6, 2);
AudioConnection          patchCord100(filter1, 0, mixer1, 0);
AudioConnection          patchCord101(filter1, 1, mixer1, 1);
AudioConnection          patchCord102(filter1, 2, mixer1, 2);
AudioConnection          patchCord103(mixer1, envelope1);
AudioConnection          patchCord104(mixer1, 0, envmixer1, 2);
AudioConnection          patchCord105(mixer2, envelope2);
AudioConnection          patchCord106(mixer2, 0, envmixer1, 3);
AudioConnection          patchCord107(mixer3, envelope3);
AudioConnection          patchCord108(mixer3, 0, envmixer2, 2);
AudioConnection          patchCord109(mixer4, envelope4);
AudioConnection          patchCord110(mixer4, 0, envmixer2, 3);
AudioConnection          patchCord111(mixer5, envelope5);
AudioConnection          patchCord112(mixer5, 0, envmixer3, 2);
AudioConnection          patchCord113(mixer6, envelope6);
AudioConnection          patchCord114(mixer6, 0, envmixer3, 3);
AudioConnection          patchCord115(mixer7, envelope7);
AudioConnection          patchCord116(mixer7, 0, envmixer4, 2);
AudioConnection          patchCord117(mixer8, envelope8);
AudioConnection          patchCord118(mixer8, 0, envmixer4, 3);
AudioConnection          patchCord119(envelope5, 0, envmixer3, 0);
AudioConnection          patchCord120(envelope2, 0, envmixer1, 1);
AudioConnection          patchCord121(envelope3, 0, envmixer2, 0);
AudioConnection          patchCord122(envelope1, 0, envmixer1, 0);
AudioConnection          patchCord123(envelope4, 0, envmixer2, 1);
AudioConnection          patchCord124(envelope6, 0, envmixer3, 1);
AudioConnection          patchCord125(envelope8, 0, envmixer4, 1);
AudioConnection          patchCord126(envelope7, 0, envmixer4, 0);
AudioConnection          patchCord127(envmixer2, 0, mixerL, 1);
AudioConnection          patchCord128(envmixer2, 0, mixerR, 1);
AudioConnection          patchCord129(envmixer4, 0, mixerL, 3);
AudioConnection          patchCord130(envmixer4, 0, mixerR, 3);
AudioConnection          patchCord131(envmixer1, 0, mixerL, 0);
AudioConnection          patchCord132(envmixer1, 0, mixerR, 0);
AudioConnection          patchCord133(envmixer3, 0, mixerL, 2);
AudioConnection          patchCord134(envmixer3, 0, mixerR, 2);
AudioConnection          patchCord135(mixerL, flangerL);
AudioConnection          patchCord136(mixerR, flangerR);
AudioConnection          patchCord137(flangerL, chorusL);
AudioConnection          patchCord138(flangerR, chorusR);
AudioConnection          patchCord139(chorusL, 0, i2s1, 0);
AudioConnection          patchCord140(chorusR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=760.5,282.49998474121094
// GUItool: end automatically generated code



#endif
