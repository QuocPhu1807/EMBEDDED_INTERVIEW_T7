/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 02/08/2023
* Description: This file for converting the numbers to the letters
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
/*
// VD: 
// input: 125672 (Gioi han chi co the nhap vao 7 so)
//output: Mot trieu hai tram nam muoi sau nghin bay tram hai muoi tam
// input: 1000000 -> 1 trieu
//        1000001 -> 1 trieu khong nghin khong tram linh mot
//        1000050 -> 1 trieu khong nghin khong tram nam muoi
*/

// Struct dữ liệu với hai member: pointer và số ký tự của phần tử.
typedef struct 
{
   int *iArray;
   uint8_t CountElement;

}Words;

// The Strings for print the letters

char *Number[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};

char *Number1[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};

char *Unit[] = {" ","muoi", "tram", "nghin", "muoi", "tram", "trieu","chuc", "tram", "ty", "chuc", "tram", "nghin ty", "chuc", "tram", "trieu ty"};

char *Unit1[] = {" ","linh", "tram", "nghin", "muoi", "tram", "trieu","chuc", "tram", "ty", "chuc", "tram", "nghin ty", "chuc", "tram", "trieu ty"};

char *Unit2[] = {" "," muoi ", "tram", "nghin", " ", " ", "trieu"," ", " ", "ty", " ", " ", "nghin ty", " ", " ", "trieu ty"};


/*
* Function: InputNumbers
* Description: Enter the numbers
* Input:
*     
* Output:
*   return the numbers 
*/
int InputNumbers(){

        int iNumbers;
        printf(" INPUT\t : ");
        scanf("%d", &iNumbers);

        if ( iNumbers <= 0 ) {
              printf("ERROR! Please enter the another number.\n");
        }

        return iNumbers;
}
/*
* Function: IsSplitToArray
* Description: Enter the numbers
* Input:
*      iNumbers - the numbers
* Output:
*   return WordArr have typefdata of Words
*/
Words IsSplitToArray(int iNumbers){

      int TemperateNumbers = iNumbers;            // luu gia tri size vao temp
      int DigitNumbers;
      int CountNumbers = 0;
      uint8_t Index =0;

      int *Array=(int*)malloc(sizeof(int)*CountNumbers);

      do
      {      DigitNumbers = TemperateNumbers %10;           // Lấy chữ số cuối cùng bằng phép chia lấy dư cho 10
        
             Array[Index]= DigitNumbers;          // Luu gia tri lay phan du vao phan tu của mảng
  
             CountNumbers++;                   // tăng số phần tử
             Index++;                    // tăng chỉ số phần tử

             TemperateNumbers /=10;                 // Bỏ chữ số cuối cùng bằng cách lấy phần nguyên khi chia cho 10(lấy số nguyên)

      } while (TemperateNumbers > 0);

      Words WordArr;                   // khai báo biến gồm hai member
      WordArr.iArray   = Array;
      WordArr.CountElement = CountNumbers;

      return WordArr;
      free(Array);
}
/*
* Function: *IsConvertNumber
* Description: This function convert number to letter
* Input:
*      IsNumbers - enter number need to convert
* Output:
*   return WordArr have typefdata of Words
*/
char *IsConvertNumber(int IsNumber){

       if(IsNumber >= 0) return Number[IsNumber];  // so sanh bien IsNumber

}
/*
* Function: PrintElemen
* Description: This function print the Elements according to the letters respectively.
* Input:
*       array  - a array have typedata of words
*      *cUnit  - a pointer have typedata of char
*      *cUnit1 - a pointer have typedata of char
*      *cUnit2 - a pointer have typedata of char
* Output:
*   return WordArr have typefdata of Words
*/
void PrintElement(Words array, char *cUnit[], char *cUnit1[],char *cUnit2[]){

   
         for (int i = (array.CountElement) - 1 ; i >= 0; i--)
         {
          
             if(array.iArray[0] == 0 && array.iArray[1] == 0 )                  // truong hop xet : 1 trieu
             {
                   printf(" %s %s ",IsConvertNumber(array.iArray[(array.CountElement)-1]),Unit[(array.CountElement)-1]);
                   break;
             }

             else if ( array.iArray[1] == 0 )                                  // truong hop xet : 1 trieu khong nghin khong tram linh mot
             {
                   printf("%s %s ",IsConvertNumber(array.iArray[i]),Unit1[i]) ;
             }

              else if ( array.iArray[2] == 0 && array.iArray[1] != 0 )         // truong hop xet :  1 trieu khong nghin khong tram nam muoi
             {
                   printf("%s %s ",IsConvertNumber(array.iArray[i]),Unit2[i]) ;
             }

             else                                                              // cac truong hop con lai
             {
                   printf("%s %s ",IsConvertNumber(array.iArray[i]),Unit[i]) ;
             }

         }
                   printf("<dong>");
    }
/*
* Function: PrintElemen
* Description: This function print the Elements in Array.
* Input:
*      array   - a array have typedata of words
* Output:
*   return 
*/
void PrintElement1(Words array){

      for (int i = 0; i < array.CountElement; i++)
      {
           printf(" %d ", array.iArray[i]);
      }
}
// Anothe Solution for counting Elements
/*
* Function: CountArray
* Description: This function print the Elements in Array.
* Input:
*      *array   - a pointer have typedata of char
* Output:
*   return 
*/
int CountArray(char *array[] ){

       int count=0;
       while (array[count])
      {
           count++;
      }

       return count; 
}

//
int main(int argc, char const *argv[])
{
    int Numbers = InputNumbers();
    
    Words Array = IsSplitToArray(Numbers);

    //printEleme(ptr1);
    //int size1 = CountArr(number);
    //int size2 = CountArr(unit);
    //printf(" kich thuoc : %d  %d", size1,size2);

    printf("OUTPUT\t : ");
  
    PrintElement(Array, Unit, Unit1, Unit2);

    return 0;
}


