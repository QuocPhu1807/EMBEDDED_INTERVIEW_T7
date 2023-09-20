/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 30/07/2023
* Description: This file will resever the elements in String
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define MAX 300

char String[] = "Getting ahead in a difficult profession requires avid faith.";

/*
* Function: IsSizeSpace
* Description: The function will count the size of space in String.
* Input:
*      
* Output:
*   return the Count of the Element
*/
 static uint8_t IsSizeSpace(){

    char *AddressString = String;
    uint8_t SizeSapce = 0;
     while (*AddressString != '\0'){
           if (*AddressString == ' ') SizeSapce++;

            AddressString ++;
    }
        return SizeSapce;

}
/*
* Function: AddWords
* Description: The function will add the letter into the Array respectively.
* Input:
*      Array[] - a array have typedata of char
*      Index   - a integer value
* Output:
*      not return 
*/
 static void AddWords( char Array[], uint8_t Index ){

    static uint8_t i = 0;
    while( String[i] != '\0'){
            Array[i] = String[Index];
            i++;
            Index++;
         if (String[Index] == ' ' || String[Index] == '\0'){
            Array[i]= ' ';
             i++;
            break;
         }
    }
}
/*
* Function: AddWords
* Description: The function will give the letters in String into The Array respectively( mean contain the Reserve String)
* Input:
*      Array[] - a array have typedata of char
* Output:
*      not return 
*/
void ReverseWords(char Array[]){

    uint8_t SizeSpace = IsSizeSpace();
    uint8_t i = 0;
    uint8_t Count;
    uint8_t Check = 0;

    while (SizeSpace !=0){
        while (String[i] != '\0'){
             if (String[i] == ' '){
                 Count++;
                if(Count == SizeSpace){
                    AddWords(Array, i + 1);
                    Count = 0;
                    SizeSpace--;
                    Check = 1;
                    break;
                }
              } 
               if(Check == 1) break;
               i++;         
        }
         Check = 0;
         i=0;
    }
     AddWords(Array,0);               // Save the final letter into the Array 
     //Array[28] = '\0';
}
/* 
* Function: PrintArray
* Description: This function print the Elements of the Array
* Input:
*      Array[] - a array have typedata of char 
* Output:
*      not return 
*/
void PrintArray(char Array[]){

   int i = 0;
    while (String[i] != '\0')
    {
        printf("%c",Array[i]);
        i++;
    }
    
}


int main(int argc, char const *argv[])
{
  char Array[MAX];     // Array will contain the reverse letter from the String 
  ReverseWords(Array);
  PrintArray(Array);

    return 0;
}
