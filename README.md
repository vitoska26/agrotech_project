# Agrotech 2022 watering system project
## Project Goal
We wanted to make an irrigation system that will automatically water the plants to keep the soil humidity ≤ 41%.
We wanted to make the irrigation system specifically tuned for the different plants it is connected to because each plant is positioned a little differently than the others, which can lead to different values.

### The system structure
We used the SH sensor in order to measure the soil humidity. the sensors send data to Thingspeak. The system calculates the VPD of each plant and

We started by building a prototype that measures the soil humidity for one plant. When the humidity was ≤ 41%, the prototype irrigated the plant until the soil reached 100% humidity.

### The prototype
![Prototype](https://user-images.githubusercontent.com/91986255/179000675-68276c4d-32a7-4e2e-b659-fc2c33ef77c8.jpeg)

Then, we wanted to make the irrigation for crops. We made it with one ESP and attached it 4 different SH sensors, relays and irrigation systems.
We encountered an issue of readings that are not received from all the SH sensors, which caused the irrigation system to not work.
After 3 hours of investigation, we understood that the problem was that the ESP was low-end and didn't support connection of 4 different sensors simultaniously, but only 2. In addition we saw that one of the ESP pins was bent on the breadboard
![Bent pin](https://user-images.githubusercontent.com/91986255/179001783-73ccc5d5-1d0a-473f-ac53-addc0dc241e5.jpeg)

Therefore, we split the sensors between 2 different ESPs and connected them to the breadboard carefully to not harm the pins.

## The final outcome

![WhatsApp Image 2022-07-14 at 16 50 08](https://user-images.githubusercontent.com/91986255/179002137-ef69bb09-e792-4f0a-be5d-d7007f262c5a.jpeg)
![WhatsApp Image 2022-07-14 at 16 50 09](https://user-images.githubusercontent.com/91986255/179002213-14f661ef-38e4-4d9a-a6d1-49d43fabdad2.jpeg)


![WhatsApp Image 2022-07-14 at 16 48 59](https://user-images.githubusercontent.com/91986255/179002364-831d9659-e40f-41da-9dff-58a7027fa39f.jpeg)

We created a system that can sense each plant individually using SH sensor for each plant. The system can respond very quickly (~several seconds) to humidity changes and irrigate the plant accordingly.
We placed the system on 2 pepper crops, 1 tomato and 1 corn.

## Data analysis
TODO
