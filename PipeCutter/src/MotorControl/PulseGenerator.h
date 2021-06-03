#pragma once

#include <math.h>

class PulseGenerator
{
private:
    
    float DISTANCE; 
    float VELOCITY;
    float ACCELARETION;
    float TIME;
    float RAMP_UP;
    float RAMP_DOWN;

    double pulse;
    float d ;
    float minimum_ramp_distance;

public:
    PulseGenerator(/* args */);
    void Motordata();

    void Accelaretion(float accelrate);

    void SimpleMoveSteps(double moveSteps);//blocking code
    void RampMoveSteps(double moveSteps);//blocking code

    void SimpleMoveMm(double moveMM);//blocking code
    void RampMoveMm(double moveMm);//blocking code

    void ClosedLoopPulse();//blocking code
};

/*
void Calculator()
{
    // find RAMP_UP and RAMP_DOWN steps for motor
    int minimum_ramp_distance =  ( ACCELARETION * (VELOCITY / ACCELARETION) * (VELOCITY / ACCELARETION) )/2;
    std::cout << minimum_ramp_distance << "\n";
    DISTANCE = 2*minimum_ramp_distance;
    
    //distance based calculation for ramp
    float d ;//=1200.0 ;
    std::cout << " If distance is " << d << "\n";
    std::cin >> d;
    
    d<DISTANCE?d=d/2:d=minimum_ramp_distance;
    
    std::cout << "ramp point " << d << "\n";
    std::cout << "Then ramp up distance = " << d << "\n";
    std::cout << "Then set accelaretion = " << ACCELARETION << "\n";
    
    double ramp_time = sqrt((2*d)/(ACCELARETION));
    std::cout << "Then ramp up time = " << ramp_time << "\n";
    double total_time = 2*(sqrt((2*d)/(ACCELARETION)));
    std::cout << "Then total up time = " << total_time << "\n";
    double max_velocity = (ACCELARETION*ramp_time);
    std::cout << "Then max velocity = " << max_velocity << "\n";
    
    //std::cout << "Then ramp down point = " << (d/(d/5)) << "\n";
    
    //int ramp_point =  
}

*/