//////////////////////////////////////////////////////////////////////
// MIDI handlers
//////////////////////////////////////////////////////////////////////
#include "global_variables.h"

Oscillator* OnNoteOffReal(uint8_t channel, uint8_t note, uint8_t velocity, bool ignoreSustain) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return 0;

#if 0 //#ifdef SYNTH_DEBUG
  SYNTH_SERIAL.println("NoteOff");
#endif
  int8_t lastNote = notesDel(notesPressed,note);
  
  if (sustainPressed && !ignoreSustain) return 0;

  Oscillator *o=oscs;
  if (portamentoOn) {
    if (o->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,note);
        if (portamentoTime == 0) {
          portamentoPos = lastNote;
          portamentoDir = 0;
        } else {
          portamentoDir = lastNote > portamentoPos? 1 : -1;
          portamentoStep = fabs(lastNote-portamentoPos)/(portamentoTime);
        }
        oscOn(*o, lastNote, velocity);
      }
      else 
      {
        oscOff(*o);
        portamentoPos = -1;
        portamentoDir = 0;
      }
    }
    if (oscs->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,o->note);
        oscOn(*o, lastNote, velocity);
      } else {
        oscOff(*o);
      }
    }
  }
  else if (polyOn) {
    Oscillator *end=oscs+NVOICES;
    do {
      if (o->note == note) break;
    } while (++o < end);
    if (o == end) return 0;
    oscOff(*o);
  } else {
    if (oscs->note == note) {
      if (lastNote != -1) {
        notesDel(notesOn,o->note);
        oscOn(*o, lastNote, velocity);
      } else {
        oscOff(*o);
      }
    }
  }
  
  return o;
}

void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 1
  SYNTH_SERIAL.println("NoteOn");
#endif

  notesAdd(notesPressed,note);

  Oscillator *o=oscs;
  if (portamentoOn) {
    if (portamentoTime == 0 || portamentoPos < 0) {
      portamentoPos = note;
      portamentoDir = 0;
    } else if (portamentoPos > -1) {
      portamentoDir  = note > portamentoPos ? 1 : -1;
      portamentoStep = fabs(note-portamentoPos)/(portamentoTime);
    }
    *notesOn = -1;
    oscOn(*o, note, velocity);
  }
  else if (polyOn) {
    Oscillator *curOsc=0, *end=oscs+NVOICES;
    if (sustainPressed && notesFind(notesOn,note)) {
      do {
        if (o->note == note) {
          curOsc = o;
          break;
        }
      } while (++o < end);
    }
    for (o=oscs; o < end && !curOsc; ++o) {
      if (o->note < 0) {
        curOsc = o;
        break;
      }
    }
    if (!curOsc && *notesOn != -1) {
#if SYNTH_DEBUG > 0
      SYNTH_SERIAL.println("Stealing voice");
#endif
      curOsc = OnNoteOffReal(channel,*notesOn,velocity,true);
    }
    if (!curOsc) return;
    oscOn(*curOsc, note, velocity);
  }
  else 
  {
    *notesOn = -1;
    oscOn(*o, note, velocity);
  }

  return;
}

inline void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  OnNoteOffReal(channel,note,velocity,false);
}

void OnAfterTouchPoly(uint8_t channel, uint8_t note, uint8_t value) {
#if SYNTH_DEBUG > 0
  SYNTH_SERIAL.print("AfterTouchPoly: channel ");
  SYNTH_SERIAL.print(channel);
  SYNTH_SERIAL.print(", note ");
  SYNTH_SERIAL.print(note);
  SYNTH_SERIAL.print(", value ");
  SYNTH_SERIAL.println(value);
#endif
}

/////////////////////////////////// SYNTH MASTER CONTROL ///////////////////////////////////////////////////////////////////////////////////////////


void OnControlChange(uint8_t channel, uint8_t control, uint8_t value) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;

  switch (control) {

    
//////////////////////// WAVEFORM SECTION /////////////////////////////////////////////////////////////////

  case CC_Waveform1: // Waveform OSC1
    if (value <= 32) currentProgram1 = 0;
    else if (value > 32 && value <= 64) currentProgram1 = 1;
    else if (value > 64 && value <= 96) currentProgram1 = 2;
    else if (value > 96 && value <= 127) currentProgram1 = 3;
    updateWaveform1();
    
    #if SYNTH_DEBUG > 1
    SYNTH_SERIAL.print("Waveform 1 change: channel ");
    SYNTH_SERIAL.print(channel);
    SYNTH_SERIAL.print(", program ");
    SYNTH_SERIAL.println((String) progs[currentProgram1]);
    #endif
    break;
    
  case CC_Octave1: // Octave OSC 1
        switch (value) {
        case 0:
          octave1 = -24; // Pot min value = 2 octaves down
          break;
        case 4:
          octave1 = 24; // Pot max value = 2 octaves up
          break;
        default:
          octave1=map(value, 0, 127, -12, 12); // Map any value between the 2 octaves -12 to 12
          break;
      }
  case CC_PWM1: // Pulse Width Ammount OSC 1
    pwmmixer1.gain(0,value/127.);
    break;
  
  case CC_Waveform2: // Waveform OSC2
    if (value <= 32) currentProgram2 = 0;
    else if (value > 32 && value <= 64) currentProgram2 = 1;
    else if (value > 64 && value <= 96) currentProgram2 = 2;
    else if (value > 96 && value <= 127) currentProgram2 = 3;
    updateWaveform2();
    
    #if SYNTH_DEBUG > 1
      SYNTH_SERIAL.print("Waveform 2 change: channel ");
      SYNTH_SERIAL.print(channel);
      SYNTH_SERIAL.print(", program ");
      SYNTH_SERIAL.println((String) progs[currentProgram2]);
    #endif
    break;
    
  case CC_Octave2: // Octave OSC2
        switch (value) {
        case 0:
          octave2 = -24; // Pot min value = 2 octaves down
          break;
        case 4:
          octave2 = 24; // Pot max value = 2 octaves up
          break;
        default:
          octave2=map(value, 0, 127, -12, 12); // Map any value between the 2 octaves -12 to 12
          break;
      }
      
  case CC_PWM2: // Pulse Width OSC2
    pwmmixer2.gain(0,value/127.);
    break;

//////////////////////// LFO 1: Pitch /////////////////////////////////////////////////////////////////
    case CC_LFO_Level1: // LFO1 level 
      LFO1_Level = map(value, 0, 127, 1, 100); // Level 0 - 100
      updateLFO1();
      break;
    case CC_LFO_Waveform1: // LFO2 waveform
      if (value <= 32) currentLFOProgram1 = 0;
      else if (value > 32 && value <= 64) currentLFOProgram1 = 1;
      else if (value > 64 && value <= 96) currentLFOProgram1 = 2;
      else if (value > 96 && value <= 127) currentLFOProgram1 = 3;
      updateLFO1();
      break;
    case CC_LFO_Rate1: // LFO1 Rate
      LFO1_Rate = map(value, 0, 127, 1, 30); // Rate 1 - 30 Hz
      updateLFO1();
      break;
      
//////////////////// LFO 2: Filter ///////////////////////////////////////////

    case CC_LFO_Level2: // LFO2 Level 
      LFO2_Level = map(value, 0, 127, 1, 100); // Level 0 - 100
      updateLFO2();
      break;
      
    case CC_LFO_Waveform2: // LFO2 Waveform
      if (value <= 32) currentLFOProgram2 = 0;
      else if (value > 32 && value <= 64) currentLFOProgram2 = 1;
      else if (value > 64 && value <= 96) currentLFOProgram2 = 2;
      else if (value > 96 && value <= 127)currentLFOProgram2 = 3;
      updateLFO2();
      break;  
      
    case CC_LFO_Rate2: // LFO2 Rate
      LFO2_Rate = map(value, 0, 127, 1, 30); // Rate 1 - 30 Hz
      updateLFO2();
      break;

/////////////// MASTER ////////////////////////////////////////////

  case CC_Portamento: // portamento time
  {
    if (value > 63) {
      portamentoOn = true;
      float portamentoRange = portamentoStep*portamentoTime;
      portamentoTime = value*50;
      portamentoStep = portamentoRange/portamentoTime;
      if (oscs->note != -1) portamentoPos = oscs->note;
      portamentoOn = false;
    }
    else portamentoOn = false;
    break;
  }
  case CC_Volume: // volume
    channelVolume = value/127.;
    updateVolume();
    break;
  case CC_Pan: // PAN
    panorama = value/127;
    updatePan();
    break;
   
  case CC_Chorus:
    switch(value) {
      case 0:
        nvoices=0;
        break;
      default:
        nvoices= map(value, 0, 127, 1, 10);
        break;
    }
/*
  case 9: // fix volume
    switch (value) {
    case 0:
      velocityOn = false;
      break;
    case 1:
      velocityOn = true;
      break;
    default:
      velocityOn = !velocityOn;
      break;
    }
    break;
    */
  case CC_Noise: // Pink White Noise
    noise = value/127.;
    updateNoise();
    break;

//////////////// ENVELOPE ADSR/////////////////////////////////////////
  case CC_Attack: // attack
    envAttack = value*envelopeMax/127.;
    updateEnvelope();
    break;
  case CC_Decay: // decay
    envDecay = value*envelopeMax/127.;
    updateEnvelope();
    break;
  case CC_Sustain: // sustain
    envSustain = value/127.;
    updateEnvelope();
    break;
  case CC_Release: // release
    envRelease = value*envelopeMax/127.;
    updateEnvelope();
    break;
    
//////////////// FILTER ///////////////////////////////////////////
  case CC_Filter_Frequency: // filter frequency
    filtFreq = value/2.5*AUDIO_SAMPLE_RATE_EXACT/127.;
    updateFilter();
    break;
  case CC_Filter_Resonance: // filter resonance
    filtReso = value*4.1/127.+0.9;
    updateFilter();
    break;
  case CC_Filter_Attenuation: // filter attenuation
    filtAtt = value/127.;
    updateFilterMode();
    break;
  case CC_Filter_Mode: // filter mode
    if (value < FILTERMODE_N) {
      filterMode = FilterMode_t(value);
    } else {
      filterMode = FilterMode_t((filterMode+1)%FILTERMODE_N);
    }
    updateFilterMode();
    break;
////////////////////////////////////////////////////////////////////////////
  case CC_PWM_Rate:
    LFO_PWM_Freq=map(value, 0, 127, 20, 1000);
    updatePWM();
    break;
  case CC_Envelope_Mode: // envelope mode
    allOff();
    envOn = !envOn;
    updateEnvelopeMode();
    break;
////////////// FLANGER ////////////////////////////////////////////////////////////////

  case CC_Flanger_On: // flanger toggle
    if (value > 63)
        flangerOn = 3;
    else
        flangerOn = !flangerOn;
    updateFlanger();
    break;
  case CC_Flanger_Offset: // flanger offset
    flangerOffset = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case CC_Flanger_Depth: // flanger depth
    flangerDepth = int(value/127.*8)*DELAY_LENGTH/8;
    updateFlanger();
    break;
  case CC_Flanger_Fine: // flanger coarse frequency
    flangerFreqCoarse = value/127.*10.;
    updateFlanger();
    break;
    
///////////// UNDEFINED ////////////////////////////////////////////////////////////////////
  case CC_Oscmix:
    currentLevel1=value/127.;
    currentLevel2=1-value;
    updateVolume();
    break;  
/*
  case CC_Poly_Mode: // poly mode
    switch (value) {
    case 0:
      polyOn = true;
      portamentoOn = false;
      break;
    case 1:
      polyOn = false;
      portamentoOn = false;
      break;
    case 2:
      polyOn = false;
      portamentoOn = true;
      break;
    default: // cycle POLY, MONO, PORTAMENTO
    {
      bool tmp = polyOn;
      polyOn = portamentoOn;
      portamentoOn = !(tmp || portamentoOn);
      break;
    }
    }
    updatePolyMode();
    break;
  
  case CC_Pitch_Range: // pitch range in semitones
    pitchScale = 12./value;
    break;
*/
  case CC_Sustain_Pedal: // sustain/damper pedal
    if (value > 63) sustainPressed = true;
    else {
      sustainPressed = false;
      Oscillator *o=oscs, *end=oscs+NVOICES;
      do {
        if (o->note != -1 && !notesFind(notesPressed,o->note)) oscOff(*o);
      } while (++o < end);
    }
    break;
    
  case 84: // portamento control (start note)
    portamentoPos = value;
    break;
  case 121: // controller reset
    resetAll();
    break;
  case 123: // all notes off
    allOff();
    break;
  case 124: // omni off
    allOff();
    omniOn = false;
    break;
  case 125: // omni on
    allOff();
    omniOn = true;
    break;
  case 126: // mono
    polyOn = false;
    portamentoOn = false;
    updatePolyMode();
    break;
  case 127: // poly
    polyOn = true;
    portamentoOn = false;
    updatePolyMode();
    break;
  default:
#if SYNTH_DEBUG > 0
    SYNTH_SERIAL.print("Unhandled Control Change: channel ");
    SYNTH_SERIAL.print(channel);
    SYNTH_SERIAL.print(", control ");
    SYNTH_SERIAL.print(control);
    SYNTH_SERIAL.print(", value ");
    SYNTH_SERIAL.println(value);
#endif
    break;
  }    
#if 1 //0
  SYNTH_SERIAL.print("Control Change: channel ");
  SYNTH_SERIAL.print(channel);
  SYNTH_SERIAL.print(", control ");
  SYNTH_SERIAL.print(control);
  SYNTH_SERIAL.print(", value ");
  SYNTH_SERIAL.println(value);
#endif
}

////////////////////////////////// END CONTROL CHANGE ///////////////////////////////////////////////////

void OnPitchChange(uint8_t channel, int pitch) {
  if (!omniOn && channel != SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 1
  SYNTH_SERIAL.print("PitchChange: channel ");
  SYNTH_SERIAL.print(channel);
  SYNTH_SERIAL.print(", pitch ");
  SYNTH_SERIAL.println(pitch);
#endif

#ifdef USB_MIDI
  if (pitch == 8192)
    pitchBend = 0;
  else
    pitchBend = (pitch-8192)/8192.;
#else  
  pitchBend = pitch/8192.;
#endif
  
  updatePitch();
}

//////////////////////////////////////////// A F T E R T O U C H ////////////////////

void OnAfterTouch(uint8_t channel, uint8_t pressure) {
  if (!omniOn && channel!=SYNTH_MIDICHANNEL) return;

#if SYNTH_DEBUG > 0
  SYNTH_SERIAL.print("AfterTouch: channel ");
  SYNTH_SERIAL.print(channel);
  SYNTH_SERIAL.print(", pressure ");
  SYNTH_SERIAL.println(pressure);
#endif
}

void OnSysEx( const uint8_t *data, uint16_t length, bool complete) {
#if SYNTH_DEBUG > 0
  SYNTH_SERIAL.print("SysEx: length ");
  SYNTH_SERIAL.print(length);
  SYNTH_SERIAL.print(", complete ");
  SYNTH_SERIAL.println(complete);
#endif
}

void OnRealTimeSystem(uint8_t realtimebyte) {
#if SYNTH_DEBUG > 0
  SYNTH_SERIAL.print("RealTimeSystem: ");
  SYNTH_SERIAL.println(realtimebyte);
#endif
}

void OnTimeCodeQFrame(uint16_t data)
{
#if SYNTH_DEBUG > 0
  SYNTH_SERIAL.print("TimeCodeQuarterFrame: ");
  SYNTH_SERIAL.println(data);
#endif
}
