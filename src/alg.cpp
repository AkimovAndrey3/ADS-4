// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len-1; i++) {
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
    int leftBorder = i;
    int rightBorder = len - 1;
    while (rightBorder - 1 > leftBorder) {
      middle = (rightBorder + leftBorder) / 2;
      if ((arr[i] + arr[middle]) == value) {
        k++;
        int mid2 = middle+1;
        while (((arr[i] + arr[mid2] == value)) && (rightBorder > mid2)) {
          k++;
          mid2++;
        }
        while (((arr[i] + arr[mid2]) == value) && (leftBorder < mid2)) {
          k++;
          mid2--;
        }
        break;
      }
      if ((arr[i]+arr[middle]) > value) {
        rightBorder = middle;
      } else {
        leftBorder = middle;
      }
    }
  }
  return k;
}
