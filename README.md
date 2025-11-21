# This library essentially ports the Arduino MFRC522 driver into a raspberry pi C++ compatible version #

This comes with very limited documentation as this is simply from a project that required this code.

I have added a simple build script to compile the sample code. This uses the [Prebuilt Windows Toolchain for Raspberry Pi](https://gnutoolchains.com/raspberry/) cross-compiler.

On Windows, install the GNU Toolkit for Raspberry Pi, make sure the PATH is configured, run `build.bat`, then copy the `sample1` file to your raspberrypi and run it. **You'll need to make sure your pins are connected to your MFRC522 Module correctly.**

Enjoy
