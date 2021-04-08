# PicoRGB
A small and easy to use C library to control ws2812 RGB led strips with Raspberry Pi Pico, C SDK.

This """Library""" is based on the official example: pico_example/pio/ws2812, is just more usable and ready-to-go, you have 5 simple function to do whatever you want with your ws2812 addressable RGB led strip.

To use this example you first need to create the project using the pico project generator, then create the files shown in this repository calling them with the same names, and copy-paste the content.
Pay extra attention to the CmakeLists.txt file, if you simply copy-paste it you will have errors: set(PICO_SDK_PATH...) has to be the one of your machine so remove mine from the file!

Also, edit the define.h file with your settings (it's embarrassingly simple).

The functions you will use are:

- strip_init() : initialize the ws2812 strip with the settings you provided in the define.h file.
- strip_set_led_color(LED_NUMBER, R, G, B) : set the led specified by the "LED_NUMBER" parameter to a certain RGB value.
- strip_clear() : set all leds to off.
- strip_update(): send data to the strip, this is needed every time you want to see your changes on the strip.

Hey, if you specify the wrong settings in define.h like the wrong NUMLEDS (or obviously STRIP_PIN) the strip. 
will not work properly, so pay attention.

Remember to use the strip_update() function every time you need or you will not see changes on the strip.



