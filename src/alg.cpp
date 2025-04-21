// Copyright 2021 NNTU-CS
#include <iostream>
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

int bin(int *arr, int len, int target, int start) {
  int left = start + 1;
  int right = len - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}


int countPairs3(const int *arr, int len, int value) {
 int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    if (bin(arr, len, complement, i) != -1) {
      count++;
    }
  }
  return count / 2;
}
