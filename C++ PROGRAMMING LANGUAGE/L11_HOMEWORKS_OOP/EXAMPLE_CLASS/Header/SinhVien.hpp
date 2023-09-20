#ifndef   _SinhVien_H
#define   _SinhVien_H

#include<iostream>
#include<string>

using namespace std;

class SinhVien{
    public:
        void SetInformation1(string ten, int tuoi); 
        void Display1();  
        static int ID; 
    private:
        int NAM_SINH;
        void display1();
        static int CMND;
    protected:
        string TEN;                         
        int TUOI;   
        void display2();                       
                                       
};

class HocSinh : public SinhVien{                    // CLASS Kế Thừa
    public:
        void SetInformation(string ten, int tuoi, int mssv); 
        void Display();  
        int MSSV;
        int SBD;
    private:
         void Print();
};

#endif // _SinhVien_H INCLUDED