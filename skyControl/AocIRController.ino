
#ifndef AOCIRCONTROLLER_H
#define AOCIRCONTROLLER_H

#include "Arduino.h"
#include <IRremote.h>







class AOC{

  const unsigned long  AOC_SOURCE = 0xBD10EF;
  const unsigned long  AOC_MUTE= 0xBD10EF;
  const unsigned long  AOC_POWER = 0xBD10EF;

  const unsigned long  AOC_NUM1 = 0xBD10EF;
  const unsigned long  AOC_NUM2 = 0xBD10EF;
  const unsigned long  AOC_NUM3 = 0xBD10EF;
  const unsigned long  AOC_NUM4 = 0xBD10EF;
  const unsigned long  AOC_NUM5 = 0xBD10EF;
  const unsigned long  AOC_NUM6 = 0xBD10EF;
  const unsigned long  AOC_NUM7 = 0xBD10EF;
  const unsigned long  AOC_NUM8 = 0xBD10EF;
  const unsigned long  AOC_NUM9 = 0xBD10EF;
  const unsigned long  AOC_NUM100 = 0xBD10EF;
  const unsigned long  AOC_NUM0 = 0xBD10EF;
  
  const unsigned long  AOC_RETURN = 0xBD10EF;
  const unsigned long  AOC_MENU = 0xBD10EF;
  const unsigned long  AOC_SERVICE = 0xBD10EF;

  const unsigned long  AOC_VOLUP = 0xBD10EF;
  const unsigned long  AOC_VOLDOWN = 0xBD10EF;
  const unsigned long  AOC_CHUP = 0xBD10EF;
  const unsigned long  AOC_CHDOWN = 0xBD10EF;

  const unsigned long  AOC_UP = 0xBD10EF;
  const unsigned long  AOC_DOWN = 0xBD10EF;
  const unsigned long  AOC_LEFT = 0xBD10EF;
  const unsigned long  AOC_RIGHT = 0xBD10EF;
  const unsigned long  AOC_CONFIRM = 0xBD10EF;

  const unsigned long  AOC_EPG = 0xBD10EF;
  const unsigned long  AOC_DISPLAY = 0xBD10EF;
  const unsigned long  AOC_CHLIST = 0xBD10EF;
  const unsigned long  AOC_EXIT = 0xBD10EF;
  const unsigned long  AOC_CC = 0xBD10EF;
  const unsigned long  AOC_AUDIO = 0xBD10EF;
  const unsigned long  AOC_PICTURE = 0xBD10EF;
  const unsigned long  AOC_SOUND = 0xBD10EF;

  const unsigned long  AOC_RED = 0xBD10EF;
  const unsigned long  AOC_GREEN = 0xBD10EF;
  const unsigned long  AOC_YELLOW = 0xBD10EF;
  const unsigned long  AOC_BLUE = 0xBD10EF;

  const unsigned long  AOC_ASPECT = 0xBD10EF;
  const unsigned long  AOC_SLEEP = 0xBD10EF;
  const unsigned long  AOC_FREEZE = 0xBD10EF;
  const unsigned long  AOC_INFO = 0xBD10EF;

  const unsigned long  AOC_RW = 0xBD10EF;
  const unsigned long  AOC_PLAY = 0xBD10EF;
  const unsigned long  AOC_FF = 0xBD10EF;
  const unsigned long  AOC_STOP = 0xBD10EF;

  private:
  
  IRsend irsend;
  int nbits;

  public:

  AOC();
  void send(const unsigned int code);

 
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






AOC::AOC(){
  
  nbits = 32;
  
  }



void AOC::send(const unsigned int code){
  
  irsend.sendNEC(code,nbits);

  
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
