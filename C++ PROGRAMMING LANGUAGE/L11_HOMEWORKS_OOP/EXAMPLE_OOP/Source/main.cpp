#include"OOP.hpp"

int main()
{

    SinhVien sv;

    sv.SetInformation1("Tuan Trung ", 35, 191081);

    sv.Display1();

    HocSinh hs;

    hs.SetInformation1("Hoang",29,18187);

    hs.Display1();

    hs.PrintData();

    return 0;
}
