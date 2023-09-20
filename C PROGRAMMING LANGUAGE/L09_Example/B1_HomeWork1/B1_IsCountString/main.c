/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 30/07/2023
* Description: This file for counting elements in a String
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
/*
// VD: Cho String sau đó tìm số lần phần tử lặp lại

              char String[]="nhat hoang tuan nam nhat tuan hoang nhat nam bao quoc nam";
*/

// Struct dữ liệu với hai member: pointer và số ký tự của phần tử.
typedef struct 
{
  char *cArrdress;
  uint8_t cLength;
}Words;

typedef struct 
{
  char *ptr1;
  uint8_t len;
}WordArray;

/*
* Function: isNumberElement
* Description: calculate the number elements of string
* Input:
*   cString - an  pointer have typedata of char.
* Output:
*   return number of Element in String
*/
int IsNumberElement(char *cString){

   int numberElement =1;

    while (*cString != '\0') // co the ghi la while(*ptr)
    {
         if(*cString == ' ') numberElement++;
         cString ++;
    }
    return numberElement;

}
/*
* Function: *splitString
* Description: This function will split the Element of String
* Input:
*      String[] - an char Array
*      numberElement - an quanity of Elements
* Output:
*      return address of Array which contain the Elements
*/
Words *SplitString(char cString[],int iNumberElement){

    Words *Array= (Words *)malloc(sizeof(Words)*iNumberElement);
    uint8_t CountChar=1;
    uint8_t Index=0;
    Array[Index].cArrdress= cString;

      while (*cString != '\0' ) // co the ghi while(*string)
      {
  
         if(*cString== ' '){
            Array[Index].cLength= CountChar;
            CountChar=1;
            cString ++;
            Array[++Index].cArrdress= cString;
         } else {

            CountChar ++;
            cString ++;

         }
      }

     Array[Index].cLength= CountChar;
     return Array;
}
/*
* Function: PrintArray
* Description: This function will print the count of Array
* Input:
*      Element - an Array have typedata of Words
* Output:
*   return address of Array which contain the Elements
*/
void PrintArray(Words Element){

     for (int i = 0; i < Element.cLength; i++)
     {
          printf("%c", Element.cArrdress[i]);
     }

}
/*
* Function: IsSwapElement
* Description: This function will swap between two Elements
* Input:
*      *Element1 - an Pointer have typedata of Words
*      *Element2 - an Pointer have typedata of Words
* Output:
*/
void IsSwapElement(Words *Element1, Words *Element2 ){

     Words TemporaryElement;
     TemporaryElement   = *Element1;
            *Element1   = *Element2;
            *Element2   = TemporaryElement;

}
/*
* Function: IsCompareLager
* Description: This function compare between two elements.
* Input:
*      array1 - an array have typedata of char
*      array2 - an array have typedata of char
* Output:
*      return true or false
*/
bool IsCompareLager(const char array1[], const char array2[]){
  
    while (*(array1)==*(array2))
    {
         if(*array1=='\0') {

            return true;
         }
            array1++;
            array2++;
        }

         if (*array1 > *array2) {

            return true;
     }
 
     return false;

}
/*
* Function: IsSortAlphabet
* Description: This function sort the Elements based on Alphabet
* Input:
*      array[] - an array have typedata of words
*      NumberArray - an integer value
* Output:
*      return true or false
*/
void IsSortAlphabet(Words Array[],int NumberElement ){
     for (int i = 0; i < NumberElement; i++)
     {
   
         for (int j = i+1; j < NumberElement; j++)
         {
            if(IsCompareLager(Array[i].cArrdress, Array[j].cArrdress)){
         
                IsSwapElement(Array+i,Array+j);
          
            }
         } 
     }
  
 }
/*
* Function: CheckElements
* Description: This function sort the Elements based on Alphabet
* Input:
*      array1 - an variable have typedata of words
*      array2 - an variable have typedata of words
* Output:
*      return true or false
*/
bool CheckElements(Words array1, Words array2){    // truyen vao hai phan tu kieu word
    
    if(array1.cLength == array2.cLength)
    {
         for (int i = 0; i < array1.cLength; i++)
         {
             if(array1.cArrdress[i] == array2.cArrdress[i]) return true;

             if (array1.cArrdress[i] != array2.cArrdress[i])
             {
                   return false;
             }
         } 
    }
      return false;

}

////
/*
* Function: CheckElements
* Description: This function sort the Elements based on Alphabet
* Input:
*      array1 - an variable have typedata of words
*      array2 - an variable have typedata of words
* Output:
*      return true or false
*/
bool isEqual(const char arr1[], const char arr2[])   // truyen input parameter la hai dia chi
{
    while (*arr1 == *arr2)
    {
          if(*arr1 == ' ') 
          {
              return true;
          }
              arr1++;
              arr2++;
    }

     return false;
}
////

/*
* Function: IsCountElement
* Description: This function will count the Elements.
* Input:
*      Array - an array have typedata of words
*      NumberElement - an variable have typedata of int
* Output:
*      not return 
*/ 
void IsCountElement(Words Array[], int NumberElement){

    int CountElement = 1;
    for(int i = 0; i < NumberElement-1; i++){

      if(CheckElements(Array[i], Array[i+1]))
        {
            CountElement++;
        } else {
            PrintArray(Array[i]);
            printf("\txuat hien : %d lan \n", CountElement);
            CountElement = 1;

        }
    }
  }

//
int main(int argc, char const *argv[])
{

    char String1[]="nhat hoang tuan nam quoc nhat tuan hoang nhat nam bao quoc nhat hoang nam";

    int NumberElement =IsNumberElement(String1);

    Words *Array= SplitString(String1, NumberElement);

    IsSortAlphabet(Array, NumberElement);

    IsCountElement(Array, NumberElement);

   // for (int i = 0; i < 12; i++)
   //  {

   //     test(ptr[i]);

   //     printf("\n");
 
   //  }
    
    return 0;
 }

//
// void countArr(Words arr[], int size){

//     int count=1;
//     for (int i = 0; i < size; i++)
//     {
//       if(check(arr[i],arr[i+1])){
           
//           count ++;

//           if(check(arr[i+1],arr[i+2])){
//            count ++;
//            test(arr[i]);
//            printf(" xuat hien %d lan \n",count);
//            count=1;
//            continue;

//           }
//            test(arr[i]);
//            printf(" xuat hien %d lan \n",count);
//            count =1;
//       }
//       else{
//           test(arr[i]);
//           printf(" xuat hien %d lan \n",count);
//       }
         
//     }
// }