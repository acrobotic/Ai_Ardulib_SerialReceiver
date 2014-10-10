#ifndef SERIALRECEIVER_H
#define SERIALRECEIVER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Streaming.h"
<<<<<<< HEAD
#include <SoftwareSerial.h>
=======
>>>>>>> cd7fd877de2ba685e047a300b5de4ec8b7434934

enum {SR_MAX_ITEM_SZ = 25};
enum {SR_MAX_ITEMS = 5};

const char SR_DFLT_START_CHAR = '[';
const char SR_DFLT_STOP_CHAR = ']';
const char SR_DFLT_SEP_CHAR = ','; 

const int SR_STATE_IDLE = 0;
const int SR_STATE_RECEIVING = 1;
const int SR_STATE_MESSAGE = 2;

const int SR_ERR_NONE = 0;
const int SR_ERR_ILLEGAL_CHAR = 1;
const int SR_ERR_ITEM_LENGTH = 2;
const int SR_ERR_MESSAGE_LENGTH = 3;

class SerialReceiver {

    public:
        SerialReceiver();
<<<<<<< HEAD
        void setSerialObj(SoftwareSerial *serial);
=======
>>>>>>> cd7fd877de2ba685e047a300b5de4ec8b7434934
        void process(int serialByte);
        bool messageReady();
        void reset();
        uint8_t numberOfItems();
        uint8_t itemLength(uint8_t itemNum);
        char readChar(uint8_t itemNum, uint8_t ind); 
        int readInt(uint8_t itemNum);
        long readLong(uint8_t itemNum);
        float readFloat(uint8_t itemNum);
        double readDouble(uint8_t itemNum);
        void copyString(uint8_t itemNum, char *string, uint8_t size);
        void printInfo();
        void printMessageInfo();
        void printMessage();
        
    private:
<<<<<<< HEAD
        Stream *_serial;
=======
>>>>>>> cd7fd877de2ba685e047a300b5de4ec8b7434934
        uint8_t state;
        uint8_t error;
        char itemBuffer[SR_MAX_ITEMS][SR_MAX_ITEM_SZ+1];
        uint8_t itemLenBuffer[SR_MAX_ITEMS];
        uint8_t itemCnt;
        uint8_t itemPos; 
        char startChar;
        char stopChar; 
        char sepChar;
        void resetItems();
        void resetState();
        void processNewMsg(int serialByte);
        void processCurMsg(int serialByte);
        void handleNewChar(int serialByte);
        void handleSepChar(int serialByte);
        void handleStopChar(int serialByte);
        void handleStartChar(int serialByte);
        bool checkItemRange(uint8_t itemNum);
};


#endif
