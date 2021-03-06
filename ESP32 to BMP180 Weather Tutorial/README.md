For this tutorial, we are going to test using the ESP32 Microcontroller with the BMP180 Sensor to get live temperature, pressure, altitude, and sea level pressure readings. 

Hardware Needed:
1. [ESP32 Microcontroller](https://www.amazon.com/SongHe-Development-Dual-Mode-Bluetooth-Antenna/dp/B08246MCL5/ref=sr_1_3?dchild=1&keywords=esp32&qid=1631832417&sr=8-3)
2. [Weather Kit](https://www.amazon.com/gp/product/B07GPBBY7F/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1) (includes the BMP180, Micro USB - USB Cable, 4 40pin Male to Male Jumper Wires, Mini Breadboards)

Software Prerequisites:
1. You have the Arduino IDE set up and are able to see the port available for the ESP32 (on Mac it should say "/dev/cu.SLAB_USBtoUART" and on Windows "COM3")
2. You can download the driver for the ESP32 [here](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) if you haven't done so already

Hardware Steps:
1. Connect the ESP32 to the BMP180 using 4 Male to Male Jumper Wires as shown below and connect the ESP32 to your computer using the Micro USB to USB Cable ([Image Credit](https://www.electronicshub.org/esp32-bmp180-tutorial/))

![ESP32-BMP180-Circuit](https://user-images.githubusercontent.com/55901654/133938289-3afcab56-640f-43ed-8bad-e112c9f194fa.jpg)

Software Steps:
1. Go to Tools > Boards > Board Manager and install the esp32 package if you haven't already
2. Go to File > Preferences and paste this into Additional Boards Manager URLs: https://dl.espressif.com/dl/package_esp32_index.json and then click OK
3. Go to Sketch > Include Library > Manage Libraries and install the Adafruit BMP085 Library
4. Go to and select Tools > Board > ESP32 Arduino > ESP32 Dev Module
5. Go to File > Examples > Adafruit BMP085 Library > BMP085test
6. Click Upload and go to the Serial Monitor to change the Baud Type to 9600

Abstract:
I had some trouble initially when connecting the BMP180 to the ESP32 so I used a clip to hold the wires in place that hold up the sensor. This sensor is tough to connect to the ESP32 relative to the others that we have used. I think that it should have a similar design to the DHT11 so that you could connect it more easily to a breadboard. 

References:
[ESP32 with BMP180 Barometric Sensor ??? Guide](https://randomnerdtutorials.com/esp32-with-bmp180-barometric-sensor/)

![IMG_9645](https://user-images.githubusercontent.com/55901654/133938297-5f9c5264-5cfa-4e01-a675-476c712039d3.jpeg)
![IMG_9646](https://user-images.githubusercontent.com/55901654/133938307-abd75076-8d87-4bdc-a8d6-68f0fb9079e7.jpeg)

https://user-images.githubusercontent.com/55901654/133938311-6cad5b32-d8ec-42da-a20f-048f287e4d1d.mov

