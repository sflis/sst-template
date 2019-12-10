#include "my_lib.h"

void read_data(uint16_t* array, int n_samples) {
  for (int i=0;i<n_samples;i++) {
    array[i] = i;
  }
}


int add(int i, int j) {
    return i + j;
}