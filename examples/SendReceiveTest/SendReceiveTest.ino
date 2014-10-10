#include "SerialReceiver.h"
#include <SoftwareSerial.h>

SerialReceiver receiver = SerialReceiver();
Stream *s;
#define rxPin 3
#define txPin 4
SoftwareSerial softSerial(rxPin,txPin);

void setup() 
{

#ifdef PORTD
 Serial.begin(9600);
 s = &Serial;
#else
 softSerial.begin(9600);
 receiver.setSerialObj(&softSerial);
 s = &softSerial;
#endif

}

void loop() 
{
    int myInt;
    float myFloat;
    while (s->available() > 0) 
    {
        receiver.process(s->read());
        if (receiver.messageReady()) 
        {
            *s << "Message Ready" << endl;
            myInt = receiver.readInt(0);
            *s << "myInt = " << _DEC(myInt) << endl;
#ifdef PORTD
            myFloat = receiver.readFloat(1);
            *s << "myFloat = " << myFloat << endl;
#endif
            *s << endl;
            receiver.reset();
        }
    }
}
