#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int __attribute__ ((noinline)) func(int idx, int size);

int func(int idx, int size)
{
    return (idx + 1)%size;
}

int identity_func(int idx)
{
    return idx;
}

void indirect_access(int* base_array, int base_array_size, int* target_array, int target_array_size) {
    for (int i = 0; i < base_array_size; i++)
    {
        target_array[func(base_array[i], target_array_size)]++;
    }
}

int main(int argc, char *argv[])
{
    // -------------------------- SET UP --------------------------
    // Open file and initialize variables
    FILE *file = fopen("base_array.txt", "r");
    int base_array_size, num, idx = 0;

    // Read size and initialize base_array
    fscanf(file, "%d", &base_array_size);
    int* base_array = (int*)malloc(sizeof(int)*base_array_size);

    // Read rest of numbers into base_array
    while (!feof(file))
    {
        fscanf(file, "%d", &num);
        base_array[idx++] = num;
    }

    // Close file
    fclose(file);

    // Open file and initialize variables
    file = fopen("target_array.txt", "r");
    int target_array_size = 0;
    idx = 0;

    // Read size and initialize target_array
    fscanf(file, "%d", &target_array_size);
    int* target_array = (int*)malloc(sizeof(int)*target_array_size);

    // Read rest of numbers into target_array
    while (!feof(file))
    {
        fscanf(file, "%d", &num);
        target_array[idx++] = num;
    }

    // Close file
    fclose(file);

    // -------------------------- INDIRECT MEMORY ACCESS --------------------------
    clock_t begin = clock();

    indirect_access(base_array, base_array_size, target_array, target_array_size);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time_spent : ~ %fsec\n", time_spent);
    // -------------------------- WRAPPING UP --------------------------

    // Free resources
    free(base_array);
    free(target_array);

    return 0;
}
