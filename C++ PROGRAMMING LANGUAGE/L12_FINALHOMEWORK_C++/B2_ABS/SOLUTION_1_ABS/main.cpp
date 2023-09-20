/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 08/09/2023
* Description:This file is used to identify the brake force based on the wheel's speed. It's likely the ABS's system in Automotive.
*/
#include<iostream>
using namespace std;

class Wheel{
    private:
        double rotationSpeedOfWheel;
    public:
        double const getSpeedForWheel ();
        void setSpeedForWheel(double inputRotationSpeedOfWheel);
};

void Wheel::setSpeedForWheel(double inputRotationSpeedOfWheel){

    this->rotationSpeedOfWheel = inputRotationSpeedOfWheel;
}

double const Wheel::getSpeedForWheel (){

    return rotationSpeedOfWheel;
}

class Car {
    private:
        double basicMassOfCar;
        double passengerMass;
        Wheel speedWheel;
    public:
        Car(double basicMassOfCar = 0);

        double const getMassOfCar();
        double getTotalMassOfCar();
        Wheel& getWheel();

        void addMassOfPassengers(double massOfPassgenrs=0);
};

Car ::Car(double basicMassOfCar): passengerMass(0.0){               // passengerMass(0.0): passengerMass property is assigned the value: 0.0.

    this->basicMassOfCar = basicMassOfCar;
}

 Wheel& Car ::getWheel(){
    
    return speedWheel;
 }

 double const Car :: getMassOfCar(){

    return basicMassOfCar;
 }

void Car :: addMassOfPassengers(double massOfPassgenrs){

    this->passengerMass += massOfPassgenrs ;
}

double Car ::getTotalMassOfCar(){

    return  basicMassOfCar + passengerMass;
}

class ABS : public Car{
    private:
        Car car;
    public:
        ABS(Car& objectOfCars);
    
        void forceBrakeApplied();
        Car& getCar();

};

ABS :: ABS(Car &objectOfCars) : car(objectOfCars) {                  // car(objectOfCars): car property is assigned the value of objectOfCars.
    
    this->car= objectOfCars;
}

Car& ABS ::getCar(){

    return car;
}

void ABS ::forceBrakeApplied(){
       
    if(getCar().getWheel().getSpeedForWheel() >= 10) cerr<<endl<<" Brake Forces are applied normally.";

    else cerr<<endl<<" Warning: The wheel is locking up! Adjusting the brake forces based on the total mass of car: "<<(double)(getCar().getTotalMassOfCar())<<" (kg)";

    cerr<<endl<<" The speed of wheel now: "<<getCar().getWheel().getSpeedForWheel()<< " (rpm)"<<endl;

}

int main(int argc, char const *argv[])
{
    Car carKia(1000);
    ABS checkOfAbs(carKia);

    checkOfAbs.getCar().getWheel().setSpeedForWheel(14);
    checkOfAbs.forceBrakeApplied();

    checkOfAbs.getCar().addMassOfPassengers(70);                  // add mass of the passenger
    checkOfAbs.getCar().getWheel().setSpeedForWheel(9);          // speed of wheel will decrease

    checkOfAbs.forceBrakeApplied();
    
    return 0;
}
