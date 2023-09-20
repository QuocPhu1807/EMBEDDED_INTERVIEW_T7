/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file print Date in Week based on dd/mm/yy when you input
*/

#include"SinhVien.hpp"

void SinhVien::SetInformation1(string ten, int tuoi){

       TEN = ten;
       TUOI = tuoi;
       NAM_SINH = 201;
       ID =60;
       CMND= 30;
}
void SinhVien::Display1(){

     cout << "TEN: " <<TEN <<endl;
     cout << "TUOI: " <<TUOI <<endl;
     ID = 900;
     display1();
     display2();
}

int SinhVien :: ID =10;

int SinhVien::CMND;

void HocSinh::SetInformation(string ten, int tuoi, int mssv){
    TEN  = ten;
    TUOI = tuoi;
    MSSV = mssv;
    ID = 21;
}
void HocSinh :: Display(){
    // cout << "TEN: " <<TEN <<endl;
    // cout << "TUOI: " <<TUOI <<endl;
    // cout << "MSSV: " << MSSV <<endl;
    Print();
}

void SinhVien::display1(){
    cout<<"Nhap TEN: "<< TEN <<endl;
    cout<<"Nhap TUOI: "<<TUOI << endl;
}

void SinhVien::display2(){

    cout<<"Nhap NAM_SINH: "<< NAM_SINH<< endl;
    cout << "ID: " <<ID <<endl;
    CMND = 800;
    cout<<"Nhap CMND: "<<CMND<< endl;
}

void HocSinh::Print(){

    cout<<"MSSV HOC SINH: "<< MSSV<<endl;
    ID = 812;
    printf("------\n");
    display2();
    printf("------\n");
    Display1();
}