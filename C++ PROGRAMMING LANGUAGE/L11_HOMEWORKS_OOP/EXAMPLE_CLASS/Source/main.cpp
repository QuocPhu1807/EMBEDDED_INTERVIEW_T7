#include<iostream>
#include"SinhVien.hpp"

using namespace std;

int main(){
    
    //SinhVien sv("Hoang",2001);

     SinhVien sv;

     sv.SetInformation1("Tuan",22);

     HocSinh hs;

     hs.SetInformation("Hoang", 23, 191674);

     hs.ID = 100; 

     sv.ID = 400;

     sv.Display1();

     printf("*********************\n");
    
     hs.Display();
     


    return 0;
}
