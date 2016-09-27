#include <stdio.h>
#include <stdlib.h>
#include "tables.h"

int main(int argc, char const *argv[]) {
  int table[5] = {10, 25, 3, 7, 52};
  int copyTable[5] = {0};
  display_table(table, 5);
  display_table(copyTable, 5);
  printf("Table sum: %d\n", sum_table(table, 5));
  printf("Table average: %.2f\n", avg_table(table, 5));
  copy(table, copyTable, 5);
  display_table(copyTable, 5);
  max_table(copyTable, 5, 24);
  display_table(copyTable, 5);
  sort_table(table, 5);
  display_table(table, 5);
  return 0;
}

void display_table(int table[], int tableSize) {
  for (size_t i = 0; i < tableSize; i++) {
    printf("%d ", table[i]);
  }
  printf("\n");
}

int sum_table(int table[], int tableSize) {
  int sum = 0;
  for (size_t i = 0; i < tableSize; i++) {
    sum += table[i];
  }
  return sum;
}

double avg_table(int table[], int tableSize) {
  return (double)sum_table(table, tableSize) / (double)tableSize;
}

void copy(int originalTable[], int copyTable[], int tableSize) {
  for (size_t i = 0; i < tableSize; i++) {
    copyTable[i] = originalTable[i];
  }
}

void max_table(int table[], int tableSize, int maxValue) {
  for (size_t i = 0; i < tableSize; i++) {
    if (table[i] > maxValue) {
      table[i] = 0;
    }
  }
}

void sort_table(int table[], int tableSize) {
  for (size_t i = 0; i < tableSize-1; i++) {
    int min = i;
    for (size_t j = i+1; j < tableSize; j++) {
      if (table[j] < table[min]) {
        min = j;
      }
    }
    int temp = table[i];
    table[i] = table[min];
    table[min] = temp;
  }
}
