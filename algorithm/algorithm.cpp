#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int target, int len)
{
    int fbM2 = 0;
    int fbM1 = 1;
    int fbM = fbM2 + fbM1;
    int offset = -1;
    while (fbM < len)
    {
        fbM2 = fbM1;
        fbM1 = fbM;
        fbM = fbM2 + fbM1;
    }
    while (fbM > 1)
    {
        int i = min(offset + fbM2, len - 1);
        if (arr[i] < target)
        {
            fbM = fbM1;
            fbM1 = fbM2;
            fbM2 = fbM - fbM1;
            offset = i;
        }
        else if (arr[i] > target)
        {
            fbM = fbM2;
            fbM1 = fbM1 - fbM2;
            fbM2 = fbM - fbM1;
        }
        else return i;
    }
    if (fbM1 && arr[offset + 1] == target)
        return offset + 1;

    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int index = 0;
    int inputTarget = 0;

    cout << "input target number(1~9) : ";
    cin >> inputTarget;
    int index = fibonacciSearch(arr, inputTarget, sizeof(arr)/4);
    if (index == -1) cout << "Fail !!";
    else {
        cout << "Element found at index " << index;
    }
    return 0;
}