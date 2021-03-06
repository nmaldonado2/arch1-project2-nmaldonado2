#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_change();
}

void led_change()
{
    // Turns on bits
    // if red on then obooooooo1
    // if green on then ob01000000
    char ledFlags = redVal[red_on] | greenVal[green_on];

    // 
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds

    
    P1OUT |= ledFlags;		     // set bit for on leds
   
}


void turn_on_green() {
  green_on = 1;
  red_on = 0;
  led_change();
}

void turn_on_red() {
  red_on = 1;
  green_on = 0;
  led_change();
}

void turn_off_green() {
  green_on = 0;
  led_change();
}

void turn_off_red() {
  red_on = 0;
  led_change();
}

void turn_off_green_red() {
  red_on = green_on = 0;
  led_change();
}
