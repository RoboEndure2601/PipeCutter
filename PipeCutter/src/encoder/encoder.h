#pragma once

class encoder
{
private:
    volatile int lastEncoded = 0;
    volatile long encoderValue = 0;

    long lastencoderValue = 0;

    int lastMSB = 0;
    int lastLSB = 0;

    int encoderPin1;
    int encoderPin2;
    
public:
    encoder(int _encoderPin1 , int _encoderPin2);
    void updateEncoder(/* args */);
};