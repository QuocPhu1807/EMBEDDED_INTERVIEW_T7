/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file print Date in Week based on dd/mm/yy when you input
*/
#include "Date.h"

const char *Days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

static uint16_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
/*
* Function: IsLeapYear
* Description: The function consider the leap year.
* Input:
*      year   - a integer value
* Output:
*      return true or false 
*/

static bool IsLeapYear(uint16_t Year) {

     if((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0)) return true;

     return false;
}
/*
* Function: IsValidDate
* Description: The function consider that The Date is valid .
* Input:
*      DateCurrent   - a Date value
* Output:
*      return true or false
*/
bool IsValidDate(Date DateCurrent) {


    if (DateCurrent.Month < JANUARY || DateCurrent.Month > DECEMBER) return false; // Invalid month
    
    if (IsLeapYear(DateCurrent.Year)) daysInMonth[2] = 29;
    
    if (DateCurrent.Day < 1 || DateCurrent.Day > daysInMonth[DateCurrent.Month ]) return false; // Invalid day for the given month
    
    return true;
}
/*
* Function: IsDayOfWeekInputDate
* Description: The function process and find the day in week.
* Input:
*      DateCurrent   - a Date value
* Output:
*      return the day in week.
*/
uint8_t IsDayOfWeek(Date DateCurrent){

    if (IsLeapYear(DateCurrent.Year)) {
        daysInMonth[2] = 29;
    }

    int TotalDays = 0;
    for (int i = 1; i < DateCurrent.Month; i++) {
        TotalDays += daysInMonth[i];
    }
    TotalDays += DateCurrent.Day;

    uint8_t dayOfWeek = (TotalDays + DateCurrent.Year - 1 + (DateCurrent.Year - 1) / 4 - (DateCurrent.Year- 1) / 100 + (DateCurrent.Year - 1) / 400) % 7;

    return dayOfWeek;
}