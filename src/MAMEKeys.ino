// A mini keyboard HID device to provide the standard MAME (non-player control) keys to a cabinet. Ideal for cabinets with Zero Delay Controllers to maintain default key mappings within MAME. Also includes Consumer keys for control of the system volume.  



#include "HID-Project.h"  //https://github.com/NicoHood/HID

// MAME Key assignment for the pins (// and default keyboard key in comments)
const int Coin1 = 2;    // 5
const int Coin2 = 3;    // 6
const int Player1 = 4;  // 1
const int Player2 = 5;  // 2
const int Exit = 6;     // Esc
const int Pause = 7;    // P
const int Select = 8;   // Enter (also used for digital pinball plunger)
const int Menu = 9;     // Tab
const int MameVol = 10;      // Tilde ~ (press then use joystick left/right to control MAME volume)
const int Service = 11;      // F2
const int ServiceCoin = 12;  // 9

// HID Media keys
const int VolUp = A0;    // HID System Master Volume Control Up
const int VolDown = A1;  // HID System Master Volume Control Down
const int VolMute = A2;  // HID System Master Volume Mute Toggle

// for later expansion - eg BigBox exit (Key X), mouse keys, movement
// const int Unused0 = 0;
// const int Unused1 = 1;
// const int Unused13 = 13; (optionally used - see untested comments below)
// const int UnusedA3 = A3;
// const int UnusedA4 = A4;
// const int UnusedA5 = A5;

// delay between button repeats if held down
const int ButtonRepeatDelay = 300;
const int PauseRepeatDelay = 1000;

void setup() {
  Serial.begin(9600);
 
  // Set pins to internal pull-up and assign as input
  pinMode(Coin1, INPUT_PULLUP);
  pinMode(Coin2, INPUT_PULLUP);
  pinMode(Player1, INPUT_PULLUP);
  pinMode(Player2, INPUT_PULLUP);
  pinMode(Exit, INPUT_PULLUP);
  pinMode(Pause, INPUT_PULLUP);
  pinMode(Select, INPUT_PULLUP);
  pinMode(Menu, INPUT_PULLUP);
  pinMode(MameVol, INPUT_PULLUP);
  pinMode(Service, INPUT_PULLUP);
  pinMode(ServiceCoin, INPUT_PULLUP);
  pinMode(VolUp, INPUT_PULLUP);
  pinMode(VolDown, INPUT_PULLUP);
  pinMode(VolMute, INPUT_PULLUP);

  Consumer.begin();  // Initiate consumer HID device on host

  // for later expansion - Can be used for additional custom keys to a cabinet
  // pinMode(Unused0, INPUT_PULLUP);
  // pinMode(Unused1, INPUT_PULLUP);
  // pinMode(Unused13, INPUT_PULLUP); //Optionally used to delay start of a
  // second Zero Delay Joystick Encoder pinMode(UnusedA2, INPUT_PULLUP);
  // pinMode(UnusedA3, INPUT_PULLUP);
  // pinMode(UnusedA4, INPUT_PULLUP);
  // pinMode(UnusedA5, INPUT_PULLUP);

  Keyboard.begin();

  /*
  //This section Yet to be tested - just a thought bubble, not tried/implemented

  //Optionally set Pin 13 as Output and High (5v on the ATMega32U4 boards) and
  use the output to enable power a second Zero Delay Joystick Encoder (ie cut
  the USB +5V line going to the encoder and connect the encoder board to this
  pin.) Useful if the order your zero delay encoders are detected by the OS is
  random, and P1 / P2 controls sometimes swap.

  //Pin D13 (ref C7) appears to remain low at  so until set high, power
  won't flow to the second controller. Setting the "delay(60000);" line to an
  appropriate value allows the pin to go high after the OS has ed and has
  detected the first controller.

  //DANGER Will Robinson!!! - the output will probably not have the current to
  drive the board directly - doing so would probably smoke the Leonardo board
  (or maybe just the pin). I haven't measured the current drawn by a ZD encoder
  under load, but the pin can only supply 40mA... and only 20mA for continuos
  current draw. If attempting this, use this output to drive a transistor/FET to
  supply power - and at your own risk!

  delay(60000); // millisecons - Set to at least the time it takes to  the
  OS and detect the first USB Controller digitalWrite(13, HIGH); //power pin 13
  and whatever is connected to it
  */

  Serial.println("Starting Keyboard...");
}

void loop() {
  if (digitalRead(Coin1) == LOW) {
    Keyboard.press('5');
    Serial.println("Coin1");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Coin2) == LOW) {
    Keyboard.press('6');
    Serial.println("Coin2");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Player1) == LOW) {
    Keyboard.press('1');
    Serial.println("Player1");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Player2) == LOW) {
    Keyboard.press('2');
    Serial.println("Player2");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Exit) == LOW) {
    Keyboard.press(KEY_ESC);
    Serial.println("Exit");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Pause) == LOW) {
    Keyboard.press('P');
    Serial.println("Pause");
    Keyboard.releaseAll();
    delay(PauseRepeatDelay);
  }

  if (digitalRead(Select) == LOW) {
    Keyboard.press(KEY_RETURN);
    Serial.println("Select");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Menu) == LOW) {
    Keyboard.press(KEY_TAB);
    Serial.println("Menu");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(Service) == LOW) {
    Keyboard.press(KEY_F2);
    Serial.println("Service");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(ServiceCoin) == LOW) {
    Keyboard.press('9');
    Serial.println("ServiceCoin");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  if (digitalRead(MameVol) == LOW) {
    Keyboard.press('~');
    Serial.println("MameVol");
    Keyboard.releaseAll();
    delay(ButtonRepeatDelay);
  }

  // this section sets the system volume for the default sound device - ie the
  // OS master volume control.  Tested in Win 10 and 11.

  if (!digitalRead(VolUp)) {
    Consumer.write(MEDIA_VOLUME_UP);  // see HID Project documentation for more
                                      // Consumer keys  - commented out for
                                      // Arduino Nano and MAME Volume Keys used
    delay(300);  // simple debounce

    Serial.println("VolUp");
  }
  if (!digitalRead(VolDown)) {
    Consumer.write(
        MEDIA_VOLUME_DOWN);  // see HID Project documentation for more Consumer
                             // keys  - commented out for Arduino Nano and MAME
                             // Volume Keys used
    delay(ButtonRepeatDelay);
    Serial.println("VolDown");
  }

  if (!digitalRead(VolMute)) {
    Consumer.write(
        MEDIA_VOLUME_MUTE);  // see HID Project documentation for more Consumer
                             // keys  - commented out for Arduino Nano and MAME
                             // Volume Keys used
    delay(ButtonRepeatDelay);
    Serial.println("VolMute");
  }
}