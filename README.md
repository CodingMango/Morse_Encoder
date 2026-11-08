# Morse_Encoder
Morse code Encoder and Transmitter (through buzzer and LED)

Morse code is the oldest method used for wireless data transfer in an encrypted format. 
I have used a piezoelectric buzzer and an LED to transmit/output the encrypted message and simultaneously the message will be printed on the serial monitor.
Arduino UNO (microcontroller) is used to encrypt messages.

![VideoCapture_20250109-103538](https://github.com/user-attachments/assets/30ef8fa4-9eb1-4ab3-b634-023e1e02d9e4)

##  Tech Stack

*   **Software/Language:** C++ (Arduino Framework)
*   **Hardware:** Arduino Uno (or compatible microcontroller), Piezo Buzzer
*   **IDE:** Arduino IDE


![m](https://github.com/user-attachments/assets/03381874-a11c-4bb2-937a-4c2d670482ea)

## Demo (click the image below)
[![Morse Code Hardware Demo](https://img.youtube.com/vi/-XiU2IRJeZI/0.jpg)](https://www.youtube.com/watch?v=-XiU2IRJeZI)

---
## Core Logic & Architecture

The system operates by receiving a text string via the Serial Monitor and processing it character by character. 

### 1. Timing Standards (20 WPM)
The project strictly adheres to the standard International Morse Code timing rules. The base unit of time (`unitTime`) is set to **60 milliseconds**, which corresponds to a transmission speed of approximately 20 Words Per Minute (WPM).

*   **Dit (·):** 1 unit (60ms)
*   **Dah (—):** 3 units (180ms)
*   **Intra-character space (between dits/dahs):** 1 unit (60ms)
*   **Inter-character space (between letters):** 3 units (180ms)
*   **Word space (between words):** 7 units (420ms)

### 2. Signal Generation
The hardware relies on the microcontroller's hardware timers to generate a square wave. The `tone()` function is used to drive a buzzer at 700Hz for the exact duration of a *dit* or *dah*, followed immediately by `noTone()` and `delay()` to enforce the required spacing between pulses.

### 3. Character Mapping
A comprehensive `switch-case` structure serves as the lookup dictionary. It maps alphanumeric characters to their respective sequences of `dit()` and `dah()` function calls, keeping memory overhead low by avoiding complex data structures.

**Message:** Hi I am an ECE Engineer
![m1](https://github.com/user-attachments/assets/ee9ba9ad-c4b8-42e8-b3a7-550c4635289b)

**Message:** Just playing with Arduino UNO
![m2](https://github.com/user-attachments/assets/eeead350-10a9-44b1-93b3-c17db87f96f4)

The Logic Behind the Morse Code Encoder is given in the Arduino sketch (file with .ino extension)

Here is the simulation of my Arduino project on "Morse Code Encoder" in Wokwi simulator:
https://wokwi.com/projects/419083685728047105

## Edge Cases Handled

*   **Case Insensitivity:** The `switch` statement uses case fall-throughs (e.g., `case 'A': case 'a':`) to ensure that both uppercase and lowercase inputs are successfully translated without requiring additional string manipulation functions.
*   **Word Boundaries:** When a space (`' '`) is detected in the input string, the code bypasses the character map and outputs a `/` to the serial monitor. It then applies a specific mathematical delay (`unitTime*7-240`) to maintain the strict 7-unit word gap while accounting for loop execution time.
*   **Unmapped/Special Characters:** If the user inputs a character not defined in the switch cases (like punctuation marks or symbols), the `switch` statement simply ignores it. No sound is produced, preventing the system from crashing or halting, though a visual space will still be printed to the monitor to indicate a skipped character.

## Future Improvements
*   Replace `delay()` with non-blocking timers (`millis()`) to allow for concurrent tasks.
*   Store the Morse dictionary in `PROGMEM` to free up dynamic SRAM.

---

Happy Learning :)
