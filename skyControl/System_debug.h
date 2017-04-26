#ifndef SYSTEM_H
#define SYSTEM_H

#include "Arduino.h"
#include <SoftwareSerial.h>



/*************************
   VARIAVEIS DO SISTEMA
 *************************/

/*
     Numero maximo de parametros que o sistema ira aceitar.
*/
const byte MAX_PARAMS = 2;  // Quantidade de parametros aceito pelo sistema
const byte MAX_URL = 255;  // Tamanho maximo da URL de entrada
const byte MAX_URI = 100;  // tamanho maximo da URI que sera utilizada como rota
const byte MAX_PARAM_NAME = 20; //tamanho maximo dos campos de parametro

const byte RX_PIN = 7;
const byte TX_PIN = 8;
const int  BAUNDRATE = 9600;


typedef struct param {
  char name[MAX_PARAM_NAME];
  char value[MAX_PARAM_NAME];

} Params;



void split_url(char  * url, char * uri, Params *params);

class UrlParams {

  private:

  public:
    Params _params[MAX_PARAMS];
    void clear_all();
    char * get_param(char * name);
};


char * UrlParams::get_param(char *name) {


  for (int i = 0; i < MAX_PARAMS; i++) { //faz uma busca pela estrutura de parametros

    if (strcmp(_params[i].name, name) == 0) {
      return _params[i].value;
    }
  }

  return NULL;

}

void UrlParams::clear_all() {

  for (int i = 0; i < MAX_PARAMS; i++) {
    strcpy(_params[i].name, '\0');
    strcpy(_params[i].value, '\0');
  }
}






class System {

  private:
    char _url[MAX_URL];
    char _uri[MAX_URI];
    UrlParams _url_params;
   // SoftwareSerial * _my_serial;
    void _init_vars();
    void _process_url();

  public:
    System();    
    void begin();
    boolean get_data();
    char * get_url();
    char * get_uri();
    void send_response(char *msg);
    UrlParams get_params();


};


System::System() {

}


void System::begin() {

  Serial.begin(BAUNDRATE);

 // _my_serial = new SoftwareSerial(RX_PIN, TX_PIN);
//  _my_serial->begin(BAUNDRATE);

  _init_vars();


}

void System::_init_vars() {


  for (int i = 0; i < MAX_URI; i++) {
    _uri[i] = '\0';
  }

  /*
    for (int i = 0; i < MAX_PARAMS; i++) {
      strcpy(_params[i].name, '\0');
      strcpy(_params[i].value, '\0');
    }

  */

  _url_params.clear_all();

}
boolean System::get_data() {

  //char buff[MAX_URL];
  int index = 0;
  char c;





  if (Serial.available() > 0) {

    for (int i = 0; i < MAX_URI; i++) {
      _url[i] = '\0';
    }



    while (Serial.available()) {
      c = Serial.read();

 
      delay(10);
      if ((c != '\r' && c != '\n') && index < MAX_URL) {
        _url[index++] = c;
      }


    }
    //retorna os dados;
    _process_url();
    return true;

  }
  // se nao houver dados retorna null.
  return false;



}



void System::send_response(char * msg) {


  //Verifica qual o tamando da mensagem.
  int size_msg = strlen(msg);

  // limpa o buffer da serial??? Sera que limpa mesmo?
  Serial.flush();


  for (int i = 0; i < size_msg; i++) {
    Serial.print(msg[i]);
    delay(1);
  }
  //Envia um caractere de nova linha, indicando o fim do envio.
  Serial.println();



  free(msg);

}


void System::_process_url() {

  _init_vars();
  split_url(_url, _uri, _url_params._params);
}



char * System::get_url() {
  return _url;
}

char * System::get_uri() {

  return _uri;
}

UrlParams System::get_params(){
  return _url_params;
}


/*
   ESTA FUNCAO faz o processamento da URL vinda da serial
   divide em : URI que sera utilizada como rota
   PARAMETROS que foram passados pela url.
*/
void split_url(char  * url, char * uri, Params *params) {


  char * raw_params[MAX_PARAMS];            // string dos parametros
  char * token;                             // recebe os blocos de dados

  int num_params = 0;                       // index dos parametros

  // init_vars();                              // limpa as variaveis globais URI e PARAMS

  token = strtok(url, "?");                 // divide a URL em dois. URI e parametros
  strncpy(uri, token, MAX_URI);                 // copia a rota para a variavel global uri
  token = strtok(NULL, "?");                // avanca para o proximo bloco de texto


  token = strtok(token, "&;");              // comeca a divisao dos parametros

  while (token != NULL && num_params < MAX_PARAMS) { // enquanto houver tokens ou o nao atingir o numero maximo de parametros continua
    raw_params[num_params] = token;       // divide os pares de parametros nome=valor
    token = strtok(NULL, "&;");           // avanca para o proximo bloco
    num_params++;                         // atualiza o indice
  }

  for (int i = 0; i < num_params; i++) {    // divide os blocos de parametros em nome e valor

    token = strtok(raw_params[i], "=");     // procura blocos com '=' e salva na estrutura de parametros
    strncpy(params[i].name, token, MAX_PARAM_NAME);     // salva a primeira parte em .nome
    token = strtok(NULL, "=");              // avanca o bloco de texto
    if (token != NULL) {                    // salva a proxima parte em .valor, salva como valor ou em branco.

      strncpy(params[i].value, token, MAX_PARAM_NAME);
    } else {
      strncpy(params[i].value, "", MAX_PARAM_NAME);

    }
  }

  //se a uri possuir uma barra no final, serah retirada
  if (strlen(uri) > 1) {
    if (uri[strlen(uri) - 1] == '/') {
      uri[strlen(uri) - 1] = '\0';
    }
  }
}




#endif
