#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int dinopos = 3;
int cactuspos = 15;
bool gameover = 0;
bool jumping = 0;
int jumpcount = 0;
int gamescore = 0;

byte dino[8] = {
  B00111,
  B00111,
  B00111,
  B10110,
  B11111,
  B11110,
  B01010,
  B01010,
};

byte cactus[8] = {
  B00100,
  B01110,
  B01111,
  B01111,
  B11110,
  B11110,
  B01110,
  B01110,
};

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.createChar(0,dino);
  lcd.createChar(1,cactus);
}

void loop() {
  
  if (cactuspos == dinopos && !jumping) {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("GAME OVER");
    lcd.setCursor(0,1);
    lcd.print("press 'a' to start");
    gameover = 1;
    gamescore = 0;
  }

  if (gameover) {
    while (true) {
      if (Serial.available()) {
        char ch = Serial.read();
        if (ch == 'a') {
          gameover = 0;
          cactuspos = 15;
          lcd.clear();
          break;
        }
      }
    }
  }

  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == 'j' && !jumping) {
      jumping = true;
      jumpcount = 3;
    }
  }

  if (jumping) {
    if (jumpcount > 0) {
      lcd.setCursor(dinopos, 0);  
      lcd.write(byte(0));
      jumpcount--;
    } else {
      jumping = false;
    }
  } else {
    lcd.setCursor(dinopos, 1);  
    lcd.write(byte(0));
  }

  lcd.setCursor(cactuspos, 1);
  lcd.write(byte(1));
  cactuspos--;
  if (cactuspos < 0) cactuspos = 15;
  lcd.setCursor(10,0);
  lcd.print("G.S=");
  lcd.print(gamescore);
  gamescore++;
  delay(400);  
  lcd.clear();
}
