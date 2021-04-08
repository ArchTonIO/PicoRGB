#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "picoRGB.h"
#include "define.h"

//uint8_t NUMLEDS; //number of leds in the led strips
//uint8_t* NUMLEDS_ptr = &NUMLEDS; // pointer to the memory address of NUMLEDS

typedef struct led{ //structure RGB_led to store each led R, G, and B values

    uint8_t R_value;
    uint8_t G_value;
    uint8_t B_value;

}RGB_led;

RGB_led led_strip[NUMLEDS];

static inline void set_led(uint32_t pixel_grb){

  pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);

}

static inline uint32_t pack_rgb(uint8_t r, uint8_t g, uint8_t b){

  return ((uint32_t)(r) << 8) |
         ((uint32_t)(g) << 16) |
         (uint32_t)(b);

}

void strip_init(){
   
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    char str[12];
    ws2812_program_init(pio, sm, offset, STRIP_PIN, 800000, false);

    //NUMLEDS = num_leds; //copy num_leds value in the NUMLEDS global variable
     
}

void strip_set_led_color(uint8_t led_number, uint8_t R, uint8_t G, uint8_t B){

    led_strip[led_number].R_value = R;
    led_strip[led_number].G_value = G;
    led_strip[led_number].B_value = B;

}

void strip_clear(){

    for(uint8_t i = 0; i < NUMLEDS; i++){

        strip_set_led_color(i, 0, 0, 0);       

    }

}

void strip_update(){

    for (uint8_t i = 0; i < NUMLEDS; i++){

        set_led(pack_rgb(led_strip[i].R_value, led_strip[i].G_value, led_strip[i].B_value));    

    }
 
}

void strip_print_debug(uint16_t time_between_prints){

    for (uint8_t i = 0; i < NUMLEDS; i++){

        printf("LED %d values: --> ", i);
        printf("R: %hu || ",   led_strip[i].R_value);
        printf("G: %hu || ",   led_strip[i].G_value);
        printf("B: %hu || \n", led_strip[i].B_value);
        sleep_ms(time_between_prints);

    }

}
