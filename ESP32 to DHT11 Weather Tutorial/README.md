(This is very similar to my [ESP8266 to DHT11 Tutorial](https://github.com/EliJaghab/IOT_Tutorials/tree/main/ESP8266%20to%20DHT11%20Weather%20Tutorial) with some minor adjustments)

For this tutorial, we are going to use the ESP32 microcontroller with the DHT11 analog sensor to get live humidity, temperature and heat index readings.

Things Needed:
1. [ESP32 Microcontroller](https://www.amazon.com/SongHe-Development-Dual-Mode-Bluetooth-Antenna/dp/B08246MCL5/ref=sr_1_3?dchild=1&keywords=esp32&qid=1631832417&sr=8-3)
2. [Weather Kit](https://www.amazon.com/gp/product/B07GPBBY7F/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) (includes the DHT11, Micro USB - USB Cable, 3 40pin Male to Male Jumper Wires)
3. Breadboard

Software Prerequisites:
1. You have the Arduino IDE set up and are able to see the port available under Tools > Port

Hardware Steps:
1. Connect the ESP32 to the DHT11 using the 3 Male to Male Jumper Wires as shown below and connect the ESP32 to your computer using the Micro USB to USB Cable

Software Steps:
1. Go to Tools > Boards > Board Manager and install the esp32 package if you haven't already
2. Go to File > Preferences and paste this into Additional Boards Manager URLs: https://dl.espressif.com/dl/package_esp32_index.json and then click OK
3. Go to Sketch > Include Library > Manage Libraries and install these 3 libraries: DHT Sensor Library, DHT Sensor library for ESPx, and Adafruit Unified Sensor
4. Go to and select Tools > Board > ESP32 Arduino > ESP32 Dev Module
5. Go to File > New, remove the code that is there and copy and paste the C code attached that I adapted from [here](https://circuits4you.com/2019/01/25/interfacing-dht11-with-nodemcu-example/) into the window and then click Save as and name the file as DT11Test2.ino
6. After pasting this code into the window, click Verify and then Upload after the code compiles
7. Go to and select Tools > Upload Speed > 115200
8. Go to Tools > Serial Monitor and change the baud type on the bottom to 115200 baud

Abstract:
For this exercise, I had trouble connecting to the DHT11 receiving nan errors. Lakshmi helped me resolve this error by realizing that the "#define DHTpin" code at the beginning of the file requires the pin to match from the board. For this set up, using #define DHTpin 5 resolved the error.

![IMG_9637](https://user-images.githubusercontent.com/55901654/133938115-f642dd6e-48ce-49dd-ae29-d5cad7c4fa6b.jpeg)

https://user-images.githubusercontent.com/55901654/133938119-00382080-9d60-4eaf-8a13-715fa2a97295.mov

