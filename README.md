Mastermind – EECE 2560 Project
Overview

This project implements the game Mastermind, where the user plays as the codebreaker and the computer acts as the codemaker. The codemaker generates a random sequence of digits, and the codebreaker attempts to guess it within ten tries. After each guess, the codemaker provides feedback:

Correct digits in the correct position

Correct digits in the wrong position

The program is written in C++ and uses modular, object-oriented design.

Features

Code class to store and manipulate secret codes and guesses.

Random code generation based on user-specified length (n) and digit range (m).

Functions to check guesses for correct and misplaced digits.

A main() driver that demonstrates the functionality with sample guesses.

Part A

Implements the Code class.

Provides functions:

checkCorrect() → digits correct in the right spot.

checkIncorrect() → digits correct but in the wrong spot.

Includes a main() function that initializes a secret code and tests three sample guesses:

(5, 0, 3, 2, 6)

(2, 1, 2, 2, 2)

(1, 3, 3, 4, 5)

