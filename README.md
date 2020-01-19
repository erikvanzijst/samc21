# Bare metal ARM MCU testing

A little project into getting a bare [32 pin, TQFP SAMC21E18A](http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en598829) chip to do something.

![](images/breakouts.jpg)


## Prerequisites

Install the ARM embedded toolkit and openocd (`brew install homebrew/cask/gcc-arm-embedded openocd`).

Get an [Atmel-ICE programmer](https://www.digikey.com/short/z72v4z).


## Schematic

![](images/samc21_schematic.png)

Connect the programmer to the breadboard

![](images/breadboard.jpg)

Power up the board.




## Compile and write flash

Figure out the serial number of the ICE programmer. On OSX look in "System Information -> USB"; on Linux use `lsusb`:

```
$ lsusb | grep Atmel
Bus 001 Device 004: ID 03eb:2141 Atmel Corp. ICE debugger
$ lsusb -v -s 001:004 | grep iSerial
  iSerial                 3 J42700008952
```

Write the serial number to `openocd.cfg`.

Compile:
```
$ cd gcc
gcc$ make
CC build/main.o
CC build/startup_samc21n.o
LD build/blinky.elf
OBJCOPY build/blinky.hex
OBJCOPY build/blinky.bin
size:
   text	   data	    bss	    dec	    hex	filename
    352	      0	      0	    352	    160	build/blinky.elf
    352	      0	      0	    352	    160	(TOTALS)
$
```

and upload to the MCU:

```
$ make program
Writing flash...
openocd -f openocd.cfg -c "program build/blinky.elf verify reset exit"
Open On-Chip Debugger 0.10.0
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
none separate
adapter speed: 400 kHz
cortex_m reset_config sysresetreq
Info : CMSIS-DAP: SWD  Supported
Info : CMSIS-DAP: JTAG Supported
Info : CMSIS-DAP: Interface Initialised (SWD)
Info : CMSIS-DAP: FW Version = 01.00.0021
Info : SWCLK/TCK = 1 SWDIO/TMS = 1 TDI = 1 TDO = 1 nTRST = 0 nRESET = 1
Info : CMSIS-DAP: Interface ready
Info : clock speed 400 kHz
Info : SWD DPIDR 0x0bc11477
Info : at91samc21n18.cpu: hardware has 4 breakpoints, 2 watchpoints
target halted due to debug-request, current mode: Thread 
xPSR: 0x21000000 pc: 0x00000110 msp: 0x20008000
** Programming Started **
auto erase enabled
Info : SAMD MCU: SAMC21E18A (256KB Flash, 32KB RAM)
wrote 16384 bytes from file build/blinky.elf in 2.098460s (7.625 KiB/s)
** Programming Finished **
** Verify Started **
verified 352 bytes in 0.062266s (5.521 KiB/s)
** Verified OK **
** Resetting Target **
shutdown command invoked
$
```

The LED should start flashing.
