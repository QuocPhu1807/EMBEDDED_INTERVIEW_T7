/*
* File: main.cpp
* Author: Doan Quoc Phu
* Date: 31/08/2023
* Description: This file is used to manage the information of the hotel such as: reservation, customer, employee.
*/

#include"Hotel.hpp"

int main()
{

    vector<Room> databaseRoom;
    CustomerManager customerManagement;
    EmployeeManager employeeManagement;
    SecurityManagement securityManagement;
    ServiceManagement serviceManagement;
    PaymentManagement paymentManagement;
    StatisticManagement statisticManagement;

    setQuanityRoom(databaseRoom,9);

    while(1)
    {
        cout<<endl<<" MAIN MONITOR: "<<endl;
        cout<<"\n 1: Reservation Management\n 2: Customer Management\n 3: Employee Management\n 4: Service Management\n 5: Payment Management\n 6: Security Management\n 7: Reports and statistics Management" <<endl;
        cout<<" --------------------------------";
        cout<<endl<<" Please enter your choice: ";
        int chooseOption;
        cin>>chooseOption; cin.ignore();

        switch (chooseOption)
        {
                case RESERVATION:
                    ReservationManagement(databaseRoom, customerManagement, statisticManagement);
                    break;
                case CUSTOMER:
                    CustomerManagement(databaseRoom, customerManagement, statisticManagement);
                    break;
                case EMPLOYEE:
                    EmployeeManagement(employeeManagement, securityManagement);
                    break;
                case SERVICE:
                    ServiceManagements(serviceManagement,securityManagement);
                    break; 
                case PAYMENT:
                    PaymentManagements(paymentManagement, customerManagement, statisticManagement, databaseRoom);
                    break;
                case SECURITY:
                    SecurityManagements(securityManagement);
                    break;  
                case STATISTICS:
                    StatisticManagements(statisticManagement);
                    break; 
                // case FEEDBACK = 9:
                //     FeedbackManagements(statisticManagement);
                //     break;  
                default:
                    break;
        } 
    }
       return 0;
}


