#include"Hotel.hpp"

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
////////
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
//////////
Employee ::Employee(string nameEmployees, string phonenumberEmployees, positionOfEmployees positionEmployees){

    static int id = 0;
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
/////
void EmployeeManager :: AddEmployee(Employee employee){

    databaseEmployee.push_back(employee);
}
vector<Employee>& EmployeeManager :: getdataEmployee(){

    return databaseEmployee;
}

////////////////////////

 USER::USER(string UserName, string PassWord ){

    static int id = 1;
    this ->IdUsername =id;
    id++;

    this->password = PassWord;
    this->username = UserName;
 }

string USER::GetUsername(){

    return username;
}

string USER :: GetPassword(){

    return password;
}
int USER :: GetIdUsername(){

    return IdUsername;
}

void USER::SetUsername(string UserName){

    this->username = UserName;
}

 void USER :: SetPassword(string Password){

    this->password = Password;
 }

bool USER:: ConfirmForUser(string inputUsername, string inputPassword){

    bool checkSignup =( inputUsername == username && inputPassword == password);
    return checkSignup;
}

////////////////////////

 void SecurityManagement:: addUser( string inputUsername, string inputPassword ){

    USER user ={inputUsername, inputPassword};
    databaseUser.push_back(user);
 }

 void SecurityManagement :: eraseUser(int idUsername){

    for(  auto i = databaseUser.begin(); i <= databaseUser.end(); i++){

        if(i->GetIdUsername() == idUsername ) databaseUser.erase( i );
    }
 }
void SecurityManagement:: editUser(string inputUsername, string inputPassword){

    for (auto i = databaseUser.begin(); i <= databaseUser.end(); i++)
    {
        if(i->GetUsername() == inputUsername) i->SetPassword(inputPassword);
    }
}

void SecurityManagement::setManagerPassword(string inputPassword){

    ObjectUser.SetPassword(inputPassword);
 }

bool SecurityManagement::getCheckSignUp(string inputUsername, string inputPassword){

    if(ObjectUser.ConfirmForUser(inputUsername, inputPassword)) return true;

    return false;
}

vector<USER>& SecurityManagement:: getDatabaseUser(){

    return databaseUser;
}
///////////////

Services :: Services( typeService serviceForCustomer, typeStatusOfService  statusServiceForCustomer ){

    static int id = 1;
    this->idService = id;
    id++;

    this->service = serviceForCustomer;
    this->statusService = statusServiceForCustomer;
}

typeService Services :: GetService(){

    return service;
}

typeStatusOfService Services :: GetStatus(){

    return statusService;
}

int Services ::GetIdService(){

    return idService;
}
////////////////////////
void ServiceManagement :: addService(typeService serviceForCustomer, typeStatusOfService statusServiceForCustomer ){

    Services serviceForObject ={serviceForCustomer, statusServiceForCustomer};
    databaseServices.push_back(serviceForObject);
}

void ServiceManagement :: eraseService(typeService service){

    for (auto i = databaseServices.begin(); i < databaseServices.end(); i++)
    {
        if(i->GetService() == service)  databaseServices.erase(i);
    }
    
}

vector<Services>& ServiceManagement :: getDatabaseServices(){

    return databaseServices;
}

///////////////////////

Payment::Payment( typePayment paymentmethod, typePriceRoom priceroom){

    static int idEachPayment = 1;
    this->idPayment = idEachPayment;
    idEachPayment++;

    this->paymentMethod = paymentmethod;
    this->priceRoom     = priceroom;

}

void Payment::addPaymentHistory(typePaymentHistory paymenthistory){

    paymentHistory.push_back(paymenthistory);
}

vector<typePaymentHistory>& Payment:: getdatabasePaymentHistory(){

    return paymentHistory;
}

 typePriceRoom Payment:: getPriceRoom(){

    return priceRoom;
 }

 typePayment Payment:: getPaymentMethod(){

    return paymentMethod;
 }
 int Payment::getIdRoom(){

    return idPayment;
 }
 void PaymentManagement::addPayment(Payment paymentForObject){

    databasePayment.push_back(paymentForObject);
 }

 void PaymentManagement:: erasePayment(int idPayment){

    for (auto i = databasePayment.begin(); i < databasePayment.end(); i++)
    {
        if( i->getIdRoom() == idPayment ) databasePayment.erase(i);
    }

 }
 vector<Payment>& PaymentManagement:: getdatabasePayment(){

    return databasePayment;
 }
//////////////////////

Statistic:: Statistic(typeEvaluate evaluatequality, int revenueofhotel){

    static int id = 1;
    this->evaluateOrderNumber = id;
    id++;

    this->evaluateQuality = evaluatequality;
    this->revenueOfHotel  = revenueofhotel;
}

 typeEvaluate Statistic:: GetEvaluateQuality(){

    return evaluateQuality;
 }

int Statistic:: GetRevenueOfHotel(){

    return revenueOfHotel;
}

int Statistic ::GetevaluateOrderNumber(){

    return evaluateOrderNumber;
}


void StatisticManagement :: addStatistic(Statistic statisticOfObject){

    databaseStatistic.push_back(statisticOfObject);
}

void StatisticManagement :: eraseStatistic(int evaluateOrderNumber){

    for (auto  i = databaseStatistic.begin(); i < databaseStatistic.end(); i++)
    {
        if(i->GetevaluateOrderNumber() == evaluateOrderNumber) databaseStatistic.erase(i);
    }
    
}

int StatisticManagement :: GetReversedRoomQuanity(){

    return reversedRoomQuanity;
}

void StatisticManagement :: SetRoomQuanity(int reversedroomquanity){

    this->reversedRoomQuanity = reversedroomquanity;

}

 vector<Statistic>& StatisticManagement :: GetdatabaseStatistic(){

    return databaseStatistic;
 }

double StatisticManagement :: GetQualityAverage(){

    double evaluateAverageScore = 0;
    for (auto i = databaseStatistic.begin(); i < databaseStatistic.end(); i++)
    {
        evaluateAverageScore += i->GetEvaluateQuality();
    }
    
        return evaluateAverageScore/databaseStatistic.size();
}

string StatisticManagement :: GetQualityHotel(){

    if(GetQualityAverage() >= 800 ) return "Very Good" ;
    else if(GetQualityAverage() >= 650 ) return "Good" ;
    else return "Bad" ;
}

int StatisticManagement :: GetRevenueHotel(){
    
    int totalRevenue;
    for (auto i = databaseStatistic.begin(); i < databaseStatistic.end(); i++)
    {
        totalRevenue +=i->GetRevenueOfHotel();
    }

    return totalRevenue;
    
}

/////////////////////

void DisplayListOfCustomer(vector<Customer> &databaseCustomer);

////////////////////////
void DisplayListOfStaff(vector<Employee> &databaseEmployee);
////////////////////////////
void PrintService(ServiceManagement &serviceManagement);
///////////

void setQuanityRoom(vector<Room> &databaseRoom, uint8_t quanity){

    for (uint8_t i = 1; i <= quanity; i++)
    {
        Room room = {i};
        databaseRoom.push_back(room);
    }
    
}

void printLishOfRoom(vector<Room> &databaseRoom){

    cout<<endl<<" List of Room: \n"<<endl;
    cout<<"\tRoom\t|";

    for (uint8_t i = 0; i < databaseRoom.size(); i++)
    {
        printf("  %d\t|",databaseRoom[i].getRoomNumber());
    }

    cout<<endl<<"\t---------------------------------------------------------------------------------\t";
    cout<<endl<<"\tStatus\t|";
    for(uint8_t i =0; i< databaseRoom.size(); i++){

        if( databaseRoom[i].isAvailable() == true) cout<<"  0\t|";
        else cout<<"  X\t|";
    }
    cout<<endl<<endl<<"\t 0 : have room";
    cout<<endl<<"\t X : booked room";
    cout<<"\n\n";
    
}

void bookRoom(vector<Room> &databaseRoom, CustomerManager &customerManager, StatisticManagement &statisticManagement){

    int chooseAddCustomer;
    
    do{

        printLishOfRoom(databaseRoom);

        cout<<endl<<"\tEnter the room number: ";

        int chooseRoomNumber;

        cin>>chooseRoomNumber; cin.ignore();

        static uint8_t reservedRoomQuanity = 0;

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

            cout<<endl<<"\tEnter the day: "; 
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
        cout<<endl<<"\tPlease entern your choice: ";
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

        reservedRoomQuanity++;

        statisticManagement.SetRoomQuanity(reservedRoomQuanity);

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

    if(statusCustomer == IN) return "Enter";
    else if(statusCustomer == OUT) return "Exit";

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

    cout<<endl<<"\tID Room\t  |"<<"Name\t\t  |"<<"PhoneNumber\t\t\t|"<<"Adrress\t |";
    cout<<endl<<"\t--------------------------------------------------------------------------\t";
    for (uint8_t i = 0; i < databaseCustomer.size(); i++)
    {
        cout<<endl<<"\t"<<databaseCustomer[i].getIdRoom()<<"\t  |"<<databaseCustomer[i].getname()<<"\t\t  |"<<databaseCustomer[i].getPhoneNumber()<<"\t\t\t|"<<
            databaseCustomer[i].getAddress()<<"\t\t |"; 
        cout<<endl<<"\t--------------------------------------------------------------------------\t";
    }

    cout<<endl<<"The history of Customer: "<<endl;
    cout<<endl<<"\tID Room\t  |"<<"Name\t\t  |"<<"Date\t\t\t  |"<<"Time\t\t\t  |"<<"Status\t\t|";
    cout<<endl<<"\t-----------------------------------------------------------------------------------------------\t";

    for (uint8_t i = 0; i < databaseCustomer.size(); i++)
    {
        cout<<endl<<"\t"<<databaseCustomer[i].getIdRoom()<<"\t  |"<<databaseCustomer[i].getname()<<"\t\t  |";
        DisplayHistoryOfCustomer(databaseCustomer[i].getBookingHistory());
        cout<<endl<<"\t-----------------------------------------------------------------------------------------------\t";
    }
    
    cout<<"\n\n";
    
}

void ReservationManagement(vector<Room> &databaseRoom, CustomerManager &customerManager, StatisticManagement &statisticManagement){

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
                bookRoom(databaseRoom, customerManager, statisticManagement);
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
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseId  )
        {
        
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

        int chooseIDCustomer;
        cin>>chooseIDCustomer; cin.ignore();

        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\t 1: Change the name of customer";
        cout<<endl<<"\t 2: Change the phonenumber of customer";
        cout<<endl<<"\t 3: Change the address of customer";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\tPlease enter your choice: ";

        int chooseOptionChange;
        cin>>chooseOptionChange; cin.ignore();

        switch (chooseOptionChange)
            {
            case 1:
                ChangeNameOfCustomerInId(customerManagement, chooseIDCustomer);
                break;
            case 2:
                ChangePhoneNumberOfCustomerInId(customerManagement,chooseIDCustomer);
                break;
            case 3:
                ChangeAddressOfCustomerInId(customerManagement, chooseIDCustomer);
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
    cout<<endl<<"The list of room after update: "<<endl;
    
}

void CustomerManagement(vector<Room> &databaseRoom,CustomerManager &customerManagement,StatisticManagement &statisticManagement){

        if(customerManagement.getDatabaseCustomer().size() == 0) cout<<endl<<endl<<"Please enter the information of customer at the choice 1!"<<endl;
        
        else {
            int chooseReturn;
            while(1){

                cout<<endl<<"The list of the customer informations :  \n";
                DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

                cout<<endl<<"\t--------------------------------------\t";
                cout<<endl<<"\t 1: Add the customer";
                cout<<endl<<"\t 2: Change the information of customer";
                cout<<endl<<"\t 3: Delete the information of customer";
                cout<<endl<<"\t 0: Return";
                cout<<endl<<"\t--------------------------------------\t";
                cout<<endl<<"\tPlease enter your choice: ";
                
                int chooseOptionToChangeCustomer;
                cin>>chooseOptionToChangeCustomer;

                switch (chooseOptionToChangeCustomer)
                {
                        case ADDCUSTOMER:
                            bookRoom(databaseRoom,customerManagement, statisticManagement);
                            break;
                        case CHANGECUSTOMER:
                            ChangeInformationCustomerInId(customerManagement);
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

        cout<<endl<<"\tPlease enter the ID Employee which you want change it: ";

        int chooseIDEmployee;
        cin>>chooseIDEmployee; cin.ignore();

        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\t 1: Change the name of employee";
        cout<<endl<<"\t 2: Change the phonenumber of employee";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\tPlease enter your choice: ";

        int chooseOptionChange;
        cin>>chooseOptionChange; cin.ignore();

        switch (chooseOptionChange)
            {
            case 1:
                ChangeNameOfEmployeeInId(employeeManagement, chooseIDEmployee);
                break;
            case 2:
            ChangePhoneNumberOfEmployeeInId(employeeManagement, chooseIDEmployee);
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
    cout<<endl<<"The list of room after update: "<<endl;
    
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

    if(statusEmployee == IN) return "Enter";
    else if(statusEmployee == OUT) return "Exit";

    return " ";

}
void DisplayScheduleOfEmployee(vector<scheduleOfEmployees> scheduleEmployee){


    for (uint8_t i = 0; i < scheduleEmployee.size(); i++)
    {
         cout<<scheduleEmployee[i].date.day<<"/"<<scheduleEmployee[i].date.month<<"/"<<scheduleEmployee[i].date.year
        <<"\t\t  |"<<scheduleEmployee[i].time.hour<<":" <<scheduleEmployee[i].time.minute<<":"<<scheduleEmployee[i].time.second
        <<"\t\t  |"<<AssignStatusInHotelOfEmployee(scheduleEmployee[i].status)<<"\t\t |";

    }
    
}
void DisplayListOfStaff(vector<Employee> &databaseEmployee){

    cout<<endl<<"\nThe list of staff : ";
    cout<<endl<<"\tID\t  |"<<"Name\t\t  |"<<"PhoneNumber\t\t\t |"<<"Position\t\t   |";
    cout<<endl<<"\t-------------------------------------------------------------------------------------\t";
    for (uint8_t i = 0; i < databaseEmployee.size(); i++)
    {
        cout<<endl<<"\t"<<databaseEmployee[i].GetId()<<"\t  |"<<databaseEmployee[i].GetName()<<"\t\t  |"<<databaseEmployee[i].GetPhoneNumber()<<"\t\t  |"<<
            AssignStatusPositionOfEmployee(databaseEmployee[i].GetPosition())<<"\t\t\t  |"; 
        cout<<endl<<"\t-------------------------------------------------------------------------------------\t";
    }
    
    cout<<"\n\n";

    cout<<endl<<"The history of Customer: "<<endl;
    cout<<endl<<"\tID\t  |"<<"Name\t\t  |"<<"Date\t\t\t  |"<<"Time\t\t\t  |"<<"Status\t\t  |";
    cout<<endl<<"\t---------------------------------------------------------------------------------------------\t";

    for (uint8_t i = 0; i < databaseEmployee.size(); i++)
    {
        cout<<endl<<"\t"<<databaseEmployee[i].GetId()<<"\t  |"<<databaseEmployee[i].GetId()<<"\t\t  |";
        DisplayScheduleOfEmployee(databaseEmployee[i].GetSchedule());
        cout<<endl<<"\t---------------------------------------------------------------------------------------------\t";
    }
    
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
        cout<<endl<<"\tPlease enter your choice: ";

        positionOfEmployees positionOfEmployee;
        int choosePositionEmployee;
        cin>>choosePositionEmployee; cin.ignore();

        switch(choosePositionEmployee)
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
        cout<<endl<<"\tPlease entern your choice: ";
        
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

void FunctionOfStaffToChangeInformation(EmployeeManager &employeeManagement){

     cout<<endl<<" STAFF";
    int chooseOptionReturn;
    while(1){

        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\t 1: Change the information of employee";
        cout<<endl<<"\t 2: The List of staff";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t--------------------------------------\t";
        cout<<endl<<"\tPlease enter your choice: ";

        int chooseOptionEmployee;
        cin>>chooseOptionEmployee;

        switch (chooseOptionEmployee)
        {
            case 1:
                cout<<endl<<"STAFF";
                ChangeInformationEmployeeInId(employeeManagement);
                break;
            case 2:
                cout<<endl<<"STAFF";
                DisplayListOfStaff(employeeManagement.getdataEmployee());
                break;
            default:
                chooseOptionReturn = 1;
                break;
        }
        
        if(chooseOptionReturn == 1) break;
    }

}

void FunctionOfStaffForEmployeeManagement(EmployeeManager &employeeManagement, SecurityManagement &securityManagement){

    cout<<endl<<" STAFF";
    bool checkSignUp = securityManagement.getCheckSignUp("MANAGER", "ADMIN");

    if(checkSignUp){

        string usernameEmployee;
        cout<<endl<<"\tEnter your employee username : ";
        cin>> usernameEmployee;

        string passwordEmployee;
        cout<<"\n\tPlease enter your employee password: ";
        cin>> passwordEmployee;

        for (auto i = securityManagement.getDatabaseUser().begin(); i < securityManagement.getDatabaseUser().end(); i++)
        {
                if(i->GetUsername() == usernameEmployee && i->GetPassword() == passwordEmployee){

                        FunctionOfStaffToChangeInformation(employeeManagement);
                        break;
                }
        }
    }
}

void FunctionOfManagerForEmployeeManagement(EmployeeManager &employeeManagement, SecurityManagement &securityManagement){

    cout<<endl<<" MANAGER";
    cout<<endl<<"\tPlease log in the account of manager: ";
    string username;
    cout<<"\n\tEnter username of manager: "; cin>>username; cin.ignore();
    string password;
    cout<<endl<<"\tEntern password of manager: ";cin>>password;cin.ignore();

    bool checkSignUp = securityManagement.getCheckSignUp(username, password);

    if( checkSignUp == false) cout<<endl<<"\tPassword is not right !!";
    
    else {
        int chooseOptionReturn;
        while(1){

            cout<<endl<<"\t MANAGER";
            cout<<endl<<"\t--------------------------------------\t";
            cout<<endl<<"\t 1: Add the employee";
            cout<<endl<<"\t 2: Change the information of employee";
            cout<<endl<<"\t 3: Delete the information of employee";
            cout<<endl<<"\t 4: The List of staff";
            cout<<endl<<"\t 0: Return";
            cout<<endl<<"\t--------------------------------------\t";
            cout<<endl<<"\tPlease enter your choice: ";

            int chooseOptionEmployee;
            cin>>chooseOptionEmployee;

            switch (chooseOptionEmployee)
            {
                case ADDEMPLOYEE:
                    cout<<endl<<"MANAGER";
                    AddInformationOfEmployee(employeeManagement);
                    break;
                case CHANGEEMPLOYEE:
                    cout<<endl<<"MANAGER";
                    ChangeInformationEmployeeInId(employeeManagement);
                    break;
                case DELETEEMPLOYEE:
                    cout<<endl<<"MANAGER";
                    DeleteEmployee(employeeManagement);
                    break;
                case PRINTOFSTAFF:
                    cout<<endl<<"MANAGER";
                    DisplayListOfStaff(employeeManagement.getdataEmployee());
                    break;
                default:
                    chooseOptionReturn = 1;
                    break;
            }
            
            if(chooseOptionReturn == 1) break;
        }
    }
}

void EmployeeManagement(EmployeeManager &employeeManagement, SecurityManagement &securityManagement ){
    
    cout<<endl<<"Please choose the position that you work on";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<"\t 1: Manager";
    cout<<endl<<"\t 2: Employee";
    cout<<endl<<"\t 0: Return";
    cout<<endl<<"\t----------------------\t";
    cout<<endl<<" Please enter your choice: ";

    int chooseOptionPosition;
    cin>>chooseOptionPosition; cin.ignore();

    switch (chooseOptionPosition){

        case 1:
            FunctionOfManagerForEmployeeManagement(employeeManagement, securityManagement);
            break;
        case 2:
            FunctionOfStaffForEmployeeManagement(employeeManagement, securityManagement);
            break;
        default:
            break;

        }
}
///////

void PrintListOfUser(SecurityManagement &securityManagement){

    cout<<endl<<"\t"<<"Stt\t |"<<"Username\t |"<<"Password\t\t |";
    for (uint8_t i =0 ; i < securityManagement.getDatabaseUser().size(); i++)
    {
        cout<<endl<<"\t------------------------------------------------\t";
        cout<<endl<<"\t"<<(securityManagement.getDatabaseUser())[i].GetIdUsername()<<"\t |"<<(securityManagement.getDatabaseUser())[i].GetUsername()<<"\t\t |"<<(securityManagement.getDatabaseUser())[i].GetPassword()<<"\t\t |";
    }
    
        cout<<endl;
   
}
void AddUser(SecurityManagement &securityManagement){

    cout<<endl<<"\n\tAdd new user into the list: "<<endl;
    int chooseOption;
    do {

        string newUsername;
        cout<<endl<<"\tEnter username: "; cin>>newUsername;
        string newPassword;
        cout<<endl<<"\tEnter password: ";cin>>newPassword;

        securityManagement.addUser(newUsername, newPassword);

        cout<<endl<<"\n\tThe list of account :";
        PrintListOfUser(securityManagement);

        cout<<endl<<"\t Would you like to add user ? ";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\t 1: Go on add user";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\tPlease enter your choice: ";
        
        cin>>chooseOption; cin.ignore();

    } while (chooseOption == 1);

}

void EraseUser(SecurityManagement &securityManagement){

    cout<<endl<<"\n\tThe list of account :";
    PrintListOfUser(securityManagement);

    cout<<endl<<"\n\tPlease enter ID of username which need delete: ";
    int chooseIdUsername;
    cin>>chooseIdUsername;cin.ignore();

    securityManagement.eraseUser(chooseIdUsername);
    cout<<endl<<"\n\tThe list of account when updated :";

    PrintListOfUser(securityManagement);

}

void ChangePasswordUser(SecurityManagement &securityManagement){

    cout<<endl<<"\n\tThe list of account :";
    PrintListOfUser(securityManagement);

    cout<<endl<<"\n\t Please choose user which need change "<<endl;
    
    string newUsername;
    cout<<"\tEnter username: "; cin>>newUsername;
    string newPassword;
    cout<<endl<<"\tEnter password: ";cin>>newPassword;

    securityManagement.editUser( newUsername, newPassword);

    cout<<endl<<"\n\tThe list of user when updated information:";

    PrintListOfUser(securityManagement);

}

void ChangePasswordManager(SecurityManagement &securityManagement){

    string oldPassword;
    string newPassword;
    string newPasswordAgain;
    string UsernameManager;

    cout<<endl<<"Please enter the username of manager: ";
    cin>>UsernameManager;
    cout<<endl<<"Please enter the old password of manager: ";
    cin>>oldPassword;

    bool checkSignUp = securityManagement.getCheckSignUp(UsernameManager,oldPassword);

    if( checkSignUp == false) cout<<endl<<"\tPassword is not right. Please enter again!!";

    else{

        cout<<endl<<"Enter the new password of manager: "; cin>>newPassword;
        cout<<endl<<"Enter the new password of manager again: "; cin>> newPasswordAgain;
        securityManagement.setManagerPassword(newPasswordAgain);
        cout<<endl<<"Updated successfully the new password for manager. ";
    
    }
}

void SecurityManagements(SecurityManagement &securityManagement){

    cout<<endl<<"Please log in the account of manager: "<<endl;
    string username;
    cout<<endl<<"\tEnter username of manager: "; cin>>username;
    string password;
    cout<<"\n\tEnter password of manager: ";cin>>password;

    bool checkSignUp = securityManagement.getCheckSignUp(username, password);

    if( checkSignUp == false) cout<<endl<<"\tPassword of manager is not right !!";

    else{

        int chooseReturn;
        while(1){

            cout<<endl<<"\t-----------------------------------\t";
            cout<<endl<<"\t1: Add user. ";
            cout<<endl<<"\t2: Delete user. ";
            cout<<endl<<"\t3: Change password of user. ";
            cout<<endl<<"\t4: Change password of manager. ";
            cout<<endl<<"\t0: Return. ";
            cout<<endl<<"\t-----------------------------------\t";
            cout<<endl<<"\tPlease enter your choice: ";
            
            int chooseOption;
            cin>>chooseOption; cin.ignore();

            switch (chooseOption){

                case 1:
                    AddUser(securityManagement);
                    break;
                case 2:
                    EraseUser(securityManagement);
                    break;
                case 3:
                    ChangePasswordUser(securityManagement);
                    break;
                case 4:
                    ChangePasswordManager(securityManagement);
                    break;
                default:
                    chooseReturn = 1;
                    break;
                }
            
            if(chooseReturn == 1) break;
        }
    }

}
////////////////

void EraseService(ServiceManagement &serviceManagement){

    cout<<endl<<" The list of services: ";
    PrintService(serviceManagement);

    cout<<endl<<"\tEnter the service that you want to delete it: ";

    int chooseService;
    cin>>chooseService;

    typeService service;


    switch (chooseService)
    {
        case 1:
            service = HOTEL;
            break;
        case 2:
            service = BAR;
            break;
        case 3:
            service = POOL;
            break;
        case 4:
            service = GYM;
            break;
        default:
            break;    
    }

    serviceManagement.eraseService(service);

    cout<<endl<<"The list of services that are updated: ";
    PrintService(serviceManagement);
}

string AssignForService(typeService service){

    if(service == HOTEL) return "Hotel";
    else if (service == BAR) return "Bar";
    else if (service == POOL) return "Pool";
    else if (service == GYM) return "Gym";

    return " ";

}
string AssignForStatusService(typeStatusOfService statusService){

    if(statusService == FULL) return "full";
    else if(statusService == STILL) return "still";

    return " ";
}
void PrintService(ServiceManagement &serviceManagement){

    cout<<endl<<endl<<"\t"<<"Stt\t  |"<<"Service\t\t |"<<"Status\t  |";
    for (uint8_t i = 0; i < serviceManagement.getDatabaseServices().size(); i++)
    {
        cout<<endl<<"\t--------------------------------------------------\t";
        cout<<endl<<"\t"<<(serviceManagement.getDatabaseServices())[i].GetIdService()<<"\t  |"<<AssignForService((serviceManagement.getDatabaseServices())[i].GetService())
            <<"\t\t  |"<<AssignForStatusService((serviceManagement.getDatabaseServices())[i].GetStatus())<<"\t   |";
    }
    cout<<endl;
    

}

void AddService(ServiceManagement &serviceManagement){

    int chooseOption;
    do{
        cout<<endl<<" SERVICE ";
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\t1: Hotel ";
        cout<<endl<<"\t2: Bar ";
        cout<<endl<<"\t3: Pool ";
        cout<<endl<<"\t4: Gym ";
        cout<<endl<<"\t0: Return";
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\tPlease choose service then you want it: ";

        int chooseService;
        cin>>chooseService;

        typeService service;

        switch (chooseService)
        {
            case 1:
                service = HOTEL;
                break;
            case 2:
                service = BAR;
                break;
            case 3:
                service = POOL;
                break;
            case 4:
                service = GYM;
                break;
            default:
                break;    
        }
        
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\t1: Full ";
        cout<<endl<<"\t2: still ";
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\tPlease choose status of the service: ";
        int chooseStatus;
        cin>>chooseStatus;

        typeStatusOfService statuService;

        switch (chooseStatus)
        {
            case 1:
                statuService = FULL;
                break;
            case 2:
                statuService = STILL;
                break;
           
                break;
            default:
                break;    
        }

        serviceManagement.addService(service,statuService);

        cout<<endl<<" The list of services: ";
        PrintService(serviceManagement);

        cout<<endl<<"\t Would you like to add service ? ";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\t 1: Go on add service";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\tPlease enter your choice: ";
        
        cin>>chooseOption; cin.ignore();

    }while(chooseOption == 1);

}

void ServiceManagements(ServiceManagement &serviceManagement, SecurityManagement &securityManagement){

    cout<<endl<<"Please log in the account of manager: "<<endl;
    string username;
    cout<<endl<<"\tEnter username of manager: "; cin>>username;
    string password;
    cout<<"\n\tEnter password of manager: ";cin>>password;

    bool checkSignUp = securityManagement.getCheckSignUp(username, password);

    if( checkSignUp == false) cout<<endl<<"\tPassword of manager is not right !!";

    else {

        cout<<endl<<" MANAGER";
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\t1: Add service ";
        cout<<endl<<"\t2: Erase service ";
        cout<<endl<<"\t0: Return  ";
        cout<<endl<<"\t-----------------------------------\t";
        cout<<endl<<"\tPlease choose status of the service: ";

        int chooseOption;
        cin>>chooseOption; cin.ignore();

        switch (chooseOption)
        {
            case 1:
                AddService(serviceManagement);
                break;
            case 2:
                EraseService(serviceManagement);
                break;
            default:
                break;
        }
    }

}
////////////////////////

string AssignStatusPaymentOfCustomer(typeStatus statusCustomer){

     if(statusCustomer == OUT) return "Exit";

    return " ";

}
void DisplayHistoryOfPayment(vector<typePaymentHistory> &paymentHistory ){

    for (uint8_t i = 0; i < paymentHistory.size(); i++)
    {
         cout<<paymentHistory[i].date.day<<"/"<<paymentHistory[i].date.month<<"/"<<paymentHistory[i].date.year
        <<"\t\t  |"<<paymentHistory[i].time.hour<<":" <<paymentHistory[i].time.minute<<":"<<paymentHistory[i].time.second
        <<"\t\t  |"<<AssignStatusPaymentOfCustomer(paymentHistory[i].status)<<"\t\t|";

    }
    
}
string AssignTypeRoomOfCustomer(typePriceRoom priceRoom){

    if(priceRoom == VIP) return "Vip";
    else if(priceRoom == NORMAL) return "Normal";
    else if(priceRoom == LUXURY) return "Luxury";
    return " ";

}

void PaymentBillForCustomer(PaymentManagement &paymentmanagement,CustomerManager &customerManagement, StatisticManagement &statisticManagement, int chooseIdRoom){
    
    cout<<endl<<"\t\t\t\t__________PAYMENT BILL__________\t\t\t\t "<<endl;
    cout<<endl<<"\t#############################################################################"<<endl;
    for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseIdRoom ){

            cout<<endl<<"\tID Room\t  |"<<"Name\t\t  |"<<"PhoneNumber\t\t\t|"<<"Adrress\t |";
            cout<<endl<<"\t--------------------------------------------------------------------------\t";
            cout<<endl<<"\t"<<(customerManagement.getDatabaseCustomer())[i].getIdRoom()<<"\t  |"<<(customerManagement.getDatabaseCustomer())[i].getname()<<"\t\t  |"<<(customerManagement.getDatabaseCustomer())[i].getPhoneNumber()<<"\t\t\t|"<<
            (customerManagement.getDatabaseCustomer())[i].getAddress()<<"\t\t |"; 
        }
    }
    
    cout<<endl<<endl<<"\n\tID Room\t  |"<<"TypeRoom\t  |"<<"Date\t\t\t  |"<<"Time\t\t\t  |"<<"Status\t\t|";
    cout<<endl<<"\t--------------------------------------------------------------------------------------------------\t";

    int totalPrice = 0;

     for (uint8_t i = 0; i < paymentmanagement.getdatabasePayment().size(); i++)
    {
        if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseIdRoom ){

            cout<<endl<<"\t"<<(customerManagement.getDatabaseCustomer())[i].getIdRoom()<<"\t  |"<<AssignTypeRoomOfCustomer((paymentmanagement.getdatabasePayment())[i].getPriceRoom())<<"\t\t  |";
            DisplayHistoryOfPayment((paymentmanagement.getdatabasePayment())[i].getdatabasePaymentHistory());

            totalPrice = (paymentmanagement.getdatabasePayment())[i].getPriceRoom();
    
        }
    }
    
    cout<<endl<<endl<<"\t#############################################################################"<<endl;
    cout<<endl<<"\n\tTotal Cost: "<<totalPrice<<" (USD)";


    cout<<endl<<"\n\tPlease evaluate the room quality of hotel !!";
    cout<<endl<<"\t------------------------\t";
    cout<<endl<<"\t 1: One star";
    cout<<endl<<"\t 2: Two star";
    cout<<endl<<"\t 3: Three star";
    cout<<endl<<"\t 4: Four star";
    cout<<endl<<"\t 5: Five star";
    cout<<endl<<"\t------------------------\t";
    cout<<endl<<"\tPlease choose your the level satisfaction: ";

    int chooseQuality;
    cin>>chooseQuality; cin.ignore();

    typeEvaluate statusQuality;

    switch (chooseQuality)
    {
    case 1:
        statusQuality = ONESTAR;
        break;
    case 2:
        statusQuality = TWOSTAR;
        break;
    case 3:
        statusQuality = THREESTAR;
        break;
    case 4:
        statusQuality = FOURSTAR;
        break;
    case 5:
        statusQuality = FIVESTAR;
        break;
    default:
        break;
    }

    Statistic statisticObject = {statusQuality, totalPrice};

    statisticManagement.addStatistic(statisticObject);

    cout<<endl<<"\n\tPaid for room number: "<<chooseIdRoom<<endl;

}

void PaymentManagements(PaymentManagement &paymentmanagement,CustomerManager &customerManagement, StatisticManagement &statisticManagement, vector<Room> databaseRoom){
  
    printLishOfRoom(databaseRoom);
    cout<<endl<<"The information list of customer: "<<endl;
    DisplayListOfCustomer(customerManagement.getDatabaseCustomer());

    int choosePaymentAgain;
    do{
        cout<<endl<<"\t Please choose room which you want to pay for it: ";
        int chooseIdRoom;
        cin>>chooseIdRoom; cin.ignore();

        for (uint8_t i = 0; i < databaseRoom.size(); i++)
        {
            if(databaseRoom[i].getRoomNumber() == chooseIdRoom){

                databaseRoom[i].checkOut();
            }
        }

        for (uint8_t i = 0; i < customerManagement.getDatabaseCustomer().size(); i++)
        {
            if((customerManagement.getDatabaseCustomer())[i].getIdRoom() == chooseIdRoom ){

                cout<<endl<<"\tID Room\t  |"<<"Name\t\t  |"<<"PhoneNumber\t\t\t|"<<"Adrress\t |";
                cout<<endl<<"\t--------------------------------------------------------------------------\t";
                cout<<endl<<"\t"<<(customerManagement.getDatabaseCustomer())[i].getIdRoom()<<"\t  |"<<(customerManagement.getDatabaseCustomer())[i].getname()<<"\t\t  |"<<(customerManagement.getDatabaseCustomer())[i].getPhoneNumber()<<"\t\t\t|"<<
                (customerManagement.getDatabaseCustomer())[i].getAddress()<<"\t\t |"; 
            }
        }

        cout<<endl<<"\n The date for payment: ";
        int day   = 0;
        int month = 0;
        int year = 0;
        while(1){

            cout<<endl<<"\tEnter the day: "; 
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
        
        typeStatus statusCustomer = OUT ;

        typePaymentHistory paymenthistory;

        paymenthistory.date.day   = day;
        paymenthistory.date.month = month;
        paymenthistory.date.year  = year;

        paymenthistory.time.second = second;
        paymenthistory.time.minute = minute;
        paymenthistory.time.hour   = hour;

        paymenthistory.status      = statusCustomer;

        cout<<endl<<"\n\tPlease choose type of room that you are reserved :";
        cout<<endl<<"\t------------------------\t";
        cout<<endl<<"\t 1: VIP ";
        cout<<endl<<"\t 2: NORMAL";
        cout<<endl<<"\t 3: LUXURY";
        cout<<endl<<"\t------------------------\t";
        cout<<endl<<"\tPlease enter your choice : ";
        
        int chooseOptionRoom;
        cin>>chooseOptionRoom; cin.ignore();
        typePriceRoom choosePriceRoom;
        
        switch (chooseOptionRoom)
        {
            case 1:
                choosePriceRoom = VIP;
                break;
            case 2:
                choosePriceRoom = NORMAL;
                break;
            case 3:
                choosePriceRoom = LUXURY;
                break;
            default:
                break;
        }

        cout<<endl<<"\n\tPlease choose type of payment that you can pay for it:";
        cout<<endl<<"\t------------------------\t";
        cout<<endl<<"\t 1: CREDIT CARD ";
        cout<<endl<<"\t 2: INTERNET BANKING";
        cout<<endl<<"\t 3: DIGITAL WALLET";
        cout<<endl<<"\t------------------------\t";
        cout<<endl<<"\tPlease enter your choice : ";

        int chooseOption;
        cin>>chooseOption; cin.ignore();
        typePayment choosePayment;
        
        switch (chooseOption)
        {
            case 1:
                choosePayment = CREDIT;
                break;
            case 2:
                choosePayment = BANKING;
                break;
            case 3:
                choosePayment = DIGITAL_WALLET;
                break;
            default:
                break;
        }

        if(choosePayment == CREDIT){

            cout<<endl<<"\tPayment by Credit card:"<<endl;

            Payment paymentForObject = {choosePayment,choosePriceRoom};
            paymentForObject.addPaymentHistory(paymenthistory);
            paymentmanagement.addPayment(paymentForObject);

            PaymentBillForCustomer(paymentmanagement,customerManagement, statisticManagement, chooseIdRoom);

            cout<<endl<<"\tYou scan credit card here and enter password to pay for room\t"<<endl;
            cout<<endl<<"\t\t\t______Thank you for your belief that choose us!!______\t\t\t"<<endl;

            cout<<endl<<"The list of room aften payemnt:"<<endl;
            printLishOfRoom(databaseRoom);

        }
        else if(choosePayment == BANKING) {

            cout<<endl<<"\tPayment by Internet Banking:"<<endl;

            Payment paymentForObject = {choosePayment,choosePriceRoom};
            paymentForObject.addPaymentHistory(paymenthistory);
            paymentmanagement.addPayment(paymentForObject);

            PaymentBillForCustomer(paymentmanagement,customerManagement, statisticManagement, chooseIdRoom);
            cout<<endl<<"\tYou have successfully transferred money\t"<<endl;
            cout<<endl<<"\t\t\t______Thank you for your belief that choose us!!______\t\t\t"<<endl;
            
            cout<<endl<<"The list of room aften payemnt:"<<endl;
            printLishOfRoom(databaseRoom);

        }
        else if( choosePayment == DIGITAL_WALLET) {

            cout<<endl<<"\tPayment by Digital Wallet:"<<endl;
            
            Payment paymentForObject = {choosePayment,choosePriceRoom};
            paymentForObject.addPaymentHistory(paymenthistory);
            paymentmanagement.addPayment(paymentForObject);

            PaymentBillForCustomer(paymentmanagement,customerManagement, statisticManagement, chooseIdRoom);
            cout<<endl<<"\tPlease for us that see the information transferred money\t"<<endl;
            cout<<endl<<"\t\t\t______Thank you for your belief that choose us!!______\t\t\t"<<endl;

            cout<<endl<<"The list of room aften payemnt:"<<endl;
            printLishOfRoom(databaseRoom);

        }
        
        cout<<endl<<"\t Would you like pay for the futher room ? ";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\t 1: Go on pay for";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\tPlease enter your choice : ";

        cin>>choosePaymentAgain;

    } while (choosePaymentAgain == 1);

}
///////////////////////////

void reseredRoomQuanity(StatisticManagement &statisticManagement){

    cout<<endl<<"\tThe quanity of rooms which are reserved: "<< statisticManagement.GetReversedRoomQuanity();

    cout<<endl<<"\tRate of rooms booked: "<< (float)(statisticManagement.GetReversedRoomQuanity()/9) ;

}
string AssignStatusQualityHotel(typeEvaluate evaluateQuality){

    if(evaluateQuality == ONESTAR) return " * ";
    else if(evaluateQuality == TWOSTAR) return " ** ";
    else if(evaluateQuality == THREESTAR) return " *** ";
    else if(evaluateQuality == FOURSTAR) return " **** ";
    else if(evaluateQuality == FIVESTAR) return " ***** ";
    return " ";
}

void EvaluationOfCustomer(StatisticManagement &statisticManagement){

    cout<<endl<<"\tThe evaluation about the quality for hotel: ";
    cout<<endl<<endl<<"\tThe table of the evaluation from customer:"<<endl;

    cout<<endl<<"\t"<<"Stt\t |\t"<<"Quality\t |";
    for (uint8_t i = 0; i < statisticManagement.GetdatabaseStatistic().size(); i++)
    {
        cout<<endl<<"\t------------------------------\t";
        cout<<endl<<"\t"<<(statisticManagement.GetdatabaseStatistic())[i].GetevaluateOrderNumber()<<"\t |\t"
            <<(statisticManagement.GetdatabaseStatistic())[i].GetEvaluateQuality()<<"\t |";
    }
    

    cout<<endl<<endl<<"\tThe quality of hotel evaluated is: "<<statisticManagement.GetQualityHotel();
    cout<<endl;
}
string AssignStatusQualityHotel(int revenue){

    if(revenue >= 8000 ) return " very High ";
    else if(revenue >= 6000) return " High ";
    else if(revenue >= 4000) return " Low ";
    else return " very Low ";
    
    return " ";
}
void RevenueOfHotel(StatisticManagement &statisticManagement){

    cout<<endl<<endl<<"\tThe revenue of hotel:";

    cout<<endl<<"\tThe revenue evaluated is:"<<AssignStatusQualityHotel(statisticManagement.GetRevenueHotel());
    cout<<endl;
}

void StatisticManagements(StatisticManagement &statisticManagement){

    int chooseReturn;
    while(1){

        cout<<endl<<"\t Reports and statistics about the actives of Hotel: ";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\t 1: Revenue of the hotel ";
        cout<<endl<<"\t 2: Evaluation of the customer ";
        cout<<endl<<"\t 3: Quanity for reserving the room ";
        cout<<endl<<"\t 0: Return";
        cout<<endl<<"\t----------------------\t";
        cout<<endl<<"\tPlease enter your choice : ";

        int chooseOption;
        cin>>chooseOption; cin.ignore();

        switch (chooseOption)
        {
            case 1:
                RevenueOfHotel(statisticManagement);
                break;
            case 2:
                EvaluationOfCustomer(statisticManagement);
                break;
            case 3:
                reseredRoomQuanity(statisticManagement);
                break;    
            default:
                chooseReturn = 1;
                break;
        }

        if( chooseReturn == 1 ) break;
    }
}