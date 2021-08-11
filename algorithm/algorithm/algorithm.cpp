#include <iostream>
#include<stdio.h>
using namespace std;

int BinarySearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid = 0;

    while (first <= last) {
        mid = (first + last) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else {
            if (arr[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1;
}

int BinarySearchRecur(int arr[], int first, int last, int target) {
    int mid = (first + last) / 2;
    if (first > last)
        return -1;
    else {
        if (arr[mid] == target)
            return mid;
        else {
            if (arr[mid] > target) {
                last = mid - 1;
                BinarySearchRecur(arr, first, last, target);
            }
            else {
                first = mid + 1;
                BinarySearchRecur(arr, first, last, target);
            }
        }
    }
}

int main()
{
    int arr[] = { 1,2,3,7,9,12,21,23,27 };
    int index = 0;
    int inputTarget = 0;

    printf("input number : ");
    scanf_s("%d", &inputTarget);

    index = BinarySearch(arr, sizeof(arr), inputTarget);
    if (index == -1) printf("Fail");
    else {
        printf("arr[] target index : %d", index);
    }
}


