#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int items[100];
	int f;
	int r;
	int count;
}Q;

Q q;

void indegree(int a[100][100],int n,int *inq,int *flag){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			if(a[j][i]==1)inq[i]++;
		if(inq[i]==0){
			q.r= (q.r+1)%n;
			q.items[q.r] = i;
			flag[i] = 1;
			q.count++;
		}
	}
	if(q.count==0){
		printf("Cycles exists hence no solution\n");
		exit(1);
	}
}

void source(int a[100][100],int n,int *inq,int *flag){
	while(q.count!=0){
		int source = q.items[q.f];
		q.f = (q.f+1)%n;
		q.count--;
		int flag1 = 0;
		for(int i = 0;i<n;i++){
			if(a[source][i] == 1)inq[i]--;
			if(inq[i]==0 && flag[i]==0){
				flag1 = 1;
				q.r = (q.r+1)%n;
				q.items[q.r] = i;
				q.count++;
				flag[i] = 1;
			}
		}
		if(flag1 == 0){
			printf("Cycles exists hence no solution\n");
			exit(1);
		}else
			printf("%d, ",source);
	}
}



int main(){
	int n;
	q.r = -1;
	q.f = 0;
	printf("Enter the number of vertices\n");
		scanf("%d",&n);
	int a[100][100];
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	int *inq = (int *)calloc(sizeof(int),n);
	int *flag = (int *)calloc(sizeof(int),n);
	indegree(a,n,inq,flag);
	printf("Topological sorting\n");
	source(a,n,inq,flag);
}