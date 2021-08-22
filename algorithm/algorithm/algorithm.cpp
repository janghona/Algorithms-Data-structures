#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int* list, const int n){
	int i, j, temp;

	for (i = n-1; i > 0; i--){
		for (j = 0; j < i; j++){
			if (list[j] > list[j+1]){
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
int main(){
	int list[] = { 5,8,6,4,1,3,2,7,10,9 };

	printf("정렬 전 : ");
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("정렬 후 : ");
	bubbleSort(list,sizeof(list)/4);
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ",list[i]);
	}

	return 0;
}
