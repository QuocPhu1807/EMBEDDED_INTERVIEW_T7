/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file print Date in Week based on dd/mm/yy when you input
*/

#include "Date.h"

extern const char *Days[];

int main() {

    Date DateCurrent;

    printf("Enter Day: ");
    scanf("%hhd", &DateCurrent.Day);

    printf("Enter Month: ");
    scanf("%hhd", &DateCurrent.Month);

    printf("Enter Year: ");
    scanf("%hd", &DateCurrent.Year);


    if (!IsValidDate(DateCurrent)) {
        printf("The entered date is not valid.\n");
    }

    uint8_t DayOfWeek = IsDayOfWeek(DateCurrent);
    
    printf("The date %d/%d/%d falls on a %s.\n", DateCurrent.Day, DateCurrent.Month, DateCurrent.Year, Days[DayOfWeek]);

    return 0;
}