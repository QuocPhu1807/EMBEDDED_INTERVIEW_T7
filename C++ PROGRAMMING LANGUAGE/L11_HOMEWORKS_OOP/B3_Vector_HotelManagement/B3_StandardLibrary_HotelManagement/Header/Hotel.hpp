#ifndef _HOTEL_H
#define _HOTEL_H

#include<iostream>
#include<vector>
#include<string>
#include<stdint.h>

using namespace std;

namespace Hotel{

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
    EMPLOYEE,
    SERVICE,
    PAYMENT,
    SECURITY,
    STATISTICS
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
/////////////
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

class CustomerManager{
    private:
        vector<Customer> databaseCustomer;
    public:
        void addCustomer( Customer &customer);
        void editIdRoomCustomer(vector<Room> &databaseRoom, int idRoom_Current, int idRoom);
       // void deleteCustomer();

        vector<Customer> &getDatabaseCustomer();
};
////
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
/////
class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        void AddEmployee(Employee employee);
        vector<Employee>& getdataEmployee();
       // bool getAuthenticate(string inputPassword, string inputUsername);

};

////////
class USER{
    private:
        string username;
        string password;
        int IdUsername;
    public:
        USER(string UserName = "QUOCPHU", string PassWord = "2001");

        string GetUsername();
        string GetPassword();
        int GetIdUsername();

        void SetUsername(string UserName);
        void SetPassword(string Password);

        bool ConfirmForUser(string inputUsername, string inputPassword);
        
};
//////

class SecurityManagement{
    private:
        vector<USER> databaseUser;
        USER ObjectUser;
        bool CheckSignUp;
    public:
        void addUser( string inputUsername, string inputPassword );
        void eraseUser(int idUsername);
        void editUser(string inputUsername, string inputPassword);
        void setManagerPassword(string inputPassword);

        bool getCheckSignUp(string inputUsername, string inputPassword);
        vector<USER> &getDatabaseUser();
};  
///////////

typedef enum{
    FULL,
    STILL
}typeStatusOfService;

typedef enum{
    HOTEL,
    BAR,
    POOL,
    GYM
}typeService;

class Services{
    private:
        typeService service;
        typeStatusOfService statusService;
        int idService;
    public:
        Services(typeService serviceForCustomer, typeStatusOfService statusServiceForCustomer );

        typeService GetService();
        typeStatusOfService GetStatus();
        int GetIdService();

};

class ServiceManagement{
    private:
        vector<Services> databaseServices;
    public:
        void addService(typeService serviceForCustomer, typeStatusOfService statusServiceForCustomer );
        void eraseService(typeService service);

        vector<Services>& getDatabaseServices();

};
//////
typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}typePaymentHistory;

typedef enum{
    CREDIT = 1,
    BANKING,
    DIGITAL_WALLET
}typePayment;

typedef enum{
    VIP = 800,
    NORMAL = 600,
    LUXURY = 1000
}typePriceRoom;

class Payment{
    private:
        vector<typePaymentHistory> paymentHistory;
        typePayment paymentMethod;
        typePriceRoom priceRoom;
        int idPayment;
    public:
        Payment(typePayment paymentMethod, typePriceRoom priceRoom);
        
        void addPaymentHistory(typePaymentHistory paymenthistory);
        vector<typePaymentHistory>& getdatabasePaymentHistory();

        typePriceRoom getPriceRoom();
        typePayment getPaymentMethod();
        int getIdRoom();
};

class PaymentManagement{
    private:
        vector<Payment> databasePayment;
    public:
        void addPayment(Payment payment);
        void erasePayment(int idPayment);

        vector<Payment>& getdatabasePayment();

};
//////////
typedef enum{
    ONESTAR   = 200,
    TWOSTAR   = 400,
    THREESTAR = 600,
    FOURSTAR  = 800,
    FIVESTAR  = 1000
}typeEvaluate;

class Statistic{
    private:
        typeEvaluate evaluateQuality;
        int revenueOfHotel;
        int evaluateOrderNumber;
    public:
        Statistic(typeEvaluate evaluatequality, int revenueofhotel);

        typeEvaluate GetEvaluateQuality();
        int GetRevenueOfHotel();
        int GetevaluateOrderNumber();

};

class StatisticManagement{
    private:
        vector<Statistic> databaseStatistic;
        int reversedRoomQuanity;
    public:
        void addStatistic(Statistic statisticOfObject);
        void eraseStatistic(int evaluateOrderNumber);
        void SetRoomQuanity(int reversedroomquanity);
        int GetReversedRoomQuanity();
        double GetQualityAverage();
        string GetQualityHotel();
        int GetRevenueHotel();
        
        vector<Statistic>& GetdatabaseStatistic();
};

}


using namespace Hotel;

/// @brief 
/// @param databaseRoom 
/// @param quanity 

void setQuanityRoom(vector<Room> &databaseRoom, uint8_t quanity);

void ReservationManagement(vector<Room> &databaseRoom, CustomerManager &customerManager, StatisticManagement &statisticManagement);

void CustomerManagement(vector<Room> &databaseRoom,CustomerManager &customerManagement, StatisticManagement &statisticManagement);

void EmployeeManagement(EmployeeManager &employeeManagement, SecurityManagement &securityManagement);

void SecurityManagements(SecurityManagement &securityManagement);

void ServiceManagements(ServiceManagement &serviceManagement, SecurityManagement &securityManagement);

void PaymentManagements(PaymentManagement &paymentManagement, CustomerManager &customerManagement, StatisticManagement &statisticManagement, vector<Room> databaseRoom);

void StatisticManagements(StatisticManagement &statisticManagement);
//////
#endif //_HOTEL_H INCLUDED