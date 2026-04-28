# C++ Class Logic & Operator Overloading
## University Assignment - Object Oriented Programming 2

A collection of advanced C++ modules emphasizing class design, the Rule of Three (Constructors, Destructors, Copy Constructors), and technical problem-solving. This project demonstrates how to build scalable and reusable components without using the STL.

---

## 🚩 Project Modules

### 1. Custom Dynamic Array Class
A robust implementation of a dynamic integer array (`Array` class) that handles its own memory management.
* **Features:** `push_back`, `pop_back`, `insert`, `erase`, `sort`, and `reverse`.
* **Deep Copying:** Includes a custom copy constructor to ensure data integrity during object assignment.
* **Sub-Arrays:** Ability to extract segments of an array using both object-return and pointer-return methods.

### 2. Rational Number Arithmetic
An implementation of a `Rational` class for precise fraction arithmetic.
* **Operator Overloading:** Overloads `+`, `-`, `*`, and `/` to allow intuitive math operations between fraction objects.
* **Auto-Reduction:** Uses Euclidean-style logic (HCF/GCD) to maintain fractions in their simplest form.
* **Error Handling:** Protects against division by zero and invalid denominators.

### 3. Tap Code Communication Engine
A cryptography tool that mimics the "Tap Code" system used by prisoners to communicate.
* **Logic:** Maps the alphabet to a 5x5 Polybius square grid (treating 'K' as 'C').
* **Two-Way Conversion:** Encodes plain text into numeric tap sequences and decodes numeric sequences back into strings.

### 4. C++ Trivia Quiz System
A modular quiz game demonstrating **Class Composition**.
* **Question Class:** Encapsulates question text, multiple-choice options, and the correct answer index.
* **Game Logic:** A two-player competitive system that tracks scores and determines a winner based on correct responses.

### 5. Chocolate Wrapper Optimization (Logic Task)
A recursive/iterative algorithm to solve the "Maximum Chocolate" problem, calculating the total yield based on purchase price and wrapper exchange rates.

---

## 🛠 Technical Skills
* **Encapsulation:** Extensive use of `private` members and `public` getters/setters.
* **Memory Safety:** Manual management of heap memory with `new[]` and `delete[]` to prevent leaks.
* **Bitwise Swapping:** Use of the XOR swap algorithm (`a = a ^ b`) in the `reverse` and `sort` functions.
* **Modularization:** Use of `#ifndef` and `#pragma once` header guards for clean compilation.

---

## 📂 File Architecture
* `Array.h`: Dynamic array logic and deep copy implementation.
* `Question.h/cpp`: Quiz object definition and implementation.
* `Rational.h`: Operator overloading and fraction logic.
* `Tapcode.h`: Cryptography matrix and string manipulation.
* `main.cpp`: Entry point for testing all assignment questions.

---

## 🚀 How to Run
1. Ensure you have a C++ compiler installed (GCC/Clang).
2. Compile all source files:
   ```bash
   g++ main.cpp Question.cpp -o oop_assign_2
