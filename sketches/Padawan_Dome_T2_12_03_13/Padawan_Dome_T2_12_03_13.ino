// =======================================================================================
// /////////////////////////Padawan Dome Code v1.4///////////////////////////////////////
// =======================================================================================
//                                 danf
//                        Revised  Date: 12/03/13
//   Designed to be used with a second Arduino running the Padawan Body code
//
//  This program is free software: you can redistribute it and/or modify it .
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
#include <LedControl.h>
#include <EasyTransfer.h>
#include <Servo.h>

EasyTransfer ET;//create object
struct RECEIVE_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int hpx; // hp movement
  int hpy; // hp movement
  int hpl; // hp light
  int hpa; // hp automation
  int dsp; // 0 = random, 1 = alarm, 5 = leia, 11 = alarm2
};

RECEIVE_DATA_STRUCTURE domeData;//give a name to the group of data

int cA[] = { B00000110,
            B00001001,
            B00001111,
            B00001001,
            B00001001 };
           
int cB[] = { B00000111,
            B00001001,
            B00000111,
            B00001001,
            B00000111 };

int cC[] = { B00000110,
            B00001001,
            B00000001,
            B00001001,
            B00000110 };

int cD[] = { B0000111,
            B0001001,
            B0001001,
            B0001001,
            B0000111 };

int cE[] = { B00001111,
            B00000001,
            B00000111,
            B00000001,
            B00001111 };
            
int cF[] = { B00001111,
            B00000001,
            B00000111,
            B00000001,
            B00000001 };
            
int cG[] = { B00001110,
            B00000001,
            B00001101,
            B00001001,
            B00000110 };
            
int cH[] = { B00001001,
            B00001001,
            B00001111,
            B00001001,
            B00001001 };
            
int cI[] = { B00000111,
            B00000010,
            B00000010,
            B00000010,
            B00000111 };
            
int cJ[] = { B00001000,
            B00001000,
            B00001000,
            B00001001,
            B00000110 };
            
int cK[] = { B00001001,
            B00000101,
            B00000011,
            B00000101,
            B00001001 };
            
int cL[] = { B00000001,
            B00000001,
            B00000001,
            B00000001,
            B00001111 };
            
int cM[] = { B00010001,
            B00011011,
            B00010101,
            B00010001,
            B00010001 };
            
int cN[] = { B00001001,
            B00001011,
            B00001101,
            B00001001,
            B00001001 };
            
int cO[] = { B00000110,
            B00001001,
            B00001001,
            B00001001,
            B00000110 };
            
int cP[] = { B00000111,
             B00001001,
             B00000111,
             B00000001,
             B00000001 };
            
int cQ[] = { B00000110,
            B00001001,
            B00001101,
            B00001001,
            B00010110 };
            
int cR[] = { B00000111,
            B00001001,
            B00000111,
            B00000101,
            B00001001 };
            
int cS[] = { B00001110,
             B00000001,
             B00000110,
             B00001000,
             B00000111 };
int cT[] = { B00001111,
             B00000110,
             B00000110,
             B00000110,
             B00000110 };
int cU[] = { B00001001,
             B00001001,
             B00001001,
             B00001001,
             B00000110 };
int cV[] = { B00001001,
             B00001001,
             B00001001,
             B00000110,
             B00000110 };
int cW[] = { B00010001,
             B00010001,
             B00010101,
             B00011011,
             B00010001 };
int cX[] = { B00001001,
             B00001001,
             B00000110,
             B00001001,
             B00001001 };
int cY[] = { B00001001,
             B00001001,
             B00000110,
             B00000110,
             B00000110 };
int cZ[] = { B00001111,
             B00000100,
             B00000010,
             B00000001,
             B00001111 };
int c0[] = { B00000110,
             B00001101,
             B00001011,
             B00001011,
             B00000110 };
//Non-letters
int c1[] = { B00000110,
             B00000101,
             B00000100,
             B00000100,
             B00011111 };
int c2[] = { B00001110,
             B00010001,
             B00000100,
             B00000010,
             B00011111 };  
int c3[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };  
int c4[] = { B00001001,
             B00001001,
             B00001111,
             B00001000,
             B00011100 };  
int c5[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };  
int c6[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };  
int c7[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };  
int c8[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };      
int c9[] = { B00001100,
             B00010100,
             B00000100,
             B00000100,
             B00011111 };  
// Heart Symbol    
int ch[] = { B00110110,
             B01001001,
             B01000001,
             B00100010,
             B00001000 };
// Tie Fighter Symbol    
int ct[] = { B00100010,
             B00101010,
             B00110110,
             B00101010,
             B00100010 }; 
// R2D2 Symbol    
int cr[] = { B00001110,
             B00011011,
             B00011111,
             B00010101,
             B00010001 } ; 
// dash - Symbol    
int cd[] = { B00000000,
             B00000000,
             B00001110,
             B00000000,
             B00000000 };
// Film Bar Symbol for use with Leia message
int cf[] = { B00000100,
             B00000100,
             B00000100,
             B00000100,
             B00000100 };

//Blank Symbol
int cb[] = { B00000000,
             B00000000,
             B00000000,
             B00000000,
             B00000000 };  

//upSymbol
int cu[] = { B00000001,
             B00000010,
             B00000100,
             B00001000,
             B00010000 }; 

//down Symbol
int cn[] = { B00010000,
             B00001000,
             B00000100,
             B00000010,
             B00000001 }; 


LedControl lc=LedControl(12,11,10,5);

int scrollPositions[]={9,9,27};
long previousMillis[3];
long randomSpeed = 150;
long scrollSpeed = 48;
long scrollCount[4];
int timer = scrollCount[2];
long flick = 100;
long twitch = 2500;
unsigned long HpMillis = 0;
Servo HPXservo;
Servo HPYservo;
const int redPin =  6;      // the number of the Psi LED pin
const int bluePin =  8;
const int yelPin =  9;     
const int grnPin =  5;
const int hpPin =  3;
// Variables will change:
int redState = LOW;
int blueState = HIGH;// ledState used to set the LED
long psiMillis = 0;        // will store last time LED was updated
long psiTime = random(1,7);
int displayMode = 0; // 0=random, 5=leia,
int a = 0;
int b = 0;
//virtual coords are 5x27; device coords are 3 panels 6x8 each
unsigned long v_grid[3][5]; //this will give 5x32 bits
int posY = 90;
int posX = 90;
int hpY = 0;
int hpX = 0;
///////////setup run once//////////////////////////////////////////////////////

void setup() 
{
  HPYservo.attach(A4);
  HPXservo.attach(A5);
    Serial.begin(57600);//start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
   ET.begin(details(domeData), &Serial);
  
   pinMode(redPin, OUTPUT);// set the digital pin as output:
   pinMode(bluePin, OUTPUT);
   pinMode(yelPin, OUTPUT);
   pinMode(grnPin, OUTPUT);
   pinMode(hpPin, OUTPUT);
   randomSeed(analogRead(0));

  for(byte dev=0;dev<lc.getDeviceCount();dev++)
  {
    lc.shutdown(dev, false); //take the device out of shutdown (power save) mode
    lc.setIntensity(dev, 10);
    lc.setIntensity(0, 1);
    lc.setIntensity(1, 1); //intensity is 1-15
    lc.clearDisplay(dev);
  }
  
}
//////////////Loop run over and over//////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void loop() 
{ 
 ///start random psi blink 
   randomPsi();
 ///startup display  
  if (scrollCount[0]<1)
  {
    scrollingText(0, "PADAWAN         "); //top front text
  }
  if (scrollCount[1]<1)
  {
    scrollingText(1, "         VER 1-4");//bottom front text
  }
  if (scrollCount[2]<1)
    {
    scrollingText(2, "ARTOO DETOO  ");//rear text
    return;
  }
  
  //check for new data from body
  if(ET.receiveData())
  {
    hpY=domeData.hpy;// hp servo up/down
    hpX=domeData.hpx;// hp servo left/right
    if (domeData.dsp != 100)
    {
    displayMode = domeData.dsp;// logic display
    timer = scrollCount[2];
    }
    if (displayMode != 5)//if not in leia display
    {
      if (domeData.hpl==1)
      {digitalWrite(hpPin, HIGH);//turn on hp light
      }
      else
      {
      digitalWrite(hpPin, LOW);//turn off hp light
      }
    }
  }
  
  ///display
  if (displayMode == 5)
  {
    leiaDisplay();
    flicker();
  }
  else if (displayMode == 11)
  {
    alarm2Display(175000);
  }
  else if (displayMode == 1)
  {
    alarmDisplay();
  }
  else if (displayMode == 4)
  {
    
    if (scrollCount[2]==timer)
    {
     scrollingText(0,"*");
     scrollingText(1,"*");
     scrollingText(2,"* * * *");
    }
    else (displayMode = 0);
  }
  
   else if (displayMode == 21)
  {
    
    if (scrollCount[2]==timer)
    {
     scrollingText(0," SPEED ");
     scrollingText(1,"  1  1  ");
     scrollingText(2,"SPEED 1");
    }
    else (displayMode = 0);
  }
  
  else if (displayMode == 22)
  {
    
    if (scrollCount[2]==timer)
    {
     scrollingText(0," SPEED ");
     scrollingText(1,"  2  2  ");
     scrollingText(2,"SPEED 2");
    }
    else (displayMode = 0);
  }
  
  else if (displayMode == 23)
  {
    
    if (scrollCount[2]==timer)
    {
     scrollingText(0,"SPEED ");
     scrollingText(1,"  3  3  ");
     scrollingText(2,"SPEED 3  ");
    }
    else (displayMode = 0);
  }
  else
  {
  randomDisplay();
  }
 
  ////hp movement
  if (hpY>posY)// down
  {
    unsigned long currentMillis = millis();
   if (currentMillis - HpMillis > 3)                                 
    { HPYservo.write(posY);               
    HpMillis = currentMillis;
     posY += 1;
    if(posY>= 150) {hpY=1;} // 150 and 30-- adjust these to your application 
  }} 
     if (hpY<posY&&hpY>10)  // up
  {                                
   unsigned long currentMillis = millis();
   if (currentMillis - HpMillis > 3)                                 
    { HPYservo.write(posY);               
    HpMillis = currentMillis;
     posY-=1;     
     if(posY<=30) {hpY=0;} // 150 and 30-- adjust these to your application
  }} 
  
  if (hpX>posX)// right
  {                                   
    unsigned long currentMillis = millis();
   if (currentMillis - HpMillis > 3)                                 
    { HPXservo.write(posX);               
    HpMillis = currentMillis;               
     posX += 1;
    if(posX>= 150) {hpX=1;} // 150 and 30-- adjust these to your application 
  }} 
     if (hpX<posX&&hpX>10)  // left
  {                               
   unsigned long currentMillis = millis();
   if (currentMillis - HpMillis > 3)                                 
    { HPXservo.write(posX);               
    HpMillis = currentMillis;
     posX-=1;     
    if(posX<=30) {hpX=0;} // 150 and 30-- adjust these to your application
  }}
 if (domeData.hpa==0)
  {autoHP();}
}  

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
void showGrid(byte display)
{
  byte minDev, maxDev;
  displayHelper(display, minDev, maxDev);
  //copy from virt coords to device coords
  unsigned char col8=0;
  unsigned char col17=0;
  unsigned char col26=0;
  for (byte row=0; row<5; row++)
  {
    int loops = 0;
  	for (byte dev=minDev; dev < maxDev; dev++){
  		lc.setRow(dev, row, rev(  (v_grid[display][row] & 255L<<(9*loops)) >> (9*loops)    )   );
  		loops++;
  	}   
     if ( (v_grid[display][row] & 1L<<8) == 1L<<8)   col8 += 128>>row;
    if (display == 2){
    	if ( (v_grid[display][row] & 1L<<17) == 1L<<17) col17 += 128>>row;
    	if ( (v_grid[display][row] & 1L<<26) == 1L<<26) col26 += 128>>row;
	}
  }
  
 lc.setRow(minDev, 5, col8);
  if (display == 2){
  	lc.setRow((minDev+1), 5, col17);
  	lc.setRow((minDev+2), 5, col26);
  }
}
///////////////////////////////////////////////////////////////////////////////////////
unsigned char rev(unsigned char b)
{
  //reverse bits of a byte
  return (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
}
//////////////////////////////////////////////////////////////////////////////////////
void initGrid(byte display)
{
  for (byte row=0; row<5; row++) v_grid[display][row]=0L;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void drawLetter(byte display, char let, int shift)
{
  int *pLetter;
  switch (let)
  {
    case 'A': pLetter=cA; break;
    case 'B': pLetter=cB; break;
    case 'C': pLetter=cC; break;
    case 'D': pLetter=cD; break;
    case 'E': pLetter=cE; break;
    case 'F': pLetter=cF; break;
    case 'G': pLetter=cG; break;
    case 'H': pLetter=cH; break;
    case 'I': pLetter=cI; break;
    case 'J': pLetter=cJ; break;
    case 'K': pLetter=cK; break;
    case 'L': pLetter=cL; break;
    case 'M': pLetter=cM; break;
    case 'N': pLetter=cN; break;
    case 'O': pLetter=cO; break;
    case 'P': pLetter=cP; break;
    case 'Q': pLetter=cQ; break;
    case 'R': pLetter=cR; break;
    case 'S': pLetter=cS; break;
    case 'T': pLetter=cT; break;
    case 'U': pLetter=cU; break;
    case 'V': pLetter=cV; break;
    case 'W': pLetter=cW; break;
    case 'X': pLetter=cX; break;
    case 'Y': pLetter=cY; break;
    case 'Z': pLetter=cZ; break;
    //non-letters
    //numbers
    case '0': pLetter=c0; break;
    case '1': pLetter=c1; break;
    case '2': pLetter=c2; break;
    case '3': pLetter=c3; break;
    case '4': pLetter=c4; break;
    case '5': pLetter=c5; break;
    case '6': pLetter=c6; break;
    case '7': pLetter=c7; break;
    case '8': pLetter=c8; break;
    case '9': pLetter=c9; break;
    //special characters
    case '*': pLetter=ch; break;
    case '#': pLetter=ct; break;
    case '@': pLetter=cr; break;
    case '-': pLetter=cd; break;
    case '|': pLetter=cf; break;
    //whitespace
    case ' ': pLetter=cb; break;
    case '<': pLetter=cu; break;
    case '>': pLetter=cn; break;
    default:return;
  }
  

  //loop thru rows of the letter
  for (byte i=0; i<5; i++) 
  {
    if (shift>0) //positive shift means letter is slid to the right on the display
      v_grid[display][i] += (long)pLetter[i] << shift;
    else //negative shift means letter is slid to the left so that only part of it is visible
      v_grid[display][i] += (long)pLetter[i] >> -shift;
  }

}
//////////////////////////////////////////////////////////////////////////////////////
void scrollingText(byte display, char text[])
{
  unsigned long currentMillis = millis();
 
  if((currentMillis - previousMillis[display]) >= scrollSpeed) 
  {   
  initGrid(display);
   previousMillis[display] = currentMillis;
     
  for (int i=0; i<strlen(text); i++)
  {
    drawLetter(display, text[i], i*5 + scrollPositions[display]);
  }
 
 scrollPositions[display]--;
  if (scrollPositions[display] < -5*(int)strlen(text))
  {
    if (display==2)
    {scrollPositions[display]=27;}
    else
    {scrollPositions[display]=9;}
   
    scrollCount[display]++;
   
  }
  }
  showGrid(display);
  
}
//////////////////////////////////////////////////////////////////////////////////////
void displayHelper(byte display, byte &counter, byte &limit){
	if (display == 0){
		counter = 0;
		limit = 1;
	}else if(display == 1){
		counter = 1;
		limit = 2;
	}else{
		counter = 2;
		limit = lc.getDeviceCount();
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void randomDisplay()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis[0] > randomSpeed) 
  {   
    previousMillis[0] = currentMillis;
  for (byte device=0; device<5; device++)
    //for (byte row=0; row<6; row++)
      lc.setRow(device,random (0,6),random(63,256));
  }
}
///////////////////////////////////////////////
void randomPsi()
{
  unsigned long currentMillis = millis();  
  if(currentMillis - psiMillis > psiTime*500) // delay between .5 to 3.5 seconds
  {   
    psiMillis = currentMillis;
    // if the psi is blue turn it red and vice-versa:
    if (redState == LOW)
      {
        redState = HIGH;
        blueState = LOW;
      }
    else
    {
      redState = LOW;
      blueState = HIGH;
    }// set the LED with the ledState of the variable:
    digitalWrite(redPin, redState);
    digitalWrite(bluePin, blueState);
    digitalWrite(yelPin, redState);
    digitalWrite(grnPin, blueState);
 psiTime = random(1,7);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////
void leiaDisplay()
{
  int devices=lc.getDeviceCount();
//unsigned long interval=600;
unsigned long currentMillis = millis();

if (scrollCount[3]==2200)
  
  {    
      for(int address=0;address<devices;address++) 
      {        
        lc.setRow(address,a,255);
        lc.setLed(address,5,a,true);
            
        lc.setRow(address,b,0);
        lc.setLed(address,5,b,false);
      } 
        b=a;
        a++;
        if (a>4)
        a=0;
        scrollCount[3]=0;
      }
else
{
   scrollCount[3]++;
}
      if(currentMillis - previousMillis[0] > 35000)
        {displayMode = 0;
         digitalWrite(hpPin, LOW);}
    
  }
 ///////////////////////////////////////////////////////////////////////////////////////////////////
void alarmDisplay()
{ 
  //read the number cascaded devices
  int devices=lc.getDeviceCount();
unsigned long delaytime=100;
unsigned long currentMillis = millis();
static unsigned long swtchMillis = millis();
 static byte swtch = 0;
 if (currentMillis - swtchMillis > delaytime)
 { 
  if (swtch == 0) 
   { //we have to init all devices in a loop
  for(int row=0;row<5;row++) {
    
      for(int address=0;address<devices;address++) {
        
        lc.setRow(address,row,255);
        lc.setLed(address,5,row,true);
      }}
      swtchMillis = millis();
       swtch = 1;}
       else  if (swtch == 1) 
   {
        for(int row=0;row<5;row++) {
    
      for(int address=0;address<devices;address++) {
       
        lc.setRow(address,row,0);
        lc.setLed(address,5,row,false);
      }}
      swtchMillis = millis();
      swtch = 0;}}
    if(currentMillis - previousMillis[0] > 2500)
        {displayMode = 0;}
  }
////////////////////////////////////////////////////////////////////////////////////////////////// 
void alarm2Display(long playTime)
{
  unsigned long delaytime=200;
 unsigned long currentMillis = millis();
 static unsigned long swtchMillis = millis();
 static byte swtch = 0;
 if (currentMillis - swtchMillis > delaytime)
 { 
  if (swtch == 0) 
   {//we have to init all devices in a loop
    for(int row=0;row<5;row++) {
        lc.setRow(0,row,15);
        lc.setRow(1,row,15);
        lc.setRow(3,row,15);
        lc.setRow(2,row,0);
        lc.setRow(4,row,255);
        lc.setLed(0,5,row,true);
        lc.setLed(1,5,row,true);
        lc.setLed(3,5,row,true);
        lc.setLed(4,5,row,true);
        lc.setLed(2,5,row,false);
        swtchMillis = millis();
        swtch = 1;
      }}
    else  if (swtch == 1) 
   {
        for(int row=0;row<5;row++) {
        lc.setRow(0,row,248);
        lc.setRow(1,row,248);
        lc.setRow(3,row,248);
        lc.setRow(2,row,255);
        lc.setRow(4,row,0);
        lc.setLed(0,5,row,false);
        lc.setLed(1,5,row,false);
        lc.setLed(3,5,row,false);
        lc.setLed(2,5,row,true);
        lc.setLed(4,5,row,false);
        swtchMillis = millis();
        swtch = 0;
      }}
   }
    if(currentMillis - previousMillis[0] > playTime)
        {displayMode = 0;}
  }
  ///////////////////////////////////////////////////////////////////
  void flicker()
  {
    unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis[1] > flick) {
    // save the last time you blinked the LED 
    previousMillis[1] = currentMillis;   

    analogWrite(hpPin, random(255));
   flick = random(100);
  }
  }
  ///////////////////////////////////////////////////////////////////
  void autoHP()
  {
    if (hpY!=150&&hpY!=30&&hpX!=150&&hpX!=30&&displayMode!=5)
  {  unsigned long currentMillis = millis();
   if (currentMillis - HpMillis > twitch)                                 
    {
     hpY=random(31,150);
     hpX=random(31,150);
     HpMillis = currentMillis;
     twitch = random(700,10500);
  }}}
