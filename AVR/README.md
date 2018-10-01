# AVR ATmega2560

This experiments are made with Modified Eclipse.
Follow all instructions for execute the old and new projects.

# Step by Step

## Configure Eclipse IDE for AVR use.

Wait for the special link.

## Configure new Workspace.

1. Create a project:

```
File > new > C++ Project > AVR Cross Target Application > Empty Project > AVR-GCC Toolchain

>> Put the new name on "Project name"
>> Click on Finish
```

2. Configure the project to AVR use:

```
>> Right click on project name.
>> Properties
> AVR > AVRDUDE > New ...
>> Insert a new "Configuration name".
>> Insert "/dev/ttyUSB0" on "Override default port (-P)". Note that this is your Port configuration, if isn't ok verify with "dmesg" command.
>> Insert "-D" option on "Use this field to add any avrdude option not covered by the plugin.".
>> Select "Atmel AVR ISP mkll" on "Programmer Hardware (-c)" option.
>> OK
```

3. Configure the project to AVR compile:

```
>> Right click on project name.
>> Properties
> C/C++ Build > Settings
>> Check the options:
- Generate HEX file from flash memory
- Generate Extended Listing (Source + generated Assembler)
- Print Size
>> OK
```

# Makefile

You can use the file [Makefile](https://github.com/leticiacoelho/EmbeddedSystems/tree/master/AVR/Makefile) made by [Bruno Pinho](https://github.com/bruno-antonio-pinho).
You just need to change the ```PRG``` variable value for the file's name that will be compiled (without .cpp).

## Important commands

* Generate a new binary file. ```make```
* Save information on board. ```make flash```

# Important Links

* [Arduino schematic](https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf)
