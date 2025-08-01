#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define F_CPU 16000000UL

#define INC_BTN   PD2
#define DEC_BTN   PD3
#define PAUSE_BTN PD4
#define RESET_BTN PD5

#define RED_LED   PC0
#define GREEN_LED PC1
#define BLUE_LED  PC2

#define BUZZER    PC5
#define SEG_CTRL  PC6

int seg_digits[8] = {
    0b01111110,
    0b00001100,
    0b10110110,
    0b10011110,
    0b11001100,
    0b11011010,
    0b11111010,
    0b00001110
};

void init_ports() {
    DDRA = 0xFE;
    DDRC = 0xFF;
    DDRD &= 0b11000011;
    PORTD |= 0b00111100;
}

int is_pressed(int pin) {
    if (!(PIND & (1 << pin))) {
        _delay_ms(30);
        if (!(PIND & (1 << pin))) return 1;
    }
    return 0;
}

void display_number(int num) {
    if (num < 8) {
        PORTA = (PORTA & ~(0xFE)) | (seg_digits[num] & 0xFE);
        PORTC |= (1 << SEG_CTRL);
    }
}

void update_leds(int num) {
    if (num & 0x01) PORTC |= (1 << RED_LED); else PORTC &= ~(1 << RED_LED);
    if (num & 0x02) PORTC |= (1 << GREEN_LED); else PORTC &= ~(1 << GREEN_LED);
    if (num & 0x04) PORTC |= (1 << BLUE_LED); else PORTC &= ~(1 << BLUE_LED);
}

void buzz(int times) {
    for (int i = 0; i < times; i++) {
        PORTC |= (1 << BUZZER);
        _delay_ms(500);
        PORTC &= ~(1 << BUZZER);
        _delay_ms(500);
    }
}

void flash_leds(int times) {
    for (int i = 0; i < times; i++) {
        PORTC |= (1 << RED_LED) | (1 << GREEN_LED) | (1 << BLUE_LED);
        _delay_ms(700);
        PORTC &= ~((1 << RED_LED) | (1 << GREEN_LED) | (1 << BLUE_LED));
        _delay_ms(700);
    }
}

int main(void) {
    int number = 0;
    char paused = 0;
    init_ports();
    display_number(number);
    update_leds(number);

    while (1) {
        if (is_pressed(PAUSE_BTN)) {
            paused = !paused;
            while (is_pressed(PAUSE_BTN));
        }

        if (!paused) {
            if (is_pressed(INC_BTN)) {
                if (number < 7) {
                    number++;
                    display_number(number);
                    update_leds(number);
                } else {
                    buzz(3);
                }
                while (is_pressed(INC_BTN));
            }

            if (is_pressed(DEC_BTN)) {
                if (number > 0) {
                    number--;
                    display_number(number);
                    update_leds(number);
                } else {
                    buzz(3);
                }
                while (is_pressed(DEC_BTN));
            }
        }

        if (is_pressed(RESET_BTN)) {
        	paused = 0;
            flash_leds(3);
            number = 0;
            display_number(number);
            update_leds(number);
            while (is_pressed(RESET_BTN));
        }
    }
}
