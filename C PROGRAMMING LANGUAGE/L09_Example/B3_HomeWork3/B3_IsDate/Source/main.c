/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file print the day in Week based on dd/mm/yy when you input
*/

#include "Date.h"

extern const char *DAYS[];

int main() {

    Date DateCurrent;

    printf("Enter Day: ");
    scanf("%hhd", &DateCurrent.Day);

    printf("Enter Month: ");
    scanf("%hhd", &DateCurrent.Month);

    printf("Enter Year: ");
    scanf("%hd", &DateCurrent.Year);

    if (!IsValidDate(DateCurrent)) {

         printf("The entered date is not valid");
    } 

     uint8_t DayOfWeek = IsDayOfWeek(DateCurrent);

     printf("The Date %d/%d/%d falls on a %s.\n", DateCurrent.Day, DateCurrent.Month, DateCurrent.Year, DAYS[DayOfWeek]);

     return 0;

}