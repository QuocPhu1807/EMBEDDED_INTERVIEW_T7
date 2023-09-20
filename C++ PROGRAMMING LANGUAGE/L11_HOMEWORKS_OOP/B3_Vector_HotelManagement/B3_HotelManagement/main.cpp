/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 29/08/2023
* Description: This file is used to manager the information of the retaurants such: Menu, the number of table
*/

#include<iostream>
#include<vector>
#include<string>
#include<stdint.h>

using namespace std;

typedef enum{

    ADDEMPLOYEE = 1,
    CHANGEEMPLOYEE,
    DELETEEMPLOYEE,
    PRINTOFSTAFF

}managerFunctionOfStaff;
typedef enum{

    ADDCUSTOMER = 1,
    CHANGECUSTOMER,
    DELETECUSTOMER

}managerFunctionOfCustomer;

typedef enum{

    RESERVATION = 1,
    CUSTOMER,
    EMPLOYEE

}managerFunctionOfHotel;

class Room{
    private:
        uint8_t roomNumber;
        bool isBooked;
    public:
        Room(uint8_t number);
        
        int getRoomNumber();
        bool isAvailable();
        void bookRoom();
        void checkOut();

        void setIdRoom(int idRoom);
};

Room :: Room(uint8_t number){

    this->roomNumber = number;
    this->isBooked   = false;
}
int Room :: getRoomNumber(){

    return roomNumber;
}
bool Room :: isAvailable(){
    
    return !isBooked;   
}
void Room :: bookRoom(){

    this->isBooked = true;
}
void Room :: checkOut(){

    this->isBooked = false;
}
void Room :: setIdRoom(int idRoom){

    this->roomNumber = idRoom;
}
//////////////////////////////////////////////////////
typedef struct{
    int day;
    int month;
    int year;
}typeDate;

typedef struct{
    int second;
    int minute;
    int hour;
}typeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}bookingHistory;

class Customer{

    private:
        int idRoom;
        string name;
        string phoneNumber;
        string address;
        vector <bookingHistory> bookingHistorys;
    public: 
        Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom);

        void addBookingHistory(bookingHistory bookingDetails);
        vector<bookingHistory> &getBookingHistory();

        string getname();
        int getIdRoom();
        string getPhoneNumber();
        string getAddress();

        void setId(int id);
        void setName(string customerName);
        void setPhoneNumber(string customerPhone);
        void setAdrress(string customerAddress);
};

Customer :: Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom){

    this->idRoom = customerIdRoom;
    this->name = customerName;
    this->phoneNumber = customerPhone;
    this->address = customerAddress;
}

void Customer :: addBookingHistory(bookingHistory bookingDetails){

    bookingHistorys.push_back(bookingDetails);

}

vector<bookingHistory>& Customer ::getBookingHistory(){

    return bookingHistorys;
}

string Customer :: getname(){

    return name;
}
int Customer :: getIdRoom(){

    return idRoom;
}
string Customer :: getPhoneNumber(){

    return phoneNumber;
}
string Customer :: getAddress(){

    return address;
}
void Customer :: setId(int id){

    this->idRoom = id;
}
void Customer :: setName(string customerName){

    this->name = customerName;
}
void Customer :: setPhoneNumber(string customerPhone){

    this->phoneNumber = customerPhone;
}
void Customer :: setAdrress(string customerAddress){

    this->address = customerAddress;
}
////////////////////////////////////////////////////////

class CustomerManager{
    private:
        vector<Customer> databaseCustomer;
    public:
        void addCustomer( Customer &customer);
        void editIdRoomCustomer(vector<Room> &databaseRoom, int idRoom_Current, int idRoom);
        void deleteCustomer();

        vector<Customer> &getDatabaseCustomer();
};

void CustomerManager :: addCustomer( Customer &customer){

    databaseCustomer.push_back(customer);
}

void CustomerManager :: editIdRoomCustomer(vector<Room> &databaseRoom, int idRoom_Current, int idRoom){

    for (uint8_t i = 0; i < databaseRoom.size(); i++) 
    {
        if( databaseRoom[i].getRoomNumber() == idRoom_Current)  databaseRoom[i].checkOut();
        if( databaseRoom[i].getRoomNumber() == idRoom) databaseRoom[i].bookRoom();
    }

    for (uint8_t i = 0; i < databaseRoom.size(); i++)
    {
        if( databaseRoom[i].getRoomNumber() == idRoom_Current ) databaseRoom[i].setIdRoom(idRoom);
    }
       
}
vector<Customer>& CustomerManager :: getDatabaseCustomer(){

    return databaseCustomer;
}
//////////////////////////////////////////////

typedef struct 
{
    typeTime time;
    typeDate date;
    typeStatus status;
}scheduleOfEmployees;

typedef enum{
    SECURITIER,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF
}positionOfEmployees;

class Employee {
    private:
        int idEmployee;
        string nameEmployee;
        string phonenumberEmployee;
        positionOfEmployees positionEmployee;
        vector<scheduleOfEmployees> scheduleEmployee;
    public:
        Employee(string nameEmployee, string phonenumberEmployee, positionOfEmployees positionEmployee);

        int GetId();
        string GetName();
        string GetPhoneNumber();
        positionOfEmployees GetPosition();
        vector<scheduleOfEmployees>& GetSchedule();
        void addScheduleEmployee(scheduleOfEmployees scheduleEmployees);

        void SetName(string nameEmployees);
        void SetPhoneNumber(string phonenumberEmployees);
        void SetPosition(positionOfEmployees positionEmployees);

};
Employee ::Employee(string nameEmployees, string phonenumberEmployees, positionOfEmployees positionEmployees){

    static int id = 100;
    this->idEmployee = id;
    id++;

    this->nameEmployee        = nameEmployees;
    this->phonenumberEmployee = phonenumberEmployees;
    this->positionEmployee    = positionEmployees;  
}
void Employee ::addScheduleEmployee(scheduleOfEmployees scheduleEmployees){

    scheduleEmployee.push_back(scheduleEmployees);
}
int Employee :: GetId(){

    return idEmployee;
}
string Employee :: GetName(){

    return nameEmployee;
}
string Employee :: GetPhoneNumber(){

    return phonenumberEmployee;
}
positionOfEmployees Employee :: GetPosition(){

    return positionEmployee;
}
vector<scheduleOfEmployees>& Employee :: GetSchedule(){

    return scheduleEmployee;
}

void Employee :: SetName(string nameEmployees){

    this->nameEmployee = nameEmployees;
}
void Employee :: SetPhoneNumber(string phonenumberEmployees){

    this->phonenumberEmployee = phonenumberEmployees;
}
void Employee :: SetPosition(positionOfEmployees positionEmployees){

    this->positionEmployee = positionEmployees;
}
////////////////////////
class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        void AddEmployee(Employee employee);
        vector<Employee>& getdataEmployee();
       // bool getAuthenticate(string inputPassword, string inputUsername);

};

void EmployeeManager :: AddEmployee(Employee employee){

    databaseEmployee.push_back(employee);
}
vector<Employee>& EmployeeManager :: getdataEmployee(){

    return databaseEmployee;
}

////////////////////////

void DisplayListOfCustomer(vector<Customer> &databaseCustomer);

////////////////////////
void DisplayListOfStaff(vector<Employee> &databaseEmployee);
////////////////////////////
void setQuanityRoom(vector<Room> &databaseRoom, uint8_t quanity){

    for (uint8_t i = 0; i < quanity; i++)
    {
        Room room = {i};
        databaseRoom.push_back(room);
    }
    
}


void printLishOfRoom(vector<Room> &databaseRoom){

    cout<<endl<<"List of Room: "<<endl;
    cout<<"\tRoom\t|";

    for (uint8_t i = 0; i < databaseRoom.size(); i++)
    {
        printf("  %d\t|",databaseRoom[i].getRoomNumber());
    }

    cout<<endl<<"\tStatus\t|";
    for(uint8_t i =0; i< databaseRoom.size(); i++){

        if( databaseRoom[i].isAvailable() == true) cout<<"  x\t|";
        else cout<<"  o\t|";
    }
    cout<<endl<<endl<<"\t x : have room";
    cout<<endl<<"\t o : booked room";
    cout<<"\n\n";
    
}

void bookRoom(vector<Room> &databaseRoom, CustomerManager &customerManager){

    int chooseAddCustomer;
    do{
    printLishOfRoom(databaseRoom);

    cout<<endl<<"\tEnter the room number: ";

    int chooseRoomNumber;

    cin>>chooseRoomNumber; cin.ignore();

    for (uint8_t i = 0; i < databaseRoom.size(); i++)
    {
        if(databaseRoom[i].getRoomNumber() == chooseRoomNumber){

            databaseRoom[i].bookRoom();
        }
    }

    cout<<endl<<"\tROOM NUMBER: "<<chooseRoomNumber<<endl;
    cout<<"\tPlease enter your name: ";
    string nameCustomer;
    cin>>nameCustomer;

    cout<<endl<<"\tPlease enter your phone number: ";
    string phonenumberCustomer;
    cin>>phonenumberCustomer;

    cout<<endl<<"\tPlease enter your address: ";
    string addressCustomer;
    cin>>addressCustomer;

    Customer customer = {nameCustomer, phonenumberCustomer, addressCustomer, chooseRoomNumber};

    int day   = 0;
    int month = 0;
    int year = 0;
    while(1){

        cout<<endl<<"\tEnter the day :"; 
        cin>>day; cin.ignore();
        if(day > 0 && day <= 31) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEnter the month: ";
        cin>> month; cin.ignore(); 
        if(month > 0 && month <= 12) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEntern the year: ";
        cin>>year; cin.ignore();
        if(year > 0 ) break;
        else cout<<endl<<"\tERROR";

    }

    int second = 0;
    int minute = 0;
    int hour   = 0;
    while(1){

        cout<<endl<<"\tEnter the second: ";
        cin>>second; cin.ignore();
        if(second >=0 && second <= 60) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEnter the minute: ";
        cin>>minute; cin.ignore();
        if(minute >=0 && minute <= 60) break;
        else cout<<endl<<"\tERROR";

    }
  

    cout<<endl<<"\tEnter the hour: ";
    cin>>hour; 
      
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 0: Status is stay in room";
    cout<<endl<<"\t 1: status is outside";
    cout<<endl<<"\t----------------------\t";
    int chooseStatus; cin.ignore();
    typeStatus statusCustomer;
    cout<<endl<<"Please entern your choice: ";
    cin>>chooseStatus; cin.ignore();

    switch (chooseStatus)
    {
        case 0:
            statusCustomer = IN;
            break;
        case 1:
            statusCustomer = OUT;
            break;
        default:
            break;
    }

    bookingHistory bookingHistories;

    bookingHistories.date.day   = day;
    bookingHistories.date.month = month;
    bookingHistories.date.year  = year;

    bookingHistories.time.second = second;
    bookingHistories.time.minute = minute;
    bookingHistories.time.hour   = hour;

    bookingHistories.status      = statusCustomer;


    customer.addBookingHistory(bookingHistories);

    customerManager.addCustomer(customer);

    cout<<endl<<"\t Would you like reserve the futher room ? ";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 1: Go on reserve another room";
    cout<<endl<<"\t 0: Return";
    cout<<endl<<"\t----------------------\t";

    cin>>chooseAddCustomer;

    } while( chooseAddCustomer == 1);

    cout<<endl<<" The list of the room which are reserved: "<<endl;

    printLishOfRoom(databaseRoom);

    cout<<endl<<"The information of customers when they reserve the room : "<<endl;

    DisplayListOfCustomer(customerManager.getDatabaseCustomer());


}

string AssignStatusInRoomOfCustomer(typeStatus statusCustomer){

    if(statusCustomer == IN) return "StayRoom";
    else if(statusCustomer == OUT) return "Outside";

    return " ";

}
void DisplayHistoryOfCustomer(vector<bookingHistory> &bookingHistories ){


    for (uint8_t i = 0; i < bookingHistories.size(); i++)
    {
         cout<<bookingHistories[i].date.day<<"/"<<bookingHistories[i].date.month<<"/"<<bookingHistories[i].date.year
        <<"\t\t  |"<<bookingHistories[i].time.hour<<":" <<bookingHistories[i].time.minute<<":"<<bookingHistories[i].time.second
        <<"\t\t  |"<<AssignStatusInRoomOfCustomer(bookingHistories[i].status)<<"\t\t|";

    }
    
}

void DisplayListOfCustomer(vector<Customer> &databaseCustomer){

    cout<<endl<<"\tID Room\t  |"<<"Name\t  |"<<"PhoneNumber\t\t\t|"<<"Adrress\t |";
    cout<<endl<<"\t------------------------------------------------------------------\t";
    for (uint8_t i = 0; i < databaseCustomer.size(); i++)
    {
        cout<<endl<<"\t"<<databaseCustomer[i].getIdRoom()<<"\t  |"<<databaseCustomer[i].getname()<<"\t  |"<<databaseCustomer[i].getPhoneNumber()<<"\t\t\t|"<<
            databaseCustomer[i].getAddress()<<"\t\t |"; 
    }
    cout<<endl<<"\t------------------------------------------------------------------\t";
    cout<<"\n\n";

    cout<<endl<<"The history of Customer: "<<endl;
    cout<<endl<<"\tID Room\t |"<<"Day\t\t\t  |"<<"Time\t\t\t  |"<<"Status\t\t|";
    cout<<endl<<"\t----------------------------------------------------------------------------------\t";

    for (uint8_t i = 0; i < databaseCustomer.size(); i++)
    {
        cout<<endl<<"\t"<<databaseCustomer[i].getIdRoom()<<"\t  |";
        DisplayHistoryOfCustomer(databaseCustomer[i].getBookingHistory());
    }
    cout<<endl<<"\t----------------------------------------------------------------------------------\t";
    cout<<"\n\n";
    
}

void ReservationManagement(vector<Room> &databaseRoom, CustomerManager &customerManager){

    int chooseReturn;
    while(1){

    cout<<endl<<" Reservation Management "<<endl;
    cout<<"------------------------";
    cout<<endl<<" 1: The list of reservation "<<endl;
    cout<<" 2: Resever Room "<<endl;
    cout<<" 0: Return "<<endl;
    cout<<"------------------------";
    cout<<endl<<" Please enter your choice : ";
    
    int chooseOption;

    cin>> chooseOption;

    switch (chooseOption)
    {
    case 1:
        printLishOfRoom(databaseRoom);
        break;
    case 2:
        bookRoom(databaseRoom, customerManager);
        break;
    default:
        chooseReturn = 1;
        break;
    }

    if(chooseReturn == 1) break;

    }

}

void ChangeNameOfCustomerInId(CustomerManager &customerManagement, int chooseId){

    cout<<endl<<"\tPlease enter the new name of customer: ";
    string chooseNewName;
    cin>>chooseNewName; cin.ignore();

    for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseId  ){
        
            (customerManagement.getDatabaseCustomer())[i].setName(chooseNewName);
        }
    }

    cout<<endl<<"The list of customer after update the new information: ";
    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

}
void ChangePhoneNumberOfCustomerInId(CustomerManager &customerManagement, int chooseId){

    cout<<endl<<"\tPlease enter the new name of customer: ";
    string chooseNewPhoneNumber;
    cin>>chooseNewPhoneNumber; cin.ignore();

    for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseId  ){
        
            (customerManagement.getDatabaseCustomer())[i].setPhoneNumber(chooseNewPhoneNumber);
        }
    }

    cout<<endl<<"The list of customer after update the new information: ";
    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

}
void ChangeAddressOfCustomerInId(CustomerManager &customerManagement, int chooseId){

    cout<<endl<<"\tPlease enter the new name of customer: ";
    string chooseNewAddress;
    cin>>chooseNewAddress; cin.ignore();

    for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseId  ){
        
            (customerManagement.getDatabaseCustomer())[i].setAdrress(chooseNewAddress);
        }
    }

    cout<<endl<<"The list of customer after update the new information: ";
    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

}

void ChangeInformationCustomerInId(CustomerManager &customerManagement){

    int chooseOptionReturn;
    while(1){

    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

    cout<<endl<<"\tPlease enter the ID room which you want change it: ";

    cout<<endl<<"\t--------------------------------------\t";
    cout<<endl<<"\t 1: Change the name of customer";
    cout<<endl<<"\t 2: Change the phonenumber of customer";
    cout<<endl<<"\t 3: Change the address of customer";
    cout<<endl<<"\t 0: Return";
    cout<<endl<<"\t--------------------------------------\t";
    cout<<endl<<"Please entern your choice: ";

    int chooseIdRoom;
    cin>>chooseIdRoom; cin.ignore();

    switch (chooseIdRoom)
        {
        case 1:
            ChangeNameOfCustomerInId(customerManagement, chooseIdRoom);
            break;
        case 2:
            ChangePhoneNumberOfCustomerInId(customerManagement, chooseIdRoom);
            break;
        case 3:
            ChangeAddressOfCustomerInId(customerManagement, chooseIdRoom);
            break;
        default:
            chooseOptionReturn = 1;
            break;
        }

    if(chooseOptionReturn == 1) break;

    }
}

void  DeleteCustomer(CustomerManager &customerManagement){

    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());
    cout<<endl<<"\tPlease enter the ID room which you want delete it: ";
    int chooseIdRoom;
    cin>>chooseIdRoom; cin.ignore();

    for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseIdRoom  ){
        
            customerManagement.getDatabaseCustomer().erase(customerManagement.getDatabaseCustomer().begin() + i);
        }
    }

    cout<<endl<<"The list of customers after are deleted in ID "<<endl;
    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());
    cout<<endl<<" The list of room after update: "<<endl;
    
}

void CustomerManagement(vector<Room> &databaseRoom,CustomerManager &customerManagement){


        if(customerManagement.getDatabaseCustomer().size() == 0) cout<<endl<<endl<<"Please enter the information of custumer at the choice 1:"<<endl;
        
        else {
        int chooseReturn;
        while(1){
            DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

            cout<<endl<<"\t--------------------------------------\t";
            cout<<endl<<"\t 1: Add the customer";
            cout<<endl<<"\t 2: Change the information of customer";
            cout<<endl<<"\t 3: Delete the information of customer";
            cout<<endl<<"\t 0: Return";
            cout<<endl<<"\t--------------------------------------\t";
            cout<<endl<<"Please entern your choice: ";
            
            int chooseOptionToChangeCustomer;
            cin>>chooseOptionToChangeCustomer;

            switch (chooseOptionToChangeCustomer)
                {
                case ADDCUSTOMER:
                    bookRoom(databaseRoom,customerManagement);
                    break;
                case CHANGECUSTOMER:

                    break;
                case DELETECUSTOMER:
                    DeleteCustomer(customerManagement);
                    printLishOfRoom(databaseRoom);
                    break;
                default:
                    chooseReturn = 1;
                    break;
                }

                if(chooseReturn == 1) break;
            }
        }

}
///////////////////////

void ChangeNameOfEmployeeInId(EmployeeManager &employeeManagement, int chooseId){

    cout<<endl<<"\tPlease enter the new name of employee: ";
    string chooseNewName;
    cin>>chooseNewName; cin.ignore();

    for (uint8_t i = 0; i < employeeManagement.getdataEmployee().size(); i++)
    {
        if((employeeManagement.getdataEmployee())[i].GetId() == chooseId  ){
        
            (employeeManagement.getdataEmployee())[i].SetName(chooseNewName);
        }
    }

    cout<<endl<<"The list of customer after update the new information: ";
    DisplayListOfStaff(employeeManagement.getdataEmployee());

}
void ChangePhoneNumberOfEmployeeInId(EmployeeManager &employeeManagement, int chooseId){

    cout<<endl<<"\tPlease enter the new phonenumber of employee: ";
    string chooseNewPhoneNumber;
    cin>>chooseNewPhoneNumber; cin.ignore();

    for (uint8_t i = 0; i < employeeManagement.getdataEmployee().size(); i++)
    {
        if((employeeManagement.getdataEmployee())[i].GetId() == chooseId  ){
        
            (employeeManagement.getdataEmployee())[i].SetPhoneNumber(chooseNewPhoneNumber);
        }
    }

    cout<<endl<<"The list of customer after update the new information: ";
    DisplayListOfStaff(employeeManagement.getdataEmployee());

}

void ChangeInformationEmployeeInId(EmployeeManager &employeeManagement){

    int chooseOptionReturn;
    while(1){

    DisplayListOfStaff(employeeManagement.getdataEmployee());

    cout<<endl<<"\tPlease enter the ID room which you want change it: ";

    cout<<endl<<"\t--------------------------------------\t";
    cout<<endl<<"\t 1: Change the name of employee";
    cout<<endl<<"\t 2: Change the phonenumber of employee";
    cout<<endl<<"\t 0: Return";
    cout<<endl<<"\t--------------------------------------\t";
    cout<<endl<<"Please entern your choice: ";

    int chooseIdEmployee;
    cin>>chooseIdEmployee; cin.ignore();

    switch (chooseIdEmployee)
        {
        case 1:
            ChangeNameOfEmployeeInId(employeeManagement, chooseIdEmployee);
            break;
        case 2:
           ChangePhoneNumberOfEmployeeInId(employeeManagement, chooseIdEmployee);
            break;
        default:
            chooseOptionReturn = 1;
            break;
        }

    if(chooseOptionReturn == 1) break;

    }
}

//////////////////////
void DeleteEmployee(EmployeeManager &employeeManagement){

    DisplayListOfStaff(employeeManagement.getdataEmployee());
    cout<<endl<<"\tPlease enter the ID of Employee which you want delete it: ";
    int chooseIdEmployee;
    cin>>chooseIdEmployee; cin.ignore();

    for (uint8_t i = 0; i < employeeManagement.getdataEmployee().size(); i++)
    {
        if((employeeManagement.getdataEmployee())[i].GetId() == chooseIdEmployee  ){
        
            employeeManagement.getdataEmployee().erase(employeeManagement.getdataEmployee().begin() + i);
        }
    }

    cout<<endl<<"The list of staff after are deleted in ID "<<endl;
    DisplayListOfStaff(employeeManagement.getdataEmployee());
    cout<<endl<<" The list of room after update: "<<endl;
    
}

////////////////
string AssignStatusPositionOfEmployee( positionOfEmployees positionEmployee){

    if(positionEmployee == SECURITIER) return "Securitier";
    else if(positionEmployee == RECEPTIONIST) return "Receptionist";
    else if(positionEmployee == LAUNDRY_STAFF) return "Launary";
    else if(positionEmployee == LUGGAGE_STAFF) return "Luggage";
    return " ";

}

string AssignStatusInHotelOfEmployee(typeStatus statusEmployee){

    if(statusEmployee == IN) return "Inside";
    else if(statusEmployee == OUT) return "Outside";

    return " ";

}
void DisplayScheduleOfEmployee(vector<scheduleOfEmployees> scheduleEmployee){


    for (uint8_t i = 0; i < scheduleEmployee.size(); i++)
    {
         cout<<scheduleEmployee[i].date.day<<"/"<<scheduleEmployee[i].date.month<<"/"<<scheduleEmployee[i].date.year
        <<"\t\t  |"<<scheduleEmployee[i].time.hour<<":" <<scheduleEmployee[i].time.minute<<":"<<scheduleEmployee[i].time.second
        <<"\t\t  |"<<AssignStatusInHotelOfEmployee(scheduleEmployee[i].status)<<"\t\t|";

    }
    
}
void DisplayListOfStaff(vector<Employee> &databaseEmployee){

    cout<<endl<<"\tID Room\t  |"<<"Name\t  |"<<"PhoneNumber\t\t\t|"<<"Adrress\t |";
    cout<<endl<<"\t------------------------------------------------------------------\t";
    for (uint8_t i = 0; i < databaseEmployee.size(); i++)
    {
        cout<<endl<<"\t"<<databaseEmployee[i].GetId()<<"\t  |"<<databaseEmployee[i].GetName()<<"\t  |"<<databaseEmployee[i].GetPhoneNumber()<<"\t\t\t|"<<
            AssignStatusPositionOfEmployee(databaseEmployee[i].GetPosition())<<"\t\t |"; 
    }
    cout<<endl<<"\t------------------------------------------------------------------\t";
    cout<<"\n\n";

    cout<<endl<<"The history of Customer: "<<endl;
    cout<<endl<<"\tID Room\t |"<<"Day\t\t\t  |"<<"Time\t\t\t  |"<<"Status\t\t|";
    cout<<endl<<"\t----------------------------------------------------------------------------------\t";

    for (uint8_t i = 0; i < databaseEmployee.size(); i++)
    {
        cout<<endl<<"\t"<<databaseEmployee[i].GetId()<<"\t  |";
        DisplayScheduleOfEmployee(databaseEmployee[i].GetSchedule());
    }
    cout<<endl<<"\t----------------------------------------------------------------------------------\t";
    cout<<"\n\n";
    

}

void AddInformationOfEmployee(EmployeeManager &employeeManagement){

    int chooseOptionAdd;
    do{

    cout<<endl<<"\tEnter the name of Employee: ";
    string nameEmployee;
    cin>>nameEmployee; cin.ignore();

    cout<<endl<<"\tEnter the phonenumber of Employee: ";
    string phonenumberEmployee;
    cin>>phonenumberEmployee;


    cout<<endl<<"\tEnter the work position of Employee: ";
   
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 1: Securitier ";
    cout<<endl<<"\t 2: Receptionist";
    cout<<endl<<"\t 3: Laundry Employee ";
    cout<<endl<<"\t 4: Luggage Employee ";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"Please enter your choice: ";
    
    positionOfEmployees positionOfEmployee;
    int choosePosition; 
    cin>>choosePosition; cin.ignore();

    switch (choosePosition)
    {
        case 1:
            positionOfEmployee = SECURITIER;
            break;
        case 2:
            positionOfEmployee = RECEPTIONIST;
            break;
        case 3:
            positionOfEmployee = LAUNDRY_STAFF;
            break;
        case 4:
            positionOfEmployee = LUGGAGE_STAFF;
            break;
        default:
            break;
    }

    cout<<endl<<"\tEnter the work schedule of Employee: ";

    int day   = 0;
    int month = 0;
    int year = 0;
    while(1){

        cout<<endl<<"\tEnter the day :"; 
        cin>>day; cin.ignore();
        if(day > 0 && day <= 31) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEnter the month: ";
        cin>> month; cin.ignore(); 
        if(month > 0 && month <= 12) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEntern the year: ";
        cin>>year; cin.ignore();
        if(year > 0 ) break;
        else cout<<endl<<"\tERROR";

    }

    int second = 0;
    int minute = 0;
    int hour   = 0;
    while(1){

        cout<<endl<<"\tEnter the second: ";
        cin>>second; cin.ignore();
        if(second >=0 && second <= 60) break;
        else cout<<endl<<"\tERROR";

    }
    while(1){

        cout<<endl<<"\tEnter the minute: ";
        cin>>minute; cin.ignore();
        if(minute >=0 && minute <= 60) break;
        else cout<<endl<<"\tERROR";

    }
  
    cout<<endl<<"\tEnter the hour: ";
    cin>>hour; 
      
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 0: Status is inside ";
    cout<<endl<<"\t 1: status is outside";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"Please entern your choice: ";
    
    typeStatus statusEmployee;
    int chooseStatus;
    cin>>chooseStatus; cin.ignore();

    switch (chooseStatus)
    {
        case 0:
            statusEmployee= IN;
            break;
        case 1:
            statusEmployee = OUT;
            break;
        default:
            break;
    }

    scheduleOfEmployees scheduleEmployee;

    scheduleEmployee.date.day   = day;
    scheduleEmployee.date.month = month;
    scheduleEmployee.date.year  = year;

    scheduleEmployee.time.second = second;
    scheduleEmployee.time.minute = minute;
    scheduleEmployee.time.hour   = hour;

    scheduleEmployee.status      = statusEmployee;

    Employee employee = {nameEmployee, phonenumberEmployee, positionOfEmployee};

    employee.addScheduleEmployee(scheduleEmployee);

    employeeManagement. AddEmployee(employee);

    cout<<endl<<"\t Would you like reserve the futher room ? ";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 1: Go on reserve another room";
    cout<<endl<<"\t 0: Return";
    cout<<endl<<"\t----------------------\t";

    cin>>chooseOptionAdd;

    } while( chooseOptionAdd == 1);

    cout<<endl<<"The information of customers when they reserve the room : "<<endl;

    DisplayListOfStaff(employeeManagement.getdataEmployee());

}

void EmployeeManagement(EmployeeManager &employeeManagement){

    int chooseOptionReturn;
    while(1){

        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\t 1: Add the employee";
        cout<<endl<<"\t 2: Change the information of employee";
        cout<<endl<<"\t 3: Delete the information of employee";
        cout<<endl<<"\t 4: The List of staff";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"Please entern your choice: ";

        int chooseOptionEmployee;
        cin>>chooseOptionEmployee;

        switch (chooseOptionEmployee)
        {
            case ADDEMPLOYEE:
                AddInformationOfEmployee(employeeManagement);
                break;
            case CHANGEEMPLOYEE:
                ChangeInformationEmployeeInId(employeeManagement);
                break;
            case DELETEEMPLOYEE:
                DeleteEmployee(employeeManagement);
                break;
            case PRINTOFSTAFF:
                DisplayListOfStaff(employeeManagement.getdataEmployee());
                break;
            default:
                chooseOptionReturn = 1;
                break;
        }
        
        if(chooseOptionReturn == 1) break;
    }
}

int main(int argc, char const *argv[])
{

    vector<Room> databaseRoom;
    vector<Employee> databaseEmployee;
    CustomerManager customerManagement;
    EmployeeManager employeeManagement;

    setQuanityRoom(databaseRoom,9);

    while(1){

        cout<<"\n 1: Reservation Management\n 2: Customer Management\n 3: Employee Management"<<endl;
        cout<<" --------------------------";
        cout<<endl<<" Please enter your choice :";
        int chooseOption;
        cin>>chooseOption; cin.ignore();

    switch (chooseOption)
        {
            case RESERVATION:
                ReservationManagement(databaseRoom, customerManagement);
                break;
            case CUSTOMER:
                CustomerManagement(databaseRoom, customerManagement);
                break;
            case EMPLOYEE:
                EmployeeManagement(employeeManagement);
                break;
            default:
                break;
        } 
    }
       return 0;
}
