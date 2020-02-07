#include <stdio.h>
#include<string.h>
void search(char [][20],int,char[]);        //search function
int main()                  //main function
{
    char string[20][20],t[20],word[20];        //variables
    int i, j, n;
    printf("Enter the number of words: \n");
    scanf("%d", &n);                             //getting number of words
    printf("Enter the words: \n");
    for (i = 0; i < n; i++)                   //entering words
            scanf("%s",string[i]);

    /*  sorting elements as for binary search elements should be sorted */
    for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {                                              //if the previous string is greater than next
          if (strcmp(string[j - 1], string[j]) > 0)
          {                                         //swap their positions
              strcpy(t, string[j - 1]);
               strcpy(string[j - 1], string[j]);
              strcpy(string[j], t);
          }
      }
   }
   printf("Enter the Word to be searched: \n");
   scanf("%s",word);                                   //entering the word to be searched
   search(string,n,word);                          //calling search function
}

/*  Binary searching begins */
void search(char string[][20],int n,char word[])
{
    int lb, mid, ub;
    lb = 0;                             //lower bound to 0
    ub = n;                             //upper bound to n
    do
    {
        mid = (lb + ub) / 2;             //finding the mid of the array
        if ((strcmp(word,string[mid]))<0)       //compare the word with mid
            ub = mid - 1;                          //if small then decrement ub
        else if ((strcmp(word,string[mid]))>0)
            lb = mid + 1;                          //if greater then increment lb
     /*repeat the process till lb doesn't becomes ub and string is found */   
    } while ((strcmp(word,string[mid])!=0) && lb <= ub);
    if ((strcmp(word,string[mid]))==0)              //if string is found
          printf("%s is Found at %d\n",word,mid+1);
    else                                        //if not found
          printf("%s Not Found \n",word);
}
