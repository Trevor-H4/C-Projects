#include <stdio.h>
#include <stdlib.h>

typedef struct {  
  int empID, age, ssn;  
  float salary;
  } Record;
  
  Record* readRecordFile(FILE*);
  int getSize(Record*);
  Record* getEmpByAge(Record*,int);
  void adjustSalaries(Record*,int,float);
  void freeRecordArray(Record*);


int main(void)
{
		FILE *fp = fopen("employee.csv", "r"); // reads in the file
		
		if (fp == NULL) // fp returns null if file couldn't be opened
		{
			puts("Error: Could not open file.\n");
			return -1;
		}
		
	    Record *staff = readRecordFile(fp), *p; // reads file into *staff variable
        fclose(fp); // closes file pointer
		
		int size = getSize(staff); // assigns the value returned by getSize to size variables
		printf("\nAmount of employees in this array: %d\n", size);
		
		p = getEmpByAge(staff, 36); // gets all the employees that are 36
		printf("\nEmp ID for 36 year old: %d\n", p->empID); 
		
		adjustSalaries(staff, 18, 4.5); // adjusts the salaries for all 18 year olds by multypling it by 4.5
		printf("\nNew salary for 18 year old: %.2f\n", staff->salary);
	
	
		freeRecordArray(staff); // frees the memory allocated
	
	return 0;
}

Record *readRecordFile(FILE *fp) // this function reads in a file and stores it in an array and returns said array
{
	    if(!feof(fp)) // this means if it is not the end of the file
    {
        int size, i;
        fscanf(fp, "%d\n", &size); // scans in the amount of employees
        
        int *staff = malloc(sizeof(Record) * size + sizeof(int)); // allocates enough memory to store all the employees info
        
        if(staff == NULL) // this checks to see if emps returns NULL and if it does the program ends
        {
            puts("Error: Failed to allocate memory.");
            return NULL;
        }
        

        *staff = size; 
        staff++; // this hides the amount of employees in the array

        for(i = 0; i < size; i++) // this loops through the whole file and scans the employee info into "emps"
        {
            if(!feof(fp))
            {
                fscanf(fp, "%f,%d,%d,%d\n", &(((Record *)staff + i)->salary), &(((Record *)staff + i)->age), &(((Record *)staff + i)->empID), &(((Record *)staff + i)->ssn));
            }
        }
            return (Record *)staff; // returns the array full of info
    }
    else
        return NULL; // returns null if it is the end of the file
}

int getSize(Record *staff) // this function gets the size of the array with all the structs
{
	return *((int *)staff - 1); // returns the [-1] element of the array that has the number of emps in the array
}

Record *getEmpByAge(Record *staff, int age) // this function get the employees that are the age that the user passes to the function
{
	int i;
    for(i = 0; i < getSize(staff); i++) // this loops through all the employees and gets the employees with the same age as the age passed to the function
    {
        if(staff[i].age == age)
            return &(staff[i]);
    }
    
    puts("\nA person does not exist with the specified age, please enter a new one.\n");
    return NULL; // returns null if employee age not found
}

void adjustSalaries(Record *staff, int ageOfEmps, float salaryMultiplier) // this function loops through all the employees and narrows it down to the employees with the age that is passed and multiples those peoples salary's by the salaryMultiplier
{
	int i;
    for(i = 0; i < getSize(staff); i++) // this loops through all the employees and narrows it down to all the employees with the age that is passed
    {
        if(staff[i].age == ageOfEmps)
            staff->salary *= salaryMultiplier; //multiple all salaries by salaryMultiplier
			return;
    }
}

void freeRecordArray(Record *staff) // this frees the memory allocated for the array of structs
{
	free((void *)((int *)staff - 1)); // increments to the [-1] spot in the array and frees everything
}
