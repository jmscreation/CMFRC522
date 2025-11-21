@echo off

echo Build Sample

arm-linux-gnueabihf-gcc -Iinclude -Ilibraries\pigpio\include -s -c libraries\pigpio\src\pigpio.c -o libraries\pigpio\pigpio.o
arm-linux-gnueabihf-gcc -Iinclude -Ilibraries\pigpio\include -s -c libraries\pigpio\src\command.c -o libraries\pigpio\command.o

arm-linux-gnueabihf-c++ -Iinclude -Ilibraries\pigpio\include -Iinclude -std=c++20 -O3 -Os -s -c src\CMFRC522.cpp -o src\CMFRC522.o
arm-linux-gnueabihf-c++ -Iinclude -Ilibraries\pigpio\include -Iinclude -std=c++20 -O3 -Os -s -c src\spi_helper.cpp -o src\spi_helper.o
arm-linux-gnueabihf-c++ -Iinclude -Ilibraries\pigpio\include -Iinclude -std=c++20 -O3 -Os -s -c src\arduino_remap.cpp -o src\arduino_remap.o

arm-linux-gnueabihf-c++ -Iinclude -Ilibraries\pigpio\include -Iinclude -std=c++20 -O3 -Os -s -c sample1.cpp -o sample1.o

arm-linux-gnueabihf-g++ -o sample1 libraries\pigpio\pigpio.o libraries\pigpio\command.o src\CMFRC522.o src\spi_helper.o src\arduino_remap.o sample1.o -static -static-libstdc++ -static-libgcc -lpthread