/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 6/09/2023
* Description:This file is used for management the active of the DC motor 
              that based on max voltage, current and temperature. It's likely DC Motor in Automotive.
*/
#include<iostream>
#include<vector>
#include<stdint.h>

using namespace std;

typedef enum{
    COUNTERCLOCKWISE,
    CLOCKWISE
}typeRotationDirection;

typedef enum{
    OFF,
    ON
}typeStatusActive;

class DCMotorController{
    protected:
        float voltage;
        float maxCurrent;
        float speed; 
        float maxTemperature;
        typeRotationDirection direction;
        typeStatusActive statusActive;
    public:
        DCMotorController(float inputVoltage = 12.0, float inputMaxCurrent = 1.50, float inputMaxTemperature = 80.0);
        
        void setSpeedMotor(float inputSpeed);
        void setDirection(typeRotationDirection inputDirection);
        void setStart();
        void setStop();

        bool checkOverLoad(float inputVoltage, float inputCurrent);
        bool checkOverHeat(float inputTemperature);

        // float getMaxVoltage();
        // float getMaxCurrent();
        // float getMaxTemperature();
        float getSpeedMotor() const ;
        typeRotationDirection getDirection() const ;
   
};

DCMotorController :: DCMotorController( float inputVoltage, float inputMaxCurrent, float inputMaxTemperature){

    this->voltage        = inputVoltage;
    this->maxCurrent     = inputMaxCurrent;
    this->maxTemperature = inputMaxTemperature;
}

void DCMotorController :: setSpeedMotor(float inputSpeed){

    this->speed = inputSpeed;
}

void DCMotorController :: setDirection(typeRotationDirection inputDirection){

    this->direction = inputDirection;
}
void DCMotorController :: setStart(){

    this->statusActive = ON;
}

void DCMotorController :: setStop(){

    this->statusActive = OFF;
}

float DCMotorController :: getSpeedMotor() const {

    return speed;
}

typeRotationDirection DCMotorController ::getDirection() const {

    return direction;
}
bool DCMotorController :: checkOverLoad(float inputVoltage, float inputCurrent){

    if((inputVoltage > 0.0 && inputVoltage <= voltage) && (inputCurrent > 0.0 && inputCurrent <= maxCurrent)) return true;

    else cerr<<endl<<" Voltage or current are overload! ";

    return false;        
}

bool DCMotorController :: checkOverHeat(float inputTemperature){

    if( inputTemperature >= 0 && inputTemperature <=maxTemperature) return true;

    else cerr<<endl<<" Detecte overtemperature!";

    return false;
}

class FeedbackSystem : public DCMotorController{
    private:
        DCMotorController& dcController;      
    public:
        FeedbackSystem(DCMotorController& dcControllers) : dcController(dcControllers) {};  //  dcController(dcControllers): passengerWeight property is assigned the class: dcControllers 

        void controllMotor(float inputVoltage, float inputCurrent, float inputTemperature);
        DCMotorController &getDcController();
};

DCMotorController& FeedbackSystem ::getDcController(){

    return dcController;
}

void FeedbackSystem :: controllMotor(float inputVoltage, float inputCurrent, float inputTemperature ){
    
    if(checkOverHeat(inputTemperature) && checkOverLoad(inputVoltage, inputCurrent)){

        cerr<<endl<<" DC Motor active at speed : "<< dcController.getSpeedMotor()<<" (rpm)";
    }

    else{

        dcController.setStop();
        cerr<<endl<<" Detecte the fault! Stopping the DC motor. ";
    }
    cerr<<endl;
}

int main(int argc, char const *argv[])
{
    DCMotorController dcController(13.0, 1.5, 80.0);  //: DCMotorController(voltage, maxCurrent, maxTemperature);

    dcController.setStart();
    dcController.setDirection(CLOCKWISE);
    dcController.setSpeedMotor(2000);

    FeedbackSystem feedback(dcController);

    //feedback.getDcController().checkOverLoad(12, 1.4);
    //feedback.getDcController().checkOverHeat(90.0);
    
    feedback.controllMotor(12, 1.4, 80.0);

     
    feedback.controllMotor(12, 1.4, 90.0);

    return 0;
}


