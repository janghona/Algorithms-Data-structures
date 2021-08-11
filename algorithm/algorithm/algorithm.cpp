#include <iostream>
#include<stdio.h>
using namespace std;

int InterpolationSearch(int arr[], int len, int target)
{

    int low = 0, high = (len - 1);
    int pos = 0;

    while (arr[low] != arr[high] && target >= arr[low] && target <= arr[high])
    {
        pos = low + (target - arr[low]) * (high - low) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] > target)
            high = pos - 1;
        else
            low = pos + 1;
    }

    if (target == arr[low])
        return low;
    else
        return -1;
}

int main()
{
    int arr[] = { 1,2,3,7,9,12,21,23,27 };
    int index = 0;
    int inputTarget = 0;

    printf("input number : ");
    scanf_s("%d", &inputTarget);

    index = InterpolationSearch(arr, sizeof(arr), inputTarget);
    if (index == -1) printf("Fail");
    else {
        printf("arr[] target index : %d", index);
    }
}


