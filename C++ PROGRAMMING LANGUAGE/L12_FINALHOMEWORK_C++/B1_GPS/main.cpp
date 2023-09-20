/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 6/09/2023
* Description: This file is used to calculate the distance between two coordinates(latitude, longitude) on the EARTH based on the Haversine formula.
*/

#include<iostream>
#include<math.h>

using namespace std;

#define EARTH_RADIUS 6371

class GPSPoint{
    private:
        double latitude;
        double longitude;
    public:
        GPSPoint(double inputLatitude, double inputLongitude);

        bool isValidOfPoint();

        void convertToRadians(double inputLatitude, double inputLongitude);

        double getLatitude()  const;
        double getLongitude() const;

};

GPSPoint :: GPSPoint(double inputLatitude, double inputLongitude){

    this->latitude   = inputLatitude;
    this->longitude  = inputLongitude;
}

bool GPSPoint ::isValidOfPoint(){

    if((latitude >= -90.0 && latitude <= 90.0) && (longitude >= -180.0 && longitude <=180.0) ) return true;

    else{

        cerr<<" The latitude and the longitude are not right!!"<<endl; 
    }
        return false;
}

void GPSPoint :: convertToRadians(double inputLatitude, double inputLongitude){

    this->latitude  = (double)(inputLatitude * (M_PI/180));

    this->longitude = (double)(inputLongitude * (M_PI/180));

}

double GPSPoint :: getLatitude() const {

    return latitude;
}

double GPSPoint :: getLongitude() const {

    return longitude;
}

void distanceBetweenPoints(double latitude1, double longitude1, double latitude2, double longitude2){

    cerr<<endl<<" Calculate the distance between two coordinate on Earth according to the Haversine formula: "<<endl;

    double distanceOfTwoPoint;

    //distanceOfTwoPoint   = 2*EARTH_RADIUS*asin(sqrt(pow(sin((latitude2-latitude1)/2),2)+cos(latitude1)*cos(latitude2)*pow(sin((latitude2-latitude1)/2),2)));
    distanceOfTwoPoint = 2*EARTH_RADIUS*asin(sqrt(pow(sin((latitude2-latitude1)/2),2)+cos(latitude1)*cos(latitude2)*pow(sin((latitude2-latitude1)/2),2)));

    cerr<<endl<<" The distances between two coodinates on the Earth: "<< (double)distanceOfTwoPoint <<" (km)";
}

int main(int argc, char const *argv[])
{
    cout<<endl<<" Please enter the coordinate of point 1:";
    double inputLatitude1;
    double inputLongitude1;
    while(1){

        cout<<endl<<" Latitude of point 1: ";
        cin>> inputLatitude1; cin.ignore();
        if(inputLatitude1 >= -90.0 && inputLatitude1 <= 90.0) break;
        else cout<<endl<<" Enter the value in range of [-90,90].";

    }
    while(1){

        cout<<endl<<" Longitude of point 2: ";
        cin>> inputLongitude1; cin.ignore();
        if(inputLongitude1 >= -180.0 && inputLongitude1 <= 180.0) break;
        else cout<<endl<<"Enter the value in range of [-180,180]. ";

    }

    GPSPoint gpsPonit1(inputLatitude1, inputLongitude1);
    if(gpsPonit1.isValidOfPoint()) gpsPonit1.convertToRadians(inputLatitude1, inputLongitude1);
    
    cout<<endl<<" Please enter the coordinate of point 2:";
    double inputLatitude2;
    double inputLongitude2;

    while(1){

        cout<<endl<<" Latitude of point: ";
        cin>> inputLatitude2; cin.ignore();
        if(inputLatitude2 >= -90.0 && inputLatitude2 <= 90.0) break;
        else cout<<endl<<" Enter the value in range of [-90,90].";

    }
    while(1){

        cout<<endl<<" Longitude of point: ";
        cin>> inputLongitude2; cin.ignore();
        if(inputLongitude2 >= -180.0 && inputLongitude2 <= 180.0) break;
        else cout<<endl<<"Enter the value in range of [-180,180]. ";

    }
    
    GPSPoint gpsPonit2(inputLatitude2, inputLongitude2);
    if(gpsPonit2.isValidOfPoint()) gpsPonit2.convertToRadians(inputLatitude2, inputLongitude2);

    distanceBetweenPoints(gpsPonit1.getLatitude(), gpsPonit1.getLongitude(), gpsPonit2.getLatitude(), gpsPonit2.getLongitude());

    return 0;
}
