#include <stdio.h>
#include <stdlib.h>

void QuickSort(int s[], int left, int right) {		
	if(left < right){
		int i = left, j = right;
		int p = s[left];
		while(i < j) {
			while(s[j] > p && i < j) j--;
			if(i < j) {
				s[i++]=s[j];
			}

			while(s[i] < p && i < j) i++;
			if(i < j) {
				s[j--]=s[i];
			}
		}

		s[i] = p;
		QuickSort(s, left, i - 1);
		QuickSort(s, i + 1, right);
	}
	
}

int main() {
	int a[10] = {2,4,27,3,64,16,74,34,65,32};
	QuickSort(a, 0, sizeof(a)/sizeof(int)-1);
	for(int i = 0; i < 10; i++){
		printf("%d ",a[i]);
	}
}
