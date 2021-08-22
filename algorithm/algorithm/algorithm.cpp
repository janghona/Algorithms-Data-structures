#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* v1, int* v2) {
	int temp;
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
void downheap(int cur, int k,int* data){
	int left, right, p;
	while (cur < k) {
		left = cur * 2 + 1;
		right = cur * 2 + 2;

		if (left >= k && right >= k) break;

		p = cur;
		if (left < k && data[p] < data[left]) p = left;
		if (right < k && data[p] < data[right]) p = right;
		if (p == cur) break;

		swap(&data[cur], &data[p]);
		cur = p;
	}
}

void heapify(int* data,int n){
	int i, p;
	for (i = (n - 1) / 2; i >= 0; i--) {
		downheap(i, n,data);
	}
	//for(i=0;i<size;++i)printf("%d ",data[i]);
	//printf("\n");
}

void heapSort(int* data, int size){
	int k;
	heapify(data, size);
	for (k = size - 1; k > 0; k--) {
		swap(&data[0], &data[k]);
		downheap(0, k,data);
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
	heapSort(list,sizeof(list)/4);
	for (int i = 0; i < sizeof(list) / 4; i++) {
		printf("%d ",list[i]);
	}

	return 0;
}
