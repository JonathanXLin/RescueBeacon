# RescueBeacon

RescueBeacon is a small, simple Arduino based device that creates a loud audio and visual signal when wirelessly activated. RescueBeacon was successfully used in the 2018 International Youth Drone Competition to win 2nd place.

## Components

The beacon consists of a Arduino Nano, 4 LEDs, and a 9V buzzer powered by a 9V battery. The beacon receives RF commands using an NRF24L01 radio transceiver. When a command is given to activate, the LEDs and Buzzer are activated using a BJT transistor.

The controller uses an Arduino Nano, NRF24L01 radio transceiver, and a button to toggle the state of the beacon.

### Beacon

<p align="center"> 
  <img src="https://i.imgur.com/dI7CyG2.png" width="500">
</p>

### Controller

<p align="center"> 
  <img src="https://i.imgur.com/hHxRSeD.png" width="250">
</p>

## Competition Use

One of the 2018 International Youth Drone Competition scenarios required a drone be flown in FPV to locate a mannequin. Once the mannequin is found, the drone must hover above its location and transmit an audio and visual signal. RescueBeacon was successfully built and used for this purpose, winning our team 2nd place.

<br>

<p align="center"> 
  <img src="https://i.imgur.com/ET3dt6C.jpg?1" width="400">
</p>
