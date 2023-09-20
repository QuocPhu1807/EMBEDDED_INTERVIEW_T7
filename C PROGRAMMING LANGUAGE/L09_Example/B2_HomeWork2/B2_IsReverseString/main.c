/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 02/08/2023
* Description: This file for converting the numbers to the letters
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/* VD:dùng để đảo một chuỗi bất kỳ */

char string1[] = "Getting ahead in a difficult profession requires avid faith in yourself. That is why some people with mediocre talent, but with great inner drive, go so much further than people with vastly superior talent. Success always comes to those who dare to act and seldom comes close to those who are too coward to take the consequences  I’m selfish, impatient and a little insecure. I make mistakes, I am out of control and at times hard to handle. But if you can’t handle me at my worst, then you sure as hell don’t deserve me at my best. – Marilyn Monroe";

// Struct dữ liệu với hai member: pointer và số ký tự của phần tử.
typedef struct 
{
    char *cAddress;
    uint8_t Length;

}words;
/*
* Function: NumberOfElement
* Description: The function will count the number element.
* Input:
*      String[] - a array have typedata of char 
* Output:
*   return the Count of the Element
*/
int NumberOfElement( char String[]){

    char *array = String;
    uint8_t CountArray = 1;
    while(*array != '\0'){

        if(*array == ' ') CountArray++;
        array++;
    }
    return CountArray;
}
/*
* Function: IsSplitString
* Description: The function will split Element in Array.
* Input:
*      String[]      - a array have typedata of char 
*      NumberElement - a number of Element
* Output:
*   return the Count of the Element
*/
words* IsSplitString( char String[], int NumberElement){

    uint8_t CountElement = 1;
    uint8_t Index = 0;

    words *array = (words*)malloc(sizeof(words)*NumberElement);            // cap phat dong mot mang cho cac phan tu

    array[Index].cAddress = String;                                    // Lap phan tu dau tien tro den dia chi ban dau

    while( *String != '\0' ){

        if (*String == ' '){
            array[Index].Length = CountElement;
            CountElement =1;
            String++;
            array[++Index].cAddress = String;
        }

        else{
            CountElement++;
            String++;
        } 
    }

     array[Index].Length = CountElement;         // Luu cac ky tu vao phan tu cuoi cung cua mang array

     return array;
     free(array);
}
/*
* Function: IsPrintArray
* Description: The function will print the Elements in Array.
* Input:
*      Element  - a element in array.
* Output:
*      not return 
*/
void IsPrintArray(words Element){

    for (int i = 0; i < Element.Length; i++)
    {
         printf("%c",Element.cAddress[i]);
    }
    
}
/*
* Function: IsSwapElement
* Description: This function will print the count of Array
* Input:
*      *Element1 - an Pointer have typedata of Words
*      *Element2 - an Pointer have typedata of Words
* Output:
*/
void IsSwapElement(words *Element1, words *Element2 ){

     words TemporaryElement;
     TemporaryElement   = *Element1;
            *Element1   = *Element2;
            *Element2   = TemporaryElement;

}
/*
* Function: IsReseverWord
* Description: This function will reverse the Elements
* Input:
*      array[] - an array have typedata of Words
*      *Element2 - an Pointer have typedata of Words
* Output:
*/
void IsReseverWord(words array[], int NumberElement){

   for (int i = 0; i < (int)NumberElement/2; i++)
     {
        IsSwapElement(array + i, array + NumberElement -1 -i);
     }
        
}
//
int main(int argc, char const *argv[])
{
    int NumberElement = NumberOfElement(string1);              // Function lay so phan tu can tach

    printf("size: %d\n", NumberElement);                       // print ra so phan tu

    words *array = IsSplitString(string1, NumberElement);       // Dung bien con tro tro mang can luu phan tu

        // Dung for de chay phan tu cuoi den dau
    // for (int i = size-1; i >= 0; i--)
    // {
    //    printArr(ptr[i]);

    //    printf(" ");
    // }

    IsReseverWord(array,NumberElement);                       // Function dung de reverse cac phan tu
   
    for (int i = 0 ; i < NumberElement ; i++)
    {
       IsPrintArray(array[i]);
       printf(" ");
    }

    
    return 0;
}
