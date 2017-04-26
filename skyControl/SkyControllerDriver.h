
#ifndef SKYCONTROLLERDRIVER_H
#define SKYCONTROLLERDRIVER_H

#include "Arduino.h"
#include <aJSON.h>

#include "SkyIRController.h"




  /*CONSTANTES DE ROTA*/

  const char ROUTE_ROOT[]        PROGMEM = "/";
  const char ROUTE_DEVICE[]      PROGMEM = "/sky";
  const char ROUTE_COMMANDS[]    PROGMEM = "/sky/commands";
  const char ROUTE_BTN_NUM0[]    PROGMEM = "/sky/num0";
  const char ROUTE_BTN_NUM1[]    PROGMEM = "/sky/num1";
  const char ROUTE_BTN_NUM2[]    PROGMEM = "/sky/num2";
  const char ROUTE_BTN_NUM3[]    PROGMEM = "/sky/num3";
  const char ROUTE_BTN_NUM4[]    PROGMEM = "/sky/num4";
  const char ROUTE_BTN_NUM5[]    PROGMEM = "/sky/num5";
  const char ROUTE_BTN_NUM6[]    PROGMEM = "/sky/num6";
  const char ROUTE_BTN_NUM7[]    PROGMEM = "/sky/num7";
  const char ROUTE_BTN_NUM8[]    PROGMEM = "/sky/num8";
  const char ROUTE_BTN_NUM9[]    PROGMEM = "/sky/num9";
  const char ROUTE_BTN_NUMD[]    PROGMEM = "/sky/numD";
  const char ROUTE_BTN_NUME[]    PROGMEM = "/sky/numE";
  const char ROUTE_BTN_POWER[]   PROGMEM = "/sky/power";
  const char ROUTE_BTN_SCRTV[]   PROGMEM = "/sky/scrtv";
  const char ROUTE_BTN_PLAY[]    PROGMEM = "/sky/play";  
  const char ROUTE_BTN_STOP[]    PROGMEM = "/sky/stop";   
  const char ROUTE_BTN_PAUSE[]   PROGMEM = "/sky/pause";  
  const char ROUTE_BTN_RW[]      PROGMEM = "/sky/rw";
  const char ROUTE_BTN_FF[]      PROGMEM = "/sky/ff";
  const char ROUTE_BTN_REC[]     PROGMEM = "/sky/rec";
  const char ROUTE_BTN_CFF[]     PROGMEM = "/sky/cff";
  const char ROUTE_BTN_CRW[]     PROGMEM = "/sky/crw";
  const char ROUTE_BTN_GUIDE[]   PROGMEM = "/sky/guide"; 
  const char ROUTE_BTN_CENTRAL[] PROGMEM = "/sky/central";  
  const char ROUTE_BTN_LIST[]    PROGMEM = "/sky/list";
  const char ROUTE_BTN_EXIT[]    PROGMEM = "/sky/exit";
  const char ROUTE_BTN_RETURN[]  PROGMEM = "/sky/return"; 
  const char ROUTE_BTN_MENU[]    PROGMEM = "/sky/menu";
  const char ROUTE_BTN_INFO[]    PROGMEM = "/sky/info";
  const char ROUTE_BTN_CONFIRM[] PROGMEM = "/sky/confirm";  
  const char ROUTE_BTN_UP[]      PROGMEM = "/sky/up";
  const char ROUTE_BTN_DOWN[]    PROGMEM = "/sky/down"; 
  const char ROUTE_BTN_LEFT[]    PROGMEM = "/sky/left";
  const char ROUTE_BTN_RIGHT[]     PROGMEM = "/sky/right";
  const char ROUTE_BTN_RED[]       PROGMEM = "/sky/red";
  const char ROUTE_BTN_GREEN[]     PROGMEM = "/sky/green"; 
  const char ROUTE_BTN_YELLOW[]    PROGMEM = "/sky/yellow"; 
  const char ROUTE_BTN_BLUE[]      PROGMEM = "/sky/blue";
  const char ROUTE_BTN_CHUP[]      PROGMEM = "/sky/chup";
  const char ROUTE_BTN_CHDOWN[]    PROGMEM = "/sky/chdown"; 
  const char ROUTE_BTN_CHRETURN[]  PROGMEM = "/sky/chreturn";  
  
  /*
   CONSTANTES DE VARIAVEIS DO DISPOSITIVO
*/

  const char  DEVICE_NAME[] PROGMEM = "sky";
  const char  COMMANDS[] PROGMEM = "{\"commands\":[{\"route\":\"/sky\",\"label\":\"sky\"}]}";
  



class SkyControllerDriver{



  private:
    char * device_commands();
    Sky *device;

  public:
     SkyControllerDriver(Sky *sky);
    void begin();
    char * get_main_route();
    char * process_message(char * uri, UrlParams url_params);
    char * get_name();
    void update();
  
};

SkyControllerDriver::SkyControllerDriver(Sky * sky){

  device = sky;
  
}

void SkyControllerDriver::begin(){}

void SkyControllerDriver::update(){}
  

char * SkyControllerDriver::get_main_route(){

    static char response[5];

  strcpy_P(response,ROUTE_DEVICE);
  
  return response;
}



char * SkyControllerDriver::get_name(){
    static char response[4];

  strcpy_P(response,DEVICE_NAME);
  
  return response;
}




char * SkyControllerDriver::device_commands(){


  static char  response[255];

  strcpy_P(response,COMMANDS);


  return response;


}




char * SkyControllerDriver::process_message(char * uri,UrlParams url_params){

 char * response = NULL;
 boolean valid_route = false;


  if (strcmp_P(uri, ROUTE_DEVICE) == 0) {        // verifica se a rota eh a rota raiz do dispositivo
   valid_route = true;

  }
  
  else if (strcmp_P(uri, ROUTE_BTN_NUM0) == 0) {
    valid_route = true;
    device->btn_num0();

  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM1) == 0) {
    valid_route = true;
    device->btn_num1();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM2) == 0) {
    valid_route = true;
    device->btn_num2();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM3) == 0) {
    valid_route = true;
    device->btn_num3();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM4) == 0) {
    valid_route = true;
    device->btn_num4();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM5) == 0) {
   valid_route = true;
   device->btn_num5();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM6) == 0) {
   valid_route = true;
   device->btn_num6();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM7) == 0) {
   valid_route = true;
   device->btn_num7();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM8) == 0) {
   valid_route = true;
   device->btn_num8();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUM9) == 0) {
   valid_route = true;
   device->btn_num9();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUMD) == 0) {
   valid_route = true;
   device->btn_numD();
  }
    else if (strcmp_P(uri, ROUTE_BTN_NUME) == 0) {
   valid_route = true;
   device->btn_numE();
  }
  else if (strcmp_P(uri, ROUTE_BTN_POWER) == 0) {
   valid_route = true;
   device->btn_power();
  }
  
  else if (strcmp_P(uri, ROUTE_BTN_SCRTV) == 0) {
   valid_route = true;
   device->btn_scrtv();
  }
  
  else if (strcmp_P(uri, ROUTE_BTN_PLAY) == 0) {
   valid_route = true;
   device->btn_play();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_STOP) == 0) {
   valid_route = true;
   device->btn_stop();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_PAUSE) == 0) {
   valid_route = true;
   device->btn_pause();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_RW) == 0) {
   valid_route = true;
   device->btn_rw();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_FF) == 0) {
   valid_route = true;
   device->btn_ff();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_REC) == 0) {
   valid_route = true;
   device->btn_rec();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CFF) == 0) {
   valid_route = true;
   device->btn_cff();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CRW) == 0) {
   valid_route = true;
   device->btn_crw();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_GUIDE) == 0) {
   valid_route = true;
   device->btn_guide();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CENTRAL) == 0) {
   valid_route = true;
   device->btn_central();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_LIST) == 0) {
   valid_route = true;
   device->btn_list();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_EXIT) == 0) {
   valid_route = true;
   device->btn_exit();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_RETURN) == 0) {
   valid_route = true;
   device->btn_return();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_MENU) == 0) {
   valid_route = true;
   device->btn_menu();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_INFO) == 0) {
   valid_route = true;
   device->btn_info();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CONFIRM) == 0) {
   valid_route = true;
   device->btn_confirm();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_UP) == 0) {
   valid_route = true;
   device->btn_up();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_DOWN) == 0) {
   valid_route = true;
   device->btn_down();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_LEFT) == 0) {
   valid_route = true;
   device->btn_left();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_RIGHT) == 0) {
   valid_route = true;
   device->btn_right();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_RED) == 0) {
   valid_route = true;
   device->btn_red();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_GREEN) == 0) {
   valid_route = true;
   device->btn_green();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_YELLOW) == 0) {
   valid_route = true;
   device->btn_yellow();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_BLUE) == 0) {
   valid_route = true;
   device->btn_blue();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CHUP) == 0) {
   valid_route = true;
   device->btn_chup();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CHDOWN) == 0) {
   valid_route = true;
   device->btn_chdown();
  }
  
    else if (strcmp_P(uri, ROUTE_BTN_CHRETURN) == 0) {
   valid_route = true;
   device->btn_chreturn();
  }
  
   


  else if (strcmp_P(uri, ROUTE_COMMANDS) == 0) {
   valid_route = true;
  }


  // O JSON eh montado se a rota for valida ou se a cor for requisitada.

  if (valid_route) {
    aJsonObject *root;
    root = aJson.createObject();
    aJson.addStringToObject(root, "name", get_name());
    aJson.addStringToObject(root, "msg", "command successful.");

    response = aJson.print(root);
    aJson.deleteItem(root);

  }

 return response;

}










#endif
