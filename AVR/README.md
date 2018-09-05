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
>> Insert "/dev/ttyACM0" on "Override default port (-P)". Note that this is your Port configuration, if isn't ok verify with "dmesg" command.
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

# Important Links

[Arduino schematic](https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf)