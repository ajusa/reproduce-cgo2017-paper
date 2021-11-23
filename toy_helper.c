#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Write base_array.txt and target_array.txt given a size parameter
    int size = 1000;
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
        if(i != size - 1) {
            fprintf(file, "%d\n", i);
        } else {
            fprintf(file, "%d", i);
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

    // Create random seed for random numbers
    int randomnumber;
    srand(time(NULL));

    fprintf(file, "%d\n", size);
    for(int i = 0; i < size; i++) {
        randomnumber = rand() % size + 1;

        if(i != size - 1) {
            fprintf(file, "%d\n", randomnumber);
        } else {
            fprintf(file, "%d", randomnumber);
        }
    }
    fclose(file);
}