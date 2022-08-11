#include<stdio.h>
int count;
void Heapcon(int a[100],int n){
	for(int i = n/2;i>=1;i--){
		int v = a[i];
		int k = i;
		int heap = 0;
		while(!heap && 2*k<=n){
			int j = 2*k;

			if(j<n){
				count++;
				if(a[j+1]>a[j])
					j++;
			}
			count++;
			if(v>=a[j])
				heap = 1;
			else{
				a[k] = a[j];
				k = j;
			}
		}
		a[k] = v;
	}
}

void Heapdel(int a[100],int n){
	int size = n;
	for(int i = 0;i<size-1;i++){
		int temp = a[1];
		a[1] = a[n];
		a[n] = temp;
		n--;
		int v = a[1];
		int k = 1;
		int heap = 0;
		while(!heap && 2*k<=n){
			int j = 2*k;
			if(j<n){
				count++;
				if(a[j+1]>a[j])
					j++;
			}
			count++;
			if(v>=a[j])
				heap = 1;
			else{
				a[k] = a[j];
				k = j;
			}
		}
		a[k] = v;
	}
}

int main(){
	int n;
	printf("Enter the number of elements\n");
		scanf("%d",&n);
	int a[100];
	printf("Enter the elements\n");
	for(int i = 1;i<=n;i++)
		scanf("%d",&a[i]);
	Heapcon(a,n);
	Heapdel(a,n);
	printf("After sorting\n");
	for(int i = 1;i<=n;i++)
		printf("%d, ",a[i]);
	printf("\nCount = %d\n",count);
}