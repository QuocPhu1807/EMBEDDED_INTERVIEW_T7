/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 08/09/2023
* Description:This file is used for identify the brake force based on the wheel's speed. It's likely the ABS's system in Automotive.
*/
#include<iostream>

using namespace std;

class Wheel {
    private:
        double speed;                                               // Speed of wheel (đơn vị: vòng/phút)  
    public:
        Wheel() : speed(0.0) {}                                    // speed(0.0): speed property is assigned the value: 0.0.
        void setSpeed(double s) {this->speed = s; }               // set the speed for wheel
        double getSpeed() const { return speed; }                // get the speed for wheel
};

class Car{
    private:
        Wheel wheel;
        double weight;
        double passengerWeight;
    public:
        Car(double weight) : passengerWeight(0.0){ this->weight = weight;}      // passengerWeight(0.0): passengerWeight property is assigned the value: 0.0. 
        Wheel &getWheel(){ return wheel;}
        void setWeight(double inputWeight){ this->weight = inputWeight;}
        double getWeight() const { return weight;}
        void addPassenger( double passenger){ passengerWeight += passenger;}   // add the passenger
        double getTotalWeight() const{ return weight + passengerWeight;}       // get the total weight of car.
};

class ABS{
    private:
        Car& car;
        const double threshold = 10.0;
    public:
        ABS(Car& inputCar): car(inputCar){}

        void applyBrakeForce(){

            if( car.getWheel().getSpeed() < threshold ){                      // Compare the speed of wheel to the threshold speed

                cerr<<endl<< "Warning: Wheel is locking up! Adjusting brake force based on car weight: " << car.getTotalWeight()<< " kg." << endl;
            } else {

                cerr<<"Brakes are applied normally."<<endl ;
            }

        }
};

 int main(int argc, char const *argv[])
 {
    Car carKia(1000);                  // assign the weight for car

    ABS carAbs(carKia);
    carKia.getWheel().setSpeed(15.0);   // set the speed for wheel
    carAbs.applyBrakeForce();           // function is used for check the brake force.

    carKia.addPassenger(70);           // add the weight of passenger.
    carKia.getWheel().setSpeed(9.0);   // set the speed for wheel
    carAbs.applyBrakeForce();

    return 0;
 }
 