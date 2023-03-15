// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = len-1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    int leftBorder = i, rightBorder = len;
    while (rightBorder - 1 > leftBorder) {
      int mid = (leftBorder + rightBorder) / 2;
      if (arr[i] + arr[mid] == value) {
        k++;
        int mid2 = mid + 1;
        while (arr[i] + arr[mid2] == value && mid2 < rightBorder) {
          k++;
          mid2++;
        }
        mid2 = mid - 1;
        while (arr[i] + arr[mid2] == value && mid2 > leftBorder) {
          k++;
          mid2--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        rightBorder = mid;
      } else {
        leftBorder = mid;
      }
    }
  }
  return k;
}
