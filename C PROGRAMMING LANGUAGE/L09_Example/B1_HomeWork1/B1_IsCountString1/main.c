#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>


typedef struct 
{
   char *ptr;
   uint8_t length;
}words;

typedef struct 
{
   char *ptr1;
   uint8_t len;
}wordArr;


char string1[]="nhat nam hoang tuan nam nhat tuan hoang nhat nam bao quoc nam";

// Function tra ve size cac phan tu
int numofEle(char *ptr){
    
    uint8_t size = 1;
     while (*ptr )
     {
         if( *ptr == ' ') size ++;
         ptr++;
     }
      
      return size;
     
}
//
 words* SplitString(char string[], int size){

        uint8_t count = 1;
        uint8_t index = 0;
        words *arr= (words *)malloc(sizeof(words)*size);
        arr[index].ptr=string;

        while(*string){

             if (*string == ' ')
             {
                arr[index].length = count;
                count = 1;
                string ++;
                arr[++index].ptr = string;
             }

             else
             {
                count++;
                string++;
             }
        }
           arr[index].length = count;
           return arr;
           free(arr);
 } 
//
void printArr(words test){

    for (int i = 0; i < test.length; i++)
    {
        printf("%c", test.ptr[i]);
    }
    
}
//
bool isLarger(char arr1[], char arr2[]){

       while( *arr1 == *arr2)
       {
            if(*arr1 == '\0') return true;

             arr1++;
             arr2++;
       }

        if (*arr1 > *arr2)
        {
            return true;
        }
    
           return false; 
}
// 
void swap(words *x, words *y){

       words temp;
       temp = *x;
       *x   = *y;
       *y   = temp;
}

//Ham sap xep cac phan tu theo thu tu alphabet
void isAlphabet( words arr[], int size){
      
        for (int i = 0; i < size -1; i++)
        {
           for (int j= i + 1; j < size; j++)
           {
               if (isLarger(arr[i].ptr, arr[j].ptr))
               {
                      swap(arr+i ,arr+j);
               }
               
           }
        
        }
      

}

// Ham dem so phan tu kieu 1
bool ischeck(words arr1, words arr2){
      
      uint8_t i=0;
      while ( arr1.length == arr2.length)
      {
           if( arr1.ptr[i] == arr2.ptr[i]) return true;
           if( arr1.ptr[i] != arr2.ptr[i]) return false;

           i++;
      }

            return false;
     
}

// Ham dem so phan tu kieu 2
bool ischeck1( const char arr1[], const char arr2[]){
      
       uint8_t i=0;
       while(*arr1 == *arr2)
        {
            arr1++;
            arr2++;
            if(arr1[i] == arr2[i]) return true;

        }
        
        return false;
       
}

// Ham dem so phan tu va in ra
void countElemt(words arr[],int size){
   
       uint8_t count=1;
       for (int i = 0; i < size; i++)
       {
            if (ischeck1(arr[i].ptr,arr[i+1].ptr))
            {
                count++;
            }
            else
            {
                printArr(arr[i]);
                printf("\t xuat hien: %d lan\n", count);
                count=1;
            }   
       }
       
}

//
 int main(int argc, char const *argv[])
 {
    uint8_t size = numofEle(string1);

    words *ptr= SplitString(string1,size);

    isAlphabet(ptr,size);

    countElemt(ptr,size);
     
    // for (int i = 0; i < size; i++)
    // {
    //    printArr(ptr[i]);

    //    printf("\n");
    // }
    

    return 0;
 }
 