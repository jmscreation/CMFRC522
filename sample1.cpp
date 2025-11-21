//============================================================================
// Name        : sample1.cpp
// Description : Test sample using CMFRC522 class : detect the presence of a new card
//               and print its serial number
//               To compile this program, use build.bat
//============================================================================

#include "CMFRC522.h"
#include "pigpio.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>

using std::string, std::cout;

int main(int argc, char *argv[]) {
    gpioInitialise();

	MFRC522 mfrc522;
    // Initializes PCD
    mfrc522.PCD_Init();
    while(1) {
        if (mfrc522.PICC_IsNewCardPresent()) { // Detect whether a new card is present
            std::cout << "New card is here..." << std::endl;

            if(mfrc522.PICC_ReadCardSerial()){
                for (uint8_t i = 0; i < mfrc522.uid.size; i++) {
                    std::cout<<std::hex<<int(mfrc522.uid.uidByte[i])<<" ";
                }
            }
        }
    }
}

