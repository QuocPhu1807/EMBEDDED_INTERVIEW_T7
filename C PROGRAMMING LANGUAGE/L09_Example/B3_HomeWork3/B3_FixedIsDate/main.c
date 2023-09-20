/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 30/07/2023
* Description: This file print the day of week with the Dtae respectively.
*/

#include<stdio.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>

// Struct dữ liệu với ba member: Day, Month, Year.
typedef struct 
{
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;

}Dates;

// Enum the day in weeks
typedef enum 
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
   
}DayOfWeeks;


Dates date = {1,1,0001};            //    The date make milestone.

Dates DateCurrent;                                  //    The date want to know the day in weeks.

const char *Days[] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/*
* Function: CheckDate
* Description: The function will check whether the same date 
* Input:
*      
* Output:
*   return the Count of the Element
*/


bool CheckDate(){


    if(date.Day == DateCurrent.Day && date.Month == DateCurrent.Month&& date.Year  == DateCurrent.Year) {

          return true;
    }
          return false;

}

/*
* Function: IsCountDays
* Description: The function will count the days in month,year.
* Input:
*      
* Output:
*   return the total day.
*/

uint16_t IsCountDays(){

    uint16_t CountDay =0;

    while(1) {

          CountDay++;
          if(CheckDate()) return CountDay;

        switch (date.Month){

        case 1:
              if(date.Day == 31){
                  date.Month = 2;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 2:
              if((date.Year % 4 == 0 && date.Year % 4 == 100 && date.Year % 400 != 0) || date.Year % 4 != 0 ){  
                  if(date.Day == 28){
                      date.Month = 3;
                      date.Day = 1;
                      break;
                  }
               }
              else {
                  if(date.Day == 29){
                      date.Month = 3;
                      date.Day =1;
                      break;
                   }
               }
                 date.Day++;
                 break;
        case 3:
              if(date.Day == 31){
                  date.Month = 4;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 4:
              if(date.Day == 30){
                  date.Month = 5;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 5:
              if(date.Day == 31){
                  date.Month = 6;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 6:
              if(date.Day == 30){
                  date.Month = 7;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 7:
              if(date.Day == 31){
                  date.Month = 8;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 8:
              if(date.Day == 31){
                  date.Month = 9;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 9:
              if(date.Day == 30){
                  date.Month = 10;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 10:
              if(date.Day == 31){
                  date.Month = 11;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 11:
              if(date.Day == 30){
                  date.Month = 12;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        case 12:
              if(date.Day == 31){
                  date.Month = 1;
                  date.Year ++;
                  date.Day = 1;
                  break;
               }
                  date.Day++;
                  break;
        default:
                  break;
        }
    }
         return CountDay;
}

int main()
{

    printf("Enter Day: ");
    scanf("%hhd", &DateCurrent.Day);

    printf("Enter Month: ");
    scanf("%hhd", &DateCurrent.Month);

    printf("Enter Year: ");
    scanf("%hd", &DateCurrent.Year);
    
    uint16_t Index = IsCountDays(DateCurrent);

    printf("The date %d/%d/%d falls on a %s.\n", DateCurrent.Day, DateCurrent.Month, DateCurrent.Year, Days[Index %7]);
    
    return 0;
}
