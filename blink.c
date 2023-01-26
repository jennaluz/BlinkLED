/*
 *
 */

#include <pico/stdlib.h>    // hardware/gpio.h  pico/time.h

void dot(const uint LED_PIN);
void dash(const uint LED_PIN);

int main()
{
#ifndef PICO_DEFAULT_LED_PIN
#warning blink requires a board with an LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // morse code S
        for (int i = 0; i < 3; i++) {
            dot(LED_PIN);
        }

        sleep_ms(300);

        // morse code O
        for (int i = 0; i < 3; i++) {
            dash(LED_PIN);
        }

        sleep_ms(300);

        // morse code S
        for (int i = 0; i < 3; i++) {
            dot(LED_PIN);
        }

        sleep_ms(900);
    }
#endif
}

void dash(const uint LED_PIN)
{

    gpio_put(LED_PIN, 1);
    sleep_ms(450);
    gpio_put(LED_PIN, 0);
    sleep_ms(150);
}

void dot(const uint LED_PIN)
{
    gpio_put(LED_PIN, 1);
    sleep_ms(150);
    gpio_put(LED_PIN, 0);
    sleep_ms(150);
}
