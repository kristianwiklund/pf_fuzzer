# Fuzzer for Pathfinder Wrath of the Righteous Console Puzzle

## Hardware

Reuse of something I had around, if I remember right, it is this: https://codeandlife.com/2012/02/22/v-usb-with-attiny45-attiny85-without-a-crystal/

## Software

The software is based on the  Adafruit keyboard example for the adafruit trinket (which is based on attiny).
The pinouts are not identical, and the pio run will patch the usb configuration - if using with an actual trinket, comment extra_scripts in platformio.ini and change the pins in the .ino source to something suitable.

## Demo

https://youtu.be/SPMtinphBbM

## How it works

The puzzle allows an infinite number of trials without any lock-out or back-offs, so the fuzzer simply sends a string of random numbers when the button is pressed. 

## If you don't want to build a thing to brute-force the puzzle...

...simply smash 1-6 randomly until it opens. That's what I did the first three times before I got borded with killing my keyboard.



