#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 256
// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
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
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
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
            
            while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty

                tokeniseRecord(buffer, ",", date, time, steps);    //splitting the line into date, time, steps
                strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
                strcpy(fitness_data[i].time, time);
                strcpy(fitness_data[i].steps, steps);
                i++;                                               //does this for every i; every line in the file
         }   //see what happens if u change steps to char in tokensize record
    };
}



int main() {
    printf("Enter filename: ");
    scanf(" %s", filename);

    open_file(filename, "r");

    printf("Data sorted and written to %s.tsv\n",filename);
}
