#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void quickSort(int A[], int low, int high) {
	if (low >= high) return; // base condition

	// divide process
	int i = low, j = low;
	int& pivot = A[high];
	for (; j < high; ++j) {
		if (A[j] < pivot)
			swap(A[i++], A[j]);
	}
	swap(A[i], pivot);

	// conquer process
	quickSort(A, low, i - 1);
	quickSort(A, i + 1, high);
}

int main(){
	int list[] = { 5,8,6,4,1,3,2,7,10,9 };

	printf("정렬 전 : ");
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("정렬 후 : ");
	quickSort(list,0,(sizeof(list)/4-1));
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ",list[i]);
	}

	return 0;
}
