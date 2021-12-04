Intro:

For my final project, I will be implementing AWS IoT to manage MQTT communication. This tutorial outlines how to set up an EC2 Instance to host your MQTT Broker in the cloud. The tutorial concludes with testing the instance form the terminal to the browser. If you are interested in setting this up with an ESP32 or ESP8266, you can follow the video starting [here](https://youtu.be/SDrkv2hUzAc?t=587) along with this [guide](https://aws.amazon.com/blogs/compute/building-an-aws-iot-core-device-using-aws-serverless-and-an-esp32/). Full credit goes to the Youtube tutorial and Amazon Links below.

Prerequisites:

1. Have an Amazon Web Services Account

Part 1: Creating a Role

1. Navigate to the search bar at the top of the AWS website and search "IAM" to create a role of AWS IoT Config Access
2. Select "Roles" on the left Menu and then Click the blue "Create role" button
3. Under "Choose a use case," select EC2 and click "Next: Permissions" at the bottom of the page
4. In the search bar on the next page, search for "AWSIoTConfigAccess," check the box next to it, and click "Next: Tags" and "Next: Review" on the bottom of the page to proceed to the next step
5. Enter a role name. This tutorial uses: "AWS_IoT_Config_Access" and then click "Create role" at the bottom


Part 2: Creating an EC2 Instance

1. Search "EC2" in the top search bar and select the first result
2. Click "Instances" on the left-hand column, select "Launch Instances" on the top right corner, and then check the box for "Free tier only" on the left-hand column
3. Select "Ubuntu Server 20.04 LTS (HVM), SSD Volume Type" with 64-bit (x86)
4. Check the type that has the green label "Free tier eligible" and click "Next: Configure Instance Details"
5. On the next page, in the IAM role drop down, select the role that we made in the last part, "AWS_IoT_Config_Access", and click "Next: Add Storage" and "Next: Add Tags"
6. Add a tag with a key value pair of "Name":"MQTT_Broker." Click "Review and Launch" and "Launch"
7. Select "Create a new key pair" from the dropdown, use the RSA default thats already selected and use the name "EC2_MQTT_BROKER" for the Key pair name. Click "Download Key Pair" which we will use later on and select "Launch Instances"
8. Congrats! You have created an Amazon EC2 Instance. Launching the instance takes about 10 minutes so use this time as a break.


Part 3: Examining the Instance

1. Click the Instance ID to review the instance's state. If it says "Running" you can move on to the next parts


Part 4: SSHing to the Instance

1. Open Terminal and navigate to the folder of the file we downloaded in the previous part. Mine is in my Downloads folder. CD to that folder and run this command to change the permissions of the file so that it cannot be written or executed: chmod 400 EC2_MQTT_BROKER.pem
2. In the details of your instance on AWS, copy the "Public IPv4 DNS" address of your instance and replace my address with yours at the end of the next command and run it in your Terminal: ssh -i EC2_MQTT_BROKER.pem ubuntu@ec2-54-152-224-57.compute-1.amazonaws.com


Part 5: Installing MQTT on the Instance

1. Your terminal command should now start with something like: ubuntu@ip-172-31-92-7:~$
2. Run the following commands: sudo apt-add-repository ppa:mosquitto-dev/mosquitto-ppa
3. sudo apt-get update
4. sudo apt-get install mosquitto
5. sudo apt-get install mosquitto-clients
6. sudo apt install awscli
7. Run aws-configure
8. For this command, you can leave the keys blank. for the Default Region Name, navigate to the AWS Website and take note of the region that is selected. Mine is N. Virginia which correlates with "us-east-1." Enter this in the terminal for the region parameter and leave the rest blank by pressing enter.
9. Run the following commands: aws iot create-policy --policy-name bridgeMQTT --policy-document '{"Version": "2012-10-17","Statement": [{"Effect": "Allow","Action": "iot:*","Resource": "*"}]}'
10. cd /etc/mosquitto/certs/
11. sudo wget https://www.amazontrust.com/repository/AmazonRootCA1.pem -O rootCA.pem
12. Change the parameter at the end of the URL for your region accordingly and run: sudo aws iot create-keys-and-certificate --set-as-active --certificate-pem-outfile cert.crt --private-key-outfile private.key --public-key-outfile public.key --region us-east-1
13. Copy and paste the value from the "certificateArn" key from the output above and paste it at the end of this command: aws iot attach-principal-policy --policy-name bridgeMQTT --principal <certificate ARN>
14. Run these next two commands: sudo chmod 644 private.key
15. sudo chmod 644 cert.crt
16. Run and copy the value from this command: aws iot describe-endpoint --endpoint-type iot:Data-ATS
17. Run: sudo nano /etc/mosquitto/conf.d/bridge.conf
18. Copy and paste this [text](https://raw.githubusercontent.com/EliJaghab/IOT_Tutorials/main/Creating%20an%20AWS%20EC2%20Instance%20to%20Host%20a%20MQTT%20Broker/bridge.conf) into the file and then replace the AWS IoT Core endpoint with yours from the Step 16. Use Ctrl-O, Enter, Ctrl-X to save.
19. Restart the MQTT broker using: sudo service mosquitto restart
20. To verify the setup, run: ps -aux
21. In the list of auxiliary devices, there should be mosquit+


Part 6: Testing Publish

1. Navigate to the MQTT test client
2. Make sure your region is set to the region you set up your instance with
3. In the topic filter, enter and click Subscribe: localgateway_to_awsiot
4. In terminal while you are still SSHed to the instance, run: mosquitto_pub -h localhost -p 1883 -q 1 -d -t localgateway_to_awsiot -i localClientID -m "{\"message\": \"helloFromLocalGateway\"}"
5. The message from your terminal should show up in your browser


Part 7: Testing Subscribe

1. Select "Publish to a topic" on the MQTT test client page
2. Click Publish with the default message and you should see the message in the browser

Sources:

1. [AWS IoT | How to install Mosquitto Broker on Amazon EC2](https://www.youtube.com/watch?v=SDrkv2hUzAc&ab_channel=ThatProject)
2. [How to Bridge Mosquitto MQTT Broker to AWS IoT](https://aws.amazon.com/blogs/iot/how-to-bridge-mosquitto-mqtt-broker-to-aws-iot/)
3. [Building an AWS IoT Core device using AWS Serverless and an ESP32](https://aws.amazon.com/blogs/compute/building-an-aws-iot-core-device-using-aws-serverless-and-an-esp32/)
  
  <img width="868" alt="Screen Shot 2021-12-04 at 12 38 28 PM" src="https://user-images.githubusercontent.com/55901654/144719102-f19b5f02-5bad-4ccd-bd7b-77904be3e642.png">
