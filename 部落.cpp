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
	int pre[MAXSIZE];   //����ÿ��Ԫ�ص�ǰ���ڵ��±�
	for(int i=0;i<MAXSIZE;i++){
		pre[i]=-1;               //�����ʼ��
	}
	
	int N=0;
	scanf("%d",&N);                  //СȦ�Ӹ���
	int n=0;                  //ÿ��СȦ������
	int count=0;              //��¼������
	int num=0;                //��¼������
	
	
	for(int i=0;i<N;i++){
		scanf("%d",&n); 
		int temp[n];                          //��¼СȦ�ӵ�ÿ���˱��
		for(int j=0;j<n;j++){
			scanf("%d",&temp[j]); 
			if(temp[j]>count)count=temp[j];   //�ҳ������
		}
		
		for(int k=0;k<n-1;k++){
		   Union(temp[k],temp[k+1],pre);        //�ϲ�
		}
		
	}
	for(int i=1;i<=count;i++){
		if(pre[i]<=0)num++;                   //���㲿������������ֻ�д���Ԫ��ǰ���Ǹ���������ж��ٸ������ж��ٲ���
	}
	printf("%d %d\n",count,num);
	
	int w=0;
	scanf("%d",&w); 
	for(int i=0;i<w;i++){                       //�ж��Ƿ�Ϊͬһ����
		int m=0,n=0;
		scanf("%d%d",&m,&n); 
		if(find(m,pre)==find(n,pre))printf("Y\n");
		else printf("N\n");
	}
	
	return 0;
	
}
