//ELE 124 Computer Programming-HW1-

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define LOG_SIZE 90

//*****************FUNCTİON PROTOTYPES************
void create_log(int log[],int size); 
//fills the array with random values (20-200) and puts 9 faults (-99)
int count_faults(const int log[],int size);
/*returns the total number of faults 
Note: 'const' is used to ensure the original array is read-only and cannot be modified
 */
void print_fault_indices(const int log[],int size);
//prints the indices of the faults
void repair_log(int log[],int size);
/*repairs the log by replacing faults (-99) with the previous valid reading
ıf a faulty value appears at the beginning of the array
it replaces it with the next valid reading*/
float calculate_average(const int log[],int size);
//computes and returns the average of the valid readings
int count_large_changes(const int log[],int size);
//counts how many times the absolute difference between consecutive readings exceeds 35


/*Custom Random Number Generator 
(Linear Congruential Generator 'LCG' algorithm is used from my previous ELE109 course)
(instead of using library functions,I write my own)*/
unsigned long current_seed = 1; //global variable
/*'unsigned long' is used to prevent integer overflow during large coefficient multiplications 
and to ensure the seed values remain positive*/
void set_seed(unsigned long seed);
/*sets the initial seed for the Custom Random Number Generator*/
int random_number_generator();
/*generates a random integer using a LCG algorithm
Mathematical Model:
X_{n+1}=(a*X_n+c)mod m
Where:
-X_n is the current sequence value(current_seed)
- a=1103515245(multiplier)
- c=12345(increment)
- m=2147483648(moduluus)*/  


int main()
{
int sensor_log[LOG_SIZE]; //I changed log[] with sensor_log to make it more understandable
int i,total_faults;
float average;
int large_changes;

set_seed(time(NULL));
/*time(NULL) returns the current time in seconds
passing it as a seed ensures we generate a unique
sequence of numbers every time the program runs 
without this,the log would be identical on every execution*/

//FIRST MISSION-Measurement Log Generation
create_log(sensor_log,LOG_SIZE);
printf("Original log:\n");
for(i=0;i<LOG_SIZE;i++)
{
	printf("%d   ",sensor_log[i]);
}
printf("\n");

//SECOND MISSION-Fault Detection
total_faults=count_faults(sensor_log,LOG_SIZE);
printf("Number of faults:%d\n",total_faults);
printf("Fault indices:");
print_fault_indices(sensor_log,LOG_SIZE);
printf("\n");

//THIRD MISSION-Log Repair
repair_log(sensor_log,LOG_SIZE);
printf("Repaired log:\n");
for(i=0;i<LOG_SIZE;++i)
{ 
    printf("%d   ",sensor_log[i]);
}
printf("\n");

//FOURTH MISSION-Post-Repair Analysis
average=calculate_average(sensor_log,LOG_SIZE);
printf("Average:%.2f\n",average);
large_changes=count_large_changes(sensor_log,LOG_SIZE);
printf("Large changes: %d\n",large_changes);

return 0;
}

void set_seed(unsigned long seed)
{
    current_seed=seed; //note current_seed is a global variable
}

int random_number_generator() //computes the next number in the sequence using the previous seed
{
    current_seed=(current_seed*1103515245+12345)%2147483648;
    return (int)current_seed; 
}

void create_log(int log[],int size)
{
    int i;
    //fill the entire array with valid readings between 20 and 200
    //range formula:(value%(max-min+1))+min->(value%181)+20
    for(i=0;i<size;i++)
	{
        log[i]=(random_number_generator()%181)+20; //generates between 20-200
    }
    //put 9 faults (-99) at random positions
    int replaced_faults=0;
    //use a while loop because i only increment the counter if i
    //successfully place a new fault
	//this prevents put -99 at the same place
    while(replaced_faults<9)
	{
    //pick a random index between 0 and 89
    int random_i=random_number_generator()%size;
    //if this index doesn't already have a fault,place -99
    if(log[random_i]!= -99) 
	{
        log[random_i]= -99;
        replaced_faults++;
    }
    }
}

int count_faults(const int log[], int size)
{
    int count =0;
    int i;
    //go through the array and count -99's
    for(i=0;i<size;i++)
	{
        if(log[i]== -99)
		{
            count++;
        }
    }
    return count;
}

void print_fault_indices(const int log[], int size)
{
    //go through the array and print the index of any -99 found
    for(int i=0;i<size;i++)
	{
        if(log[i]== -99)
		{
            printf("%d ",i); 
        }
    }
}

void repair_log(int log[], int size)
{
    int i; 
    //go through the array to find and replace faults
    for(i=0;i<size;i++)
	{
        if(log[i]== -99)
		{
            if(i ==0) //first case
			{
                int next_valid=i+ 1;
                while(next_valid<size && log[next_valid]== -99)
				{
                    next_valid++;
                }
                if(next_valid<size) 
				{
                    log[i]=log[next_valid];
                }
            } 
            else //second case
			{
                log[i] = log[i - 1];
            }
        }
    }
}

float calculate_average(const int log[], int size)
{
    int i;
    int sum=0;//initialize it to zero to avoid random results
    for(i=0;i<size;i++) 
	{
        sum+=log[i];
    }
    //type cast 'sum' to float to prevent integer division data loss
    return (float)sum / size;
}

int count_large_changes(const int log[], int size)
{
    int count = 0;
    int i;
    for(i=1;i<size;i++) 
	{
        //check if the absolute difference between current and previous reading > 35
        //abs() function is provided with <stdlib.h>
        if(abs(log[i] - log[i - 1]) > 35) 
		{
            count++;
        }
    }
    return count;
}




