#ifndef SYNTHARCH_H
#define SYNTHARCH_H
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       LFO_PWM; //xy=64.5,715
AudioSynthWaveform       LFO_Pitch;      //xy=66,655.25
AudioMixer4              pwmmixer2; //xy=260,773
AudioMixer4              pwmmixer1; //xy=261,593
AudioSynthNoiseWhite     noise1;         //xy=350,305
AudioSynthNoisePink      pink1;          //xy=353,261
AudioSynthWaveformModulated waveform3;   //xy=474.75000190734863,467.99999046325684
AudioSynthWaveformModulated waveform2;   //xy=474.99999618530273,430.2499966621399
AudioSynthWaveformModulated waveform1;   //xy=475.24999618530273,393.2499966621399
AudioSynthWaveformModulated waveform4;   //xy=477.2500171661377,501.74999237060547
AudioSynthWaveformModulated waveform5;   //xy=477.25000190734863,539.2499923706055
AudioSynthWaveformModulated waveform6;   //xy=478.50000190734863,575.4999923706055
AudioSynthWaveformModulated waveform13;  //xy=478.50000190734863,817.9999976158142
AudioSynthWaveformModulated waveform14;  //xy=478.50000190734863,850.4999980926514
AudioSynthWaveformModulated waveform8;   //xy=479.74999809265137,642.9999942779541
AudioSynthWaveformModulated waveform11;  //xy=479.75000190734863,752.9999961853027
AudioSynthWaveformModulated waveform15;  //xy=479.74999809265137,881.7499990463257
AudioSynthWaveformModulated waveform7;   //xy=481.00000190734863,609.2499942779541
AudioSynthWaveformModulated waveform9;   //xy=480.9999942779541,676.7499895095825
AudioSynthWaveformModulated waveform12;  //xy=481,786.7499966621399
AudioSynthWaveformModulated waveform16;  //xy=481,914.25
AudioSynthWaveformModulated waveform10;  //xy=482.25000190734863,715.4999961853027
AudioMixer4              noisemixer; //xy=488,290
AudioMixer4              mixer9;         //xy=663.75,406.5
AudioMixer4              mixer13;        //xy=662.75,723.5
AudioMixer4              mixer14;        //xy=662.75,789.5
AudioMixer4              mixer15;        //xy=662.75,856.5
AudioMixer4              mixer10;        //xy=664.75,471.5
AudioMixer4              mixer11;        //xy=664.75,537.5
AudioMixer4              mixer12;        //xy=664.75,601.5
AudioMixer4              mixer16;        //xy=663.75,921.5
AudioSynthWaveform       LFO_Filter; //xy=665,662
AudioFilterStateVariable filter2;        //xy=877.2499961853027,481.4999985694885
AudioFilterStateVariable filter4;        //xy=878.2499961853027,609.4999985694885
AudioFilterStateVariable filter7;        //xy=878.2499961853027,809.4999985694885
AudioFilterStateVariable filter1;        //xy=880.2499961853027,417.4999985694885
AudioFilterStateVariable filter3;        //xy=880.2499961853027,544.4999985694885
AudioFilterStateVariable filter8;        //xy=879.2499961853027,875.4999985694885
AudioFilterStateVariable filter5;        //xy=880.2499961853027,674.4999985694885
AudioFilterStateVariable filter6;        //xy=880.2499961853027,738.4999985694885
AudioMixer4              mixer1;         //xy=1061.25,414.5
AudioMixer4              mixer2;         //xy=1061.25,480.5
AudioMixer4              mixer3;         //xy=1061.25,546.5
AudioMixer4              mixer4;         //xy=1061.25,610.5
AudioMixer4              mixer5;         //xy=1061.25,676.5
AudioMixer4              mixer6;         //xy=1061.25,742.5
AudioMixer4              mixer7;         //xy=1061.25,809.5
AudioMixer4              mixer8;         //xy=1061.25,876.5
AudioEffectEnvelope      envelope5;      //xy=1247.25,670.5
AudioEffectEnvelope      envelope3;      //xy=1253.25,552.5
AudioEffectEnvelope      envelope4;      //xy=1254.25,615.5
AudioEffectEnvelope      envelope6;      //xy=1254.25,748.5
AudioEffectEnvelope      envelope1;      //xy=1257.25,418.5
AudioEffectEnvelope      envelope8;      //xy=1256.25,880.5
AudioEffectEnvelope      envelope2;      //xy=1259.25,485.5
AudioEffectEnvelope      envelope7;      //xy=1258.25,814.5
AudioMixer4              envmixer1;      //xy=1414.2500038146973,493.5000114440918
AudioMixer4              envmixer2;      //xy=1419.2500038146973,585.5000114440918
AudioMixer4              envmixer3;      //xy=1419.2500038146973,668.5000114440918
AudioMixer4              envmixer4;      //xy=1424.2500038146973,757.5000114440918
AudioMixer4              mixerL;         //xy=1641.2500038146973,523.5000114440918
AudioMixer4              mixerR;         //xy=1644.2500038146973,664.5000114440918
AudioEffectFlange        flangerR;       //xy=1834.2500038146973,661.5000114440918
AudioEffectFlange        flangerL;       //xy=1836.2500038146973,522.5000114440918
AudioEffectChorus        chorusL;        //xy=1992,521
AudioEffectChorus        chorusR; //xy=1996,661
AudioOutputI2S           i2s1;           //xy=2173.25,575.5
AudioConnection          patchCord1(LFO_PWM, 0, pwmmixer2, 0);
AudioConnection          patchCord2(LFO_PWM, 0, pwmmixer1, 0);
AudioConnection          patchCord3(LFO_Pitch, 0, waveform3, 0);
AudioConnection          patchCord4(LFO_Pitch, 0, waveform5, 0);
AudioConnection          patchCord5(LFO_Pitch, 0, waveform7, 0);
AudioConnection          patchCord6(LFO_Pitch, 0, waveform9, 0);
AudioConnection          patchCord7(LFO_Pitch, 0, waveform11, 0);
AudioConnection          patchCord8(LFO_Pitch, 0, waveform13, 0);
AudioConnection          patchCord9(LFO_Pitch, 0, waveform15, 0);
AudioConnection          patchCord10(LFO_Pitch, 0, waveform1, 0);
AudioConnection          patchCord11(LFO_Pitch, 0, waveform2, 0);
AudioConnection          patchCord12(LFO_Pitch, 0, waveform4, 0);
AudioConnection          patchCord13(LFO_Pitch, 0, waveform6, 0);
AudioConnection          patchCord14(LFO_Pitch, 0, waveform8, 0);
AudioConnection          patchCord15(LFO_Pitch, 0, waveform10, 0);
AudioConnection          patchCord16(LFO_Pitch, 0, waveform12, 0);
AudioConnection          patchCord17(LFO_Pitch, 0, waveform14, 0);
AudioConnection          patchCord18(LFO_Pitch, 0, waveform16, 0);
AudioConnection          patchCord19(pwmmixer2, 0, waveform2, 1);
AudioConnection          patchCord20(pwmmixer2, 0, waveform4, 1);
AudioConnection          patchCord21(pwmmixer2, 0, waveform6, 1);
AudioConnection          patchCord22(pwmmixer2, 0, waveform8, 1);
AudioConnection          patchCord23(pwmmixer2, 0, waveform10, 1);
AudioConnection          patchCord24(pwmmixer2, 0, waveform12, 1);
AudioConnection          patchCord25(pwmmixer2, 0, waveform14, 1);
AudioConnection          patchCord26(pwmmixer2, 0, waveform16, 1);
AudioConnection          patchCord27(pwmmixer1, 0, waveform1, 1);
AudioConnection          patchCord28(pwmmixer1, 0, waveform3, 1);
AudioConnection          patchCord29(pwmmixer1, 0, waveform5, 1);
AudioConnection          patchCord30(pwmmixer1, 0, waveform7, 1);
AudioConnection          patchCord31(pwmmixer1, 0, waveform9, 1);
AudioConnection          patchCord32(pwmmixer1, 0, waveform11, 1);
AudioConnection          patchCord33(pwmmixer1, 0, waveform13, 1);
AudioConnection          patchCord34(pwmmixer1, 0, waveform15, 1);
AudioConnection          patchCord35(noise1, 0, noisemixer, 1);
AudioConnection          patchCord36(pink1, 0, noisemixer, 0);
AudioConnection          patchCord37(waveform3, 0, mixer10, 0);
AudioConnection          patchCord38(waveform2, 0, mixer9, 1);
AudioConnection          patchCord39(waveform1, 0, mixer9, 0);
AudioConnection          patchCord40(waveform4, 0, mixer10, 1);
AudioConnection          patchCord41(waveform5, 0, mixer11, 0);
AudioConnection          patchCord42(waveform6, 0, mixer11, 1);
AudioConnection          patchCord43(waveform13, 0, mixer15, 0);
AudioConnection          patchCord44(waveform14, 0, mixer15, 1);
AudioConnection          patchCord45(waveform8, 0, mixer12, 1);
AudioConnection          patchCord46(waveform11, 0, mixer14, 0);
AudioConnection          patchCord47(waveform15, 0, mixer16, 0);
AudioConnection          patchCord48(waveform7, 0, mixer12, 0);
AudioConnection          patchCord49(waveform9, 0, mixer13, 0);
AudioConnection          patchCord50(waveform12, 0, mixer14, 1);
AudioConnection          patchCord51(waveform16, 0, mixer16, 1);
AudioConnection          patchCord52(waveform10, 0, mixer13, 1);
AudioConnection          patchCord53(noisemixer, 0, mixer9, 2);
AudioConnection          patchCord54(noisemixer, 0, mixer10, 2);
AudioConnection          patchCord55(noisemixer, 0, mixer11, 2);
AudioConnection          patchCord56(noisemixer, 0, mixer12, 2);
AudioConnection          patchCord57(noisemixer, 0, mixer13, 2);
AudioConnection          patchCord58(noisemixer, 0, mixer14, 2);
AudioConnection          patchCord59(noisemixer, 0, mixer15, 2);
AudioConnection          patchCord60(noisemixer, 0, mixer16, 2);
AudioConnection          patchCord61(mixer9, 0, filter1, 0);
AudioConnection          patchCord62(mixer13, 0, filter5, 0);
AudioConnection          patchCord63(mixer14, 0, filter6, 0);
AudioConnection          patchCord64(mixer15, 0, filter7, 0);
AudioConnection          patchCord65(mixer10, 0, filter2, 0);
AudioConnection          patchCord66(mixer11, 0, filter3, 0);
AudioConnection          patchCord67(mixer12, 0, filter4, 0);
AudioConnection          patchCord68(mixer16, 0, filter8, 0);
AudioConnection          patchCord69(LFO_Filter, 0, filter4, 1);
AudioConnection          patchCord70(LFO_Filter, 0, filter5, 1);
AudioConnection          patchCord71(LFO_Filter, 0, filter6, 1);
AudioConnection          patchCord72(LFO_Filter, 0, filter7, 1);
AudioConnection          patchCord73(LFO_Filter, 0, filter8, 1);
AudioConnection          patchCord74(LFO_Filter, 0, filter3, 1);
AudioConnection          patchCord75(LFO_Filter, 0, filter2, 1);
AudioConnection          patchCord76(LFO_Filter, 0, filter1, 1);
AudioConnection          patchCord77(filter2, 0, mixer2, 0);
AudioConnection          patchCord78(filter2, 1, mixer2, 1);
AudioConnection          patchCord79(filter2, 2, mixer2, 2);
AudioConnection          patchCord80(filter4, 0, mixer4, 0);
AudioConnection          patchCord81(filter4, 1, mixer4, 1);
AudioConnection          patchCord82(filter4, 2, mixer4, 2);
AudioConnection          patchCord83(filter7, 0, mixer7, 0);
AudioConnection          patchCord84(filter7, 1, mixer7, 1);
AudioConnection          patchCord85(filter7, 2, mixer7, 2);
AudioConnection          patchCord86(filter1, 0, mixer1, 0);
AudioConnection          patchCord87(filter1, 1, mixer1, 1);
AudioConnection          patchCord88(filter1, 2, mixer1, 2);
AudioConnection          patchCord89(filter3, 0, mixer3, 0);
AudioConnection          patchCord90(filter3, 1, mixer3, 1);
AudioConnection          patchCord91(filter3, 2, mixer3, 2);
AudioConnection          patchCord92(filter8, 0, mixer8, 0);
AudioConnection          patchCord93(filter8, 1, mixer8, 1);
AudioConnection          patchCord94(filter8, 2, mixer8, 2);
AudioConnection          patchCord95(filter5, 0, mixer5, 0);
AudioConnection          patchCord96(filter5, 1, mixer5, 1);
AudioConnection          patchCord97(filter5, 2, mixer5, 2);
AudioConnection          patchCord98(filter6, 0, mixer6, 0);
AudioConnection          patchCord99(filter6, 1, mixer6, 1);
AudioConnection          patchCord100(filter6, 2, mixer6, 2);
AudioConnection          patchCord101(mixer1, envelope1);
AudioConnection          patchCord102(mixer1, 0, envmixer1, 2);
AudioConnection          patchCord103(mixer2, envelope2);
AudioConnection          patchCord104(mixer2, 0, envmixer1, 3);
AudioConnection          patchCord105(mixer3, envelope3);
AudioConnection          patchCord106(mixer3, 0, envmixer2, 2);
AudioConnection          patchCord107(mixer4, envelope4);
AudioConnection          patchCord108(mixer4, 0, envmixer2, 3);
AudioConnection          patchCord109(mixer5, envelope5);
AudioConnection          patchCord110(mixer5, 0, envmixer3, 2);
AudioConnection          patchCord111(mixer6, envelope6);
AudioConnection          patchCord112(mixer6, 0, envmixer3, 3);
AudioConnection          patchCord113(mixer7, envelope7);
AudioConnection          patchCord114(mixer7, 0, envmixer4, 2);
AudioConnection          patchCord115(mixer8, envelope8);
AudioConnection          patchCord116(mixer8, 0, envmixer4, 3);
AudioConnection          patchCord117(envelope5, 0, envmixer3, 0);
AudioConnection          patchCord118(envelope3, 0, envmixer2, 0);
AudioConnection          patchCord119(envelope4, 0, envmixer2, 1);
AudioConnection          patchCord120(envelope6, 0, envmixer3, 1);
AudioConnection          patchCord121(envelope1, 0, envmixer1, 0);
AudioConnection          patchCord122(envelope8, 0, envmixer4, 1);
AudioConnection          patchCord123(envelope2, 0, envmixer1, 1);
AudioConnection          patchCord124(envelope7, 0, envmixer4, 0);
AudioConnection          patchCord125(envmixer1, 0, mixerL, 0);
AudioConnection          patchCord126(envmixer1, 0, mixerR, 0);
AudioConnection          patchCord127(envmixer2, 0, mixerL, 1);
AudioConnection          patchCord128(envmixer2, 0, mixerR, 1);
AudioConnection          patchCord129(envmixer3, 0, mixerL, 2);
AudioConnection          patchCord130(envmixer3, 0, mixerR, 2);
AudioConnection          patchCord131(envmixer4, 0, mixerL, 3);
AudioConnection          patchCord132(envmixer4, 0, mixerR, 3);
AudioConnection          patchCord133(mixerL, flangerL);
AudioConnection          patchCord134(mixerR, flangerR);
AudioConnection          patchCord135(flangerR, chorusR);
AudioConnection          patchCord136(flangerL, chorusL);
AudioConnection          patchCord137(chorusL, 0, i2s1, 0);
AudioConnection          patchCord138(chorusR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=943.5,228.49998998641968
// GUItool: end automatically generated code


#endif
