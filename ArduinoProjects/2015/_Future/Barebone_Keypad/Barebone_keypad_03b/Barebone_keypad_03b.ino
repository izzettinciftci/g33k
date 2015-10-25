// Barebones keyboard v03.0
// V3 - uses UsbKeyboard library instead of Leonardo's built-in Keyboard library

// If you need a key code that is not in the usbKeyboard.h, look here, and add it below
// https://github.com/technomancy/orestes/blob/master/usb_keyboard.h
#define KEY_CAPS_LOCK   57

int rowPins[] = {14, 15, 16, 17}; // aka A0..A3
int columnPins[] = {0, 1, 3, 6, 7, 8, 9, 10, 11, 12}; // We skipped 2,4,5 so they can be used by the USB keyboard
int shiftPin = 18; // aka A4
int redShiftPin = 19; // aka A5

//*** COMMENT THIS NEXT LINE TO COMPILE USBKEYBOARD UNDER OLD Arduino IDE ***
//#define LEONARDO

#ifdef LEONARDO
#define HIT Keyboard.press
#else
#include "UsbKeyboard.h"
#define HIT UsbKeyboard.sendKeyStroke
#endif

// If the timer isr is corrected
// to not take so long change this to 0.
#define BYPASS_TIMER_ISR 1

void setupKeyboard() {
#ifdef LEONARDO
  Keyboard.begin();
#else
#if BYPASS_TIMER_ISR
  // disable timer 0 overflow interrupt (used for millis)
  TIMSK0 &= !(1 << TOIE0); // ++
#endif
#endif
}


#if BYPASS_TIMER_ISR
void delayMs(unsigned int ms) {
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
#endif

void setup() {
  setupKeyboard();

  for (byte c = 0; c < 10; c++)
  {
    pinMode(columnPins[c], OUTPUT);
    digitalWrite(columnPins[c], LOW);
  }
  for (byte r = 0; r < 4; r++)
  {
    pinMode(rowPins[r], INPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  // Shift Key
  pinMode(shiftPin, INPUT);
  digitalWrite(shiftPin, HIGH);

  // Red Shift Key
  pinMode(redShiftPin, INPUT);
  digitalWrite(redShiftPin, HIGH);
}

void loop() {
#ifndef LEONARDO
  UsbKeyboard.update();
#endif
  
  //digitalWrite(13, !digitalRead(13)); // I don't understand this, but it's in Oxer's code
  
  for (byte c = 0; c < 10; c++)
  {
    digitalWrite(columnPins[c], LOW);
    for (byte r = 0; r < 4; r++)
    {
      if (digitalRead(rowPins[r]) == 0)
      {
	    int Mods = Shift() + RedShift();

        if (r == 0 && c == 0) {
          HIT(KEY_1, Mods);
        }
        if (r == 0 && c == 1) {
          HIT(KEY_2, Mods);
        }
        if (r == 0 && c == 2) {
          HIT(KEY_3, Mods);
        }
        if (r == 0 && c == 3) {
          HIT(KEY_4, Mods);
        }
        if (r == 0 && c == 4) {
          HIT(KEY_5, Mods);
        }
        if (r == 0 && c == 5) {
          HIT(KEY_6, Mods);
        }
        if (r == 0 && c == 6) {
          HIT(KEY_7, Mods);
        }
        if (r == 0 && c == 7) {
          HIT(KEY_8, Mods);
        }
        if (r == 0 && c == 8) {
          HIT(KEY_9, Mods);
        }
        if (r == 0 && c == 9) {
          HIT(KEY_0, Mods);
        }
        //Second Column
        if (r == 1 && c == 0) {
          HIT(KEY_Q, Mods);
        }
        if (r == 1 && c == 1) {
          HIT(KEY_W, Mods);
        }
        if (r == 1 && c == 2) {
          HIT(KEY_E, Mods);
        }
        if (r == 1 && c == 3) {
          HIT(KEY_R, Mods);
        }
        if (r == 1 && c == 4) {
          HIT(KEY_T, Mods);
        }
        if (r == 1 && c == 5) {
          HIT(KEY_Y, Mods);
        }
        if (r == 1 && c == 6) {
          HIT(KEY_U, Mods);
        }
        if (r == 1 && c == 7) {
          HIT(KEY_I, Mods);
        }
        if (r == 1 && c == 8) {
          HIT(KEY_O, Mods);
        }
        if (r == 1 && c == 9) {
          HIT(KEY_P, Mods);
        }
        //third column
        if (r == 2 && c == 0) {
          HIT(KEY_A, Mods);
        }
        if (r == 2 && c == 1) {
          HIT(KEY_S, Mods);
        }
        if (r == 2 && c == 2) {
          HIT(KEY_D, Mods);
        }
        if (r == 2 && c == 3) {
          HIT(KEY_F, Mods);
        }
        if (r == 2 && c == 4) {
          HIT(KEY_G, Mods);
        }
        if (r == 2 && c == 5) {
          HIT(KEY_H, Mods);
        }
        if (r == 2 && c == 6) {
          HIT(KEY_J, Mods);
        }
        if (r == 2 && c == 7) {
          HIT(KEY_K, Mods);
        }
        if (r == 2 && c == 8) {
          HIT(KEY_L, Mods);
        }
        if (r == 2 && c == 9) {
          HIT(KEY_ENTER, Mods);
        }
        //Fourth Column
        if (r == 3 && c == 0) {
          HIT(KEY_CAPS_LOCK, Mods);
        }
        if (r == 3 && c == 1) {
          HIT(KEY_Z, Mods);
        }
        if (r == 3 && c == 2) {
          HIT(KEY_X, Mods);
        }
        if (r == 3 && c == 3) {
          HIT(KEY_C, Mods);
        }
        if (r == 3 && c == 4) {
          HIT(KEY_V, Mods);
        }
        if (r == 3 && c == 5) {
          HIT(KEY_B, Mods);
        }
        if (r == 3 && c == 6) {
          HIT(KEY_N, Mods);
        }
        if (r == 3 && c == 7) {
          HIT(KEY_M, Mods);
        }
        if (r == 3 && c == 8) {
          //HIT(KEY_RIGHT_SHIFT, Mods); This should be wired to ShiftPin, not scanned
        }
        if (r == 3 && c == 9) {
          HIT(KEY_SPACE, Mods);
        }
        while (digitalRead(rowPins[c]) == 0) delay(10);

        #ifdef LEONARDO
        Keyboard.releaseAll();
        #endif
      }
    }
    digitalWrite(columnPins[c], HIGH);
  }

#ifndef LEONARDO
#if BYPASS_TIMER_ISR  // check if timer isr fixed.
  delayMs(20);
#else
  delay(20);
#endif
#endif
}

int Shift()
{
  return digitalRead(shiftPin) == 0 ? MOD_SHIFT_RIGHT : 0;
}

int RedShift()
{
  return digitalRead(redShiftPin) == 0 ? MOD_SHIFT_LEFT : 0;
}

