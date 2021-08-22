#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int A[], int low, int high, int B[]){
	if (low >= high) return;
	int mid = (low + high) / 2;

	mergeSort(A, low, mid, B);
	mergeSort(A, mid + 1, high, B);
	int i = low, j = mid + 1, k = low;
	for (; k <= high; ++k) {
		if (j > high) B[k] = A[i++];
		else if (i > mid) B[k] = A[j++];
		else if (A[i] <= A[j]) B[k] = A[i++];
		else B[k] = A[j++];
	}
	for (i = low; i <= high; ++i) A[i] = B[i];
}
int main(){
	int list[] = { 5,8,6,4,1,3,2,7,10,9 };
	int B[sizeof(list)/4];

	printf("정렬 전 : ");
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("정렬 후 : ");
	mergeSort(list,0,(sizeof(list)/4)-1,B);
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ",list[i]);
	}

	return 0;
}
