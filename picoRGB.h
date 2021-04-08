#include<stdint.h>

#ifndef PICORGB_H
#define PICORGB_H

    void strip_init();
    void strip_set_led_color(uint8_t led_number, uint8_t R, uint8_t G, uint8_t B);
    void strip_update();
    void strip_clear();
    void strip_print_debug(uint16_t time_between_prints);
        
#endif