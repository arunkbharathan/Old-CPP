/*
 * Project name:
     LED_Blinking (Simple 'Hello World' project)
 * Copyright:
     (c) Mikroelektronika, 2008.
 * Revision History:
     20080930:
       - initial release;
 * Description:
     This is a simple 'Hello World' project. It turns on/off LEDs connected to
     PORTA, PORTB, PORTC and PORTD.
 * Test configuration:
     MCU:             PIC16F887
     Dev.Board:       EasyPIC5
     Oscillator:      HS, 08.0000 MHz
     Ext. Modules:    -
     SW:              mikroC PRO for PIC
 * NOTES:
     - Turn ON the PORT LEDs at SW6. (board specific)
*/

void main() {

  ANSEL  = 0;            // Configure AN pins as digital
  ANSELH = 0;
  C1ON_bit = 0;          // Disable comparators
  C2ON_bit = 0;

  TRISA = 0x00;          // set direction to be output
  TRISB = 0x00;          // set direction to be output
  TRISC = 0x00;          // set direction to be output
  TRISD = 0x00;          // set direction to be output

  do {
    PORTA = 0x00;        // Turn OFF LEDs on PORTA
    PORTB = 0x00;        // Turn OFF LEDs on PORTB
    PORTC = 0x00;        // Turn OFF LEDs on PORTC
    PORTD = 0x00;        // Turn OFF LEDs on PORTD
    Delay_ms(1000);      // 1 second delay

    PORTA = 0xFF;        // Turn ON LEDs on PORTA
    PORTB = 0xFF;        // Turn ON LEDs on PORTB
    PORTC = 0xFF;        // Turn ON LEDs on PORTC
    PORTD = 0xFF;        // Turn ON LEDs on PORTD
    Delay_ms(1000);      // 1 second delay
  } while(1);            // Endless loop
}
