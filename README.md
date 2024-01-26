# MAMEKeys-Mini-MAME-Keyboard
A mini keyboard for the default MAME cabinet keys

provide the standard MAME (non-player control) keys to a cabinet. 

Ideal for cabinets with Zero Delay Controllers to maintain default key mappings within MAME. 

Also includes Consumer keys for control of the system volume - up, down and mute

Tested on an Arduino Leonardo clone (DFRobot Dremer Nano)

#include "HID-Project.h"  //https://github.com/NicoHood/HID

Provides the following MAME Key assignments :
Coin 1 - 5 key
Coin 2 - 6 key
Player 1 Start - 1 key
Player 2 Start - 2 key
Exit - Esc key
Pause - P key
Select - Enter key
Menu  - Tab key
Mame Volume - Tilde "~" key (press then use joystick left/right to control MAME volume)
Service  - F2 key
Service Coin  - 9 key

HID Media keys
Volume Up - System Volume Up
Volume Down - System Volume Down
Mute - System Volume Mute (Toggle)

Wiring is simple - wire the buttons you need directly to pins D2 to D12 and to A0 to A2 as follows, with the button switching to GND 
Coin1 to D2    // 5
Coin2 to D3    // 6
Player1 to D4  // 1
Player2 to D5  // 2
Exit to D6     // Esc
Pause to D7    // P
Select to D8   // Enter (also used for digital pinball plunger)
Menu to D9     // Tab
Mame Volume to D10   // Tilde ~ key (press then use joystick left/right to control MAME volume)
Service to D11      // F2
Service Coin to D12  // 9

Media control
System Volume Up to A0 
System Volume Down to A1
System Volum Mute to A2


