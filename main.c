#include <stdio.h>
#include "pico/stdlib.h"
#include "picoRGB.h"
#include "define.h"

/*

Please edit define.h with your settings.

The functions you will use are:

- strip_init() : initialize the ws2812 strip with the settings you provided in the define.h file.
- strip_set_led_color(LED, R, G, B) : set the led specified by the "LED" parameter to a certain RGB value.
- strip_clear() : set all leds to off.
- strip_update(): send data to the strip, this is needed every time you want to see your changes on the strip.

Hey, if you specify the wrong settings in define.h like the wrong NUMLEDS (or obviously STRIP_PIN) the strip. 
will not work properly, so pay attention.

Remember to use the strip_update() function every time you need or you will not see changes on the strip

*/

int main(){

    /*This is just a demo*/

    strip_init();
    
    for(uint8_t i = 0; i < NUMLEDS; i++){

        strip_set_led_color(i, 0, 100, 0);
        strip_update();
        sleep_ms(50);

    }

    strip_clear();
    strip_update();

    for(uint8_t i = NUMLEDS; i > 0; i--){

        strip_set_led_color(i, 0, 100, 0);
        strip_update();
        strip_clear();
        strip_update();
        sleep_ms(50);

    }    
    
    strip_clear();
        
    strip_set_led_color(0, 0, 100, 0);
    strip_set_led_color(NUMLEDS - 1 , 0, 100, 0);
    strip_update();
    sleep_ms(500);
    strip_clear();
    strip_update();
    sleep_ms(200);
    strip_set_led_color(0, 0, 100, 0);
    strip_set_led_color(NUMLEDS - 1 , 0, 100, 0);
    strip_update();
    sleep_ms(500);
    strip_clear();
    strip_update();
    
    
}