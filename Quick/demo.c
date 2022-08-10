#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 10

int count;

int partition(int a[100],int s,int e){
	int i = s,j = e, p = a[s];
	while(i<j){
		count++;
		while(i<e && a[i] < p){
			count++;
			i++;
		}
		count++;
		while(a[j]>p){
			count++;
			j--;
		}
		//count++;
		if(i<j){
			//count++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}
		// if(i==j && a[i] == p){
		// 	count++;
		// 	return j;
		// }
	} 
	//if(a[j]!=a[e]){
		int temp = a[s];
		a[s] = a[j];
		a[j]= temp;
	//}

	return j;
}

void quick(int a[100],int s,int e){
	if(s<e){
		int l = partition(a,s,e);
		quick(a,s,l-1);
		quick(a,l+1,e);
	}
}


int main(){
	int n;
	printf("Enter the number of elements in array\n");
	scanf("%d",&n);
	//int *a = (int *)malloc(sizeof(int)*n);
	int a[100];
	printf("Enter the elements\n");
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	quick(a,0,n-1);
	printf("After sorting\n");
	for(int i = 0;i<n;i++)
		printf("%d, ",a[i]);
}