/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 23/08/2023
* Description: This file is used to manager The List of Students according to:
              ID, Name, Age, Gender, Academic Background.
*/

#include"VectorStudent.hpp"

//                 ĐỀ BÀI:
// Tạo vector Liststudent với kiểu dữ liệu class SinhVien
//     class Student bao gồm:
//         ID
//         Tên
//         Tuổi
//         Giới tính
//         điểm toán lý hóa và điểm tb

//                 YÊU CẦU:
// 0: Quay lại
// 1: Thêm SV
// 2: Cập nhật tt sv bằng id
// 3: xóa sv bằng id
// 4: tìm kiếm sv theo ten
// 5: sắp xếp sv theo điểm tb
// 6: sắp xếp sv theo ten
// 7: hiển thị danh sách sv


int main(){

    vector<Student> ListOfStudents;

    int ChooseOption;

    while(1){

        printf("\n 1:Them sinh vien\n 2:Cap nhat thong tin sinh vien bang ID\n 3:Xoa sinh vien boi ID\n 4:Tim kiem sinh vien theo Name\n 5:Sap xep sinh vien theo Diem TB\n 6:Sap xep sinh vien theo Name\n 7:Hien thi danh sach sinh vien\n Nhap lua chon tu KeyBoard:\t");

        cin >> ChooseOption;

        switch (ChooseOption){

            case ADDOBJECT:
                AddStudentIntoList(ListOfStudents);
                break;
            case EDITOBJECTINLIST:
                FixObjectOfStudentList(ListOfStudents);
                break;   
            case ERASEOBJECTBYID:
                EraseStudentBasedOnID(ListOfStudents);
                break;
            case SEARCHNAME:
                SearchNameOfObject(ListOfStudents);
                break;
            case SORTAVEGARESCORE:
                SortByAverageScore(ListOfStudents);
                break;
            case SORTNAME:
                SortNameOfStudent(ListOfStudents);
                break;
            case PRINTSTUDENTLISTS:
                PrintListOfStudent(ListOfStudents);
                break;
            default:
                cout<<" \n ERROR SYTAX! PLEASE ENTER AGAIN!!!";
                cout<< "\n";
                break;
        }
    
    }
         return 0;

}
