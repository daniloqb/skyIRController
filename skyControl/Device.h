
#ifndef DEVICE_H
#define DEVICE_H

#include "Arduino.h"
#include <aJSON.h>

#include "SkyController.h"



class Device{

  /*CONSTANTES DE ROTA*/

  #define ROUTE_ROOT "/"
  #define ROUTE_DEVICE        ROUTE_ROOT"sky"
  #define ROUTE_COMMANDS      ROUTE_DEVICE"/commands"
  #define ROUTE_BTN_NUM0      ROUTE_DEVICE"/num0"
  #define ROUTE_BTN_NUM1      ROUTE_DEVICE"/num1"
  #define ROUTE_BTN_NUM2      ROUTE_DEVICE"/num2"
  #define ROUTE_BTN_NUM3      ROUTE_DEVICE"/num3"
  #define ROUTE_BTN_NUM4      ROUTE_DEVICE"/num4"
  #define ROUTE_BTN_NUM5      ROUTE_DEVICE"/num5"
  #define ROUTE_BTN_NUM6      ROUTE_DEVICE"/num6"
  #define ROUTE_BTN_NUM7      ROUTE_DEVICE"/num7"
  #define ROUTE_BTN_NUM8      ROUTE_DEVICE"/num8"
  #define ROUTE_BTN_NUM9      ROUTE_DEVICE"/num9"
  #define ROUTE_BTN_NUMD      ROUTE_DEVICE"/numD"
  #define ROUTE_BTN_NUME      ROUTE_DEVICE"/numE"
  #define ROUTE_BTN_POWER     ROUTE_DEVICE"/power"
  #define ROUTE_BTN_SCRTV     ROUTE_DEVICE"/scrtv"
  #define ROUTE_BTN_PLAY      ROUTE_DEVICE"/play"  
  #define ROUTE_BTN_STOP      ROUTE_DEVICE"/stop"   
  #define ROUTE_BTN_PAUSE     ROUTE_DEVICE"/pause"  
  #define ROUTE_BTN_RW        ROUTE_DEVICE"/rw"  
  #define ROUTE_BTN_FF        ROUTE_DEVICE"/ff"  
  #define ROUTE_BTN_REC       ROUTE_DEVICE"/rec"  
  #define ROUTE_BTN_CFF       ROUTE_DEVICE"/cff"  
  #define ROUTE_BTN_CRW       ROUTE_DEVICE"/crw"  
  #define ROUTE_BTN_GUIDE     ROUTE_DEVICE"/guide"  
  #define ROUTE_BTN_CENTRAL   ROUTE_DEVICE"/central"  
  #define ROUTE_BTN_LIST      ROUTE_DEVICE"/list"  
  #define ROUTE_BTN_EXIT      ROUTE_DEVICE"/exit"  
  #define ROUTE_BTN_RETURN    ROUTE_DEVICE"/return"  
  #define ROUTE_BTN_MENU      ROUTE_DEVICE"/menu"  
  #define ROUTE_BTN_INFO      ROUTE_DEVICE"/info"
  #define ROUTE_BTN_CONFIRM   ROUTE_DEVICE"/confirm"  
  #define ROUTE_BTN_UP        ROUTE_DEVICE"/up"  
  #define ROUTE_BTN_DOWN      ROUTE_DEVICE"/down"  
  #define ROUTE_BTN_LEFT      ROUTE_DEVICE"/left"  
  #define ROUTE_BTN_RIGHT     ROUTE_DEVICE"/right"  
  #define ROUTE_BTN_RED       ROUTE_DEVICE"/red"  
  #define ROUTE_BTN_GREEN     ROUTE_DEVICE"/green"  
  #define ROUTE_BTN_YELLOW    ROUTE_DEVICE"/yellow"  
  #define ROUTE_BTN_BLUE      ROUTE_DEVICE"/blue"  
  #define ROUTE_BTN_CHUP      ROUTE_DEVICE"/chup"  
  #define ROUTE_BTN_CHDOWN    ROUTE_DEVICE"/chdown"  
  #define ROUTE_BTN_CHRETURN  ROUTE_DEVICE"/chreturn"  
  
  /*
   CONSTANTES DE VARIAVEIS DO DISPOSITIVO
*/

  const char * DEVICE_NAME = "sky";


  private:
    char * device_commands();
    Sky sky;

  public:
     Device();
    void begin();
    char * get_main_route();
    char * process_message(char * uri, UrlParams url_params);
    char * get_name();
    void update();
  
};

Device::Device(){
  
}

void Device::begin(){}

void Device::update(){}
  

char * Device::get_main_route(){

  return ROUTE_DEVICE;
}



char * Device::get_name(){
  return DEVICE_NAME;
}




char * Device::device_commands(){


  char * response = NULL;


//response = "{\"commands\": [{\"route\": \"/rgb\",\"label\": \"rgb\",\"params\": [{\"name\": \"color\",\"type\": \"int\",\"min\": 0,\"max\": 360 },{\"name\": \"brightness\",\"type\": \"int\",\"min\": 0,\"max\": 100 }]}]}\n";




  return response;

}




char * Device::process_message(char * uri,UrlParams url_params){

 char * response = NULL;
 boolean valid_route = false;


  if (strcmp(uri, ROUTE_DEVICE) == 0) {        // verifica se a rota eh a rota raiz do dispositivo
   valid_route = true;

  }
  
  else if (strcmp(uri, ROUTE_BTN_NUM0) == 0) {
    valid_route = true;
    sky.btn_num0();

  }
    else if (strcmp(uri, ROUTE_BTN_NUM1) == 0) {
    valid_route = true;
    sky.btn_num1();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM2) == 0) {
    valid_route = true;
    sky.btn_num2();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM3) == 0) {
    valid_route = true;
    sky.btn_num3();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM4) == 0) {
    valid_route = true;
    sky.btn_num4();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM5) == 0) {
   valid_route = true;
   sky.btn_num5();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM6) == 0) {
   valid_route = true;
   sky.btn_num6();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM7) == 0) {
   valid_route = true;
   sky.btn_num7();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM8) == 0) {
   valid_route = true;
   sky.btn_num8();
  }
    else if (strcmp(uri, ROUTE_BTN_NUM9) == 0) {
   valid_route = true;
   sky.btn_num9();
  }
    else if (strcmp(uri, ROUTE_BTN_NUMD) == 0) {
   valid_route = true;
   sky.btn_numD();
  }
    else if (strcmp(uri, ROUTE_BTN_NUME) == 0) {
   valid_route = true;
   sky.btn_numE();
  }
  else if (strcmp(uri, ROUTE_BTN_POWER) == 0) {
   valid_route = true;
   sky.btn_power();
  }
  
  else if (strcmp(uri, ROUTE_BTN_SCRTV) == 0) {
   valid_route = true;
   sky.btn_scrtv();
  }
  
  else if (strcmp(uri, ROUTE_BTN_PLAY) == 0) {
   valid_route = true;
   sky.btn_play();
  }
  
    else if (strcmp(uri, ROUTE_BTN_STOP) == 0) {
   valid_route = true;
   sky.btn_stop();
  }
  
    else if (strcmp(uri, ROUTE_BTN_PAUSE) == 0) {
   valid_route = true;
   sky.btn_pause();
  }
  
    else if (strcmp(uri, ROUTE_BTN_RW) == 0) {
   valid_route = true;
   sky.btn_rw();
  }
  
    else if (strcmp(uri, ROUTE_BTN_FF) == 0) {
   valid_route = true;
   sky.btn_ff();
  }
  
    else if (strcmp(uri, ROUTE_BTN_REC) == 0) {
   valid_route = true;
   sky.btn_rec();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CFF) == 0) {
   valid_route = true;
   sky.btn_cff();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CRW) == 0) {
   valid_route = true;
   sky.btn_crw();
  }
  
    else if (strcmp(uri, ROUTE_BTN_GUIDE) == 0) {
   valid_route = true;
   sky.btn_guide();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CENTRAL) == 0) {
   valid_route = true;
   sky.btn_central();
  }
  
    else if (strcmp(uri, ROUTE_BTN_LIST) == 0) {
   valid_route = true;
   sky.btn_list();
  }
  
    else if (strcmp(uri, ROUTE_BTN_EXIT) == 0) {
   valid_route = true;
   sky.btn_exit();
  }
  
    else if (strcmp(uri, ROUTE_BTN_RETURN) == 0) {
   valid_route = true;
   sky.btn_return();
  }
  
    else if (strcmp(uri, ROUTE_BTN_MENU) == 0) {
   valid_route = true;
   sky.btn_menu();
  }
  
    else if (strcmp(uri, ROUTE_BTN_INFO) == 0) {
   valid_route = true;
   sky.btn_info();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CONFIRM) == 0) {
   valid_route = true;
   sky.btn_confirm();
  }
  
    else if (strcmp(uri, ROUTE_BTN_UP) == 0) {
   valid_route = true;
   sky.btn_up();
  }
  
    else if (strcmp(uri, ROUTE_BTN_DOWN) == 0) {
   valid_route = true;
   sky.btn_down();
  }
  
    else if (strcmp(uri, ROUTE_BTN_LEFT) == 0) {
   valid_route = true;
   sky.btn_left();
  }
  
    else if (strcmp(uri, ROUTE_BTN_RIGHT) == 0) {
   valid_route = true;
   sky.btn_right();
  }
  
    else if (strcmp(uri, ROUTE_BTN_RED) == 0) {
   valid_route = true;
   sky.btn_red();
  }
  
    else if (strcmp(uri, ROUTE_BTN_GREEN) == 0) {
   valid_route = true;
   sky.btn_green();
  }
  
    else if (strcmp(uri, ROUTE_BTN_YELLOW) == 0) {
   valid_route = true;
   sky.btn_yellow();
  }
  
    else if (strcmp(uri, ROUTE_BTN_BLUE) == 0) {
   valid_route = true;
   sky.btn_blue();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CHUP) == 0) {
   valid_route = true;
   sky.btn_chup();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CHDOWN) == 0) {
   valid_route = true;
   sky.btn_chdown();
  }
  
    else if (strcmp(uri, ROUTE_BTN_CHRETURN) == 0) {
   valid_route = true;
   sky.btn_chreturn();
  }
  
   


  else if (strcmp(uri, ROUTE_COMMANDS) == 0) {
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
