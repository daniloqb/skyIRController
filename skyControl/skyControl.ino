

#include "helperfunctions.h"
#include "System_debug.h"
#include "SkyControllerDriver.h"

#include <aJSON.h>

#define MAIN_ROUTE "/"


char * processMessage(char * uri, UrlParams url_params);
void checkSystem();

char * main_route(char * uri);
char * get_devices();
char * get_errorMessage();



System sys;
Sky sky;
SkyControllerDriver driver(&sky);

void setup() {


  sys.begin();
  driver.begin();

}



void loop() {

  char * msg;

  if (sys.get_data()){
        
    //DEBUG
    Serial.print("URL: "); 
    Serial.println(sys.get_url());
    mem();

    //Caso haja dados vai para processamento.
    msg =  processMessage(sys.get_uri(),sys.get_params());
    sys.send_response(msg);
    mem();
  } 
  else {
    checkSystem();
  }

}



void checkSystem() {

  driver.update();


}


/*
   Esta funcao faz o processamento dos dados.
   Verifica se a URI que chegou corresponde
   a alguma URI do sistema.
   Caso combine, faz uma chamada a funcao correspondente
   a URI
*/
char * processMessage(char * uri, UrlParams url_params) {

  char * response = NULL;


  response = main_route(uri);

  if(response == NULL){
    response = driver.process_message(uri, url_params); 
  }

  if(response == NULL){
    response = get_errorMessage();
  }

  // esta funcao retorna uma String JSON que recebeu das funcoes de processamento.
  return response;

}


/*
   Funcao que retorna ao cliente as informacoes que foram processadas pelo sistema.
*/



char * main_route(char * uri){
  
  char * response = NULL;

  if (strcmp(uri, MAIN_ROUTE) == 0) {
    response =   get_devices();

  }
  return response;
}


/*

   DEVICES FUNCTIONS

*/




char * get_devices() {


  char * response;

  aJsonObject *root = aJson.createObject();   
         
  aJsonObject *devices = aJson.createArray();
  
  aJsonObject *device_1 = aJson.createObject();
  aJson.addStringToObject(device_1, "name", driver.get_name());
  aJson.addStringToObject(device_1, "route", driver.get_main_route());
  aJson.addItemToArray(devices,device_1);
  
  aJson.addItemToObject(root, "devices", devices); 
 
  response = aJson.print(root);                     
  
  aJson.deleteItem(root);       


  
  return response;                                  

}

/*
   FUNCAO DE ERRO
   Retorna uma mensagem padrao quando a URI chegada nao corresponde
   a nenhuma URI do sistema
*/
char * get_errorMessage() {

  char * response;

  /*
     Por enquanto estamos utilizando a strutura da biblioteca aJSON.
     Neste caso como se trata de uma string padrao, nao necessitaria
     de utilizar a biblioteca.
  */
  aJsonObject *root;
  root = aJson.createObject();

  aJson.addStringToObject(root, "error", "Invalid command.");
  response = aJson.print(root);
  aJson.deleteItem(root);

  return response;


}





















