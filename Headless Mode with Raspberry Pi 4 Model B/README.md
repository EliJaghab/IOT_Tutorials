For this tutorial, we will go over how to connect to your Raspberry Pi 4 Model B in Headless mode (without a monitor) using a Mac. This will enable us to connect to the Pi using a virtual desktop.

Hardware Requirements:
1. [Raspberry Pi 4 Model B - 8GB DDR4](https://www.microcenter.com/product/622539/raspberry-pi-4-model-b-8gb-ddr4)
2. [Micro Center 16GB microSDHC Card Class 10 Flash Memory Card with Adapter](https://www.microcenter.com/product/486146/micro-center-micro-center-16gb-microsdhc-card-class-10-flash-memory-card-with-adapter?rf=Frequently+Bought+Together)
3. [Apple Thunderbolt 3 (USB-C) Cable](https://www.microcenter.com/product/502168/apple-thunderbolt-3-(usb-c)-cable)
Hardware Steps:

Put the Micro SD Card in the SD Card Adapter and then connect the SD Card to your computer (my computer has an SD Card slot)
Software Steps:
1. Download the Raspberry Pi Imager
2. Open the [Raspberry Pi Imager](https://www.raspberrypi.org/software/) application
3. For Operating System, select "Raspberry Pi OS (32-bit)", choose your SD Card from the dropdown and then select Write
4. Select "Yes" for deleting all existing data from the SD Card
5. Open Terminal and change the directory to your SD Card by entering: cd/Volumes/boot
6. Create an empty file called ssh by entering the command: touch ssh
7. Create a file called wpa_supplicant.conf by entering the command: touch wpa_supplicant.conf
8. Navigate to the wpa_supplicant.conf file by opening Finder > Locations > boot > wpa_supplicant.conf
9. Double click wpa_supplicant.conf, open it with TextEdit and copy and paste [this code](https://github.com/EliJaghab/IOT_Tutorials/blob/main/Headless%20Mode%20with%20Raspberry%20Pi%204%20Model%20B/wpa_supplicant.conf) into the file
10. Add your WiFi Network name and password on lines 6 and 7 and then Save the file

Hardware Steps:
1. Eject the SD Card from your computer
2. Remove the Micro SD Card from the SD Card Adapter, insert the Micro SD card into the Raspberry Pi and connect your Pi to a power source using the USB-C Cable (you can connect it to your computer)

Software Steps:
1. Install and open [Angry IP Scanner](https://angryip.org/download/#mac)
2. In the Hostname row, click the icon that says "IP" with the arrow pointing upwards and select whichever row starts with an IP Address like 192.168
3. For the IP Range, change the last numbers of the IP Address to 1 and for the second input change the last numbers of the IP Address to 255. For example, 192.168.43.234 to 192.168.43.234 -> 192.168.43.1 to 192.168.43.255
4. Select the Fetchers icon located next to the start button and move the Mac Vendor option form the Available fetchers list to the selected fetchers list and click OK
5. Click Start. Once its done scanning, sort by Ping and note the Raspberry Pi IP address in the hostname column. Mine is listed as "raspberrypi"
6. Login to your Pi using this command with your IP Address at the end from Angry IP Scanner: ssh pi@192.168.1.8
7. Enter the default password: raspberry
8. Install [VNC Viewer](https://www.realvnc.com/en/connect/download/viewer/)
9. Run this command: sudo systemctl enable vncserver-x11-serviced.service
10. nd this command: sudo systemctl start vncserver-x11-serviced.service
11. Open VNC Viewer, enter your Pi's IP Address, and then enter the username: pi and the password: raspberry

References:
1. [How to Setup Raspberry Pi 4 in Headless Mode](https://letscodepare.com/blog/how-to-setup-raspberry-pi-4-in-headless-mode)
2. [How to Find Raspberry Pi IP Address with Angry IP Scanner](https://www.youtube.com/watch?v=NOqunlnD7Cc&ab_channel=RoboticsBack-End)

![image](https://user-images.githubusercontent.com/55901654/134458923-ce94e2c1-477e-4e68-aff2-1432bde66d29.png)
![IMG_9676](https://user-images.githubusercontent.com/55901654/134458954-339a3e78-6182-447d-ae18-fbf700fac3de.jpeg)
