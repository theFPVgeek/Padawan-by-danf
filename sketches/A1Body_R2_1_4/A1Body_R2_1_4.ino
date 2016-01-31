// =======================================================================================
// /////////////////////////Padawan Body Code v1.4///////////////////////////////////////
// =======================================================================================
//                                 danf
//                        Revised  Date: 03/09/13
//   Designed to be used with a second Arduino running the Padawan Dome code
//
//         Set Sabertooth 2x25 Dip Switches 1 and 2 Down, All Others Up
//
//  This program is free software: you can redistribute it and/or modify it .
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
//************************** Set speed and turn here************************************//

byte drivespeed = 100; // 0-stop, 127-full speed. 
                      //Recommend beginner: 50 to 75, experienced: 100 to 127, I like 100
byte turnspeed = 75;  // the higher this number the faster it will spin in place, lower - easier to controll. 
                      //Recommend beginner: 40 to 50, experienced: 50 $ up, I like 75
byte domespeed = 50;  //If using a speed controller for the dome, sets the top speed
                      //Use a number up to 90
                  
///////include libs and declare variables////////////////////////////
#include <Sabertooth.h>
#include <PS2X_lib.h>  //for v1.7
#include <Servo.h> 
#include <MP3Trigger.h>
 MP3Trigger trigger;
#include <SoftEasyTransfer.h>

//////////////////////////////////////////////////////////////////

/*   For Arduino 1.0 and newer, do this:   */
#include <SoftwareSerial.h>
SoftwareSerial domeSerial(A5, 8);
SoftwareSerial SWSerial(2, 7);
/*   For Arduino 22 and older, do this:   */
//#include <NewSoftSerial.h>
//NewSoftSerial domeSerial(A5, 8);//create software serial port

/////////////////////////////////////////////////////////////////
Sabertooth ST(128, SWSerial);

SoftEasyTransfer ET;//create object

struct SEND_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int hpx; // hp movement
  int hpy; // hp movement
  int hpl; // hp light
  int hpa; // hp automation
  int dsp; // 0 = random, 1 = alarm, 5 = leia, 11 = alarm2, 100 = no change
};

SEND_DATA_STRUCTURE domeData;//give a name to the group of data

PS2X ps2x; // create PS2 Controller Class
Servo RXservo; // right stick side to side
Servo RYservo; // right stick up & down
Servo LXservo; //left stick side to side
int error = 0; // part of the ps2x lib
byte type = 0; // part of the ps2x lib
byte vibrate = 0; // part of the ps2x lib
byte vol = 20; // 0 = full volume, 255 off 
byte drive = 0; // 0 = drive motors off ( right stick disabled )

//////////////set up run once//////////////////////////////////////////

void setup(){
  LXservo.attach(5);
  LXservo.write(90);
   SWSerial.begin(9600); // 9600 is the default baud rate for Sabertooth packet serial.
  ST.autobaud(); // Send the autobaud command to the Sabertooth controller(s).
                 // NOTE: *Not all* Sabertooth controllers need this command.
                 //       It doesn't hurt anything, but V2 controllers use an
                 //       EEPROM setting (changeable with the function setBaudRate) to set
                 //       the baud rate instead of detecting with autobaud.
                 //
                 //       If you have a 2x12, 2x25 V2, 2x60 or SyRen 50, you can remove
                 //       the autobaud line and save yourself two seconds of startup delay.
             
  ST.drive(0); // The Sabertooth won't act on mixed mode packet serial commands until
  ST.turn(0);  // it has received power levels for BOTH throttle and turning, since it
               // mixes the two together to get diff-drive power levels for both motors.
 trigger.setup();
 
 error = ps2x.config_gamepad(13,11,10,12, true, false);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 trigger.setVolume(vol);//anything with trigger. is for the mp3trigger
 type = ps2x.readType();
 domeSerial.begin(57600);//start the library, pass in the data details and the name of the serial port.
 ET.begin(details(domeData), &domeSerial); 
 
 }
 
 ///////Loop run over and over//////////////////////////////////////
 //////////////////////////////////////////////////////////////////

void loop(){
    
 if(error == 1) //skip loop if no controller found
  return; 
  
  ps2x.read_gamepad();   //read controller and set large motor to spin at 'vibrate' speed
 
 //// enable / disable right stick & play sound 
 if(ps2x.ButtonPressed(PSB_START)) 
{if (drive<1)
    {drive = 1; trigger.play(52);}
 else {drive = 0; trigger.play(53);}
}

////volume controll
 if(ps2x.Button(PSB_PAD_UP)) 
 {
  if(ps2x.Button(PSB_R1))
   { if (vol>0)
   {vol--;
   trigger.setVolume(vol);}// volume up
   }  
 }
  if(ps2x.Button(PSB_PAD_DOWN)) 
  {
  if(ps2x.Button(PSB_R1))
   { if (vol<255)
   {vol++;
   trigger.setVolume(vol);}//volume down
   } 
 }
 
 /////hp movement
if(ps2x.ButtonPressed(PSB_PAD_UP))
{if (!(ps2x.Button(PSB_R1)))
 {
   domeData.hpy = 30; domeData.dsp = 100; ET.sendData();
 }}
 if(ps2x.ButtonPressed(PSB_PAD_DOWN))
{if (!(ps2x.Button(PSB_R1)))
 {
   domeData.hpy = 150; domeData.dsp = 100; ET.sendData();
 }}
 if(ps2x.ButtonReleased(PSB_PAD_UP)||ps2x.ButtonReleased(PSB_PAD_DOWN))
 {domeData.hpy = 0; domeData.dsp = 100; ET.sendData();}
  
 if(ps2x.ButtonPressed(PSB_PAD_RIGHT))
 {
   domeData.hpx = 150; domeData.dsp = 100; ET.sendData();
 }
 if(ps2x.ButtonPressed(PSB_PAD_LEFT))
 {
   domeData.hpx = 30; domeData.dsp = 100; ET.sendData();
 }
 if(ps2x.ButtonReleased(PSB_PAD_RIGHT)||ps2x.ButtonReleased(PSB_PAD_LEFT))
 {domeData.hpx = 0; domeData.dsp = 100; ET.sendData();}
 
 
 /////play sounds and change display
  if(ps2x.ButtonPressed(PSB_GREEN))//triangle top
   {if(ps2x.Button(PSB_L1))
      {(trigger.play(8)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_L2))
      {(trigger.play(2)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_R1))
      {(trigger.play(9)); domeData.dsp = 0; ET.sendData();}
     else 
      {(trigger.play(random(13,17))); domeData.dsp = 0; ET.sendData();}}
  if(ps2x.ButtonPressed(PSB_BLUE))//x bottom
   {if(ps2x.Button(PSB_L1))
      {(trigger.play(6)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_L2))
      {(trigger.play(1)); domeData.dsp = 1; ET.sendData(); domeData.dsp = 0;}
    else if(ps2x.Button(PSB_R1))
      {(trigger.play(11)); domeData.dsp = 11; ET.sendData(); domeData.dsp = 0;}
     else 
      {(trigger.play(random(17,25))); domeData.dsp = 0; ET.sendData();}}
  if(ps2x.ButtonPressed(PSB_RED))//circle right
   {if(ps2x.Button(PSB_L1))
      {(trigger.play(7)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_L2))
      {(trigger.play(3)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_R1))
      {(trigger.play(10)); domeData.dsp = 0; ET.sendData();}
     else 
      {(trigger.play(random(32,52))); domeData.dsp = 0; ET.sendData();}}
  if(ps2x.ButtonPressed(PSB_PINK))//square left
   {if(ps2x.Button(PSB_L1))
      {(trigger.play(5)); domeData.dsp = 5; ET.sendData(); domeData.dsp = 0;}
    else if(ps2x.Button(PSB_L2))
      {(trigger.play(4)); domeData.dsp = 0; ET.sendData();}
    else if(ps2x.Button(PSB_R1))
      {(trigger.play(12)); domeData.dsp = 0; ET.sendData();}
     else 
      {(trigger.play(random(25,32))); domeData.dsp = 0; ET.sendData();}}
   
 ////turn hp light on & off      
  if(ps2x.ButtonPressed(PSB_L3)) //left joystick
  {
    if(domeData.hpl == 1)
    {domeData.hpl = 0; domeData.dsp = 100; ET.sendData();}//if hp light is on, turn it off
    else
    {domeData.hpl = 1; domeData.dsp = 100; ET.sendData();}//turn hp light on
  }   
  
 /////foot drives      
  if (drive == 1)// right stick (drive)
{  
  ST.turn(map(ps2x.Analog(PSS_RX), 0, 255, -turnspeed, turnspeed));
  ST.drive(map(ps2x.Analog(PSS_RY), 0, 255, -drivespeed, drivespeed));
}

/////dome drive
   int val=constrain(ps2x.Analog(PSS_LX), 0, 255);
  val=(map(val, 0, 255, (90-domespeed), (90+domespeed))); // left stick (dome)
  if (val <92 && val >89){val =90;}
  LXservo.write(val);
 delay(50);
}
/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
