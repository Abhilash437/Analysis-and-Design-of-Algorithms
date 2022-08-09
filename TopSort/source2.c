#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int items[100];
	int f,r;
	int count;
}Q;

int inq[100];
Q q;

void indegree(int *a[100],int v,int *inq,int *flag){
	for(int i = 0;i<v;i++){
		for(int j = 0;j<v;j++)
			if(a[j][i] == 1)inq[i] = inq[i]+1;
		if(inq[i]==0){
			q.r = (q.r+1)%v;
			q.items[q.r] = i;
			q.count++;
			flag[i] = 1;		
		}
	}
	if(q.count==0){
		printf("Cycle exist hence no solution\n");
		exit(1);
	}
}

void source(int *a[100],int v,int *inq,int *flag){
	while(q.count != 0){
		int source = q.items[q.f];
		q.f = (q.f+1)%v;
		q.count--;
		printf("%d ",source);
		for(int i = 0;i<v;i++)
		{
			if(a[source][i]==1)inq[i]--;
			if(inq[i]==0 && flag[i]==0){
				q.r = (q.r+1)%v;
				q.items[q.r] = i;
				q.count++;
				flag[i] = 1;
			}
		}
	}
}

int main(){
	int v;
	q.f = 0;
	q.r = -1;
	printf("Enter the number of vertices\n");
		scanf("%d",&v);
	int *a[v];
	for(int i = 0;i<v;i++)
		a[i] = (int *)malloc(sizeof(int)*v);
	printf("Enter the adjacency matrix\n");
		for(int i = 0;i<v;i++)
			for(int j = 0;j<v;j++)
				scanf("%d",&a[i][j]);
	int *inq = (int *)calloc(sizeof(int),v);
	int *flag = (int *)calloc(sizeof(int),v);
	indegree(a,v,inq,flag);
	printf("Toplological sorting\n");
		source(a,v,inq,flag);
	
}