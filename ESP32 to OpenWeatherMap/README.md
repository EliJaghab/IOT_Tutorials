For this tutorial, we will use the ESP32 to communicate with the Open Weather API using WiFi to retrieve information about the weather.

Hardware Needed:
1. [ESP32 Microcontroller](https://www.amazon.com/SongHe-Development-Dual-Mode-Bluetooth-Antenna/dp/B08246MCL5/ref=sr_1_3?dchild=1&keywords=esp32&qid=1631832417&sr=8-3)
2. Micro USB Cable

Software Prerequisites:
1. You have the Arduino IDE set up and are able to see the port available for the ESP32 (on Mac it should say "/dev/cu.SLAB_USBtoUART" and on Windows "COM3")

Hardware Steps:
1. Connect the ESP32 to your computer using the Micro USB to USB Cable

Software Steps:
1. Go to Sketch > Include Library > Manage Libraries and install the ArduinoJson library by Benoit Blanchon
2. Copy and paste [this code](https://github.com/EliJaghab/IOT_Tutorials/blob/main/ESP32%20to%20OpenWeatherMap/ESP32tutorial.ino) adapted from Dr. Schragger's in-class exercise to the Arduino IDE and save it as ESP32toAPI.ino
3. Sign up for an account at [OpenWeatherMap](https://openweathermap.org/register)
4. Navigate to your username at the top right > My API Keys and copy your API Key
5. Add your city and API Key to this link and enter it in your browser: api.openweathermap.org/data/2.5/weather?q=CITY&appid=KEY&units=imperial
6. Go to the [ArduinoJson Assistant](https://arduinojson.org/v6/assistant/), select ESP32, Deserialize and Stream for Step 1 and copy and paste the results from the API for Step 2
7. Select Total (recommended) for Step 3 and then copy and paste the variables (starting at float coord_lon ...) to Line 89 of the Code from Step 4
8. Enter your WiFi name and password at Lines 21 and 22
9. Add your city and key to the URL on line 62
10. Click Upload

Abstract:
In class I tried this tutorial using the ESP8266, but decided that I have done many of the tutorials with this microcontroller so I thought it would be good to gain some experience using the ESP32. Christina showed me this [tutorial](https://www.teachmemicro.com/esp32-restful-api/) and I was successfully able to pull from the weather API in class. After looking into this further, I realized the HTTP Example that comes with the ESP8266 works with the ESP32 as well.

The ArduinoJson Assistant is a powerful tool that is able to accurately parse Json objects at the click of a button. It also signals to your microcontroller how much space it should allocate for the JSON object it receives from the API. This tool would have been useful for my work experience as a software intern this summer. I worked on exporting my company's data from a service and I had to normalize nested JSON objects using the json_normalize function. Half the battle was flattening these nested dictionaries into data frames and the other half was parsing JSON objects to convert certain columns from a double to a string. While I was not exactly working with an Arduino at work, I was parsing JSON objects and its nice to know that a tool like this exists. I did some Googling and am surprised to see that a more general application of this solution that works with other languages besides C++ does not exist.

I also tried to convert unix to timestamp in C++ for the sunrise and sunset, but was unsuccessful after 30 minutes of searching the internet. Its interesting to see how easy something is in Python which comprises of many libraries can easily do this conversion whereas in C++ this takes more work.

References:
1. [WiFi Tutorial](https://github.com/pschragger/IOT_Tutorials_for_VU/tree/main/wifi_tutorial)



https://user-images.githubusercontent.com/55901654/133943396-d2bff853-849c-46e2-90ad-6a36b6f7ac91.mov


