#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include "wyhash.h"

#define buckets 64

struct Entry {
  char word[100];
  uint64_t count;
};

struct Entry counts[buckets];
uint64_t secret = 7;
uint64_t hash(char* buffer){
  return wyhash(buffer, strlen(buffer), 0, &secret) % buckets;
}
void indirect_access(char** words, int word_count) {
  for (int i = 0; i < word_count; i++){
    uint64_t bucket_index = hash(words[i]);
    struct Entry* bucket = &counts[bucket_index];
    if(bucket->count == 0){
      strcpy(bucket->word, words[i]);
    }
    bucket->count++;
    free(words[i]);
  }
}


int main(int argc, char *argv[]){
  int max_lines = 10000000;
  char **words = (char **)malloc(sizeof(char*)*max_lines);
  FILE *file = fopen(argv[1], "r");
  int chars_read;
  char** line = &words[0];
  size_t len;
  int line_no = 0;
  while ((chars_read = getline(line, &len, file)) != -1) {
    line_no++;
    (*line)[strlen(*line)-1] = '\0';
    line = &words[line_no];
  }
  clock_t begin = clock();
  indirect_access(words, line_no);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time_spent : ~ %fsec\n", time_spent);
  for (int i = 0; i < buckets; i++){
    if(counts[i].count > 0){
      printf("%s %d\n", counts[i].word, counts[i].count);
    }
  }
  fclose(file);
  return 0;
}