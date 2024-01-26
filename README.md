# MAMEKeys-Mini-MAME-Keyboard
A mini USB keyboard for the default MAME cabinet keys 

This mini keyboard/HID controller provides the standard (non-player control) MAME keys for a cabinet and utilises NicoHood's excellent HID-Project library. 

It also includes keys for controlling the system (master) volume - Volume up, down and mute (tested on Win 10 and 11)

Ideal for cabinets with Zero Delay Joystick Controllers, providing the critical remaining keys needed for a cabinet whilst maintaining the default key mappings within MAME. 

I built this on an Arduino Leonardo clone (DFRobot Dreamer Nano). Other boards are compatible with the HID-Project library- see "Supported Arduinos" at https://github.com/NicoHood/HID. Pins/pin availability may vary between boards, so if you choose a different board you may need to edit the code. <br>

![Wiring Diagram](https://github.com/StudioShemp/MAMEKeys-Mini-MAME-Keyboard/blob/main/images/nano.jpg)

---
The keyboard provides the following MAME Key assignments :
 - Coin 1 - 5 key<br>
 - Coin 2 - 6 key<br>
 - Player 1 Start - 1 key<br>
 - Player 2 Start - 2 key<br>
 - Exit - Esc key<br>
 - Pause - P key<br>
 - Select - Enter key<br>
 - Menu  - Tab key<br>
 - Mame Volume - Tilde "~" key (press then use joystick left/right to control MAME volume)<br>
 - Service  - F2 key<br>
 - Service Coin  - 9 key<br><br>

HID Media keys<br>
 - Volume Up - System Volume Up<br>
 - Volume Down - System Volume Down<br>
 - Mute - System Volume Mute (Toggle)<br><br>

---
Wiring is simple - wire the buttons you need directly to pins D2 to D12 and to A0 to A2 as follows, with the button switching to GND <br>
 - Coin1 to D2<br>
 - Coin2 to D3<br>
 - Player1 to D4<br>
 - Player2 to D5<br>
 - Exit to D6<br>
 - Pause to D7<br>
 - Select to D8<br>
 - Menu to D9<br>
 - Mame Volume to D10<br>
 - Service to D11<br>
 - Service Coin to D12<br><br>

Media control<br>
 - System Volume Up to A0<br>
 - System Volume Down to A1<br>
 - System Volum Mute to A2<br>

<BR>Wiring on the DFRobot Leonardo (Dreamer Nano)<BR>
![Wiring Diagram](https://github.com/StudioShemp/MAMEKeys-Mini-MAME-Keyboard/blob/main/images/wiring.jpg)

<BR>

---

<BR>

![Panel](https://github.com/StudioShemp/MAMEKeys-Mini-MAME-Keyboard/blob/main/images/panel.jpg)
<BR>
