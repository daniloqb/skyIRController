/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */



#include <IRremote.h>

IRsend irsend;

unsigned int command_size;


unsigned int  sky_power[19] = {5850,1200, 1150,1150, 600,600, 600,550, 600,1200, 550,600, 600,550, 600,1200, 600,1150, 600};  // UNKNOWN A80E7E5E
unsigned int  sky_telatv[19] = {5800,1250, 1150,1200, 550,650, 500,1250, 1100,1250, 500,650, 1150,1200, 1100,650, 550,1200, 550};  // UNKNOWN 39767224

unsigned int  sky_play[19] = {5800,1250, 1100,1250, 500,650, 550,600, 1150,1200, 550,650, 550,600, 1150,1200, 1150,1200, 550};  // UNKNOWN 9A6F0576
unsigned int  sky_stop[19] = {5800,1250, 1150,1200, 550,650, 550,600, 1150,1200, 550,650, 500,1250, 550,600, 550,650, 500};  // UNKNOWN FBAD8623
unsigned int  sky_crw[19] = {5800,1250, 1150,1200, 550,650, 500,650, 1100,1250, 550,1200, 1150,650, 500,1200, 550,650, 550};  // UNKNOWN 21FEFDF9
unsigned int  sky_cff[19] = {5800,1250, 1150,1200, 550,650, 500,650, 1100,1250, 550,1200, 1100,1250, 550,1200, 550,1200, 550};  // UNKNOWN 9D71047C
unsigned int  sky_rw[19] = {5800,1200, 1150,1200, 550,650, 550,650, 1100,1200, 550,650, 1100,1250, 500,650, 1150,650, 500};  // UNKNOWN E6D07133
unsigned int  sky_ff[19] = {5800,1250, 1150,1200, 550,650, 500,650, 1100,1250, 550,1200, 550,650, 500,650, 1100,650, 550};  // UNKNOWN 9B72C267
unsigned int  sky_pause[21] = {1900,100, 3750,1250, 1100,1250, 550,600, 550,650, 1100,1250, 550,650, 1050,700, 500,650, 500,1250, 550};  // UNKNOWN F476B46
unsigned int  sky_rec[19] = {5800,1250, 1100,1250, 500,700, 500,650, 1100,1250, 550,1200, 550,1200, 550,600, 1150,1200, 550};  // UNKNOWN 81A840E6


unsigned int  sky_guia[19] = {5800,1250, 1100,1250, 500,650, 550,650, 1100,700, 1050,700, 500,650, 500,650, 550,650, 500};  // UNKNOWN 427EBE9F
unsigned int  sky_central[19] = {5800,1250, 1100,1250, 550,600, 550,650, 1100,650, 1100,650, 550,1200, 550,650, 500,1250, 550};  // UNKNOWN 9D65B0BC
unsigned int  sky_lista[19] = {5800,1250, 1100,1250, 500,650, 550,650, 1100,650, 1100,650, 1100,650, 550,650, 1100,650, 550};  // UNKNOWN AB4D94A9
unsigned int  sky_sair[19] = {5750,1250, 1150,1200, 550,650, 500,650, 1100,650, 550,1200, 1150,650, 1100,1200, 1150,1200, 550};  // UNKNOWN 34498102
unsigned int  sky_return[19] = {5800,1250, 1100,1250, 550,600, 550,650, 1100,650, 550,1200, 1150,1200, 550,650, 500,650, 550};  // UNKNOWN BB9BDEE7
unsigned int  sky_menu[19] = {5800,1250, 1100,1250, 500,650, 550,650, 1100,650, 500,650, 550,650, 1100,650, 1100,650, 550};  // UNKNOWN 76CF1379
unsigned int  sky_info[19] = {5800,1250, 1100,1250, 500,650, 550,600, 1150,650, 1100,1250, 1100,650, 550,1200, 550,1200, 550};  // UNKNOWN F640360

unsigned int  sky_confirma[19] = {5750,1300, 1100,1200, 550,650, 500,700, 1050,700, 500,1250, 550,1200, 1100,1250, 1100,650, 550};  // UNKNOWN 75A956A7
unsigned int  sky_up[19] = {5800,1250, 1100,1250, 550,600, 600,650, 1050,700, 500,650, 500,1250, 1100,700, 1050,1250, 500};  // UNKNOWN F24119FE
unsigned int  sky_down[19] = {5750,1250, 1100,1250, 550,650, 500,700, 1100,650, 500,650, 1100,650, 1100,1250, 500,700, 500};  // UNKNOWN B489062B
unsigned int  sky_left[19] = {5800,1250, 1100,1250, 550,600, 550,650, 1100,650, 500,650, 1100,1250, 1100,1250, 550,1200, 550};  // UNKNOWN C53794B4
unsigned int  sky_right[19] = {5750,1300, 1100,1200, 550,650, 500,700, 1050,700, 500,1200, 600,650, 1050,1250, 550,1200, 550};  // UNKNOWN BC9DF06


unsigned int  sky_red[19] = {5800,1200, 1150,1200, 600,600, 550,1200, 550,650, 500,650, 550,1200, 1100,650, 550,650, 500};  // UNKNOWN C332FABB
unsigned int  sky_green[19] = {5800,1250, 1100,1250, 550,600, 550,1200, 550,650, 550,650, 1100,1200, 1150,650, 1100,650, 500};  // UNKNOWN 8C0B38A3
unsigned int  sky_yellow[19] = {5800,1250, 1100,1250, 500,650, 550,1200, 550,650, 550,600, 1150,600, 1150,600, 550,1250, 500};  // UNKNOWN 2591C110
unsigned int  sky_blue[19] = {5800,1200, 1150,1200, 550,700, 500,1200, 550,600, 600,1200, 500,700, 1100,650, 1100,650, 550};  // UNKNOWN 506AE98B


unsigned int  sky_chup[19] = {5750,1250, 1100,1250, 500,700, 500,650, 500,650, 1100,1250, 500,1250, 1100,650, 1150,650, 500};  // UNKNOWN 165412B7
unsigned int  sky_chdown[19] = {5800,1250, 1100,1200, 550,650, 500,650, 550,650, 1100,1250, 1100,650, 1100,650, 1100,1250, 500};  // UNKNOWN 5815B090
unsigned int  sky_chreturn[19] = {5800,1300, 1050,1250, 500,650, 550,650, 500,650, 1100,1250, 1100,1250, 1100,1250, 500,700, 500};  // UNKNOWN 5BFBFDE9




unsigned int  num0[19] = {5800,1250, 1100,1200, 550,650, 550,600, 550,1250, 500,650, 550,1200, 550,1200, 1150,650, 500};  // UNKNOWN F32F72D7

unsigned int  num1[19] = {5800,1250, 1100,1250, 500,650, 550,650, 500,650, 550,650, 500,1250, 500,650, 550,1200, 550};  // UNKNOWN C9767F76
unsigned int  num2[19] =  {5800,1200, 1150,1200, 600,600, 550,650, 550,600, 550,650, 1100,650, 500,650, 1100,650, 550};  // UNKNOWN C8155AB1
unsigned int  num3[19] = {5800,1250, 1100,1250, 550,650, 500,650, 550,600, 550,600, 1150,1250, 500,650, 1100,1250, 550};  // UNKNOWN B6996DAE
unsigned int  num4[19] = {5850,1200, 1150,1200, 550,650, 500,650, 550,600, 550,1250, 550,650, 500,600, 1150,1200, 550};  // UNKNOWN 969AE844
unsigned int  num5[19] = {5800,1250, 1100,1200, 550,650, 550,650, 500,650, 500,1250, 550,1200, 550,1200, 550,650, 500};  // UNKNOWN 4AAFAC67
unsigned int  num6[19] = {5850,1200, 1100,1250, 550,600, 550,650, 550,600, 550,1250, 1100,650, 550,1200, 550,1200, 550};  // UNKNOWN 9C2A936C
unsigned int  num7[19] = {5800,1250, 1100,1250, 500,650, 550,650, 500,650, 550,1250, 1050,1250, 550,1200, 1100,700, 500};  // UNKNOWN 833ED333
unsigned int  num8[19] = {5800,1250, 1150,1200, 550,650, 500,700, 500,650, 1100,650, 500,650, 550,1200, 1150,650, 500};  // UNKNOWN 55F2B93
unsigned int  num9[19] = {5750,1250, 1150,1200, 550,650, 500,700, 500,650, 1100,650, 550,1200, 550,1200, 1150,1200, 550};  // UNKNOWN DE78B0D0
unsigned int  numd[19] = {5750,1250, 1150,1200, 550,650, 500,650, 550,1200, 550,650, 1100,650, 550,1200, 1150,1200, 550};  // UNKNOWN BDE97C12
unsigned int  nume[19] = {5800,1250, 1100,1200, 550,650, 550,650, 500,1250, 500,650, 1150,1200, 1150,600, 550,650, 500};  // UNKNOWN 3F23F43








void setup()
{

Serial.begin(9600);
command_size = sizeof(sky_power) / sizeof(sky_power[0]);

}

void loop() {
  int khz = 36; // 38kHz carrier frequency for the NEC protocol
  if(Serial.available()){
    
    char command = Serial.parseInt();

    switch(command){

      case 20:
       irsend.sendRaw(sky_power, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;      
      case 21:
       irsend.sendRaw(sky_telatv, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;          
           
      case 30:
       irsend.sendRaw(sky_play, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 31:
       irsend.sendRaw(sky_stop, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 32:
       irsend.sendRaw(sky_crw, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 33:
       irsend.sendRaw(sky_cff,command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 34:
       irsend.sendRaw(sky_rw,command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 35:
       irsend.sendRaw(sky_ff, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 36:
       irsend.sendRaw(sky_pause, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;            
      case 37:
       irsend.sendRaw(sky_rec, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 


      case 40:
       irsend.sendRaw(sky_guia, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 41:
       irsend.sendRaw(sky_central, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 42:
       irsend.sendRaw(sky_lista, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 43:
       irsend.sendRaw(sky_sair, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 44:
       irsend.sendRaw(sky_return, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 45:
       irsend.sendRaw(sky_menu, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 46:
       irsend.sendRaw(sky_info, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 

      case 50:
       irsend.sendRaw(sky_confirma, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 51:
       irsend.sendRaw(sky_up, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 52:
       irsend.sendRaw(sky_down, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 53:
       irsend.sendRaw(sky_left, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 54:
       irsend.sendRaw(sky_right, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
    
      
      case 60:
       irsend.sendRaw(sky_red, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 61:
       irsend.sendRaw(sky_green, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 62:
       irsend.sendRaw(sky_yellow, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 63:
       irsend.sendRaw(sky_blue, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 



      case 70:
       irsend.sendRaw(sky_chup, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 71:
       irsend.sendRaw(sky_chdown, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 
      case 72:
       irsend.sendRaw(sky_chreturn, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break; 


      

      case 0:
        irsend.sendRaw(num0, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;
      case 1:
        irsend.sendRaw(num1, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;
      case 2:
        irsend.sendRaw(num2, command_size, khz); //Note the approach used to automatically calculate the size of the array.
      break;
      case 3:
        irsend.sendRaw(num3, command_size, khz);
      break;
      case 4:
        irsend.sendRaw(num4,command_size, khz);
      break;
      case 5:
        irsend.sendRaw(num5, command_size, khz);
      break;
      case 6:
        irsend.sendRaw(num6, command_size, khz);
      break;
      case 7:
        irsend.sendRaw(num7, command_size, khz);
      break;
      case 8:
        irsend.sendRaw(num8, command_size, khz);
      break;
      case 9:
        irsend.sendRaw(num9, command_size, khz);
      break;
      case 10:
        irsend.sendRaw(numd, command_size, khz);
      break;
      case 11:
        irsend.sendRaw(nume, command_size, khz);
      break;
    }
    delay(40); //In this example, the signal will be repeated every 5 seconds, approximately.
        
    
    }

  /*
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  delay(40); //In this example, the signal will be repeated every 5 seconds, approximately.
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  delay(40); //In this example, the signal will be repeated every 5 seconds, approximately.  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  delay(40); //In this example, the signal will be repeated every 5 seconds, approximately.
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  delay(15000); //In this example, the signal will be repeated every 5 seconds, approximately.


  */
  
}
