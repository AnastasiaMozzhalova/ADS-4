// Copyright 2021 NNTU-CS
#include <iostream>
#include <unordered_set>
int countPairs1(const int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; ++i) {
    for (int j = i + 1; j < len ; ++j) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
  }
return count;
}
int countPairs2(const int *arr, int len, int value) {
  int count = 0;
  int lboard = 0;
  int rboard = len - 1;
  for (int i = 0; i < rboard; ++i) {
    for (int j = rboard-1; j > lboard; --j) {
      if (arr[j] > value) {
        rboard -= 1;
      }
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
    lboard += 1;
  }
return count;
}
int binarySearch(const int* arr, int left, int right, int target, bool find_first) {
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

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
      int complement = value - arr[i];
      int first = binarySearch(arr, i + 1, len - 1, complement, true);
      if (first != -1) {
        int last = binarySearch(arr, first, len - 1, complement, false);
        count += last - first + 1;
      }
    }
    return count;
}
