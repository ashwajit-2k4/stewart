# Ball balancing platform

I was part of a project to make a Stewartplatform that could balance a ball rolling on it using a resistive touchpad to provide the position of the ball at any given time. There were two parts to the project:
creating the assembly itself, and writing the software to control the state of the platform depending on the position of the ball. While we initially started with a conventional Stewart platform with six actuators,
we realised that it was unnecessary and more likely to fail given our goal, and so we shifted to a three-arm design, driven by three servos with a revolute joint connecting the two arms, and a universal joint connecting 
each arm to the platform itself to prevent the arm being overconstrained.

I worked primarily on designing the assembly (shown in the CAD files), and also on the preliminary code, which we wrote for an Arduino since we didn't require a lot of compute power.
