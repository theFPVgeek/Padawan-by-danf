/*
 WtvPadawan.h - Library to control a WTV020-SD-16P module to play voices from an Arduino board.
 Created by Diego J. Arevalo, August 6th, 2012.
 Released into the public domain.
 */

#ifndef WtvPadawan_h
#define WtvPadawan_h

class WtvPadawan
{
public:
  WtvPadawan(int clockPin,int dataPin,int busyPin);
  
  void playVoice(unsigned int voiceNumber);
  void asyncPlayVoice(unsigned int voiceNumber);
  void stopVoice();
  void pauseVoice();
  void mute();
  void unmute();
  void setVolume(unsigned int volume);

private:
  void sendCommand(unsigned int command);
  void delayMicros(unsigned long delayMicros);
  
  int _clockPin;
  int _dataPin;
  int _busyPin;
  int _busyPinState;
  unsigned int _currentVolume;
  unsigned long _lastMicros;
};

#endif


