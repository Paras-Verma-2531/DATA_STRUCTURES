#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int check(int num);
 int check(int number)
{
    int guess,c=0;
    
    printf("guess the number between 1-100..\n");
        scanf("%d", &guess);
       if (guess > number)
       {
           c++;
           printf("enter lower number please..\n");
           return guess;
        }
        else if (guess < number)
        {
            c++;
            printf("enter higher number please..\n");
           return guess;
         }
        else
         {
             printf("your guess is right\n");
            printf("you made it in %d guesses ",c);
           return guess;
       }
}
int main()
{
    int number, guess, c = 0;
    srand(time(0));
    number = rand() % 100 + 1; //genereates random number between 1-100
    int a;
    while(a!=number)
    {
       a= check(number);
    }
    

    //printf("the number is %d ", number);

    
    // while (number!=guess)
    // {
    //     c++;
    //     printf("guess the number between 1-100..\n");
    //     scanf("%d", &guess);
    //     if (guess > number)
    //     {
    //         printf("enter lower number please..\n");
    //         //b = 1;
    //     }
    //     else if (guess < number)
    //     {
    //         printf("enter higher number please..\n");
    //        // b = 1;
    //     }
    //     else
    //     {
    //         printf("your guess is right\n");
    //         printf("you made it in %d guesses ",c);
    //         //b = 0;
    //     }
    // }

    return 0;
}