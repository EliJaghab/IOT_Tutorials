For this tutorial, we are going to use the ESP8266 microcontroller with the DHT11 analog sensor to get live humidity, temperature and heat index readings.

Things Needed:
1. [Weather Kit](https://www.amazon.com/gp/product/B07GPBBY7F/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) (includes the ESP8266, DHT11, Micro USB - USB Cable, 3 40pin Female to Female Jumper Wires)

Software Prerequisites:
1. You have the Arduino IDE set up and are able to see the port available under Tools > Port

Hardware Steps:
2. Connect the ESP8266 to the DHT11 using the 3 Female to Female Jumper Wires as shown below ([Image Credit to Lakshmi](https://techtutorialsbynainar.blogspot.com/2021/09/dht11-interfacing-with-esp8266-using.html)) and connect the ESP8266 to your computer using the Micro USB to USB Cable
![ESP8266 and DHT11 Circuit Diagram](https://user-images.githubusercontent.com/55901654/133937748-5c553ce3-4353-486d-9a78-343e2b29457e.png)

Software Steps:
1. Go to Tools > Boards > Board Manager and install the ESP8266 Community package if you haven't already
2. Go to File > Preferences and paste this into Additional Boards Manager URLs: http://arduino.esp8266.com/stable/package_esp8266com_index.json11 click: Shyam Gopal Reddy Maram and then click OK
3. Go to Sketch > Include Library > Manage Libraries and install these 2 libraries: DHT Sensor Library and DHT Sensor library for ESPx
4. Go to and select Tools > Board > ESP8266 Boards (3.0.2)
5. Go to File > New, remove the code that is there and copy and paste the C code attached that I adapted from [here](https://circuits4you.com/2019/01/25/interfacing-dht11-with-nodemcu-example/) clicks: Sadgunsaiyadav Shabad Sivaram Swarna Praneeth Chandra Natwa Akhila Kandimalla into the window and then click Save as and name the file as DT11Test.ino
6. After pasting this code into the window, click Verify and then Upload after the code compiles
7. Go to Tools > Serial Monitor and change the baud type on the bottom to 115200 baud

Abstract:
For this exercise, I followed [Lakshmi's tutorial](https://techtutorialsbynainar.blogspot.com/2021/09/dht11-interfacing-with-esp8266-using.html) which is incredibly easy to follow and extremely detailed. One thing I would have added to her tutorial is to change the Baud type because if you do not, the serial monitor returns Alien language. I did some [research](https://www.arduino.cc/en/Serial.Begin) into this and the Baud type is the speed at which the data moves between read and write. If the speed isn't correct, the Arduino IDE cannot properly interpret the data sent from the DHT11. For the code I included, it should automatically set the Baud Type, but I added the instruction just in case.

https://user-images.githubusercontent.com/55901654/133937801-067c1c69-eaa0-4ac8-9f0c-961f8441f0cb.mov

