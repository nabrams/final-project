/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

// You can use any (4 or) 5 pins
#define sclk 2
#define mosi 3
#define dc   4
#define cs   7
#define rst  8
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {10, 9,A5, A4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A3, A2, A1}; //connect to the column pinouts of the keypad

String bday;
int day;
int tday;
int temp;
// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define PURPLE          0x901E
#define ORANGE          0xFAA0
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include "Adafruit_Thermal.h"
#include "libra.h"
#include "SoftwareSerial.h"
#include <Keypad.h>


Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor



void setup() {
  mySerial.begin(9600);  // Initialize SoftwareSerial

  printer.begin();        // Init printer (same regardless of serial type)
  tft.begin();
  tft.fillScreen(BLACK);
  tft.setCursor(0,50);
  tft.fillScreen(BLACK);
      tft.setTextSize(1);
    tft.setTextColor(MAGENTA);
  tft.println("Welcome to the");
    tft.setTextSize(2);
    tft.setTextColor(BLUE);
  tft.println("Horoscope Reader");
  tft.setTextSize(1);
  tft.setTextColor(MAGENTA);
  tft.println("Enter your birthday");
  tft.println("followed by the '#' ");
}

void loop(){
    
    char key = keypad.getKey();
     if (key != NO_KEY){
          bday = bday + key;
          if (key == '#'){
            temp = bday.toInt();
            bday = String();
          }
    }
    if (key == '#'){
          tft.fillScreen(WHITE);
          printer.boldOn();
          printer.feed(1);
          horoscope();
          tday = day;
          if (tday == 3){
          tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(BLUE);
          tft.println("Aries");
          printer.setSize('L'); 
          printer.println(F("Your an Aries"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
           printer.justify('C');
          printer.println(F("Aries is the first sign of the zodiac. Those who are Aries are independent and courageous. They enjoy leading others and bringing excitement into the lives of others. An Aries is enthusiastic and very goal-oriented."));
          printer.feed(1);
          }
          else if (tday == 4){
          tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(GREEN);
          tft.println("Taurus");
          printer.setSize('L'); 
          printer.println(F("Your a Taurus"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
          printer.println(F("The second sign of the zodiac, those who are a Taurus are solid and fight for what they want. A Taurus is very easy going but can also be stubborn. A Taurus can be procrastinators but also have a good-work ethic."));
          printer.feed(1);
          }
          else if (tday == 5){
          tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(YELLOW);
          tft.println("Gemini");
          printer.setSize('L'); 
          printer.println(F("Your a Gemini"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
          printer.println(F("Gemini is the third sign of the zodiac. Geminis have many sides and are known for their energy. They are very talkative and are considered social butterflies. A Gemini will always take their lives in the direction they want to go."));
            printer.feed(1);
          }
          else if (tday == 6){
          tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(CYAN);
          tft.println("Cancer");
          printer.setSize('L'); 
          printer.println(F("Your a Cancer"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
          printer.println(F("Cancer is the fourth sign of the zodiac. This sign is marked by inconsistency. They enjoy security but also seek adventure. A Cancer is not very predictable and always keep others guessing."));
            printer.feed(1);
          }
          else if (tday == 7){
           tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(RED);
          tft.println("Leo");
            printer.setSize('L'); 
          printer.println(F("Your a Leo"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
          printer.println(F("Leo is the fifth sign in the zodiac. Leos have high self esteem and are very devoted. They are also very kind and generous. A Leo is known for being hot tempered yet forgiving."));
            printer.feed(1);
          }
          else if (tday == 8){
               tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(BLACK);
          tft.println("Virgo");
            printer.setSize('L'); 
          printer.println(F("Your a Virgo"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
          printer.println(F("The sixth sign of the zodiac, Virgo is very mind oriented. They are constantly analyzing and thinking. They enjoy bettering themselves and those around them."));
            printer.feed(1);
          }
          else if (tday == 9){
              tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(PURPLE);
          tft.println("Libra");
            printer.setSize('L'); 
          printer.println(F("Your a Libra"));
          printer.feed(1);
          printer.printBitmap(libra_width, libra_height, libra_data);
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("The seventh sign of the zodiac, Libras are known for their diplomatic nature. They get along well with everyone and are ambitious. They have very expensive taste and work hard to make money."));
            printer.feed(1);
          }
          else if (tday == 10){
          tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(ORANGE);
          tft.println("Scorpio");
            printer.setSize('L'); 
          printer.println(F("Your a Scorpio"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("The eight sign of the zodiac, Scorpios are very intense. They like to question everything and work hard at making sense of things. Scorpios treat others with kindness and loyalty."));
            printer.feed(1);
          }
          else if (tday == 11){
          tft.setCursor(5,50);
          tft.setTextSize(2);
          tft.setTextColor(MAGENTA);
          tft.println("Sagittarius");
            printer.setSize('L'); 
          printer.println(F("Your a Sagittarius"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("The ninth sign of the zodiac, a Sagittarius has a very positive outlook on life. They have vibrant personalities and enjoy meeting new people. They can also be reckless."));
            printer.feed(1);
          }
          else if (tday == 12){
           tft.setCursor(5,50);
          tft.setTextSize(2);
          tft.setTextColor(BLUE);
          tft.println("Capricorn");
            printer.setSize('L'); 
          printer.println(F("Your a Capricorn"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("The 10th sign of the zodiac, those who are Capricorns are marked by their ambitious nature. They have very active minds and always have to be in control of their lives."));
            printer.feed(1);

          }
          else if (tday == 1){
              tft.setCursor(5,50);
          tft.setTextSize(2);
          tft.setTextColor(YELLOW);
          tft.println("Aquarius"); 
            printer.setSize('L'); 
          printer.println(F("Your an Aquarius"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("Aquarius is the 11th sign of the zodiac. Aquarians don't always care what others think about them. They take each opportunity they have and work towards formulating new ideas."));
            printer.feed(1);
          }
         else if (tday == 2){
                tft.setCursor(5,50);
          tft.setTextSize(3);
          tft.setTextColor(GREEN);
          tft.println("Pisces"); 
          printer.setSize('L'); 
          printer.println(F("Your a Pisces"));
          printer.feed(1);
          printer.setSize('S'); 
          printer.println(F("Here is your horoscope!"));
            printer.justify('C');
            printer.println(F("Pisces is the 12th and last sign of the zodiac. Those who are Pisces are extremely sensitive and reserved. They like to escape from reality. A Pisces is a very good listener and friend."));
            printer.feed(1);
          }
      }

       
}


void horoscope(){
  int sign = temp;
  if ((sign >= 321) and (sign <=  419)){
    day= 3;
    int sign;
}
  else if ((sign >= 420) and (sign <=  520)){
    day= 4;
        int sign;
}
  else if ((sign >= 521) and (sign <=  620)){
    day= 5;
        int sign;
}
  else if ((sign >= 621) and (sign <=  722)){
    day= 6;
        int sign;
}
  else if ((sign >= 723) and (sign <=  822)){
    day= 7;
        int sign;
}
  else if ((sign >= 823) and (sign <=  922)){
    day= 8;
        int sign;
}
  else if ((sign >= 923) and (sign <=  1022)){
    day= 9;
        int sign;
}
  else if ((sign >= 1023) and (sign <=  1121)){
    day= 10;
        int sign;
}
  else if ((sign >= 1122) and (sign <=  1221)){
    day= 11;
        int sign;
}
  else if ((sign >= 1222 and sign <=  1231) or (sign >=101 and sign <=119)){
    day= 12;
        int sign;
}
  else if ((sign >= 120) and (sign <=  218)){
    day= 1;
        int sign;
}
  else if ((sign >= 219) and (sign <=  320)){
    day= 2;
        int sign;
}
}
