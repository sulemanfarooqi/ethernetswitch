# Ethernet Switch Simulator


<!-- TABLE OF CONTENTS -->
## Table of Contents
* [About](#about)
* [What is a switch?](#what-is-a-switch)
* [How does a switch work?](#how-does-a-switch-work)
* [Implementation](#implementation)


<!-- ABOUT -->
## About 
This program was designed to show how ethernet switches work by using an input text file that contains information in the form of a frame that is relevant to a network.
The code itself will not be explained in the readme but if you check out the source code then I have commented how the code works.

<!-- WHAT IS A SWITCH -->
## What is a switch?
A switch is a device that that connects mutliple devices on a network, it transfers information between the devices by something called a "frame" which consists of information such as the ID of the frame, the port that frame came from, the MAC address of the source computer and the MAC address of the destination computer. By having all those elements a switch can easily transfer information from one device/computer to another. 

<!-- HOW DOES A SWITCH WORK -->
## How does a switch work?
A frame is passed through the switch, it first reads the port, the MAC address of the source computer and the frame ID. This way a switch can start mapping the network to see where the computers are located. When a switch initializes for the first time it has no knowledge of the computers located on the network, thus there is a slight delay in transfer of information at startup which varies by the size of the network. When a switch recieves a frame the information will be stored into a CAM table, which stores the location of the computers according to their ports.

If a switch has recieved a frame and the frame consits of a destination address that is not in the CAM table, then the switch will send that frame to all the ports on the network except the port which the source came from, this is a default rule that switches follow. In addition this rule is also used for when the destination address is not specified to a single device/computer but to all devices on the network, this is called a Broadcast Frame. A broadcast frame has many different purposes such for collision avoidance but that is not important on how a switch works.

<!-- IMPLEMENTATION -->
## Implementation 
