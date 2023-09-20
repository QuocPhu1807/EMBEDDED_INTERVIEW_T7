#include<iostream>
#include<vector>
#include<string>
#include<stdint.h>

/*
    1: Them sv
    2: Cap nhat tt sv bang id
    3: xoa sv boi id
    4: tim kiem sv theo ten
    5: sap xep sv theo diem tb
    6: sap xep sv theo ten
    7: hien th danh sach sv

*/

using namespace std;

 enum{
    ADDOBJECT = 1,
    FIXLIST,
    ERASEID,
    SEARCHNAME,
    SORTDTB,
    SORTNAME,
    PRINTLIST 

};

typedef enum{
    GIOI,
    KHA,
    TB,
    YEU
}typeHocLuc;

typedef enum{
    NAM = 1,
    NU
}typeGioiTinh;

class SinhVien{

    private:
        int ID;
        string NAME;
        int TUOI;
        typeGioiTinh GIOITINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

    public:
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);

        void SetName(string name);
        void SetTuoi(int tuoi);
        void SetGioiTinh(typeGioiTinh gioitinh);
        void SetDiemToan(double diem_toan);

        int GetId();
        string GetName();
        int GetTuoi();
        typeGioiTinh GetGioiTinh();
        double GetDiemToan();
        double GetDiemHoa();
        double GetDiemLy();
        double GetDiemTb();
        typeHocLuc getHocLuc();

};

 SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa){

    static int id =1000;
    this->ID =id;
    id++;

    this->NAME = name;
    this->TUOI = tuoi;
    this->GIOITINH  = gioitinh;
    this->DIEM_TOAN = diem_toan;
    this->DIEM_HOA  = diem_hoa;
    this->DIEM_LY   = diem_ly;
};

////

void SinhVien :: SetName(string name){

       NAME = name;
}

void SinhVien :: SetTuoi(int tuoi){

       TUOI = tuoi; 
}

void SinhVien :: SetGioiTinh(typeGioiTinh gioitinh){

       GIOITINH = gioitinh;
}

void SinhVien :: SetDiemToan(double diem_toan){
         
       DIEM_TOAN = diem_toan;
}

//
int SinhVien::GetId(){
    return ID;
}

string SinhVien :: GetName(){

    return NAME;
}

int SinhVien :: GetTuoi(){
     
    return TUOI;
}

typeGioiTinh SinhVien :: GetGioiTinh(){

    return GIOITINH;
}

double SinhVien :: GetDiemToan(){
    return DIEM_TOAN;
}
double SinhVien :: GetDiemHoa(){
    return DIEM_HOA;
}
double SinhVien :: GetDiemLy(){
    return DIEM_LY;
}
double SinhVien :: GetDiemTb(){

    return (DIEM_HOA + DIEM_TOAN + DIEM_LY)/3;
}

typeHocLuc SinhVien::getHocLuc(){

     if(GetDiemTb() >= 8) return GIOI;
     else if(GetDiemTb() >= 6.5) return KHA;
     else if(GetDiemTb() >= 5) return TB;
     else return YEU;
}
//

void PrintList(vector<SinhVien> &ListStudent){

         cout<< "\t-----------------------------------------------------------------\t\n";

         cout<<"\t|\tID\t|\tName\t|\tTuoi\t|\tDiem TB\t|\t\n";

     for (uint8_t i = 0; i < ListStudent.size(); i++)
     {
         
         cout<< "\t-----------------------------------------------------------------\t\n";

         cout<<"\t|\t"<< ListStudent[i].GetId() <<"\t|\t"<< ListStudent[i].GetName() << "\t|\t"<< ListStudent[i].GetTuoi() 
         <<"\t|\t"<< ListStudent[i].GetDiemTb()<<"\t|\t\n";
        
     }
         cout<< "\t-----------------------------------------------------------------\t\n";
     
}

void EraseStudentID(vector<SinhVien> &ListStudent){ 

    PrintList(ListStudent);

    cout<<"Nhap ID Sinh Vien can xoa:\t ";

    int EraseID = 0;

    cin >> EraseID;

    for (uint8_t i = 0; i < ListStudent.size(); i++)
    {
        if(ListStudent[i].GetId() == EraseID)   ListStudent.erase(ListStudent.begin() + i);
    }  

     cout<<"Sau khi xoa ID"<<EraseID<<endl;

     PrintList(ListStudent);
}
//

static bool SortAlphabet(string Name1, string Name2){

   uint8_t i=0;

    if(Name1 == Name2) return true;
    
    while(Name1[i] != '\0' || Name2[i] != '\0'){
      
        if(Name1[i] > Name2[i] ) return true;

        else if(Name1[i] < Name2[i] ) return false;
        i++;
   }
   return false;
        
}
///
void SearchName(vector<SinhVien> &ListStudent){

    PrintList(ListStudent);

    cout<<"Nhap ten sinh vien de hien thong tin: ";

    string NameStudent;

    cin >> NameStudent;

            cout<< "\t-----------------------------------------------------------------------\t\n";

            cout<<"\t|\tID\t|\tTuoi\t|\tDiem.TB\t|\tToan\t|\tHoa\t|\tLy\t|\t\n";

    for (uint8_t i = 0; i < ListStudent.size(); i++)
    {
        if( ListStudent[i].GetName()== NameStudent){
           
            cout<< "\t-----------------------------------------------------------------------\t\n";

            cout<<"\t|\t"<< ListStudent[i].GetId() << "\t|\t"<< ListStudent[i].GetTuoi() <<"\t|\t"<< ListStudent[i].GetDiemTb()
                 <<"\t|\t"<< ListStudent[i].GetDiemToan()<<"\t|\t"<< ListStudent[i].GetDiemHoa()<<"\t|\t"<< ListStudent[i].GetDiemLy()<<"\t|\t\n";

            cout<< "\t-----------------------------------------------------------------------\t\n";
            
        }
    }
    

 }
///
void FixListStudent(vector<SinhVien> &ListStudent){

}


void SortStudentName(vector<SinhVien> &ListStudent){

     for (uint8_t i = 0; i < ListStudent.size() - 1; i++)
        {
            for (uint8_t j = i + 1; j < ListStudent.size(); j++)
            {
                if(SortAlphabet(ListStudent[i].GetName(),ListStudent[j].GetName()))     swap(ListStudent[i],ListStudent[j]);
            }
        
        }

}

void SortStudentDTB(vector<SinhVien> &ListStudent){

        for (uint8_t i = 0; i < ListStudent.size() - 1; i++)
        {
            for (uint8_t j = i + 1; j < ListStudent.size(); j++)
            {
                if(ListStudent[i].GetDiemTb() > ListStudent[j].GetDiemTb())     swap(ListStudent[i],ListStudent[j]);
            }
        
        }

        PrintList(ListStudent);
         
}

void AddSinhVien(vector<SinhVien> &ListStudent){

    int EnterFromKeyBoard = 0;
    do
    {
        cout<< "\nNhap name:\t ";
        string name;
        cin>> name;

        int tuoi;
        while (1){

            cout << "\nNhap tuoi:\t  ";
            cin >> tuoi;
            if(tuoi > 10 && tuoi < 100) break;
            else cout << "ERROR!!!\n";
        }

        cout << "\n1:Nam\n2:Nu\n ";
        cout << "Nhap lua chon:\t ";
        typeGioiTinh gioitinh;

        int ChooseGioiTinh = 0;
        cin >> ChooseGioiTinh;

        switch (ChooseGioiTinh)
        {
        case 1:
            gioitinh = NAM;
            break;
        case 2:
            gioitinh = NU;
            break;
        default:
            break;
        }

        int DiemToan;
        cout<< "\nNhap Diem Toan:\t  ";
        cin>> DiemToan;

        int DiemHoa;
        cout<< "\nNhap Diem Hoa:\t  ";
        cin>> DiemHoa;

        int DiemLy;
        cout<< "\nNhap Diem Ly:\t  ";
        cin>> DiemLy;

        // Diem toan ly hoa

        SinhVien sv(name, tuoi, gioitinh, DiemToan, DiemLy, DiemHoa);

        ListStudent.push_back (sv);
        cout << "\nADD successfully !!\n";

        cout << "\n 1: Tiep tuc:\n 2: Quay lai:\t  ";

        cout <<"\n Nhap lu chon: ";

        cin>> EnterFromKeyBoard ;

    } while (EnterFromKeyBoard  == 1);
    

}


///////

int main(int argc, char const *argv[])
{
    vector<SinhVien> ListStudent;

   int key;

    while (1){

    //cout << " 1: Thêm sinh viên\n 2:Cập nhật thông tin sinh viên bằng ID\n 3:Xoá sinh viên bởi ID\n 4:Sắp xếp sinh viên theo tên\n 5:Sắp xếp sinh viên theo điểm TB\n6:\n7:Hiển thị danh sánh sinh viên\n Nhập lựa chọn:";
    printf("\n 1:Them sinh vien\n 2:Cap nhan thong tin sinh vien bang ID\n 3:Xoa sinh vien boi ID\n 4:Tim kiem sinh vien theo ten\n 5:Sap xep sinh vien theo Diem TB\n 6:Sap xep sinh vien theo ten\n 7:Hien thi danh sach sinh vien\n Nhap lua chon:\t ");
    
    cin >> key;

    switch (key)
    {
    case ADDOBJECT:
        AddSinhVien(ListStudent);
        break;
    // case FIXLIST:
    //     AddSinhVien(ListStudent);
    //     break;   
    case ERASEID:
        EraseStudentID(ListStudent);
        break;
    case SEARCHNAME:
        SearchName(ListStudent);
        break;
    case SORTDTB:
        SortStudentDTB(ListStudent);
        break;
    case SORTNAME:
        SortStudentName(ListStudent);
        break;
    case PRINTLIST:
        PrintList(ListStudent);
        break;
    default:
        cout<<" ERROR SYTAX! PLEASE ENTERN AGAIN!!!";
        break;
    }
    
    }
    
         return 0;
}
