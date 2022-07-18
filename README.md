# Agrotech 2022 Automated Irrigation System project
## Project Goal
We wanted to make an irrigation system that will water the plants and will keep the soil moisture capacity regulated using a simple sensor.
The goal was to make an autonomous irrigation system that is specifically tuned for each plant because like every person, each plant is a bit different from the rest. The system's vision is to be able to cut costs in terms of both water and man-power.

### System Concept
We used the capacitive soil moisture sensors in order to measure the soil moisture capacity. The sensors data is uploaded to our [Thingspeak Channel](https://thingspeak.com/channels/1757836). The system calculates the moisture in the soil for each plant individualy and each plant is irrigated when the soil's moisture drops below it's specific mark.

![](https://github.com/vitoska26/agrotech_project/blob/main/Extras/73TI.gif)

### Components:


For one irrigation computer we used :

Electronics:

* x1 ESP32 microcontrollers [click me](https://randomnerdtutorials.com/getting-started-with-esp32/)
* x1 Fullsize BreadBoards [click me](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard)
* x2 Relays [click me](https://randomnerdtutorials.com/esp32-relay-module-ac-web-server/)
* x2 Solenoid valves [click me](https://bc-robotics.com/tutorials/controlling-a-solenoid-valve-with-arduino/)
* Multiple jumper cables
* x2 capacitive soil moisture sensor [click me](https://esp32io.com/tutorials/esp32-soil-moisture-sensor)
* x1 Buck converters [click me](https://www.youtube.com/watch?v=TNR57IjVplY)
* *recommanded - x2 1MΩ resistor  

Hardware:

* x1 Electric Boxes
* 12V Power source
* Multiple electric wires

Irrigation System:

* 16mm Plastic tubes 
* x2 4 Liters/h irrigation nozzels by Netafim
* x8 4mm Sub-Surface irrigation drips

Disclaimers:
* We were able to monitor up to 2 sensors at a time so the code is for 2 sensors only. In order to keep both systems as much alike as possible, the code at the #2 esp is the same except the THINGSPEAK channel it's uploading to, and the SM mark.
* Each type of plant was irrigated by a different soil moisture percentage marks decided by previous researches.

We researched a lot so we could use all the materials properly. We have included here the links that were most effective for us in building the system.

# Construction:

## prototype
First we developed the basic structure of the system. Basic valve-relay-esp interactions can be seen [here](https://github.com/vitoska26/agrotech_project/blob/main/Images/basic%20circuit.jpeg).
Then we installed our system into a water-proof electrical box, testing it using one sensor [click me](https://github.com/vitoska26/agrotech_project/blob/main/Images/first%20prototype.jpeg)
### Adjustments
* While the valve is 12V DC, the esp and other components require 3.3V-5V. In order to reduce to voltage we used this [Buck convertor](https://www.youtube.com/watch?v=TNR57IjVplY), taking the voltage down from 12V to 5V and to the esp.
* Because we're working in a wet environment, we needed to make our sensors water-resistable. For that we did two things:
  - [x]  Ditch the f-f cables that comes with the sensor and create your own cable. Connect it to the sensor for greater range and safety. 
  - [x] When the system is almost ready, put some silicone on the top part of the sensor, as can be seen [here](https://github.com/vitoska26/agrotech_project/blob/main/Images/Corn%20Plant.jpeg).
* Relays have 2 working options: Normally closed or Normally open. We want our circuit to be always **open** (NO) in order for the valve to be shut. Make sure to test your valve as some will work the other opposite way. 
* While we did not have time to implement this in our project, you can make your sensors even more accurate, using a 1MΩ resistor. [watch here](https://www.youtube.com/watch?v=IGP38bz-K48&t=1s) for more. 

## Fritzing Sketch
![](https://github.com/vitoska26/agrotech_project/blob/main/Extras/fritzing_bb.png)
Legend
  * Red - VCC
  * Blue - GND for 12V components or analog read for sensors
  * Black - GND
  * Orange - VCC for sensors and analog pins for relays (also yellow)
  * Brown - 12V power supply or GND for relays and sensors
# Water System
Water flow needs to be constant all the time. Connect your main tube to the water source and then divide it between the various spots you'll want to water. We recommand the following layout [click me](https://github.com/vitoska26/agrotech_project/blob/main/Images/irrigation%20layout.jpeg).
Using the 4L/h nozzles make an exit for the drippers to connect. Stick the drippers close to the plant's roots. We've concluded that for maximize control it is recommanded to place 3 drippers at various points and one dripper in the close proximity of the sensor, in order to not water it to much.

# Code
* Start by calibrating your sensor's wet&dry values. you can use this [link](https://github.com/vitoska26/agrotech_project/blob/main/Code/soil_moisture_sensor_calibrating.ino)
* Learn to use your valve. All our relays are set to **NO** but your valve might work the other way around, and will allow the flow of water when the relay's state is **open**. In order to counter that just set your relay to NC - Normally closed. [click here for the code](https://github.com/vitoska26/agrotech_project/blob/main/Code/RELAY_sketch.ino) and [here](https://www.youtube.com/watch?v=zIHPogas1cU) to learn about relays.  
* After assembling the system itself, just load this [code](https://github.com/vitoska26/agrotech_project/blob/main/Code/Sensor_Controlled_Irrigation_System.ino) into your MCU. 

**important:** In order to load the code into the MCU successfully, make sure the circuit is open and the esp's only power source is your computer, via the usb cable. 

# The final outcome

![WhatsApp Image 2022-07-14 at 16 50 08](https://user-images.githubusercontent.com/91986255/179002137-ef69bb09-e792-4f0a-be5d-d7007f262c5a.jpeg)
![WhatsApp Image 2022-07-14 at 16 50 09](https://user-images.githubusercontent.com/91986255/179002213-14f661ef-38e4-4d9a-a6d1-49d43fabdad2.jpeg)


![WhatsApp Image 2022-07-14 at 16 48 59](https://user-images.githubusercontent.com/91986255/179002364-831d9659-e40f-41da-9dff-58a7027fa39f.jpeg)

We created a system that can water each plant individually using sm-capacity sensor for each plant. The system can respond very quickly (~several seconds) to changes in the soil and irrigate the plant accordingly.
We placed the system on 2 pepper plants, 1 tomato plant and 1 corn.

## Data analysis
TODO

# See Also
* [similar project](https://www.researchgate.net/publication/332254393_AUTOMATIC_WATERING_DEVICE_FOR_TOMATO_USING_SOIL_MOISTURE_SENSOR)
* [Article](https://www.researchgate.net/publication/239848253_Irrigation_Scheduling_for_Green_Bell_Peppers_Using_Capacitance_Soil_Moisture_Sensors) about how an irrigation system regulated by soil sensors instead of traditionial time regulated system dicreased the water usage by up to 62% while achieving same yield quantities.
* [Learn to water your crops](https://www.delmhorst.com/blog/whats-the-ideal-moisture-level-for-soil-to-grow-crops) 
