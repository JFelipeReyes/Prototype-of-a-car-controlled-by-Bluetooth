# PROTOTYPE OF A CAR CONTROLLES BY BLUETOOTH
In this repository you can find all the information relevant to the development of this project, we made use of a MPlab plugin "code configurator" to configure the serial communication and read it from another plugin "data visualizer" or a Bluetooth terminal on a phone.

# What's the use?

Due to contingencies with the communication only the transmission of the MCU could be guaranteed, and macros were established to move forward, backward, rotate and stop, as a demonstration of the communication due to contingencies with the communication only the transmission of the MCU could be guaranteed, and macros were established to move forward, backward, rotate and stop, as a demonstration demonstration when activating any of the macros the MCU sends a message to the serial port and is transmitted via Bluetooth that can be read by an application on a mobile device.

# How to use?

The MCU must be powered after being connected to the bluetooth module and the L298n controller (H-bridge), then leave it on a flat and wide surface to run the sequence and stop.

# How to install it?

* Download the APK of the application, go to the file manager to find the APK previously downloaded (if it is the first time you are going to install an APK from the file manager it will ask for permissions to do the installation, follow the steps that appear on the screen), at the end of the installation go to the main screen to start the application.

![APP](https://i.imgur.com/hbXglhE.jpg)

* Para visualizar la comunicación serial se utilizo la aplicación "Bluetooth SPP".

![Bluetooth SPP](https://imgur.com/JQsUVjX)



#  Information about PIC16F15244 Curiosity Nano Evaluation Kit

![PIC16F15244](https://i.imgur.com/DyVkeEG.jpg?1)

* [PIC16F15244](https://www.microchip.com/wwwproducts/en/PIC16F15244).

* [PIC16F15244 Curiosity Nano Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/EV09Z19A).

* [PIC16F15244 Curiosity Nano Hardware User Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC16F15244-Curiosity-Nano-Hardware-User-Guide-DS50003045A.pdf).

* [PIC16F15244 Curiosity Nano Schematics](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC16F15244_Curiosity_Nano_Schematics.pdf).

* [PIC16F15244 Curiosity Nano Design Documentation](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC16F15244_Curiosity_Nano_Design_Documentation.zip).

* [PIC16F15244 Curiosity Nano Altium Project](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC16F15244_Curiosity_Nano_Altium_Project.zip).

# Software

* This MPU operates with the compiler [XC8](http://ww1.microchip.com/downloads/en/DeviceDoc/MPLAB_XC8_C_Compiler_User_Guide_for_PIC.pdf)of microchip.

* [MPLAB-X-IDE](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide).

* [Code Configurator](https://www.microchip.com/en-us/development-tools-tools-and-software/embedded-software-center/mplab-code-configurator).

*[Data Visualizer](https://www.microchip.com/en-us/development-tools-tools-and-software/embedded-software-center/mplab-data-visualizer).

# Schematic circuit
![Schematic circuit](https://imgur.com/u8DykT3)
