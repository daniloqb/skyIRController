
#ifndef SKYIRCONTROLLER_H
#define SKYIRCONTROLLER_H

#include "Arduino.h"
#include <IRremote.h>







class Sky{

  const unsigned short SKY_NUM0     = 0xc116;
  const unsigned short SKY_NUM1     = 0xc011;
  const unsigned short SKY_NUM2     = 0xc022;
  const unsigned short SKY_NUM3     = 0xc033;
  const unsigned short SKY_NUM4     = 0xc043;
  const unsigned short SKY_NUM5     = 0xc054;
  const unsigned short SKY_NUM6     = 0xc065;
  const unsigned short SKY_NUM7     = 0xc076;
  const unsigned short SKY_NUM8     = 0xc086;
  const unsigned short SKY_NUM9     = 0xc097;
  const unsigned short SKY_NUMD     = 0xc127;
  const unsigned short SKY_NUME     = 0xc138;

  const unsigned short SKY_POWER    = 0xc105;
  const unsigned short SKY_SCRTV    = 0xc739;

  const unsigned short SKY_PLAY     = 0xc30f;
  const unsigned short SKY_STOP     = 0xc310;
  const unsigned short SKY_PAUSE    = 0xc321;
  const unsigned short SKY_RW       = 0xc332;
  const unsigned short SKY_FF       = 0xc342;
  const unsigned short SKY_REC      = 0xc353;
  const unsigned short SKY_CRW      = 0xc364;
  const unsigned short SKY_CFF      = 0xc375;

  const unsigned short SKY_GUIDE    = 0xc280;
  const unsigned short SKY_CENTRAL  = 0xc291;
  const unsigned short SKY_LIST     = 0xc2a2;
  const unsigned short SKY_EXIT     = 0xc26f;
  const unsigned short SKY_RETURN   = 0xc270;
  const unsigned short SKY_MENU     = 0xc20a;
  const unsigned short SKY_INFO     = 0xc2e5;

  const unsigned short SKY_CONFIRM  = 0xc25e;
  const unsigned short SKY_UP       = 0xc21b;
  const unsigned short SKY_DOWN     = 0xc22c;
  const unsigned short SKY_LEFT     = 0xc23d;
  const unsigned short SKY_RIGHT    = 0xc24d;

  const unsigned short SKY_RED      = 0xc418;
  const unsigned short SKY_GREEN    = 0xc43a;
  const unsigned short SKY_YELLOW   = 0xc429;
  const unsigned short SKY_BLUE     = 0xc44a;

  const unsigned short SKY_CHUP     = 0xc0da;
  const unsigned short SKY_CHDOWN   = 0xc0eb;
  const unsigned short SKY_CHRETURN = 0xc0fc;

  private:
  
  IRsend irsend;
  int nbits;

  public:

  Sky();
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












#endif
