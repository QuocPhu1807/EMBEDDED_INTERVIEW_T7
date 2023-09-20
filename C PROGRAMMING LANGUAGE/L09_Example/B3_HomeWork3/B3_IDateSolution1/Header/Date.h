#ifndef DATE_H
#define DATE_H

#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Weeks;

typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Months;

typedef struct {
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
} Date;

bool IsValidDate(Date DateCurrent);

uint8_t IsDayOfWeek(Date DateCurrent);


#endif