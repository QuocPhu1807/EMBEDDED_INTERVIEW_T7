#include<iostream>

typedef enum{
    ECONOMIC,
    SPORT
}drivingMode;

typedef enum{
    OFF, 
    ON
}activeMode;

class Battery{
    private:
        float maxVoltage;
        float maxCurrent;
        float presentVoltage;
        float presentCurrent;
        float batteryTemperate;
        float percentOfBattery;
        activeMode coolingFanActive;
    public:
        Battery() : maxVoltage(72.0), percentOfBattery(100.0), batteryTemperate(25.0), coolingFanActive(ON){};

        void isOnCoolingFan();
        void isOffCoolingFan();

        float getTemperateOfBattery() const;
        float getPercentOfBattery() const;

};

class DcMotor{
    private:
        float voltage;
        float motorSpeed;
    public:
        void drivingMode();

};

class HandGrip{
    private:
        float angleOfHandGrip;
    public:
        void getAngleOfHandGrip();

};


class ElectronicCar{
    private:
        Battery battery;
        DcMotor dcmotor;
        HandGrip handGrip;
        activeMode isOperate;
    public:
        ElectronicCar() : isOperate(OFF){};

        void isOn();
        void isOff();
        void isOperateForCar();
        void drivingMode(const drivingMode drivingmode);
        void display();

};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
