# adas-security-mqtt
## Purpose
The program is funded by Ministry of Science and Technolofy (MOST), Taiwan. The purpose is to provide end-to-end security based on MQTT. Although the target application is Advanced Driver Assistance System (ADAS), some projects can be applied to other applications.

Most of projects will be build from open source projects, such as
* [Paho](http://www.eclipse.org/paho/) for publisher/subscriber
* [Mosquitto](https://mosquitto.org/) for broker
* Others

## Main Projects
### Bee-CPABE (bee-cpabe-sdk-0.1)
Project Bee-CPABE provides an SDK that lets developers encrypt data using Ciphertext-Policy Attribute-Based Encryption (CPABE). By using Bee-CPABE SDK, developers can easily implement CPABE with four basic functions, **setup()**, **keygen()**, **enc()**, and **dec()**. 

Bee-CPABE SDK mainly supports C programming language on Linux. We are currently working on JNI for providing interface to JAVA developers.

## Side Projects
### mqtt-demo
This side project is only for demonstrating the feasibility of applying CPABE and MQTT to secure Internet of Vehicle.
