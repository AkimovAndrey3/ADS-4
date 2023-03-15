// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = len - 1; i < j; j--) {
      if ((arr[i] + arr[j]) == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs3(int *arr, int len, int value) {
  int middle = 0;
  int k = 0;
  for (int i = 0; i < len-1; i++) {
    int left = i;
    int right = len - 1;
    while (right > left) {
      middle = (right + left) / 2;
      if ((arr[i]+arr[middle]) == value) {
        k++;
        int mid2 = middle + 1;
        while (((arr[i] + arr[mid2] == value)) && (right > middle)) {
          k++;
          middle++;
        }
        while (((arr[i] + arr[mid2]) == value) && (left < mid2)) {
          k++;
          mid2--;
        }
        break;
      }
      if ((arr[i] + arr[middle]) > value) {
        right = middle;
      } else {
        left = middle;
      }
    }
  }
  return k;
}
