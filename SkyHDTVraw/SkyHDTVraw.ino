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


unsigned int  sky_power[11] =  {550,1200, 550,550, 550,550, 550,1200, 550,1200, 550};  // UNKNOWN A80E7E5E

unsigned int  sky_telatv[11] = {1200,1200, 550,550, 1200,1200, 1200,550, 550,1200, 550};  // UNKNOWN 39767224

unsigned int  sky_play[11] = {1200,1200, 550,550,  550,550,   1200,1200, 1200,1200, 550};  // UNKNOWN 9A6F0576
unsigned int  sky_stop[11] = {1200,1200, 550,550,  550,1200,  550,550,   550,550,   550};  // UNKNOWN FBAD8623
unsigned int  sky_crw[11] =  {1200,1200, 550,1200, 1200,550,  550,1200,  550,550,   550};  // UNKNOWN 21FEFDF9
unsigned int  sky_cff[11] =  {1200,1200, 550,1200, 1200,1200, 550,1200,  550,1200,  550};  // UNKNOWN 9D71047C
unsigned int  sky_rw[11] =   {1200,1200, 550,550,  1200,1200, 550,550,   1200,550,  550};  // UNKNOWN E6D07133
unsigned int  sky_ff[11] =   {1200,1200, 550,1200, 550,550,   550,550,   1200,550,  550};  // UNKNOWN 9B72C267
unsigned int  sky_pause[11] ={1200,1200, 550,550,  1200,550,  550,550,   550,1200,  550};  // UNKNOWN F476B46
unsigned int  sky_rec[11] =  {1200,1200, 550,1200, 550,1200,  550,550,   1200,1200, 550};  // UNKNOWN 81A840E6

unsigned int  sky_guia[11] =    {1200,550, 1200,550,  550,550,   550,550,   550,550,   550};  // UNKNOWN 427EBE9F
unsigned int  sky_central[11] = {1200,550, 1200,550,  550,1200,  550,550,   550,1200,  550};  // UNKNOWN 9D65B0BC
unsigned int  sky_lista[11] =   {1200,550, 1200,550,  1200,550,  550,550,   1200,550,  550};  // UNKNOWN AB4D94A9
unsigned int  sky_sair[11] =    {1200,550, 550,1200,  1200,550 , 1200,1200, 1200,1200, 550};  // UNKNOWN 34498102
unsigned int  sky_return[11] =  {1200,550, 550,1200,  1200,1200, 550,550,   550,550,   550};  // UNKNOWN BB9BDEE7
unsigned int  sky_menu[11] =    {1200,550, 550,550,   550,550,   1200,550,  1200,550,  550};  // UNKNOWN 76CF1379
unsigned int  sky_info[11] =    {1200,550, 1200,1200, 1200,550,  550,1200,  550,1200,  550};  // UNKNOWN F640360

unsigned int  sky_confirma[11] = {1200,550, 550,1200, 550,1200,  1200,1200, 1200,550,  550};  // UNKNOWN 75A956A7
unsigned int  sky_up[11] =       {1200,550, 550,550,  550,1200,  1200,550,  1200,1200, 550};  // UNKNOWN F24119FE
unsigned int  sky_down[11] =     {1200,550, 550,550,  1200,550,  1200,1200, 550,550,   550};  // UNKNOWN B489062B
unsigned int  sky_left[11] =     {1200,550, 550,550,  1200,1200, 1200,1200, 550,1200,  550};  // UNKNOWN C53794B4
unsigned int  sky_right[11] =    {1200,550, 550,1200, 550,550,   1200,1200, 550,1200,  550};  // UNKNOWN BC9DF06

unsigned int  sky_red[11] =    {550,550, 550,550,  550,1200,  1200,550, 550,550,  550};  // UNKNOWN C332FABB
unsigned int  sky_green[11] =  {550,550, 550,550,  1200,1200, 1200,550, 1200,550, 550};  // UNKNOWN 8C0B38A3
unsigned int  sky_yellow[11] = {550,550, 550,550,  1200,550,  1200,550, 550,1200, 550};  // UNKNOWN 2591C110
unsigned int  sky_blue[11] =   {550,550, 550,1200, 550,550,   1200,550, 1200,550, 550};  // UNKNOWN 506AE98B

unsigned int  sky_chup[11] =     {550,550, 1200,1200, 550,1200,  1200,550,  1200,550,  550};  // UNKNOWN 165412B7
unsigned int  sky_chdown[11] =   {550,550, 1200,1200, 1200,550,  1200,550,  1200,1200, 550};  // UNKNOWN 5815B090
unsigned int  sky_chreturn[11] = {550,550, 1200,1200, 1200,1200, 1200,1200, 550,550,   550};  // UNKNOWN 5BFBFDE9
 
unsigned int  num0[11] = {550,1200, 550,550,  550,1200,  550,1200, 1200,550,  550};  // UNKNOWN F32F72D7
unsigned int  num1[11] = {550,550,  550,550,  550,1200,  550,550,  550,1200,  550};  // UNKNOWN C9767F76
unsigned int  num2[11] = {550,550,  550,550,  1200,550,  550,550,  1200,550,  550};  // UNKNOWN C8155AB1
unsigned int  num3[11] = {550,550,  550,550,  1200,1200, 550,550,  1200,1200, 550};  // UNKNOWN B6996DAE
unsigned int  num4[11] = {550,550,  550,1200, 550,550,   550,550,  1200,1200, 550};  // UNKNOWN 969AE844
unsigned int  num5[11] = {550,550,  550,1200, 550,1200,  550,1200, 550,550,   550};  // UNKNOWN 4AAFAC67
unsigned int  num6[11] = {550,550,  550,1200, 1200,550,  550,1200, 550,1200,  550};  // UNKNOWN 9C2A936C
unsigned int  num7[11] = {550,550,  550,1200, 1200,1200, 550,1200, 1200,550,  550};  // UNKNOWN 833ED333
unsigned int  num8[11] = {550,550,  1200,550, 550,550,   550,1200, 1200,550,  550};  // UNKNOWN 55F2B93
unsigned int  num9[11] = {550,550,  1200,550, 550,1200,  550,1200, 1200,1200, 550};  // UNKNOWN DE78B0D0

unsigned int  numd[11] = {550,1200, 550,550, 1200,550, 550,1200, 1200,1200, 550};  // UNKNOWN BDE97C12
unsigned int  nume[11] = {550,1200, 550,550, 1200,1200, 1200,550, 550,550, 550};  // UNKNOWN 3F23F43


unsigned int  aoc_power[67] = {8750,4450, 550,600, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,600, 500,1650, 550,1650, 550,1650, 500,1700, 500,600, 500,1650, 550,1650, 550,600, 450,650, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,1650, 550,1650, 550,1650, 550,1650, 500,1700, 500,1700, 500};  // UNKNOWN 4D39D97
unsigned int  aoc_volup[67] = {8750,4450, 550,550, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 450,650, 450,1700, 550,550, 500,1700, 550,1650, 550,1650, 550,1600, 600,550, 500,1650, 550,600, 450,600, 500,1700, 550,1650, 550,550, 500,600, 500,600, 500,600, 450,1700, 550,1650, 550,550, 500,600, 500,1700, 550,1650, 550,1600, 600,1600, 550};  // UNKNOWN 1136F43B
unsigned int  aoc_voldown[67] = {8750,4450, 550,550, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 450,650, 450,1700, 550,550, 500,1700, 500,1700, 500,1700, 500,1650, 550,600, 500,1650, 550,550, 500,600, 500,600, 500,600, 500,1700, 500,600, 500,600, 500,600, 500,1650, 550,1650, 550,1650, 500,1700, 500,600, 500,1700, 500,1650, 550,1650, 550};  // UNKNOWN BF677217
unsigned int  aoc_source[67] = {8750,4450, 550,600, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,600, 450,1700, 550,1650, 550,1650, 500,1700, 500,600, 500,1650, 550,600, 500,600, 450,650, 450,1700, 550,550, 500,600, 500,600, 500,600, 500,1700, 500,1650, 550,1650, 550,600, 450,1700, 550,1650, 500,1700, 500,1700, 500};  // UNKNOWN 6429B77
unsigned int  aoc_mute[67] = {8800,4450, 500,600, 500,600, 500,600, 450,650, 450,650, 450,650, 450,600, 500,600, 500,1700, 500,600, 500,1700, 500,1650, 550,1650, 550,1650, 550,550, 500,1700, 500,600, 500,600, 500,1700, 500,600, 500,600, 450,650, 500,600, 450,650, 450,1700, 550,1650, 500,600, 500,1700, 500,1650, 550,1650, 550,1650, 500,1700, 550};  // UNKNOWN CC047317


unsigned int  headA[8] = {5800,1200, 1200,1200, 550,550, 550,550};

unsigned int codeA[19];

unsigned int  headB[8] = {5800,1200, 1200,1200, 550,550, 550,1200};

unsigned int codeB[19];


void setup()
{

Serial.begin(9600);

command_size = sizeof(sky_power) / sizeof(sky_power[0]);

for (int i=0;i<8;i++){
  codeA[i] = headA[i];
}

for (int i=0;i<8;i++){
  codeB[i] = headB[i];
}

}

void loop() {




  
  int khz = 36; // 38kHz carrier frequency for the NEC protocol
  if(Serial.available()){
    
    char command = Serial.parseInt();

    switch(command){


      case 80:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_power[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
        delay(40);
        irsend.sendRaw(aoc_power, sizeof(aoc_power) / sizeof(aoc_power[0]), 38);
      break;

      case 20:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_power[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;      
      case 21:
        for (int i=0;i<11;i++){ codeB[i+8] = sky_telatv[i]; }
        irsend.sendRaw(codeB, sizeof(codeB) / sizeof(codeB[0]), khz); 
      break;  
      case 23:
       irsend.sendRaw(aoc_volup, sizeof(aoc_volup) / sizeof(aoc_volup[0]), 38);
      break;  
      case 24:
       irsend.sendRaw(aoc_voldown, sizeof(aoc_voldown) / sizeof(aoc_voldown[0]), 38);
      break;
      case 25:
       irsend.sendRaw(aoc_source, sizeof(aoc_source) / sizeof(aoc_source[0]), 38);
      break;
      case 26:
      // irsend.sendRaw(aoc_mute, sizeof(aoc_mute) / sizeof(aoc_mute[0]), 38);
      break;
      case 27:
       irsend.sendRaw(aoc_power, sizeof(aoc_power) / sizeof(aoc_power[0]), 38);
      break;

      case 30:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_play[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;            
      case 31:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_stop[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;            
      case 32:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_crw[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;            
      case 33:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_cff[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break;            
      case 34:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_rw[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break;            
      case 35:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_ff[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break;            
      case 36:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_pause[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;            
      case 37:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_rec[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      

      case 40:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_guia[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 41:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_central[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 42:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_lista[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 43:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_sair[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 44:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_return[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 45:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_menu[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 46:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_info[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 


      case 50:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_confirma[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break; 
      case 51:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_up[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break; 
      case 52:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_down[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break; 
      case 53:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_left[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
        break; 
      case 54:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_right[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
        break; 
   
      
      case 60:
        for (int i=0;i<11;i++){ codeB[i+8] = sky_red[i]; }
        irsend.sendRaw(codeB, sizeof(codeB) / sizeof(codeB[0]), khz); 
       break; 
      case 61:
        for (int i=0;i<11;i++){ codeB[i+8] = sky_green[i]; }
        irsend.sendRaw(codeB, sizeof(codeB) / sizeof(codeB[0]), khz); 
       break; 
      case 62:
        for (int i=0;i<11;i++){ codeB[i+8] = sky_yellow[i]; }
        irsend.sendRaw(codeB, sizeof(codeB) / sizeof(codeB[0]), khz); 
      break; 
      case 63:
        for (int i=0;i<11;i++){ codeB[i+8] = sky_blue[i]; }
        irsend.sendRaw(codeB, sizeof(codeB) / sizeof(codeB[0]), khz); 
       break; 

      case 70:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_chup[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break; 
      case 71:
        for (int i=0;i<11;i++){ codeA[i+8] = sky_chdown[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break; 
      case 72:
         for (int i=0;i<11;i++){ codeA[i+8] = sky_chreturn[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
       break; 
 

      case 0:
        for (int i=0;i<11;i++){ codeA[i+8] = num0[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
      break;
      case 1:
        for (int i=0;i<11;i++){ codeA[i+8] = num1[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
        break;
      case 2:
        for (int i=0;i<11;i++){ codeA[i+8] = num2[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz); 
        break;
      case 3:
        for (int i=0;i<11;i++){ codeA[i+8] = num3[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
      break;
      case 4:
        for (int i=0;i<11;i++){ codeA[i+8] = num4[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
      break;
      case 5:
        for (int i=0;i<11;i++){ codeA[i+8] = num5[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
      break;
      case 6:
        for (int i=0;i<11;i++){ codeA[i+8] = num6[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
       break;
      case 7:
        for (int i=0;i<11;i++){ codeA[i+8] = num7[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
       break;
      case 8:
        for (int i=0;i<11;i++){ codeA[i+8] = num8[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
      break;
      case 9:
        for (int i=0;i<11;i++){ codeA[i+8] = num9[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
       break;
      case 10:
        for (int i=0;i<11;i++){ codeA[i+8] = numd[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
       break;
      case 11:
        for (int i=0;i<11;i++){ codeA[i+8] = nume[i]; }
        irsend.sendRaw(codeA, sizeof(codeA) / sizeof(codeA[0]), khz);
        break;

        
    }
    delay(40); 
    
    }

  
}
