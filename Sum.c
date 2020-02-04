//
//  Sum.c
//  
//
//  Created by Trevor Hileman on 2/4/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    int i, sum = 0;
    
    puts("The first 10 numbers are:\n");
    for (i = 1; i < 11; i++) // loops through the first 10 numbers
    {
        printf("%d ", i);
        sum += i; // adds all the numbers together and stores them in sum
    }
    
    printf("\n Sum = %d \n", sum); // prints the sum
    
    return 0;
}
