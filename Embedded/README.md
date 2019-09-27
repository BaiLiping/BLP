Material:
1. [Jonathan Valvano](https://www.youtube.com/channel/UCVf1i0hXlLsXIrF7V1NWA0Q)
2. [TI Robotics](https://training.ti.com/ti-robotics-system-learning-kit)

key skillsets:
1. Writing to registers with C
2. Industry Best Practices. There are more than one ways to accomplish a certain goal with microcontrollers. Novice and Experts differ in terms of risk control and adaptive capacitys of their code. Experts make sure that every line of the code does not interfere with other functionalities already exist, also, if later on you find that you need add functinality to your code, you might want to structure/planning ahead for that.
3. Version Control. There are all kinds of fancy tools for this. But what I find is that just save your work at the end of the day into a new folder, named after the date. This is dumb i know, but works for me.
4. Modularity. the main code should be self-explainatory, all the functionalities should be packaged into modules.
5. Capacities provided by MicroController:
1) Basic Communication Protocols such as UART, SPI, I2C
2) Hardware controlled PWM
3) ADC/DAC
6. Ninja Level use of MicroControllers:
1) Multi-threading
2) Scheduler
3) Hard Realtime Control
7. Interfacing of MicroController and Circuit
this is not as simple as it seems. Quite a lot considerations goes into the design, such as max current, max voltage. MicroController should be treated as a delicate object that is easily broken.
8. PCB Design
1) Signal Integrity, but mostly for high speed circuit
2) Layered Design of PCB (FR4)
3) Most of the PCB would feature of MicroController in the middle and various drivers around. How to power the system should be carefully considered, what is the current in the system, etc.

