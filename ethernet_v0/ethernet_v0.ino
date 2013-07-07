/*
 * Send SMS Message to Phone
*/
#include <Ethernet.h>
#include <SPI.h>

#define TROPO_SMS_TOKEN "24af4542882a1d4a8a9f510ca8e83b569bf62c5f6998ddd5d23d58a5715bf703238f961c6f0c2c345507b99b"

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x25, 0x69};
byte ip[] = {192, 168, 1, 90}; //home LAN

char server[] = "api.tropo.com";

//Initialize the Ethernet client library
EthernetClient client;

void setup()
{
  Serial.begin(9600);
  //Wait 8 seconds for the serial port to be estabilished (for Leonardo)
  while(!Serial && millis() < 8000) {}
  
  //Start the Ethernet connection
  Ethernet.begin(mac, ip);
  Serial.println(Ethernet.localIP());
  
  //give the Ethernet shield a second to initialize
  delay(1000);
  
  char mySMS[25];
  char mySMS1[2];
  strcpy(mySMS, "From+Arduino");
  strcpy(mySMS1, "83");
  sendSMS(mySMS);
}

void loop()
{
}

//client function to send/receive GET request data.
void sendSMS(char txtSMS[])
{
  //starts client connection, checks for connection
  if (client.connect(server, 80))
  {
    Serial.println(F("connected"));
    
    client.print("GET /1.0/session?action=create&token=");
    client.print(TROPO_SMS_TOKEN);
    client.print("&phone=8144037724&msg=");
    client.print(txtSMS);
    client.println(" HTTP/1.0");
    client.println("Host: api.tropo.com");
    client.println(); 
  }
  else
  {
    Serial.println(F("Connection failed"));
  }
  
  while(client.connected() && !client.available()) delay(1);
  
  while(client.connected() || client.available())
  {
    char c = client.read();
    Serial.print(c);
  }
  
  Serial.print(F("\n\ndisconnecting.\n"));
  client.stop();
}
