# Dino_Game_Arduino
Chrome Dino-style game built on Arduino Uno using 16x2 LCD using keys on laptop
# 🦖 Arduino LCD Dino Game

A simple recreation of the Chrome Dino game on a 16×2 LCD using an Arduino Uno.  
The dino jumps over moving obstacles (cactus), and the score increases for each successful jump.

---

## 🎯 Motivation
I built this to practice embedded programming fundamentals on low-cost hardware and to explore animation on character LCDs. The project helped me learn how to think about game flow on a microcontroller with very limited display capabilities.

---

## ⚙️ Components Used
- Arduino Uno (or compatible)
- 16×2 character LCD (HD44780-compatible)
- Push button (for jump)
- 10 kΩ pull-down or pull-up resistor
- Breadboard and jumper wires
- (Optional) Buzzer for sound effects

---

## 🧩 How It Works (high level)
1. The LCD shows the dino (player) and a moving cactus (obstacle) using custom characters.
2. The cactus moves from right to left at a fixed interval.
3. When the player presses the button, the dino performs a jump sequence (state machine).
4. Collision detection checks overlap between cactus position and dino position — on collision, game over.
5. Score increments for each avoided cactus.

---

## 🔧 Wiring
- LCD RS, E, D4–D7 → connect as per LiquidCrystal example (match pins in your `DinoGame.ino`)
- Button → connect to a digital input pin with proper pull-up/pull-down resistor
- VCC → 5V, GND → GND
- Contrast (VO) → Potentiometer between 5V and GND (middle pin to VO) for best visibility

(Include a photo or diagram in `Images/` for clarity.)

---

## 🧠 What I Learned / Interesting Bits
- Creating custom characters with `lcd.createChar()` was especially interesting — it involves imagining the game process step by step and then writing the corresponding bit patterns.  
- I learned how to design small figures using bitmaps (bits/bytes) to represent characters on the LCD.
- Learned about timing and synchronization for animation on a microcontroller.
- Implemented a simple state machine for jump logic and obstacle movement.
- Solved flicker issues and optimized redraws to make animations smooth.

---

## 🛠 Features
- Custom-character dino sprite
- Moving obstacle (cactus)
- Jump mechanics with basic physics-like timing
- Score display

---

## ▶️ Demo  
[Watch demo on Google Drive](https://drive.google.com/file/d/1o_6Ygc-TIptmiN6EkTSWZGFndR89kcgo/view?usp=drive_link)

---

## 📂 Project Structure
