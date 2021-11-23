#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Create random seed for random numbers
    int randomnumber;
    srand(time(NULL));

    // Write base_array.txt and target_array.txt given a size parameter
    int size = 100000000;
    if(argv[1]) {
        size = atoi(argv[1]);
    } 

    // Create base_array.txt
    FILE *file = fopen("base_array.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d\n", size);
    for(int i = 0; i < size; i++) {
        randomnumber = rand() % size;

        if(i != size - 1) {
            fprintf(file, "%d\n", randomnumber);
        } else {
            fprintf(file, "%d", randomnumber);
        }
    }
    fclose(file);

    // Create target_array.txt
    file = fopen("target_array.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d\n", size);
    for(int i = 0; i < size; i++) {
        randomnumber = rand() % size;

        if(i != size - 1) {
            fprintf(file, "%d\n", randomnumber);
        } else {
            fprintf(file, "%d", randomnumber);
        }
    }
    fclose(file);
}