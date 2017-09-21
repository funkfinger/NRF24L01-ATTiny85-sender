#include <avr/io.h>
#include <util/delay.h>

#define LED PORTB4

#define set(x) |= (1<<x)
#define clr(x) &=~(1<<x)
#define inv(x) ^=(1<<x)

void setup() {
  DDRB set(DDB4);
  PORTB clr(LED);
}

void loop() {
  for(;;) {
    PORTB inv(LED);
    _delay_ms(100);
  }
}

int main() {
  setup();
  loop();
}
