# CBSE

Lab 2 CBD for ES and Using EFPs


Description:

 

In the second lab assignment, you will use “Cecilia” which is a development environment for programming Fractal components on top of the C programming language. The purpose of this lab is to do a component-based model of a system, to reuse components and to get hands on Extra Functional Properties (EFPs).

 

Exercise 0:

In this exercise, you are supposed to get familiar with “Cecilia” through the basic concrete example “HelloWorld”. The example shows how to implement the traditional HelloWorld Fractal example with the “Cecilia” framework.

 

Exercise 1:

The main task in this exercise is to do the component-based model of an electric kettle (Max 1 Liter capacity) using Cecilia framework. You may start with the overall component-based model using the Cecilia ADL language. Then showing the definition of the interfaces of the components involved based on the Cecilia IDL language. Finally, the implementation of the components can be done in the thinkMC language.

 

The electric kettle heats the water until it starts boiling (100°c). Then, it automatically goes off. Your task in this exercise is to define appropriate component(s) and come up with a working implementation.

 

Tips:

In order to have a working system, you may consider the following tips:

1)   First, take the water amount as the user input by displaying a prompt string on the screen.

2)   Consider the fact that more water takes more time to reach 100°c i.e., water temperature is a function of water amount.

3)   Define a component called “KettleStatus” that generates random e.g., boolean values "True"/"False" indicating whether the kettle is on or off.

4)   We don not have actual sensor to sense the water temperature! So, you may define a component called “Sensor” with a method called “IncTemp” that generates random numbers in an ascending order in the range [0, 100] i.e., every time “IncTemp” method is called, it generates a bigger value.

5)   To read the temperature, other components call the “IncTemp” method from the “Sensor” component.

 

Exercise 2:

The main task here is to do a component-based model of a “Food Sterilizer” machine that comprises two composite components: “Pre-sterilizer” and “Ready for Production”.

 

The machine starts operation and leaves standby mode upon receiving “Machine Cleaned” signal and is filled by water/steam. The “Pre-sterilizer” component heats the water/steam up to 130°c, then, keeps the water/steam in this temperature for 30 minutes. It has to continuously monitor the temperature by appropriate sensors. When temperature == 130°c, a timer is activated. When timer == 30 minutes, the “Pre-sterilizer” finishes the job and sends out “Pre-sterilized” signal to the next component. While timer < 30, if temperature falls below 130°c, the timer is reset and as soon as the temperature >= 130, it is re-activated.

 

Upon receiving the “Pre-sterilized” signal from “Pre-sterilizer” component and the external “Raw Product Ready” signal, “Ready for Production” component is activated. It heats the raw product till 140°c. Then, keeps the product for 5 sec in this temperature. Then, it cools down the product to 20°c. The machine is in operation until this component receives “Raw Product Finished” or the external “Operator Stops Production” signal. Then the machine finishes the current job and goes to standby mode afterwards. You are supposed to define the appropriate components within each composite component.

 

Exercise 3:

In this exercise, you will get hands on EFPs considering timing property in the “Food sterilizer” machine.

 

Your task is to define a “Delay Alarm” for temperature in “Ready for Production” component such that in case of missing the deadline production is aborted i.e., if the temperature in “Ready for Production” component falls below 140°c for time interval 5 sec (deadline) then, the product is aborted and the machine goes to the standby mode. This means that machine can only tolerate temperature falling the threshold for 5 sec.

 

Exercise 4 (Optional):

You are supposed to reuse the previously defined components in this exercise by adding the “Standardization” component to the “Ready for Production” composite component.

 

In case of raw milk as the input product, the “Standardization” component separates cream from raw milk. Then, it mixes the desired percentage of cream e.g., 0.5%, 1%, 3% with milk and delivers the final product. It is assumed that the product is milk in this exercise.

 

Tips:

In order to have a working system, you may consider the following tips:

1)   The temperature values from sensors can be generated similar to Exercise 1.

2)   External signals can be generated similar to “On”/”Off” states in Exercise 1 i.e., “True” or “False” for the signal where “True” means the signal is active.


