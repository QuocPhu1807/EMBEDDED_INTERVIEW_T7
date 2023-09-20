#ifndef _OOP_H
#define _OOP_H

#include<iostream>
#include<string>

using namespace std;

class DoiTuong{
    protected:
            string TEN;
            int TUOI;
    public:
            void SetInformation(string ten, int tuoi);
            void Display();

};

class SinhVien : protected DoiTuong{
    private:
            int MSSV;
    public:
            void SetInformation1(string ten, int tuoi, int mssv);    // Kieu or phuong phap ghi de trong tinh ke thua cua OOP
            void Display1();
    
};

class HocSinh : public SinhVien{
    public:
            void PrintData();

};


#endif // _OOP_H INCLUDED