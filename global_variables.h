// Global variables
//////////////////////////////////////////////////////////////////////

// set SYNTH_DEBUG to enable debug logging (1=most,2=all messages)
#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

//CC Controls///////////////////////////////

// OSC1
#define CC_Waveform1 0 // CC code for WF1
#define CC_Octave1 1 // CC code for WF1
#define CC_PWM1 2 // CC code for WF1

// OSC2
#define CC_Waveform2 3 // CC code for WF1
#define CC_Octave2 4 // CC code for WF1
#define CC_PWM2 5 // CC code for WF1

// LFO1
#define CC_LFO_Level1 6// LFO2 level
#define CC_LFO_Waveform1 7 // LFO2 waveform
#define CC_LFO_Rate1 8 // LFO1 frequency

// LFO2
#define CC_LFO_Level2 9// LFO2 level
#define CC_LFO_Waveform2 10 // LFO2 waveform
#define CC_LFO_Rate2 11 // LFO2 frequency

// Master
#define CC_Volume 12 // Master Volume
#define CC_Pan 13 // Pan
#define CC_Portamento 14 // Glide
#define CC_Chorus 15 // Chorus

//Envelope
#define CC_Attack 16 // Attack
#define CC_Release 17 // // Release
#define CC_Decay 18 // Decay
#define CC_Sustain 19 // Sustain

//Filter
#define CC_Filter_Frequency 20 // CC code for volume
#define CC_Filter_Resonance 21// CC code for volume
#define CC_Filter_Attenuation 22 // CC code for volume
#define CC_Filter_Mode 23

// Flanger
#define CC_Flanger_On 24
#define CC_Flanger_Offset 25
#define CC_Flanger_Depth 26
#define CC_Flanger_Fine 27

// Misc
#define CC_PWM_Rate 28 // Pulse Width Modulation rate
#define CC_Noise 29 // White Noise - No Noise - Pink Noise
#define CC_Detune 30 // OSC 2 detune
#define CC_Oscmix 31 // OSC 1 - BALANCED - OSC 2

//MIDI
#define CC_Sustain_Pedal 64//
#define CC_Envelope_Mode 65 //

// Mux Controls
#define MnumControls 8 // Number of possible MUX controls per MUX (8 for CD4051)

#define MS0 9  // 1st bit (1)
#define MS1 10 // 2nd bit (2)
#define MS2 11 // 3rd bit (4)

#define MXIN 14 // Input MUX
#define MXIN2 15 // Input MUX
#define MXIN3 16 // Input MUX
#define MXIN4 17 // Input MUX

////////////////////////////////////////////////////////////

#define SYNTH_DEBUG 1
// define MIDI channel
#define SYNTH_MIDICHANNEL 1
// define tuning of A4 in Hz
#define SYNTH_TUNING 440
// gain at oscillator/filter input stage (1:1)
// keep low so filter does not saturate with resonance
#define GAIN_OSC 0.25
// gain in final mixer stage for polyphonic mode (4:1)
// (0.25 is the safe value but larger sounds better :) )
//#define GAIN_POLY 1.
#define GAIN_POLY 0.25
// gain in final mixer stage for monophonic modes
// define delay lines for modulation effects

#define DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
short delaylineL[DELAY_LENGTH];
short delaylineR[DELAY_LENGTH];


// audio memory
#define AMEMORY 100

#include <MIDI.h>

// switch between USB and UART MIDI
#ifdef USB_MIDI
#define SYNTH_SERIAL Serial1
#else // 'real' MIDI via UART
#define SYNTH_SERIAL Serial
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
#endif

float   masterVolume   = 1;

// Waveforms
uint8_t currentProgram1 = WAVEFORM_TRIANGLE; // OSC1 waveform
uint8_t currentProgram2 = WAVEFORM_SINE; // OSC2 waveform
int octave1; // OSC1 octave
int octave2; // OSC2 octave
float currentLevel1; //AMplitude OSC 1
float currentLevel2; // Amplitude OSC 2

//Bools
bool  polyOn;
bool  omniOn;
bool  velocityOn;
bool  sustainPressed;

float channelVolume;

// Panorama
float panorama;
float right; //right channel
float left; // left channel

//Pulse Width
float pulseWidth1; // 0.05-0.95
float pulseWidth2; // 0.05-0.95

// LFO
uint8_t currentLFOProgram1 = WAVEFORM_SQUARE;
uint8_t currentLFOProgram2 = WAVEFORM_TRIANGLE;
float LFO1_Level;
float LFO2_Level;
float LFO1_Rate;
float LFO2_Rate;

float LFO_PWM_Freq;

float pitchBend;  // -1/+1 oct
float pitchScale;
int octCorr;
int octCorr1;
int octCorr2;
float detune;

// filter
int filtermode;
float filtFreq; // 20-AUDIO_SAMPLE_RATE_EXACT/2.5
float filtReso; // 0.9-5.0
float filtAtt;  // 0-1

// envelope
const int envelopeMax = 500; //Ceiling for envelope
bool  envOn;
float envDecay;   // 0-envelopeMax
float envAttack;  // 0-envelopeMax
float envSustain; // 0-1
float envRelease; // 0-envelopeMax

// Flanger
bool  flangerOn;
int   flangerOffset;
int   flangerDepth;
float flangerFreqCoarse;
float flangerFreqFine;

// portamento
bool     portamentoOn;
uint16_t portamentoTime;
int8_t   portamentoDir;
float    portamentoStep;
float    portamentoPos;

// Master
int nvoices;
float noise;
#endif  /* GLOBALVARIABLES_H */
