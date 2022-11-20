#include<stdio.h>

#define MAXSIZE 10001

int find(int x,int *p)
{
	if(p[x]<0)return x;
	else return p[x]=find(p[x],p);
}

void Union(int x,int y,int* p)
{
	int fx=find(x,p);
	int fy=find(y,p);
	
	if(fx!=fy){
		if(p[fx]<=p[fy]){
			p[fx]+=p[fy];
			p[fy]=fx;
		}
		
		else{
			p[fy]+=p[fx];
			p[fx]=fy;
		}
	}
}
int main()
{
	int pre[MAXSIZE];   //储存每个元素的前驱节点下标
	for(int i=0;i<MAXSIZE;i++){
		pre[i]=-1;               //数组初始化
	}
	
	int N=0;
	scanf("%d",&N);                  //小圈子个数
	int n=0;                  //每个小圈子人数
	int count=0;              //记录总人数
	int num=0;                //记录部落数
	
	
	for(int i=0;i<N;i++){
		scanf("%d",&n); 
		int temp[n];                          //记录小圈子的每个人编号
		for(int j=0;j<n;j++){
			scanf("%d",&temp[j]); 
			if(temp[j]>count)count=temp[j];   //找出最大编号
		}
		
		for(int k=0;k<n-1;k++){
		   Union(temp[k],temp[k+1],pre);        //合并
		}
		
	}
	for(int i=1;i<=count;i++){
		if(pre[i]<=0)num++;                   //计算部落数，数组中只有代表元的前驱是负数，因此有多少负数就有多少部落
	}
	printf("%d %d\n",count,num);
	
	int w=0;
	scanf("%d",&w); 
	for(int i=0;i<w;i++){                       //判断是否为同一部落
		int m=0,n=0;
		scanf("%d%d",&m,&n); 
		if(find(m,pre)==find(n,pre))printf("Y\n");
		else printf("N\n");
	}
	
	return 0;
	
}
