#include<stdio.h>
#include<stdlib.h>
#include<time.h>



float euclid(int m,int n){
	float count = 0;
	int r;
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
		count++;
	}
	return count;
}

float consec(int m,int n){
	float count1=0,count2=0;
	int min;
	min = m<n?m:n;
	printf("Hi\n");
	while(1){
		count1++;
		if(m%min==0){
			count2++;
			if(n%min==0)
				break;
		}else
			min = min-1;
	}

	return count1>count2?count1:count2;
}

float me(int m,int n){
	int temp;
	float count = 0;
	printf("Hi2\n");
	while(n>0){
		if(m<n){
			temp = m;
			m = n;
			n = m;
		}
		count+=0.5;
		m = m-n;
	}

	return count;
}

void analysis(int ch){
	FILE *f1,*f2;
	int m,n;
	float maxcount,mincount,count;
	for(int i = 10;i<=100;i+=10){
		//f1 = fopen("data.txt","a");
		
		maxcount = 0;
		mincount = 10000;
		for(int j = 2;j<=i;j++){
			for(int k = 2;k<=i;k++){
				m = j;
				n = k;
				count = 0;
				switch(ch){
					case 1:
						count = euclid(m,n);
						break;
					case 2:
						count = consec(m,n);
						break;
					case 3:
						count = me(m,n);
						break;
				}
			}
			maxcount = count>maxcount?count:maxcount;
			mincount = count<mincount?count:mincount;  
		}

		switch(ch){
			case 1:
				f1 = fopen("euclidB.txt","a");
				f2 = fopen("euclidW.txt","a");
				break;
			case 2:
				f1 = fopen("consecB.txt","a");
				f2 = fopen("consecW.txt","a");
				break;
			case 3:
				f1 = fopen("meB.txt","a");
				f2 = fopen("meW.txt","a");
				break;
		}

		fprintf(f1,"%d %f\n",i,mincount);
		fprintf(f2,"%d %f\n",i,maxcount);

		fclose(f1);
		fclose(f2);
	}
}

int main(){
	int ch;
	while(1){
		printf("1.Euclid\n2.Consec Int\n3.Modified euclid\n");
			scanf("%d",&ch);

			switch(ch){
				case 1:
				case 2:
				case 3:
					analysis(ch);break;
				default: exit(1);
			}
	}
}