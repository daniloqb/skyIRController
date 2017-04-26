#include "Arduino.h"
#include "SkyIRController.h"


#include <IRremote.h>




Sky::Sky(){
  
  nbits = 16;
  
  }



void Sky::send(const unsigned short code){
  
  irsend.sendSKYhdtv(code,nbits);

  
  }


void Sky::btn_num0(){
  send(SKY_NUM0);
  }
void Sky::btn_num1(){
  send(SKY_NUM1);
  }
void Sky::btn_num2(){
  send(SKY_NUM2);
  }
void Sky::btn_num3(){
  send(SKY_NUM3);
  }
void Sky::btn_num4(){
  send(SKY_NUM4);
  }
void Sky::btn_num5(){
  send(SKY_NUM5);
  }
void Sky::btn_num6(){
  send(SKY_NUM6);
  }
void Sky::btn_num7(){
  send(SKY_NUM7);
  }
void Sky::btn_num8(){
  send(SKY_NUM8);
  }
void Sky::btn_num9(){
  send(SKY_NUM9);
  }
void Sky::btn_numD(){
  send(SKY_NUMD);
  }
void Sky::btn_numE(){
  send(SKY_NUME);
  }




void Sky::btn_power(){
  send(SKY_POWER);
  }
void Sky::btn_scrtv(){
  send(SKY_SCRTV);
  }

void Sky::btn_play(){
  send(SKY_PLAY);
  }
void Sky::btn_stop(){
  send(SKY_STOP);
  }
void Sky::btn_pause(){
  send(SKY_PAUSE);
  }
void Sky::btn_rw(){
  send(SKY_RW);
  }
void Sky::btn_ff(){
  send(SKY_FF);
  }
void Sky::btn_rec(){
  send(SKY_REC);
  }
void Sky::btn_crw(){
  send(SKY_CRW);
  }
void Sky::btn_cff(){
  send(SKY_CFF);
  }

void Sky::btn_guide(){
  send(SKY_GUIDE);
  }
void Sky::btn_central(){
  send(SKY_CENTRAL);
  }
void Sky::btn_list(){
  send(SKY_LIST);
  }
void Sky::btn_exit(){
  send(SKY_EXIT);
  }
void Sky::btn_return(){
  send(SKY_RETURN);
  }
void Sky::btn_menu(){
  send(SKY_MENU);
  }
void Sky::btn_info(){
  send(SKY_INFO);
  }

void Sky::btn_confirm(){
  send(SKY_CONFIRM);
  }
void Sky::btn_up(){
  send(SKY_UP);
  }
void Sky::btn_down(){
  send(SKY_DOWN);
  }
void Sky::btn_left(){
  send(SKY_LEFT);
  }
void Sky::btn_right(){
  send(SKY_RIGHT);
  }

void Sky::btn_red(){
  send(SKY_RED);
  }
void Sky::btn_green(){
  send(SKY_GREEN);
  }
void Sky::btn_yellow(){
  send(SKY_YELLOW);
  }
void Sky::btn_blue(){
  send(SKY_BLUE);
  }

void Sky::btn_chup(){
  send(SKY_CHUP);
  }
void Sky::btn_chdown(){
  send(SKY_CHDOWN);
  }

void Sky::btn_chreturn(){
  send(SKY_CHRETURN);
  }





  


