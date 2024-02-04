// A mini keyboard HID device to provide standard MAME (non-player control) keys to a cabinet. Ideal for cabinets with Zero Delay Controllers to maintain default key mappings within MAME. Also includes Consumer keys for control of the system volume.  

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


//Visual Pinball keys
const int LeftFlipper = A4;
const int RightFlipper = A5;


// for later expansion - eg BigBox exit (Key X), mouse keys, movement
// const int Unused0 = 0;
// const int Unused1 = 1;
// const int Unused13 = 13; (optionally used - see untested comments below)
// const int UnusedA3 = A3;


// delay between button repeats if held down
const int ButtonRepeatDelay = 300;
const int PauseRepeatDelay = 300;

int Coin1Press = 0;
int Coin2Press = 0;
int Player1Press = 0;
int Player2Press = 0;
int ExitPress = 0;
int PausePress = 0;
int SelectPress = 0;
int MenuPress = 0;
int MameVolPress = 0;
int ServicePress = 0;
int ServiceCoinPress = 0;
int VolUpPress = 0;
int VolDownPress = 0;
int VolMutePress = 0;
int LeftFlipperPress = 0;
int RightFlipperPress = 0;

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
  pinMode(LeftFlipper, INPUT_PULLUP);
  pinMode(RightFlipper, INPUT_PULLUP);

  Consumer.begin();  // Initiate consumer HID device on host

  // for later expansion - Can be used for additional custom keys to a cabinet
  // pinMode(Unused0, INPUT_PULLUP);
  // pinMode(Unused1, INPUT_PULLUP);
  // pinMode(Unused13, INPUT_PULLUP); //Optionally used to delay start of a second Zero Delay Joystick Encoder pinMode(UnusedA2, INPUT_PULLUP);
  // pinMode(UnusedA3, INPUT_PULLUP);


  Keyboard.begin();

/*---------------------This section Yet to be tested - just a thought bubble, not tried/implemented-----------------------------------
  
  Optionally set Pin 13 as Output and High (5v on the ATMega32U4 boards) and  use the output to enable power a second Zero Delay Joystick Encoder (ie cut the USB +5V line going to the encoder and connect the encoder board to this pin.) Useful if the order your zero delay encoders are detected by the OS is random, and P1 / P2 controls sometimes swap.

  Pin D13 (ref C7) appears to remain low at  so until set high, power won't flow to the second controller. Setting the "delay(60000);" line to an appropriate value allows the pin to go high after the OS has ed and has
  detected the first controller.

  DANGER Will Robinson!!! - the output will probably not have the current to drive the board directly - doing so would probably smoke the Leonardo board (or maybe just the pin). I haven't measured the current drawn by a ZD encoder under load, but the pin can only supply 40mA... and only 20mA for continuos current draw. If attempting this, use this output to drive a transistor/FET to supply power - and at your own risk!

  */

 //delay(60000); // millisecons - Set to at least the time it takes to  theOS and detect the first USB Controller 
 //digitalWrite(13, HIGH); //power pin 13 and whatever is connected to it

/*---------------------------------------------------------------------------------------------------------------*/
  
  Serial.println("Starting Keyboard...");
}

void loop() {
  if ((digitalRead(Coin1) == LOW) && (Coin1Press == 0)) {
    Keyboard.press('5');
    delay(ButtonRepeatDelay);
    Serial.println("Coin1");
    Coin1Press = 1;
  }
	
  if ((digitalRead(Coin1) == HIGH) && (Coin1Press == 1)) {	
    Keyboard.release('5');
    Coin1Press = 0;
  }

  if ((digitalRead(Coin2) == LOW) && (Coin2Press == 0)) {
    Keyboard.press('6');
    delay(ButtonRepeatDelay);
    Serial.println("Coin2");
    Coin2Press = 1;
	}
	
  if ((digitalRead(Coin2) == HIGH) && (Coin2Press == 1)) {	
    Keyboard.release('6');
    Coin2Press = 0;
  }

  if ((digitalRead(Player1) == LOW) && (Player1Press == 0)) {
    Keyboard.press('1');
    delay(ButtonRepeatDelay);
    Serial.println("Player1");
    Player1Press = 1;
  }
	
  if ((digitalRead(Player1) == HIGH) && (Player1Press == 1)) {
    Keyboard.release('1');
    Player1Press = 0;
  }

  if ((digitalRead(Player2) == LOW) && (Player2Press == 0)) {
    Keyboard.press('2');
    delay(ButtonRepeatDelay);
    Serial.println("Player2");
    Player2Press = 1;
  }
	
  if ((digitalRead(Player2) == HIGH) && (Player2Press == 1)) {
    Keyboard.release('2');
    Player2Press = 0;
  }

  if ((digitalRead(Exit) == LOW) && (ExitPress == 0)) {
    Keyboard.press(KEY_ESC);
    delay(ButtonRepeatDelay);
    Serial.println("Exit");
    ExitPress = 1;
   }
	
  if ((digitalRead(Exit) == HIGH) && (ExitPress == 1)) {
    Keyboard.release(KEY_ESC);
    ExitPress = 0;
  }

  if ((digitalRead(Pause) == LOW) && (PausePress == 0)) {
    Keyboard.press('P');
    delay(PauseRepeatDelay);
    Serial.println("Pause");
    PausePress = 1;
   }
	
  if ((digitalRead(Pause) == HIGH) && (PausePress == 1)) {
    Keyboard.release('P');
    PausePress = 0;
  }

  if ((digitalRead(Select) == LOW) && (SelectPress == 0)) {
    Keyboard.press(KEY_RETURN);
    delay(ButtonRepeatDelay);
    Serial.println("Pause");
    SelectPress = 1;
   }
	
  if ((digitalRead(Select) == HIGH) && (SelectPress == 1)) {
    Keyboard.release(KEY_RETURN);
    SelectPress = 0;
  }


/* Alternative Select for Visual Pinball and digital shoother plunger (e.g. my design at www.thingiverse.com/thing:6419048)
  if ((digitalRead(Select) == LOW) && (SelectPress == 0)) {  // this key altered for digital pinball plunger. when pin goes low, plunger is drawn. Wait for plunger to go high again to launch. Use N/O microswitch contacts
	Keyboard.press(KEY_RETURN);
	SelectPress=1;
  }
  
  if ((SelectPress == 1) && (digitalRead(Select)) == HIGH) {
    Serial.println("Select");
    Keyboard.release(KEY_RETURN);
    SelectPress = 0;
  }
*/

  if ((digitalRead(Menu) == LOW) && (MenuPress == 0)) {
    Keyboard.press(KEY_TAB);
    delay(ButtonRepeatDelay);
    Serial.println("Menu");
    MenuPress = 1;
   }
	
   if ((digitalRead(Menu) == HIGH) && (MenuPress == 1)) {
    Keyboard.release(KEY_TAB);
    MenuPress = 0;
  }

  if ((digitalRead(Service) == LOW) && (ServicePress == 0)) {
    Keyboard.press(KEY_F2);
    delay(ButtonRepeatDelay);
    Serial.println("Service");
    ServicePress = 1;
   }
	
  if ((digitalRead(Service) == HIGH) && (ServicePress == 1)) {
    Keyboard.release(KEY_F2);
    ServicePress = 0;	
  }

  if ((digitalRead(ServiceCoin) == LOW) && (ServiceCoinPress == 0)) {
    Keyboard.press('9');
    delay(ButtonRepeatDelay);
    Serial.println("ServiceCoin");
    ServiceCoinPress = 1;
   }
	
  if ((digitalRead(ServiceCoin) == HIGH) && (ServiceCoinPress == 1)) {
    Keyboard.release('9');
    ServiceCoinPress = 0;
  }

  if ((digitalRead(MameVol) == LOW) && (MameVolPress == 0)) {
    Keyboard.press('~');
    delay(ButtonRepeatDelay);
    Serial.println("MameVol");
    MameVolPress = 1;
  }
	
  if ((digitalRead(MameVol) == HIGH) && (MameVolPress == 1)) {
    Keyboard.release('~');
    MameVolPress = 0;	
  }
    

  if ((digitalRead(LeftFlipper) == LOW) && (LeftFlipperPress == 0)) {
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(ButtonRepeatDelay);
    Serial.println("LeftFlipper");
    LeftFlipperPress = 1;
  }
	
  if ((digitalRead(LeftFlipper) == HIGH) && (LeftFlipperPress == 1)) {
    Keyboard.release(KEY_LEFT_SHIFT);
    LeftFlipperPress = 0;
  }

  if ((digitalRead(RightFlipper) == LOW) && (RightFlipperPress == 0)) {
    Keyboard.press(KEY_RIGHT_SHIFT);
    delay(ButtonRepeatDelay);
    Serial.println("RightFlipper");
    RightFlipperPress = 1;
   }
	
  if ((digitalRead(RightFlipper) == HIGH) && (RightFlipperPress == 1)) {
    Keyboard.release(KEY_RIGHT_SHIFT);
    RightFlipperPress = 0;	
  }
  

  // this section sets the system volume for the default sound device - ie the
  // OS master volume control.  Tested in Win 10 and 11.

  if (!digitalRead(VolUp)) {
    Consumer.write(MEDIA_VOLUME_UP);  // see HID Project documentation for more Consumer keys
    delay(300);  // simple debounce
    Serial.println("VolUp");
  }
	
  if (!digitalRead(VolDown)) {
    Consumer.write(MEDIA_VOLUME_DOWN);  // see HID Project documentation for more Consumer keys
    delay(ButtonRepeatDelay);
    Serial.println("VolDown");
  }

  if (!digitalRead(VolMute)) {
    Consumer.write(MEDIA_VOLUME_MUTE);  // see HID Project documentation for more Consumer keys 
    delay(ButtonRepeatDelay);
    Serial.println("VolMute");
  }
}
