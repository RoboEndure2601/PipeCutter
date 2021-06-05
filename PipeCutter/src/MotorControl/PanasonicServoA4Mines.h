#pragma once

#include "src/board/board.h"
//#include "Configuration.h"


//define variable for Panasonic A4 mines motor control
float PPR_value = 30; // This value set in Panasonic A4 Series Servo drive
int max_velocity = 600;
int max_accel = 120;
float Minimum_ramp_distance = 1001;
float default_accel = 10;

float moving_to_ramp;
float accel = 00.00;
float velocity = 00.00;

// updated parameter
int DELAY = 40;         // delay between steps in microsenconds(the initial movement)  
int DELAY_SLOW = 120;   // delay between steps in microsenconds(the second reverse movement)

int BRAKE = 5;          // delay between end of rotation and encoderB measurment in miliseconds     
int OFFSET= 2;             //  value to set the number of steps the stepper should overshoot its target             
    
int encoderA;     //encoder before moving
int encoderB;     //encoder after moving
int encoderD;     //econder Delta

int ENCODER_PPR = 400;

volatile unsigned int temp = 0;  //This variable will increase or decrease depending on the rotation of encoder
int counter = 0;
int DISTANCE = 0;

int I_OVERSHOT=0;
int CORRECTED=0;

int CORRECT=0;

int LOR=0;

boolean GO = false;
boolean DIR_REV = false;

long  DEST = 0;
long  SOURCE =0;
long DIFF = 0;
long DIFFplus=0;
long DIFFmin=0; 
int CHECK=0;
int BOUNCE=100;

boolean C1=false;
boolean C2=false;
boolean C3=false;
boolean C4=false;
boolean REVERSE=false;
/*
 //upcoming version support Accelaretion and Deaccelaretion for more power and accuray
void Accel()
{

}

void Deaccel()
{

}
*/


void ai0() 
{
    // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
    // Check pin 3 to determine the direction
    if(digitalRead(3)==LOW) 
    {
        counter++;
    }
    else
    {
        counter--;
    }
}

void ai1()
{
    // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
    // Check with pin 2 to determine the direction
    if(digitalRead(2)==LOW) 
    {
        counter--;
    }
    else
    {
        counter++;  
    }
}

void PanasonicA4mines_setup()
{
    //PanasonicA4mines.connectToPins(SERVO_STEP_PIN,SERVO_STEP_PIN);

    // intrrupt for encoder input 
    //attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_A_PIN), checkPosition, CHANGE);
    //attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_B_PIN), checkPosition, CHANGE);

    // This is declare in src/board/pin.h
    //pinMode(ENCODER_PHASE_A_PIN, INPUT_PULLUP); // internal pullup input pin 2 

    //pinMode(ENCODER_PHASE_B_PIN, INPUT_PULLUP); // internal pullup input pin 3
    
    //Setting up interrupt
    //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
    attachInterrupt(0, ai0, RISING);

    //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
    attachInterrupt(1, ai1, RISING);

}

//used for only testing purpose
void MoveToPosition(float moving_mm)
{
    DEST = moving_mm * PPR_value;

    DIFF=ENCODER_PPR-abs(abs(SOURCE-DEST)-ENCODER_PPR);
    DIFFplus=ENCODER_PPR-abs(abs((SOURCE+1)-DEST)-ENCODER_PPR);
    DIFFmin=ENCODER_PPR-abs(abs((SOURCE-1)-DEST)-ENCODER_PPR);

    if(DIFFplus>DIFFmin)
    {
        digitalWrite(SERVO_DIR_PIN,LOW);     //counter CLOCK wise
    }

    if(DIFFplus<=DIFFmin)
    {
        digitalWrite(SERVO_DIR_PIN,HIGH);  //CLOCK wise
        //Serial.println("X");
    }
    if(DEST!=SOURCE)
    {  
        // diffrence between Source and Destination is tested
        GO=true;
        encoderA = counter;          // the position before the movement start is stored encoder A

        // Serial.print("SOURCE");
        // Serial.println(SOURCE);

        //  Serial.print("DEST");
        // Serial.println(DEST);


        // Serial.print("DIFF");
        // Serial.println(DIFF);

        //   Serial.print("DIFFplus");
        // Serial.println(DIFFplus);

        // Serial.print("DIFFmin");
        //Serial.println(DIFFmin);
    }

    while (GO)
    {
        digitalWrite(SERVO_STEP_PIN,HIGH);
        delayMicroseconds(DELAY);                      
        digitalWrite(SERVO_STEP_PIN,LOW); 
        delayMicroseconds(DELAY);
        encoderB = counter; 
        encoderD=32752+(1/2)-abs(abs(encoderA-encoderB)-32752+(1/2)); //  the diffrence between encoder A & B is calculated and stored in encoderD      

        if (encoderD > (DIFF+OFFSET))   
        {
            GO=false;
            //SOURCE=DEST;                        ///// remove this line 
            C1=true;

        }
    }

    if(C1)
    {

        delay(BRAKE);         // make sure the setup stoped completely
        encoderB = counter;
        encoderD=32752+(1/2)-abs(abs(encoderA-encoderB)-32752+(1/2)); //  update encoderD

        // Serial.print("encoderD   ");
        //Serial.println(encoderD);


        I_OVERSHOT=encoderD-DIFF; // POS is set to the value the stepper is stoped
        C1=false;
        C2=true;

        // Serial.print("I_OVERSHOT   ");
        // Serial.println(I_OVERSHOT);

    }



    while(C2)

    {

        if(DIFFplus>DIFFmin)  
        {
            digitalWrite(SERVO_DIR_PIN,HIGH);   //clock
            DIR_REV=false;
        }

        if(DIFFplus<=DIFFmin)
        {
            digitalWrite(SERVO_DIR_PIN,LOW);    //counter
            DIR_REV=true;
        }

        C2=false;
        REVERSE=true;
        encoderA = counter;          // the position before the movement start is stored encoder A
        // Serial.print("LOR");
        // Serial.println(LOR);

    }



    while (REVERSE)
    {
        // Serial.println("Y");
        digitalWrite(SERVO_STEP_PIN,HIGH);
        delayMicroseconds(DELAY_SLOW);                      
        digitalWrite(SERVO_STEP_PIN,LOW); 
        delayMicroseconds(DELAY_SLOW);

        encoderB = counter;
        encoderD=32752+(1/2)-abs(abs(encoderA-encoderB)-32752+(1/2)); //  the diffrence between encoder A & B is calculated and stored in encoderD 

        if(encoderD>=I_OVERSHOT)      // 
        {
            REVERSE=false;
            C3=true;
        }
    }

    if(C3)
    {

        delay(BRAKE); // make sure the setup stoped completely

        encoderB = counter;
        encoderD=32752+(1/2)-abs(abs(encoderA-encoderB)-32752+(1/2)); //  the diffrence between encoder A & B is calculated and stored in encoderD
        CORRECTED = encoderD;
        C3=false;
        C4=true;

        // Serial.print("CORRECTED   ");
        // Serial.println(CORRECTED);

    }

    while(C4)
    {
        if(CORRECTED==I_OVERSHOT)    // the correction was spott. SOURCE can be set to DEST and no correction is needed 
        {
        SOURCE=DEST;
        //   Serial.println("1");
        }



        if((CORRECTED < I_OVERSHOT)&& (DIR_REV))      // (1) clock high (2) counter low   // UNDERCORRECTED  xx 
        {

            SOURCE = (DEST + (I_OVERSHOT-CORRECTED)) ;
            DEST=SOURCE;


            //    Serial.print("SOURCE   ");
            //  Serial.println(SOURCE);

            // Serial.print("DEST   ");
            //  Serial.println(DEST);


            // Serial.println("2");
            // Serial.println();
        }

        /*  pos 0>>> pos 200
        *   pos 0>>> pos 210  
        *   
        *        pos205<<<pos 210    diffrence = CORRECTED

        new source = dest + corrected    
        ...                                   
        1000>>>0
        *  I_over 1000>>>50 
        *        30<<<50

        new source(previous dest + CORRECTED = 0+20 = 205


        */

        if((CORRECTED > I_OVERSHOT)&& (DIR_REV))      // (1) clock high (2) counter low   // overcorrect  xx
        {
            SOURCE = (DEST - (CORRECTED-I_OVERSHOT)) ;
            DEST=SOURCE;
                                                                    // note: DEST and SOURCE can become negative, fix that whith something

            //  Serial.print("SOURCE   ");
            //  Serial.println(SOURCE);

            //  Serial.print("DEST   ");
            // Serial.println(DEST);

            //    Serial.println("3");
            // Serial.println();

        }

        if(SOURCE<0)
        {
            DEST = 1200+SOURCE;
            SOURCE=DEST;
            //Serial.println("VALUE IN BOX 3 IS CORRECTED   ");    
        }

        if((CORRECTED < I_OVERSHOT)&& (!DIR_REV))      //(1)counter high (2) CLOCK low //UNDERCORRECTED
        {

            SOURCE= (DEST-(I_OVERSHOT-CORRECTED)) ;
            DEST=SOURCE;    


            // Serial.print("SOURCE   ");
            // Serial.println(SOURCE);

            //Serial.print("DEST   ");
            //Serial.println(DEST);
            //   Serial.println("4");
            // Serial.println();

        }

        if((CORRECTED > I_OVERSHOT)&& (!DIR_REV))       //(1)counter high (2) CLOCK low//OVERCORRECTED
        {

            SOURCE= (DEST-(I_OVERSHOT-CORRECTED)) ;
            DEST=SOURCE;   

            //  Serial.print("SOURCE   ");
            //Serial.println(SOURCE);

            // Serial.print("DEST   ");
            //Serial.println(DEST);
            //   Serial.println("5");
            // Serial.println();

        }
            C4=false;
    }

}

/*
void MoveToPosition(float moving_mm)
{
    unsigned long mmToMove = moving_mm * PPR_value;

    for(unsigned long i = 0; i <= mmToMove; i++)
    {
        digitalWrite(SERVO_STEP_PIN,HIGH);
        delayMicroseconds(100);
        digitalWrite(SERVO_STEP_PIN,LOW);
        delayMicroseconds(100);
    }
}
*/

