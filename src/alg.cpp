// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i =0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int high = len - 1;
  while (arr[high] > value) {
    high = high - 1;
  }
  for (int i = 0; i < high; i++) {
    for (int j = high; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int cbinsearch(int *arr, int size, int value) {
  int low = 0, count = 0, high = size - 1;
  while (low <= high) {
    int middle = (high + low) / 2;
    if (arr[middle] < value) {
      low = middle + 1;
    } else if (arr[middle] > value) {
      high = middle - 1;
    } else {
      count++;
      int now = middle - 1;
      middle++;
      while (arr[middle] == value) {
        middle++;
        count++;
      }
      while (arr[now] == value) {
        now--;
        count++;
      }
      break;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int i = 0, count = 0;
  while (arr[i] <= (value / 2) -1) {
    int num = value - arr[i];
    count += cbinsearch(arr, len, num);
    i++;
  }
  int middle = cbinsearch(arr, len, value /2);
  count += middle * (middle - 1) / 2;
  return count;
}
