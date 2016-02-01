#Padawan Astromech Control System by danf

**Revisions**
- 01/30/16 - danf posted on Astromech new sketch to support WTV020-SD-16P
- 08/12/14- Added loop counter to detect controller, helps with some controllers that have trouble connecting. (Thank you Joymonkey for that)
- 01/01/14- New Bar Graph display for Cantina song, new Short Circuit display, (thank you Marc for those) visual display for speed change, adjustable logic display brightness, can select flipped bottom logic display, now works correctly with Sparkfun Pro Micro.
- 12/14/13- Fixed auto hp in T-3 sketch, easier to change hp servo pin numbers.
- 12/02/13- Corrected a buffer overrun issue(thank you Marc), corrected padawan_control_system.JPG
- 11/11/13- Added more safety features, Multiple Speed Selection, Heart display for Wolf Whistle

**Update Posted 01/30/16**

Has the sketch (Padawan_Body_wtv020_WIP5), library (WtvPadawan), some pics (support files) and a list of pins (Arduino Pins.txt) used
Don't try to power the Sound modules with the Arduino, it wont have enough power. Use a separate voltage regulator.
Some modules and/or sd cards need a little more than 3.3v to work. If you use an adjustable regulator like one of these from eBay you can start at 3.3v and try slightly higher voltages if its not working.

This sketch is also compatible with JoyMonkey's Padawan Universal Shield which has space for 2 modules and a different voltage regulator.

> **Please Note:** Several of the arduino pins have changed from the original sketch as was necessary to work with JoyMonkey's Padawan Universal Shield. If using this sketch refer to the Arduino pins txt doc to see where to connect the Syren, Sabertooth, and Dome signal to!!

The shield isn't necessary, but is very cool. Whether you use one or not , use the new pin connections or edit the sketch to use whatever pins you want.

With this sketch you can use 1 or 2 of the cheap modules or a mp3 trigger or one of each. If using 2 R1 and up or down arrows are sound volume and R1 and left and right are music volume. Pressing all 4 triggers (L1,L2,R1,R2) stops all sounds and music. L1 and pressing the left joystick turns on jukebox. It will play songs in a random order. As is, it uses the 4 starwars tunes allready on there but you could add as much music as you want and have it use those.
If anyone try it let me know how it goes.

**Original danf ReadMe.txt below (Oct 13, 2014)**

Included are 3 versions of the body code and 2 of the dome.

**Padawan_Body_MM_DD_YY**
- Uses Serial Connections to A Sabertooth Speed Controller for the feet.
- SyRen Speed Controller for the dome
- This will probably be the preferred metheod for most cases.
- Sabertooth DIP Switches Set- 1 and 2 Down 3,4,5,and 6 Up
- SyRen DIP Switches Packetized (preferred)- Set- 1 and 2 Down 3,4,5,and 6 Up
- Simple(see below)-Set- 2 and 4 Down 1,3,5,and 6 Up
- This has been tested with a Sabertooth 2x25 ver.1 and ver. 2, and a SyRen 10. 
- A Sabertooth 2x25 ver.1  MIGHT need the baud rate changed.

**A1Body_R2_1_4**
- Uses a Serial Connection to A Sabertooth Speed Controller. 
- Senna style, servo & bump switches dome controller.
- DIP Switches Set- 1 and 2 Down 3,4,5,and 6 Up

**A1Body_R2_1_2** 
- Uses Servo Pulses to controll Speed Controller.
- Used with 2x12 RC or other brand Speed Controllers

**Padawan_Dome_T2_MM_DD_YY**
- Uses Teeces V2 Logics  Hooked Up- FDL Top, FDL Bottom, RLD and Seperate PSI Displays

**Padawan_Dome_T_3_MM_DD_YY**
- Uses Teeces V3 logics In the Common 2 Chain Config.

**Syren Notes:**
Packetized is the best choice for the Syren, but you might need to change the baud rate.
If have an older Syren and you can't get packetized to work, (and some people have had problems) you will have 2 options

**OPTION 1** - simplified serial- easy to setup, proven to work, 
          BUT a chance that the dome could start spinning if power is lost to the arduino but not the syren. 
          While I haven't seen this happen without physically yanking the power wire or pressing the reset button the risk is there. 
          I would say now that we know of this possibility, do not use this option if people, 
          especially children, will be close enough to the droid to be injured.

**OPTION 2** - send the syren to DM to be flashed- This is the better option as it allows you to use packetized without any problems.

Some changes were made to some of the libraries used to make them work with Arduino 1.0, unfortunatly, some of my code didn't work with these changes.

I also had to update some libraries to make them Arduino 1.0 compatable.

I have tested each of these updated sketches with the enclosed libraries and have included the libraries just in case future updates effect the sketches.

I recommend trying the example sketch included with the ps2 library to be sure the ps2 conroller is working properly.

A trouble shooting guide for the ps2 library is avalible at:
http://www.billporter.info/arduino-playstation-2-controller-library-troubleshooting-guide/

**If everything is hooked up properly:**

**Start button** - enable/disable foot motors
**left joystick** - left/right-dome motor
**pushbutton** - holo light
**right joystck** - drive motors
**d-pad** - if right trigger1 held down- volume controll, else holo movement
**green, red, blue, pink** - random sounds or hold one of the triggers for specific sounds or songs


**Materials List:**

**Body:**
- Aruino or compatable
- Sabertooth 2x25  (dip settings- 1 & 5 down)
- Sparkfun MP3 Trigger (Make sure the little switch on the mp3 trigger is set to usb.)
- ps2 controller (I use a Mad Catz 2.4GHz mini wireless, great range)
- Connector (cut off an old extension cable or avalible here- http://www.lynxmotion.com/p-73-ps2-controller-cable.aspx
- Dome Motor Controller (I used to use the Senna type servo & bump switches, now I use the SyRen10)
- 1/4" stereo phono jack & socket (sends 12v +&- and signal to dome)

**Dome:**
- Aruino or compatable
- Logic Displays (I use Teeces Ver.2 But should work with Ver.3)
- PSI's (I use 1 each color led's from Superbright LEDs, should be easy to code for Teeces)
- LED Light in Holo
- 2 Servos for Holo

**This program is free software:** you can redistribute it and/or modify it. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Feel free to p.m. me if you have any questions

danf
