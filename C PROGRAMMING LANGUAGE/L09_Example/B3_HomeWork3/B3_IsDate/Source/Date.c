/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file print Date in Week based on dd/mm/yy when you input
*/

#include "date.h"

 const char *DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

 const Date date = {1, 1, 0001};

 static uint16_t DaysInMonth[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
* Function: IsLeapYear
* Description: The function consider the leap year
* Input:
*      iYear - a year  
* Output:
*      return true  - the leap year
*             false - the not leap year
*/
static bool IsLeapYear(uint16_t iYear) {
    
      if ((iYear % 4 == 0 && iYear % 100 != 0 && iYear % 400 == 0) || iYear % 4 != 0) return false;
    
      return true;
}  
/*
* Function: IsValidDate
* Description: The function consider the Date which is valid?.
* Input:
*      DataCurrent   - a Date value
* Output:
*      return true or false.
*/
bool IsValidDate( Date DateCurrent) {

      if(DateCurrent.Month < JANUARY || DateCurrent.Month> DECEMBER) return false;           // Consider day is not valid
    
      if(DateCurrent.Day < 1 || DateCurrent.Day  > DaysInMonth[DateCurrent.Month]) return false;         // // Consider day is not valid

      if(IsLeapYear(DateCurrent.Year)) DaysInMonth[2] = 29;
    
      return true;

}
/*
* Function: CountDayNotLeapYear
* Description: The function will count the days with not the leap year.
* Input:
*      
* Output:
*       return Total days with not the leap year
*/
static uint64_t CountDayNotLeapYear(){
 
      int TotalDays = 0;
          for (int i = 1; i < 14; i++)
             {
                TotalDays += DaysInMonth[i];
             }

             return TotalDays;

}
/*
* Function: CountDayLeapYea
* Description: The function will count the days of the leap year.
* Input:
*      
* Output:
*        return the total days of the leap year
*/
static uint64_t CountDayLeapYear(){

      int DayOfMonths[]= {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  

      int TotalDays=0;
        for (int i = 1; i < 14; i++)
            {
                TotalDays += DayOfMonths[i];
            }
            return TotalDays;

}
/*
* Function: IsGetDayMonths
* Description: The function will count the number element.
* Input:
*      DataCurrent   - a Date value
* Output:
*      return total the days of  the current year
*/
static int IsGetDayMonths(Date DateCurrent) {

    if (!IsLeapYear(DateCurrent.Year)) {
        DaysInMonth[2] = 29;
    }

    int TotalDays = 0;
    for (int i = 1; i < DateCurrent.Month; i++) {
        TotalDays += DaysInMonth[i];
    }
    TotalDays += DateCurrent.Day;

    return TotalDays;
}
/*
* Function: IsDayOfWeek
* Description: The function will count the number element.
* Input:
*      DataCurrent   - a Date value
* Output:
*      return the day in week
*/
uint8_t IsDayOfWeek(Date DateCurrent){

    int arr1[ DateCurrent.Year];

    uint16_t  LeapYears = 0 ;
    uint16_t  NotLeapYears= 0 ;

    for (int i = date.Year ; i < DateCurrent.Year ; i++)
    {
        arr1[i]= i;
    }
    
    for (int i = date.Year; i < DateCurrent.Year; i++)
    {
            if(!IsLeapYear(arr1[i])){
                 LeapYears += CountDayLeapYear();
            }

            if(IsLeapYear(arr1[i]))  {
                 NotLeapYears += CountDayNotLeapYear();
            }
    }

      uint64_t TotalDays = LeapYears + NotLeapYears + IsGetDayMonths(DateCurrent);

      uint8_t DayofWeeks = TotalDays % 7 ;

      return DayofWeeks - 1;
    }

