#include"OOP.hpp"


void DoiTuong :: SetInformation(string ten, int tuoi){
    this->TEN = ten;                                    // the term 'this' is pointer of class DoiTuong 
    this->TUOI = tuoi;
}

void DoiTuong :: Display(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
}

void SinhVien::SetInformation1(string ten, int tuoi, int mssv){

    this->TEN = ten;
    this->TUOI = tuoi;
    this->MSSV = mssv;

}

 void SinhVien::Display1(){

    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;

 }

 void HocSinh::PrintData(){

    TEN  = "PHU DOAN";
    TUOI = 20;

    cout<< "Xuat ra du lieu: "<<endl;
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;

 }