/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 10/08/2023
* Description: This file will counting the quanity of the elements in String
*/

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdlib.h>

/*
VD: Find the repeat time of the Element in String:

char string[] = "nam hoang tuan nam thai hoang thai hoang tuan yen";
*/

char String[] = "nam hoang tuan nam thai hoang thai hoang tuan yen";


/*
Struct dữ liệu với bon member: pointer,  số ký tự của phần tử.
*       cAddress - a Char Pointer
*       ulength  - a integer(1 byte) and the lenght of the Sapce
*       uStatus  - a integer(1 byte) and the status of the Element
*       uQuanity - a integer(1 byte) and the repeat quanity of the Element
*/

typedef struct 
{
    char *cAddress;
    uint8_t ulength;
    uint8_t uStatus;
    uint8_t uQuanity;
}Words;

/*
* Function:  NumberElement
* Description: This function will count the quanity of the Elements
* Input:
*     
* Output:
*        return the quanity of the Elements
*/
static uint8_t NumberElement(){

    uint8_t NumberSpace = 1;
    char *AddressString = String;
    while (*AddressString == '\0'){
         if(*AddressString == ' ' ) NumberSpace++;
              AddressString++;
    }
           
        return NumberSpace;
}
/*
* Function: *splitString
* Description: This function will split the Element of String
* Input:
*      String[] - an char Array
*      NumberArray - an quanity of Elements
* Output:
*      return address of Array which contain the Elements
*/
 Words* SplitString(char String[], uint8_t NumberArray){
     
     uint8_t Index = 0;
     uint8_t CountChar = 1;
     Words *Array= (Words *)malloc(sizeof(Words)*NumberArray);
     Array[Index].cAddress = String;
     while (*String == '\0'){
          if(*String == ' '){
               Array[Index].ulength = CountChar;
               CountChar = 1;
               String ++;
               Array[++Index].cAddress = String;
           } else {

               String++;
               CountChar++;
           }
     }
        Array[Index].ulength = CountChar;
        return Array;
        free(Array);                                      // free the Heap Memory after finish The CodeBlock
        
}
/*
* Function: IsLager
* Description: This function will compare between the Element in String to fine the larger Elements
* Input:
*      array1[] - an const char Array
*      array2[] - an const char Array
* Output:
*      return true or false
*/
 static bool IsLager(const char array1[], const char array2[]){

      while (*array1 == *array2){
          if(*array1 == ' ') return true;

           array1++;
           array2++;
      }

      if(*array1 > *array2) return true;

      return false;

}
/*
* Function: IsSwapElement
* Description: This function will swap between two Elements
* Input:
*      *Element1 - an Pointer have typedata of Words
*      *Element2 - an Pointer have typedata of Words
* Output:
*/
 static void IsSwapElement(Words *Element1, Words *Element2 ){

     Words TemporaryElement;
     TemporaryElement   = *Element1;
            *Element1   = *Element2;
            *Element2   = TemporaryElement;

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
void SortAlphabet(Words Array[], uint8_t NumberArray ){

       for (uint8_t i = 0; i < NumberArray - 1 ; i++)
       {
            for (uint8_t j = i + 1; j < NumberArray; j++)
            {
               if(IsLager(Array[i].cAddress, Array[j].cAddress)){

                    IsSwapElement(Array + i, Array + j);
                }
            } 
       } 
}
/*
* Function: FindTheSameName
* Description: This function find the quanity of the same Elements
* Input:
*      array[] - an array have typedata of words
*      Number  - an integer value
* Output:
*      return true or false
*/
void FindTheSameName(Words Array[], uint8_t Number){

       uint8_t Count = 0;
       uint8_t IndexCurrent;
       uint8_t IndexChar = 0;

       for (uint8_t i = 0; i < Number; i++)
       {
           while(Array[IndexCurrent].cAddress[IndexChar] == Array[i].cAddress[IndexChar]){
                 IndexChar++;
                 bool CheckFinish = ( Array[IndexCurrent].cAddress[IndexChar] == ' ' ||  Array[IndexCurrent].cAddress[IndexChar] == '\0' 
                                     && Array[i].cAddress[IndexChar] == ' ' || Array[i].cAddress[IndexChar] == '\0' ) ; 
                 if(CheckFinish){
                     Count++;
                     if(Count >= 2) Array[i].uStatus = 1;
                     IndexChar = 0;
                     break;
                 }
            }
            IndexChar = 0;
       }
        Array[IndexCurrent].uQuanity = Count;
        IndexCurrent ++;
        Count = 0;  

}
/*
* Function: PrintWords
* Description: This function will print the count of Array
* Input:
*      Array[] - an array have typedata of words
*      Number  - an integer value
* Output:
*   
*/

void PrintWords(Words Array[], uint8_t Number){

         for(uint8_t i = 0; i < Number; i++){
             if(Array[i].uStatus == 0){
                for (uint8_t i = 0; i < Array[i].ulength - 1; i++){
                    printf("%c",Array[i].cAddress[i]);
                 }
                    printf(":\t%d\n:",Array[i].uQuanity); 

             }
         }
}
//

int main(int argc, char const *argv[])
{
    uint8_t NumberArray = NumberElement();

    Words* Array = SplitString(String,NumberArray);

    FindTheSameName(Array,NumberArray);

    PrintWords(Array,NumberArray);

    return 0;
}
