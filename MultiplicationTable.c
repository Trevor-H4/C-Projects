//
//  MultiplicationTable.c
//  
//
//  Created by Trevor Hileman on 2/4/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int userInput;
    int i;
    
    puts("Please enter an integer to generate a multiplication table:");
    scanf("%d", &userInput); // this is the number the user wants a multiplication table for
    
    for (i = 1; i < 11; i++)
    {
        printf("%d x %d = %d\n", userInput, i, userInput * i); // this prints the number the user entered while the integer "i" increments by 1 and then displays the product
    }
    
    return 0;
}
