
#ifndef SKYIRCONTROLLER_H
#define SKYIRCONTROLLER_H

#include "Arduino.h"
#include <IRremote.h>


  const unsigned short SKY_NUM0 PROGMEM    = 0xc116;
  const unsigned short SKY_NUM1 PROGMEM    = 0xc011;
  const unsigned short SKY_NUM2 PROGMEM    = 0xc022;
  const unsigned short SKY_NUM3 PROGMEM    = 0xc033;
  const unsigned short SKY_NUM4 PROGMEM    = 0xc043;
  const unsigned short SKY_NUM5 PROGMEM    = 0xc054;
  const unsigned short SKY_NUM6 PROGMEM    = 0xc065;
  const unsigned short SKY_NUM7 PROGMEM    = 0xc076;
  const unsigned short SKY_NUM8  PROGMEM   = 0xc086;
  const unsigned short SKY_NUM9 PROGMEM    = 0xc097;
  const unsigned short SKY_NUMD PROGMEM    = 0xc127;
  const unsigned short SKY_NUME PROGMEM    = 0xc138;

  const unsigned short SKY_POWER PROGMEM   = 0xc105;
  const unsigned short SKY_SCRTV PROGMEM   = 0xc739;

  const unsigned short SKY_PLAY  PROGMEM   = 0xc30f;
  const unsigned short SKY_STOP PROGMEM    = 0xc310;
  const unsigned short SKY_PAUSE PROGMEM    = 0xc321;
  const unsigned short SKY_RW   PROGMEM    = 0xc332;
  const unsigned short SKY_FF   PROGMEM    = 0xc342;
  const unsigned short SKY_REC  PROGMEM    = 0xc353;
  const unsigned short SKY_CRW  PROGMEM    = 0xc364;
  const unsigned short SKY_CFF  PROGMEM    = 0xc375;

  const unsigned short SKY_GUIDE  PROGMEM  = 0xc280;
  const unsigned short SKY_CENTRAL PROGMEM = 0xc291;
  const unsigned short SKY_LIST   PROGMEM  = 0xc2a2;
  const unsigned short SKY_EXIT   PROGMEM  = 0xc26f;
  const unsigned short SKY_RETURN PROGMEM  = 0xc270;
  const unsigned short SKY_MENU   PROGMEM  = 0xc20a;
  const unsigned short SKY_INFO  PROGMEM   = 0xc2e5;

  const unsigned short SKY_CONFIRM PROGMEM = 0xc25e;
  const unsigned short SKY_UP     PROGMEM  = 0xc21b;
  const unsigned short SKY_DOWN  PROGMEM   = 0xc22c;
  const unsigned short SKY_LEFT   PROGMEM  = 0xc23d;
  const unsigned short SKY_RIGHT  PROGMEM  = 0xc24d;

  const unsigned short SKY_RED    PROGMEM  = 0xc418;
  const unsigned short SKY_GREEN  PROGMEM  = 0xc43a;
  const unsigned short SKY_YELLOW PROGMEM  = 0xc429;
  const unsigned short SKY_BLUE   PROGMEM  = 0xc44a;

  const unsigned short SKY_CHUP   PROGMEM  = 0xc0da;
  const unsigned short SKY_CHDOWN PROGMEM  = 0xc0eb;
  const unsigned short SKY_CHRETURN PROGMEM = 0xc0fc;





class Sky{



  private:
  
  IRsend * irsend;
  int nbits;

  public:

  Sky(IRsend * sender);
  void send(const unsigned short code);

  void btn_num0();
  void btn_num1();
  void btn_num2();
  void btn_num3();
  void btn_num4();
  void btn_num5();
  void btn_num6();
  void btn_num7();
  void btn_num8();
  void btn_num9();
  void btn_numD();
  void btn_numE();

  void btn_power();
  void btn_scrtv();

  void btn_play();
  void btn_stop();
  void btn_pause();
  void btn_rw();
  void btn_ff();
  void btn_rec();
  void btn_crw();
  void btn_cff();

  void btn_guide();
  void btn_central();
  void btn_list();
  void btn_exit();
  void btn_return();
  void btn_menu();
  void btn_info();

  void btn_confirm();
  void btn_up();
  void btn_down();
  void btn_left();
  void btn_right();

  void btn_red();
  void btn_green();
  void btn_yellow();
  void btn_blue();

  void btn_chup();
  void btn_chdown();
  void btn_chreturn();
  
};



Sky::Sky(IRsend * sender){

  irsend = sender;
  nbits = 16;
  
  }



void Sky::send(const unsigned short code){
  
  irsend->sendSKYhdtv(code,nbits);

  
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










#endif
