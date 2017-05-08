
#ifndef AOCIRDEVICE_H
#define AOCIRDEVICE_H

#include "Arduino.h"
#include <IRremote.h>


  const unsigned long PROGMEM AOC_SOURCE = 0xBD10EF;
  const unsigned long PROGMEM AOC_MUTE= 0xBD20DF;
  const unsigned long PROGMEM AOC_POWER = 0xBD807F;

  const unsigned long PROGMEM AOC_NUM1 = 0xBDA857;
  const unsigned long PROGMEM AOC_NUM2 = 0xBD6897;
  const unsigned long PROGMEM AOC_NUM3 = 0xBDE817;
  const unsigned long PROGMEM AOC_NUM4 = 0xBD9867;
  const unsigned long PROGMEM AOC_NUM5 = 0xBD58A7;
  const unsigned long PROGMEM  AOC_NUM6 = 0xBDD827;
  const unsigned long PROGMEM AOC_NUM7 = 0xBDB847;
  const unsigned long PROGMEM AOC_NUM8 = 0xBD7887;
  const unsigned long PROGMEM AOC_NUM9 = 0xBDF807;
  const unsigned long PROGMEM AOC_NUM100 = 0xBDD22D;
  const unsigned long PROGMEM AOC_NUM0 = 0xBD827D;
  
  const unsigned long PROGMEM AOC_RETURN = 0xBD22DD;
  const unsigned long PROGMEM AOC_MENU = 0xBD50AF;
  const unsigned long PROGMEM AOC_SERVICE = 0xBD7689;

  const unsigned long PROGMEM AOC_VOLUP = 0xBD30CF;
  const unsigned long PROGMEM  AOC_VOLDOWN = 0xBD08F7;
  const unsigned long PROGMEM AOC_CHUP = 0xBD18E7;
  const unsigned long PROGMEM AOC_CHDOWN = 0xBD38C7;

  const unsigned long PROGMEM AOC_UP = 0xBDD02F;
  const unsigned long PROGMEM AOC_DOWN = 0xBDF00F;
  const unsigned long PROGMEM AOC_LEFT = 0xBD926D;
  const unsigned long PROGMEM AOC_RIGHT = 0xBD52AD;
  const unsigned long PROGMEM AOC_CONFIRM = 0xBDB04F;

  const unsigned long PROGMEM AOC_EPG = 0xBD1AE5;
  const unsigned long PROGMEM AOC_DISPLAY = 0xBD40BF;
  const unsigned long PROGMEM AOC_CHLIST = 0xBD5AA5;
  const unsigned long PROGMEM AOC_EXIT = 0xBDE01F;
  const unsigned long PROGMEM AOC_CC = 0xBDCA35;
  const unsigned long PROGMEM AOC_AUDIO = 0xBD02FD;
  const unsigned long PROGMEM AOC_PICTURE = 0xBDC03F;
  const unsigned long PROGMEM AOC_SOUND = 0xBD906F;

  const unsigned long PROGMEM AOC_RED = 0xBD32CD;
  const unsigned long PROGMEM AOC_GREEN = 0xBDB24D;
  const unsigned long PROGMEM AOC_YELLOW = 0xBD728D;
  const unsigned long PROGMEM AOC_BLUE = 0xBDF20D;

  const unsigned long PROGMEM AOC_ASPECT = 0xBD28D7;
  const unsigned long PROGMEM AOC_SLEEP = 0xBDC837;
  const unsigned long PROGMEM AOC_FREEZE = 0xBD48B7;
  const unsigned long PROGMEM AOC_INFO = 0xBDB649;

  const unsigned long PROGMEM AOC_RW = 0xBD3AC5;
  const unsigned long PROGMEM AOC_PLAY = 0xBD7A85;
  const unsigned long PROGMEM AOC_FF = 0xBDFA05;
  const unsigned long PROGMEM AOC_STOP = 0xBDBA45;




class AOC{


  private:
  
  IRsend * irsend;
  int nbits;

  public:

  AOC(IRsend * irsend);
  void send(const unsigned long code);

 
  void btn_source();
  void btn_mute();
  void btn_power();
  
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
  void btn_num100();

    
  void btn_return();
  void btn_menu();
  void btn_service();

    
  void btn_volup();
  void btn_voldown();
  
  void btn_chup();
  void btn_chdown();


  void btn_confirm();
  void btn_up();
  void btn_down();
  void btn_left();
  void btn_right();

  void btn_epg();
  void btn_display();
  void btn_chlist();
  void btn_exit();

  void btn_cc();
  void btn_audio();
  void btn_picture();
  void btn_sound();



  void btn_red();
  void btn_green();
  void btn_yellow();
  void btn_blue();

  void btn_aspect();
  void btn_sleep();
  void btn_freeze();
  void btn_info();


  void btn_play();
  void btn_stop();
  void btn_rw();
  void btn_ff();

  
};






AOC::AOC(IRsend * sender){

  irsend = sender;
  nbits = 32;
  
  }



void AOC::send(const unsigned long code){
  
  irsend->sendNEC(code,nbits);

  
  }




  void AOC::btn_source(){
    send(AOC_SOURCE);
    }
  void AOC::btn_mute(){
    send(AOC_MUTE);
    }
  void AOC::btn_power(){
    send(AOC_POWER);
    }
  
  void AOC::btn_num0(){
    send(AOC_NUM0);
    }
  void AOC::btn_num1(){
    send(AOC_NUM1);
    }
  void AOC::btn_num2(){
    send(AOC_NUM2);
    }
  void AOC::btn_num3(){
    send(AOC_NUM3);
    }
  void AOC::btn_num4(){
    send(AOC_NUM4);
    }
  void AOC::btn_num5(){
    send(AOC_NUM5);
    }
  void AOC::btn_num6(){
    send(AOC_NUM6);
    }
  void AOC::btn_num7(){
    send(AOC_NUM7);
    }
  void AOC::btn_num8(){
    send(AOC_NUM8);
    }
  void AOC::btn_num9(){
    send(AOC_NUM9);
    }
  void AOC::btn_num100(){
    send(AOC_NUM100);
    }

    
  void AOC::btn_return(){
    send(AOC_RETURN);
    }
  void AOC::btn_menu(){
    send(AOC_MENU);
    }
  void AOC::btn_service(){
    send(AOC_SERVICE);
    }

    
  void AOC::btn_volup(){
    send(AOC_VOLUP);
    }
  void AOC::btn_voldown(){
    send(AOC_VOLDOWN);
    }
  
  void AOC::btn_chup(){
    send(AOC_CHUP);
    }
  void AOC::btn_chdown(){
    send(AOC_CHDOWN);
    }


  void AOC::btn_confirm(){
    send(AOC_CONFIRM);
    }
  void AOC::btn_up(){
    send(AOC_UP);
    }
  void AOC::btn_down(){
    send(AOC_DOWN);
    }
  void AOC::btn_left(){
    send(AOC_LEFT);
    }
  void AOC::btn_right(){
    send(AOC_RIGHT);
    }

  void AOC::btn_epg(){
    send(AOC_EPG);
    }
  void AOC::btn_display(){
    send(AOC_DISPLAY);
    }
  void AOC::btn_chlist(){
    send(AOC_CHLIST);
    }
  void AOC::btn_exit(){
    send(AOC_EXIT);
    }

  void AOC::btn_cc(){
    send(AOC_CC);
    }
  void AOC::btn_audio(){
    send(AOC_AUDIO);
    }
  void AOC::btn_picture(){
    send(AOC_PICTURE);
    }
  void AOC::btn_sound(){
send(AOC_SOUND);
  }



  void AOC::btn_red(){
    send(AOC_RED);
    }
  void AOC::btn_green(){
    send(AOC_GREEN);
    }
  void AOC::btn_yellow(){
    send(AOC_YELLOW);
    }
  void AOC::btn_blue(){
    send(AOC_BLUE);
    }

  void AOC::btn_aspect(){
    send(AOC_ASPECT);
    }
  void AOC::btn_sleep(){
    send(AOC_SLEEP);
  }
  void AOC::btn_freeze(){
    send(AOC_FREEZE);
    }
  void AOC::btn_info(){
    send(AOC_INFO);
    }

  void AOC::btn_play(){
    send(AOC_PLAY);
    }
  void AOC::btn_stop(){
    send(AOC_STOP);
    }
  void AOC::btn_rw(){
    send(AOC_RW);
    }
  void AOC::btn_ff(){
    send(AOC_FF);
    }







#endif
