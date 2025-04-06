// Copyright 2021 NNTU-CS
#include <unordered_set>

int countPairs1(const int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(const int *arr, int len, int value) {
  int count = 0;
  int lb = 0;
  int rb = len - 1;
  for (int i = 0; i < rb; ++i) {
    for (int j = rb-1; j > lb; --j) {
      if (arr[j] > value) {
        rb -= 1;
      }
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
    lb += 1;
  }
  return count;
}

int binSer(const int* arr, int left, int right, int target, bool find_first) {
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid;
      if (find_first) {
        right = mid - 1;
      } else {
      left = mid + 1;
      }
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
  }
  return result;
}

int countPairs3(const int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int element = value - arr[i];
    int first = binSer(arr, i + 1, len - 1, element, true);
    if (first != -1) {
      int last = binSer(arr, first, len - 1, element, false);
      count += last - first + 1;
    }
  }
  return count;
}
