// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        a++;
      }
    }
  }
  return a;
}
int countPairs2(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = len-1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        a++;
      }
    }
  }
  return a;
}
int countPairs3(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len - 1; i++) {
    int lBorder = i, rBorder = len;
    while (rBorder - 1 > lBorder) {
      int mid = (lBorder + rBorder) / 2;
      if (arr[i] + arr[mid] == value) {
        a++;
        int mid2 = mid + 1;
        while (arr[i] + arr[mid2] == value && mid2 < rBorder) {
          a++;
          mid2++;
        }
        mid2 = mid - 1;
        while (arr[i] + arr[mid2] == value && mid2 > lBorder) {
          a++;
          mid2--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        rBorder = mid;
      } else {
        lBorder = mid;
      }
    }
  }
  return a;
}
