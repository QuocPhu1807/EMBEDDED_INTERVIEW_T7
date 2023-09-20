#include"VectorStudent.hpp"

Student::Student(string ObjectName, int ObjectAge, TypeGender ObjectGener, double ObjectMathScore, double ObjectPhysicalScore, double ObjectChemstryScore){

    static int OjectId = 1000;
    this->StudentId= OjectId;
    OjectId++;

    this->StudentName       = ObjectName;
    this->StudentAge        = ObjectAge;
    this->StudentGender     = ObjectGener;
    this->MathScore         = ObjectMathScore;
    this->ChemistryScore    = ObjectChemstryScore;
    this->PhysicalScore     = ObjectPhysicalScore;
};


void Student :: SetObjectName(string ObjectName){

        this->StudentName = ObjectName;
}

void Student :: SetObjectAge(int ObjectAge){

        this->StudentAge = ObjectAge; 
}

void Student :: SetObjectGender(TypeGender ObjectGener){

        this->StudentGender = ObjectGener;
}

void Student ::  SetObjectMathScore(double ObjectMathScore){
         
        this->MathScore = ObjectMathScore;
}

void Student :: SetObjectChemstryScore(double ObjectChemstryScore){
         
        this->ChemistryScore = ObjectChemstryScore;
}

void Student :: SetObjectPhysicalScore(double ObjectPhysicalScore){
         
        this->ChemistryScore= ObjectPhysicalScore;
}

int Student::GetObjectId(){

    return StudentId;
}

string Student :: GetObjectName(){

    return StudentName;
}

int Student:: GetObjectAge(){
     
    return StudentAge;
}

TypeGender Student :: GetObjectGender(){

    return StudentGender;
}

double Student :: GetObjectMathScore(){

    return MathScore;
}
double Student :: GetObjectChemstryScore(){

    return ChemistryScore;
}
double Student ::GetObjectPhysicalScore(){

    return PhysicalScore;
}
float Student :: GetObjectAverageScore(){

    AverageScore = (MathScore + PhysicalScore +ChemistryScore)/3;
    return  AverageScore;
}

TypeAcademicBackground Student :: GetObjectAcademyBackground(){

     if( AverageScore >= 8.5) return VERYGOOD;
     else if( AverageScore >= 6.5) return GOOD;
     else if( AverageScore >= 5) return AVERAGE;
     else return WEAK;
}

void AddStudentIntoList(vector<Student> &ListOfStudents){

    int EnterFromKeyBoard = 0;
    do
    {
        cout<< "\n Nhap Name:\t ";
        string ObjectName;
        cin>> ObjectName;

        int ObjectAge;
        while (1){

            cout << "\n Nhap Tuoi:\t  ";
            cin >> ObjectAge;
            if(ObjectAge > 10 && ObjectAge < 100) break;
            else cout << " Tuoi ERROR!!!\n";
        }

        cout << "\n 1:Nam\n 2:Nu\n";
        cout << "\n Nhap lua chon cua ban:\t ";
        TypeGender ObjectGender;

        int ChooseGender = 0;
        cin >> ChooseGender;

        switch (ChooseGender){

            case 1:
                ObjectGender= MAN;
                break;
            case 2:
                ObjectGender = FEMALE;
                break;
            default:
                break;
        }
        
        int ObjectMathScore, GetObjectChemstryScore, GetObjectPhysicalScore;

        while(1){

            cout << "\n Nhap Diem Toan:\t  ";
            cin>> ObjectMathScore;
            if(ObjectMathScore >= 0 && ObjectMathScore <=10) break;
            else cout << "\n DiemToan ERROR !!!\n";

        }

        while(1){

            cout<< "\n Nhap Diem Hoa:\t  ";
            cin>> GetObjectChemstryScore;
            if(GetObjectChemstryScore >= 0 && GetObjectChemstryScore <=10) break;
            else cout << "\n DiemHoa ERROR!!!\n";

        }
       
        while(1){

            cout<< "\n Nhap Diem Ly:\t  ";
            cin>> GetObjectPhysicalScore;
            if(GetObjectPhysicalScore >= 0 && GetObjectPhysicalScore <=10) break;
            else cout << "\n DiemLy ERROR!!!\n";

        }

        Student student(ObjectName, ObjectAge, ObjectGender, ObjectMathScore, GetObjectPhysicalScore, GetObjectChemstryScore);

        ListOfStudents.push_back (student);

        cout << "\n ADDED successfully !!\n";

        cout << "\n 1: Tiep tuc.\n 2: Quay lai.\n  ";

        cout <<"\n Nhap lua chon cua ban: ";

        cin>> EnterFromKeyBoard ;

    } while (EnterFromKeyBoard  == 1);
    
}

void FixObjectOfStudentList(vector<Student> &ListOfStudents){

    PrintListOfStudent(ListOfStudents);

    cout<<" Nhap ID cua Object de thay doi thong tin :";

    int IdObject;

    cin>> IdObject;

    for (uint8_t i = 0; i < ListOfStudents.size(); i++)
    {
        if(ListOfStudents[i].GetObjectId() == IdObject ){

            cout<<" Thay doi Name tai Id " <<IdObject<<" :";
            string NewName;  cin >> NewName;
            ListOfStudents[i].SetObjectName(NewName);

            cout<<" Thay doi Tuoi tai Id " <<IdObject<<" :";
            int NewAge;  cin >> NewAge;
            ListOfStudents[i].SetObjectAge(NewAge);

            cout<<" Thay doi GioiTinh tai Id " <<IdObject<<" :";
            cout<< " \n 1:Nam\n 2: Nu";
            cout<<"\n Nhap lua chon: ";
            int ChooseGender;  cin >> ChooseGender;
            TypeGender ObjectNewGender;

            switch (ChooseGender){

                case 1:
                    ObjectNewGender = MAN;
                    break;
                case 2:
                    ObjectNewGender = FEMALE;
                    break;
                default:
                    break;
            }

            ListOfStudents[i].SetObjectGender(ObjectNewGender); 

            cout<<" Thay doi Diem_Toan tai Id " <<IdObject<<" :";
            float MathNewScore;  cin >> MathNewScore;
            ListOfStudents[i].SetObjectMathScore(MathNewScore);

            cout<<" Thay doi Diem_Hoa tai Id " <<IdObject<<" :";
            float ChemistryNewScore;  cin >> ChemistryNewScore;
            ListOfStudents[i].SetObjectChemstryScore(ChemistryNewScore);

            cout<<" Thay doi Diem_Ly tai Id " <<IdObject<<" :";
            float PhysicalNewScore;  cin >> PhysicalNewScore;
            ListOfStudents[i].SetObjectPhysicalScore(PhysicalNewScore);

        }
    }
        cout<<" Thong tin sinh vien duoc thay doi tai ID: "<<IdObject<<endl;

        PrintListOfStudent(ListOfStudents);
}

void EraseStudentBasedOnID(vector<Student> &ListOfStudents){ 

    PrintListOfStudent(ListOfStudents);

    cout<<"Nhap ID Sinh Vien can xoa:\t ";

    int EraseIdOfObject = 0;

    cin >> EraseIdOfObject;

    for (uint8_t i = 0; i < ListOfStudents.size(); i++)
    {

        if(ListOfStudents[i].GetObjectId() == EraseIdOfObject)   ListOfStudents.erase(ListOfStudents.begin() + i);
    
    }  

    cout<<"Sau khi xoa Object tai ID: "<<EraseIdOfObject<<endl;

    PrintListOfStudent(ListOfStudents);

}

void SearchNameOfObject(vector<Student> &ListOfStudents){

    PrintListOfStudent(ListOfStudents);

    cout<<"Nhap ten sinh vien de hien thong tin: ";

    string ObjectName;

    cin >> ObjectName;

            cout<< "\t-----------------------------------------------------------------------------------------------------------------\t\n";

            cout<<"\t|\tName\t|\tID\t|\tTuoi\t|\tDTB\t|\tToan\t|\tHoa\t|\tLy\t|\t\n";

    for (uint8_t i = 0; i < ListOfStudents.size(); i++)
    {
        
        if( ListOfStudents[i].GetObjectName()== ObjectName){
           
            cout<< "\t-----------------------------------------------------------------------------------------------------------------\t\n";

            cout<<"\t|\t"<< ListOfStudents[i].GetObjectName()<<"\t|\t"<< ListOfStudents[i].GetObjectId() << "\t|\t"<< ListOfStudents[i].GetObjectAge() <<"\t|\t"<< ListOfStudents[i].GetObjectAverageScore()
                 <<"\t|\t"<< ListOfStudents[i].GetObjectMathScore()<<"\t|\t"<< ListOfStudents[i].GetObjectChemstryScore()<<"\t|\t"<< ListOfStudents[i].GetObjectPhysicalScore()<<"\t|\t\n";

            cout<< "\t-----------------------------------------------------------------------------------------------------------------\t\n";
            
        }
    }
    
 }

 void SortByAverageScore(vector<Student> &ListOfStudents){

        for (uint8_t i = 0; i < ListOfStudents.size() - 1; i++)
        {
            for (uint8_t j = i + 1; j < ListOfStudents.size(); j++)
            {

                if(ListOfStudents[i].GetObjectAverageScore() > ListOfStudents[j].GetObjectAverageScore())     swap(ListOfStudents[i], ListOfStudents[j]);
            
            }
        
        }

        PrintListOfStudent(ListOfStudents);

}

static bool SortNameBasedOnAlphabet(string Object1Name, string Object2Name){

    uint8_t i = 0;

    if(Object1Name == Object2Name) return true;
    
    while(Object1Name[i] != '\0' || Object2Name[i] != '\0'){
      
        if(Object1Name[i] > Object2Name[i] ) return true;

        else if(Object1Name[i] < Object2Name[i] ) return false;
        i++;
    }

    return false;
        
}

void SortNameOfStudent(vector<Student> &ListOfStudents){

    for (uint8_t i = 0; i < ListOfStudents.size() - 1; i++)
    {
        for (uint8_t j = i + 1; j < ListOfStudents.size(); j++)
        {

            if(SortNameBasedOnAlphabet(ListOfStudents[i].GetObjectName(),ListOfStudents[j].GetObjectName()))     swap(ListOfStudents[i],ListOfStudents[j]);
            
        }
    }

    PrintListOfStudent(ListOfStudents);

}  

static string AssignNameForGender(TypeGender Gender){

        if(Gender == MAN)  return "Man";

        else if(Gender == FEMALE)  return "Female";

        return " ";
}

static string AssignNameForAcademyBackground(TypeAcademicBackground AcademyBackground){

        if(AcademyBackground == VERYGOOD) return "So Good";

        else if(AcademyBackground == GOOD) return "Good";

        else if(AcademyBackground == AVERAGE) return "Average";

        else if(AcademyBackground == WEAK) return "Weak";

        return " ";

}

void PrintListOfStudent(vector<Student> &ListOfStudents){

         cout<< "\t-------------------------------------------------------------------------------------------------\t\n";

         cout<<"\t|\tID\t|\tSex\t|\tName\t|\tTuoi\t|\tDTB\t|\tHoc Luc\t|\t\n";

    for (uint8_t i = 0; i < ListOfStudents.size(); i++)
    {
         
         cout<< "\t-------------------------------------------------------------------------------------------------\t\n";

         cout<<"\t|\t"<< ListOfStudents[i].GetObjectId()<<"\t|\t"<< AssignNameForGender(ListOfStudents[i].GetObjectGender())<<"\t|\t"<< ListOfStudents[i].GetObjectName() << "\t|\t"<< ListOfStudents[i].GetObjectAge() 
         <<"\t|\t"<< ListOfStudents[i].GetObjectAverageScore()<<"\t|\t"<<AssignNameForAcademyBackground(ListOfStudents[i].GetObjectAcademyBackground())<<left<<"\t|\t\n";
        
    }
         cout<< "\t-------------------------------------------------------------------------------------------------\t\n";
     
}

