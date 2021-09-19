During our last IoT class, we were given some time to work on setting up an example program, Blink, on our microcontrollers. During class, I was trying to get the ESP32 microcontroller to work, but could not find a similar blink program. Today, I received the Weather Kit which includes the ESP8266.

Things Needed:
1. Computer (preferably Windows due to driver issues, but Macs also work)
2. [Weather Kit](https://www.amazon.com/gp/product/B07GPBBY7F/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) (includes the ESP8266, Micro USB - USB Cable, 2 40pin Male to Male Jumper Wires, 2 40pin Female to Female Jumper Wires)
3. [LED Lights](https://www.amazon.com/Gikfun-Emitting-Diodes-Diffused-Arduino/dp/B06XWTN1YM/ref=sr_1_19?dchild=1&keywords=microcontroller+light&qid=1631503607&sr=8-19)
4. [Breadboard](https://www.amazon.com/EL-CP-003-Breadboard-Solderless-Distribution-Connecting/dp/B01EV6LJ7G/ref=pd_sbs_4/131-5979752-5581603?pd_rd_w=dQJ6V&pf_rd_p=0a3ad226-8a77-4898-9a99-63ffeb1aef90&pf_rd_r=D9VE9FYFN9BBCBESKZEP&pd_rd_r=95efd357-c900-40f9-81f6-3d4b1e1bc1ee&pd_rd_wg=OPD8K&pd_rd_i=B01EV6LJ7G&psc=1)

Shoutout to Lakshmi for lending me the LED Lights and the Breadboard

Microcontroller Steps:
1. Connect the USB Cable to your computer and microcontroller
2. Connect two of the Male to Male Jumper Wires to two Female to Female Jumper Wires together resulting in two Female to Male Jumper Wires
3. Connect two of the Female Side Jumper Wires to D4 and G on the ESP8266 (Pic 1)
4. Connect the Male Side Jumper Wire to the Positive Side of the Breadboard (Left) and the other Male Side Jumper to the Negative Side (Right) (Pic 2)
5. Put the LED with the longer side into the positive side and the shorter side to the negative (Pic 3)


Computer Steps:
1. Install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Once installed, open the Arduino application and navigate to the preferences pane under Arduino or File. In the input box for 'Additional Boards Manager URLs:' paste this link: http://arduino.esp8266.com/stable/package_esp8266com_index.json and then click OK
3. Go to Tools > Board > Boards Manager. Here you can search and download the 'ESP8266 by ESP8266 Community' package
4. Navigate to and select Tools > Board > ESP8266 Boards (3.0.2) > Generic ESP8266 Module
5. Download the [driver](https://github.com/nodemcu/nodemcu-devkit/tree/master/Drivers) for the ESP8266. Unzip the package, run the program, uninstall and reinstall the driver, and then navigate to the Arduino application and go to Tools > Port and select your microcontroller (Thank you Erika)
Go to File > Examples > 01.Basics > Blink. Select the Verify Button at the top left, and then click the Upload Button next to it after its done compiling.

Abstract:
While it seems like this is a basic project, it is important to set up a strong foundation for future projects. Now we have the Arduino IDE set up along with some working knowledge of how the components interact with each other.




![IMG_9579](https://user-images.githubusercontent.com/55901654/133937490-e858c898-69cc-44ac-a1fc-5c76a5c61763.jpeg)
![IMG_9580](https://user-images.githubusercontent.com/55901654/133937495-e8aa4da0-691d-4aef-9d1f-4b2d5dec6f1f.jpeg)
![IMG_9581](https://user-images.githubusercontent.com/55901654/133937502-26bd7962-680d-4f59-b172-0ebd6974f089.jpeg)




https://user-images.githubusercontent.com/55901654/133937933-149de962-ad22-43b7-ae10-665d755b4720.mov


References:
[Blink Tutorial](https://github.com/pschragger/IOT_Tutorials_for_VU/blob/main/blink_tutorial/blink_tutorial.md)
