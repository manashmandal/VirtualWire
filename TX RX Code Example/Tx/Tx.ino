//simple Tx on pin D12
// Manash
#define LED 13
#define TX_PIN 12
#include <VirtualWire.h>

char *controller;

void setup() {
  pinMode(LED, OUTPUT);
  
  vw_set_ptt_inverted(true); 
  vw_set_tx_pin(TX_PIN);
  
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  controller= "1";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  
  digitalWrite(13,1);
  delay(2000);
  controller="0";
  
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  
  digitalWrite(LED, LOW);
  delay(2000);
}
