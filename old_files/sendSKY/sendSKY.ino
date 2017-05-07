#include <IRremote.h>


unsigned short SKY_NUM0     = 0xc116;
unsigned short SKY_NUM1     = 0xc011;
unsigned short SKY_NUM2     = 0xc022;
unsigned short SKY_NUM3     = 0xc033;
unsigned short SKY_NUM4     = 0xc043;
unsigned short SKY_NUM5     = 0xc054;
unsigned short SKY_NUM6     = 0xc065;
unsigned short SKY_NUM7     = 0xc076;
unsigned short SKY_NUM8     = 0xc086;
unsigned short SKY_NUM9     = 0xc097;
unsigned short SKY_NUMD     = 0xc127;
unsigned short SKY_NUME     = 0xc138;

unsigned short SKY_POWER    = 0xc105;
unsigned short SKY_SCRTV    = 0xc739;

unsigned short SKY_PLAY     = 0xc30f;
unsigned short SKY_STOP     = 0xc310;
unsigned short SKY_PAUSE    = 0xc321;
unsigned short SKY_RW       = 0xc332;
unsigned short SKY_FF       = 0xc342;
unsigned short SKY_REC      = 0xc353;
unsigned short SKY_CRW      = 0xc364;
unsigned short SKY_CFF      = 0xc375;

unsigned short SKY_GUIDE    = 0xc280;
unsigned short SKY_CENTRAL  = 0xc291;
unsigned short SKY_LIST     = 0xc2a2;
unsigned short SKY_EXIT     = 0xc26f;
unsigned short SKY_RETURN   = 0xc270;
unsigned short SKY_MENU     = 0xc20a;
unsigned short SKY_INFO     = 0xc2e5;

unsigned short SKY_CONFIRM  = 0xc25e;
unsigned short SKY_UP       = 0xc21b;
unsigned short SKY_DOWN     = 0xc22c;
unsigned short SKY_LEFT     = 0xc23d;
unsigned short SKY_RIGHT    = 0xc24d;

unsigned short SKY_RED      = 0xc418;
unsigned short SKY_GREEN    = 0xc43a;
unsigned short SKY_YELLOW   = 0xc429;
unsigned short SKY_BLUE     = 0xc44a;

unsigned short SKY_CHUP     = 0xc0da;
unsigned short SKY_CHDOWN   = 0xc0eb;
unsigned short SKY_CHRETURN = 0xc0fc;



unsigned int  aoc_power[67] = {8750,4450, 550,600, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,600, 500,1650, 550,1650, 550,1650, 500,1700, 500,600, 500,1650, 550,1650, 550,600, 450,650, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,1650, 550,1650, 550,1650, 550,1650, 500,1700, 500,1700, 500};  // UNKNOWN 4D39D97
unsigned int  aoc_volup[67] = {8750,4450, 550,550, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 450,650, 450,1700, 550,550, 500,1700, 550,1650, 550,1650, 550,1600, 600,550, 500,1650, 550,600, 450,600, 500,1700, 550,1650, 550,550, 500,600, 500,600, 500,600, 450,1700, 550,1650, 550,550, 500,600, 500,1700, 550,1650, 550,1600, 600,1600, 550};  // UNKNOWN 1136F43B
unsigned int  aoc_voldown[67] = {8750,4450, 550,550, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 450,650, 450,1700, 550,550, 500,1700, 500,1700, 500,1700, 500,1650, 550,600, 500,1650, 550,550, 500,600, 500,600, 500,600, 500,1700, 500,600, 500,600, 500,600, 500,1650, 550,1650, 550,1650, 500,1700, 500,600, 500,1700, 500,1650, 550,1650, 550};  // UNKNOWN BF677217
unsigned int  aoc_source[67] = {8750,4450, 550,600, 450,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,600, 500,1650, 550,600, 450,1700, 550,1650, 550,1650, 500,1700, 500,600, 500,1650, 550,600, 500,600, 450,650, 450,1700, 550,550, 500,600, 500,600, 500,600, 500,1700, 500,1650, 550,1650, 550,600, 450,1700, 550,1650, 500,1700, 500,1700, 500};  // UNKNOWN 6429B77
unsigned int  aoc_mute[67] = {8750,4450, 500,600, 500,600, 500,600, 550,650, 550,650, 550,650, 550,600, 500,600, 500,1700, 500,600, 500,1650, 500,1650, 550,1650, 550,1650, 550,550, 550,1650, 500,600, 500,600, 500,1650, 500,600, 500,600, 550,650, 500,600, 550,650, 550,1650, 550,1650, 500,600, 500,1700, 500,1650, 550,1650, 550,1650, 550,1700, 550};  // UNKNOWN CC047317





IRsend irsend;

int nbits = 16;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
void loop() {

if(Serial.available()){
    
    int command = Serial.parseInt();
    Serial.print("Command: ");
    Serial.println(command);

    switch(command){


      case 80:
        irsend.sendSKYhdtv(SKY_POWER,nbits);
        delay(40);
        irsend.sendRaw(aoc_power, sizeof(aoc_power) / sizeof(aoc_power[0]), 38);
 
       break;
       

      case 20:
        irsend.sendSKYhdtv(SKY_POWER,nbits);
      break;      
      case 21:
        irsend.sendSKYhdtv(SKY_SCRTV,nbits);      
      break;        break;  
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
       irsend.sendRaw(aoc_mute, sizeof(aoc_mute) / sizeof(aoc_mute[0]), 38);
      break;
      case 27:
        irsend.sendRaw(aoc_power, sizeof(aoc_power) / sizeof(aoc_power[0]), 38);
      break;


      case 30:
        irsend.sendSKYhdtv(SKY_PLAY,nbits); 
      break;            
      case 31:
        irsend.sendSKYhdtv(SKY_STOP,nbits);      
      break;            
      case 32:
        irsend.sendSKYhdtv(SKY_PAUSE,nbits);      
      break;            
      case 33:
        irsend.sendSKYhdtv(SKY_RW,nbits);      
      break;            
      case 34:
        irsend.sendSKYhdtv(SKY_FF,nbits);      
      break;            
      case 35:
        irsend.sendSKYhdtv(SKY_REC,nbits);      
       break;            
      case 36:
        irsend.sendSKYhdtv(SKY_CRW,nbits);      
       break;            
      case 37:
        irsend.sendSKYhdtv(SKY_CFF,nbits);      
      break; 
      

      case 40:
        irsend.sendSKYhdtv(SKY_GUIDE,nbits);      
      break; 
      case 41:
        irsend.sendSKYhdtv(SKY_CENTRAL,nbits);      
      break; 
      case 42:
        irsend.sendSKYhdtv(SKY_LIST,nbits);      
      break; 
      case 43:
        irsend.sendSKYhdtv(SKY_EXIT,nbits);      
      break; 
      case 44:
        irsend.sendSKYhdtv(SKY_RETURN,nbits);      
      break; 
      case 45:
        irsend.sendSKYhdtv(SKY_MENU,nbits);      
      break; 
      case 46:
        irsend.sendSKYhdtv(SKY_INFO,nbits);      
      break; 


      case 50:
        irsend.sendSKYhdtv(SKY_CONFIRM,nbits);      
      break; 
      case 51:
        irsend.sendSKYhdtv(SKY_UP,nbits);       
      break; 
      case 52:
        irsend.sendSKYhdtv(SKY_DOWN,nbits);            
      break; 
      case 53:
        irsend.sendSKYhdtv(SKY_LEFT,nbits);      
       break; 
      case 54:
        irsend.sendSKYhdtv(SKY_RIGHT,nbits);      
      break; 
   
      
      case 60:
        irsend.sendSKYhdtv(SKY_RED,nbits);      
      break; 
      case 61:
        irsend.sendSKYhdtv(SKY_GREEN,nbits);      
      break; 
      case 62:
        irsend.sendSKYhdtv(SKY_YELLOW,nbits);      
      break; 
      case 63:
        irsend.sendSKYhdtv(SKY_BLUE,nbits);      
      break; 

      case 70:
        irsend.sendSKYhdtv(SKY_CHUP,nbits);      
      break; 
      case 71:
        irsend.sendSKYhdtv(SKY_CHDOWN,nbits);      
      break; 
      case 72:
        irsend.sendSKYhdtv(SKY_CHRETURN,nbits);
      break; 
 

      case 0:
        irsend.sendSKYhdtv(SKY_NUM0,nbits);
      break;
      case 1:
        irsend.sendSKYhdtv(SKY_NUM1,nbits);
      break;
      case 2:
        irsend.sendSKYhdtv(SKY_NUM2,nbits);
      break;
      case 3:
        irsend.sendSKYhdtv(SKY_NUM3,nbits);
      break;
      case 4:
        irsend.sendSKYhdtv(SKY_NUM4,nbits);
      break;
      case 5:
        irsend.sendSKYhdtv(SKY_NUM5,nbits);
      break;
      case 6:
        irsend.sendSKYhdtv(SKY_NUM6,nbits);
      break;
      case 7:
        irsend.sendSKYhdtv(SKY_NUM7,nbits);
      break;
      case 8:
        irsend.sendSKYhdtv(SKY_NUM8,nbits);
      break;
      case 9:
        irsend.sendSKYhdtv(SKY_NUM9,nbits);
      break;
      case 10:
        irsend.sendSKYhdtv(SKY_NUMD,nbits);
      break;
      case 11:
        irsend.sendSKYhdtv(SKY_NUME,nbits);
      break;

        
    }
    delay(40); 
    
  }

  
}
