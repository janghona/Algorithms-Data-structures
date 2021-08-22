#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(int* list, const int n){
	int i, j, indexMin, temp;

	for (i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[indexMin])
			{
				indexMin = j;
			}
		}
		temp = list[indexMin];
		list[indexMin] = list[i];
		list[i] = temp;
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
	selectionSort(list,sizeof(list)/4);
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ",list[i]);
	}

	return 0;
}
