#include <avr/io.h>
#include <util/delay.h>
#include "RF24.h"


#define LED PORTB4

#define CE_PIN 3
#define CSN_PIN 3


#define set(x) |= (1<<x)
#define clr(x) &=~(1<<x)
#define inv(x) ^=(1<<x)

RF24 radio(CE_PIN, CSN_PIN);

byte address[11] = "SimpleNode";
unsigned long payload = 0;

void setup() {
  DDRB set(DDB4);
  PORTB clr(LED);
  radio.begin(); // Start up the radio
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.setRetries(15,15); // Max delay between retries & number of retries
  radio.openWritingPipe(address); // Write to device address 'SimpleNode'
}

void loop() {
  for(;;) {
    PORTB inv(LED);
    _delay_ms(1000);
    payload++;
    radio.write( &payload, sizeof(unsigned long) ); //Send data to 'Receiver' ever second
  }
}

int main() {
  setup();
  loop();
}
