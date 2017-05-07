/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>


//const char* ssid = "shofe";
//const char* password = "@root@001";

const char* ssid = "CASA_NETWORK";
const char* password = "8fc51f86x2";



/*
const char* ssid = "AndroidAP";
const char* password = "danilo12";
*/
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.setRxBufferSize(1024);
  Serial.begin(9600);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data

  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  //Serial.println(req);

  
  client.flush();

   while (Serial.available()) {
     char c = Serial.read();
   }

 String url = getUrl(req);

 char bufUrl[url.length()];

 url.toCharArray(bufUrl,url.length()+1);



 if(url.equals("/favicon.ico") == false){
  
   Serial.println(bufUrl);
 }

//First build the  response header
String s = "HTTP/1.1 200 OK\r\n";
s += "Access-Control-Allow-Origin: *\r\n";
s += "Content-Type: application/json\r\n\r\n";

/*
int val = 1;
  // Prepare the response
  s = "{\"json\":\"test\"}";
*/

//delay(250);

long timeout = millis();

while(millis() - timeout < 400){
  if (Serial.available() > 0)
    break;
}

while (Serial.available()) {
     char c = Serial.read();
     if (isprint(c))
       s += c;
     delay(2);
  }

  s = s+'\n';

  //Serial.println(s);
 Serial.flush();
  

  
  // Send the response to the client
  client.print(s);
  delay(1);
  s = "";



  


  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}



String getUrl(String str){

  String url = "";
  String delimiter = " ";
  int index = 0;
  
  while(true){
    int aux = str.indexOf(delimiter,index);

    String token = str.substring(index,aux);
    if (!(token.equalsIgnoreCase("GET") || token.equalsIgnoreCase("HTTP/1.1") || token.equals(""))){
      url = token;
    }
    
    if(aux == -1) break;
    index = aux+1;  

  }

  return url;
  
  
}




