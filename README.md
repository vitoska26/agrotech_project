# Agrotech 2022 watering system project
## Project Goal
We wanted to make an irrigation system that will automatically water the plants to keep the soil moisture capacity regulated by our needs.
The goal was to make an autonomous irrigation system that is specifically tuned for each plant because like every person, each plant is a bit different from the rest (even if they're from the same kind) and we wanted to provide each plant with his own needs.

### The system structure
We used the capacitive soil moisture sensor in order to measure the soil moisture capacity. the sensors data is uploaded to our Thingspeak channel. The system calculates the moisture in the soil for each plant and if the soil moisture capacity drops below 41%, a solenoid valve is turned on and the plant is irrigated.

We started by building a prototype that measures the soil moisture capacity for one plant. When the moisture was ≤ 41%, the prototype irrigated the plant until the s.m passed 41%.


![WhatsApp Image 2022-07-15 at 10 37 36 (1)](https://user-images.githubusercontent.com/91986255/179176178-1d252728-0aa7-41e1-b55b-1299259295eb.jpeg)

### The materials:


for this system we used :
* ESP32 microcontroller [click me](https://github.com/espressif/arduino-esp32)
* Fullsize Bread Board
* Relay [click me](https://randomnerdtutorials.com/esp32-relay-module-ac-web-server/)
* Solenoid Valve [click me](https://bc-robotics.com/tutorials/controlling-a-solenoid-valve-with-arduino/)
* Jumper cables
* CSM - capacitive soil moisture sensor [click me](https://esp32io.com/tutorials/esp32-soil-moisture-sensor)

We researched a lot so we could use all the materials properly. We have included here the links that were most effective for us in building the system.


### The prototype
![Prototype](https://user-images.githubusercontent.com/91986255/179000675-68276c4d-32a7-4e2e-b659-fc2c33ef77c8.jpeg)
![prototype (1)](https://user-images.githubusercontent.com/91986255/179176545-e2debb4b-fef2-4528-b08e-9c09273aa911.jpeg)

Then, we wanted to use the system in order to monitor several plants at a time. We made it with one ESP and attached it 4 different SM sensors, relays, valves and irrigation systems.
When we ran the system we saw we're not getting any readings from 2 specific sensors and thus leaving two plants un-irrigated :( 
After browsing through the internet and some minor assumptions we concluded that the ESP is unable to support 4 different sensors simultaniously, but only 2. 

Fun story: During our intense 3-hours inverstigation trying to figure out what's the problem, we also tried to switch esps and such. As time progressed we discovered we recieve no power to the previously working sensors at all! Imagine trying to fix a minor problem and things just keep falling apart. Nonetheless we didn't give up and as the hours passed we decided to check the MCU by itself (outside the breadboard). We couldn't believe our eyes. When we switched esp's, the 3.3V pin had been smashed inside the breadboard and basically did not provide any power to the system. A simple bend with the plier and the system was back on track.

![Bent pin](https://user-images.githubusercontent.com/91986255/179001783-73ccc5d5-1d0a-473f-ac53-addc0dc241e5.jpeg)

As we said, the esp was not suitable for our goal for one system to control more then 2 sensors. Therefore, we split the sensors between 2 different ESPs and connected them to the breadboard (carefully) and duplicated the systems in each box.


## The final outcome

![WhatsApp Image 2022-07-14 at 16 50 08](https://user-images.githubusercontent.com/91986255/179002137-ef69bb09-e792-4f0a-be5d-d7007f262c5a.jpeg)
![WhatsApp Image 2022-07-14 at 16 50 09](https://user-images.githubusercontent.com/91986255/179002213-14f661ef-38e4-4d9a-a6d1-49d43fabdad2.jpeg)


![WhatsApp Image 2022-07-14 at 16 48 59](https://user-images.githubusercontent.com/91986255/179002364-831d9659-e40f-41da-9dff-58a7027fa39f.jpeg)

We created a system that can water each plant individually using sm-capacity sensor for each plant. The system can respond very quickly (~several seconds) to changes in the soil and irrigate the plant accordingly.
We placed the system on 2 pepper plants, 1 tomato plant and 1 corn.
[click here for the final code](https://github.com/vitoska26/agrotech_project/blob/main/Accurate_soil_sensor_test.ino)
## Data analysis
TODO
