During our last IoT class, we were given some time to work on setting up an example program, Blink, on our microcontrollers. During class, I was trying to get the ESP32 microcontroller to work, but could not find a similar blink program. Today, I received the Weather Kit which includes the ESP8266.



Things Needed:

Computer (preferably Windows due to driver issues, but Macs also work)
Weather Kit (includes the ESP8266, Micro USB - USB Cable, 2 40pin Male to Male Jumper Wires, 2 40pin Female to Female Jumper Wires)
LED Lights
Breadboard


Shoutout to Lakshmi for lending me the LED Lights and the Breadboard



Microcontroller Steps:

Connect the USB Cable to your computer and microcontroller
Connect two of the Male to Male Jumper Wires to two Female to Female Jumper Wires together resulting in two Female to Male Jumper Wires
Connect two of the Female Side Jumper Wires to D4 and G on the ESP8266 (Pic 1)
Connect the Male Side Jumper Wire to the Positive Side of the Breadboard (Left) and the other Male Side Jumper to the Negative Side (Right) (Pic 2)
Put the LED with the longer side into the positive side and the shorter side to the negative (Pic 3)


Computer Steps:

Install the Arduino IDE
Once installed, open the Arduino application and navigate to the preferences pane under Arduino or File. In the input box for 'Additional Boards Manager URLs:' paste this link: http://arduino.esp8266.com/stable/package_esp8266com_index.json and then click OK
Go to Tools > Board > Boards Manager. Here you can search and download the 'ESP8266 by ESP8266 Community' package
Navigate to and select Tools > Board > ESP8266 Boards (3.0.2) > Generic ESP8266 Module
Download the driver for the ESP8266. Unzip the package, run the program, uninstall and reinstall the driver, and then navigate to the Arduino application and go to Tools > Port and select your microcontroller (Thank you Erika)
Go to File > Examples > 01.Basics > Blink. Select the Verify Button at the top left, and then click the Upload Button next to it after its done compiling.


Abstract:

While it seems like this is a basic project, it is important to set up a strong foundation for future projects. Now we have the Arduino IDE set up along with some working knowledge of how the components interact with each other.
