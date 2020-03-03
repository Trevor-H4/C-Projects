//
//  Prelab6.c
//  
//
//  Created by Trevor Hileman on 2/21/20.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID, jobType;
    float salary;
} Employee;

Employee *readEmployeeInfo(FILE *fp, int *numElems);
Employee *getEmployeeByID(Employee *, int numEmps, int ID);
void setID(Employee *p, int id);
int getID(Employee *p);
void setSalary(Employee *p, float salary);

int main(void)
{
    Employee *array;
    int numElems = 3;
    
    FILE *fp = fopen("employee.txt", "r"); // opens file with employee info
    
    array = readEmployeeInfo(fp, &numElems); // reads employee info from file and stores it in array
    
    if (fp == NULL)
    {
        printf("\n Error reading file. \n");
        return -1;
    }
    
    for (int i = 0; i < 3; i++)
    {
    printf("\nEmployee %d's ID:%d, Employee Job Number:%d, Employee Salary = %.2f\n", i, array[i].ID, array[i].jobType, array[i].salary); //prints employee's from file
    }
    
    Employee *p1 = malloc(sizeof(Employee));
    if (p1 == NULL)
    {
        puts("Error allocating memory");
        return -1;
    }
    
    p1 -> ID = getID(array);
    printf("\nEmployee 0's ID is %d\n", p1->ID);
    
    Employee *p2 = getEmployeeByID(array, 3, 234324); // gets the employee's info with ID 234324
    printf("\nSalary for employee with ID 234324: %.2f\nTheir job number is %d\n", p2 -> salary, p2 -> jobType);
    
    setID(p1,35674); // sets the 0th employee's ID to 35674
    setSalary(p1,3405430.50); // sets the 0th employee's salary to 3405430.50
    printf("\nEmployee 0's ID is now %d and their salary is now %.2f\n", p1 -> ID, p1 -> salary);
    
    free(p1); // frees memory allocated for p1
    
    return 0;
}

Employee *readEmployeeInfo(FILE *fp, int *numElems)
{
    
    Employee *array = malloc(*numElems * sizeof(Employee)); // allocates memory for the struct
    int emp = 0;
    
    if (array == NULL)
    {
        puts("\nError allocating memory.");
        return NULL;
    }
    
    fscanf(fp, "%d", numElems); // scans in how many elements there are
        while(!feof(fp))
        {
            fscanf(fp, "%d,%d,%f", &(array[emp].ID), &(array[emp].jobType), &(array[emp].salary)); // scans in info to fill for the struct
            emp++;
        }
    
    return array; // returns array full of struct info
}

Employee *getEmployeeByID(Employee *p, int numEmps, int ID)
{
    for (int i = 0; i < numEmps; i++)
    {
        if (p[i].ID == ID)
        {
            return &p[i]; // returns the employee with the passed ID
        }
    }
    
    puts("\nA person does not exist with the specified ID, please enter a new one.\n");
    return NULL; // returns null if employee ID not found
}

void setID(Employee *p, int id)
{
    p->ID = id; // sets the employee passed to the function's ID to whatever ID is passed
}

int getID(Employee *p)
{
    return p->ID; // gets the ID of the employee that's passed to it
}

void setSalary(Employee *p, float salary)
{
    p->salary = salary; // sets the employee passed to the function's salary to whatever salary is passed
}
