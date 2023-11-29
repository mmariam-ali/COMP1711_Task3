#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 256
// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    char steps[10];
} FitnessData;

//variables
char filename[100];
char record, date[11], time[6], steps[10]; 
int intsteps, line_count=0, i;
int fewest_steps, largest_steps;
int fewest_steps_index, largest_steps_index;
int total_steps;
float mean_steps;

char line[100];
char filename[100];
char buffer[buffer_size];

FitnessData fitness_data[999];


// Function to tokenize a record
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }



int open_file(char *filename , char *mode) {
    FILE *file= fopen(filename, mode);   //open file in read mode and check it isn't empty
      if (file ==NULL) {
        perror("Error: invalid file\n");  //if file does not exist
        exit(1);
        return 1;
        }
        else {
            printf("File successfully loaded.\n");
        };
            
        while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty

                tokeniseRecord(buffer, ",", date, time, steps); 
                if (date =="" || time==""||steps=="" ) {
                    perror("Incorrect format\n");
                } 
                else {  //splitting the line into date, time, steps
                strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
                strcpy(fitness_data[i].time, time);
                strcpy(fitness_data[i].steps, steps);
                i++;         
            }       
        }
            
        for (int i =0; i <10; i++) {                            //prints out date, time and steps of first 3 records.
            printf("%s/%s/%d\n", fitness_data[i].date,
                         fitness_data[i].time,
                         atoi(fitness_data[i].steps));
                            }                               //does this for every i; every line in the file
           

    // qsort(, , sizeof(fitness_data));

    //     char new_filename []= "filename.tsv";
    //     FILE *newfile = fopen(new_filename, "w");

    return 0;

    }

void qsort(void *base, size_t nitems, size_t size, int
         (*compar)(const void *, const void*));


    int main() {
        printf("Enter filename: ");
        scanf(" %s", filename);

        open_file(filename, "r");

        printf("Data sorted and written to %s.tsv\n",filename);
    }   

/*
./FitnessDataSorterCopy
FitnessDataSorter_copy gcc -o FitnessDataSorter_copy.c
*/