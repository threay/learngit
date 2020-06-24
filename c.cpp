#include<stdio.h>
#include<math.h>
const double h=0.1;/*���峣��������h*/ 
const int n=11;/*������ݲ�������ĵ�ĸ���������n*/
/*
�������ƣ�f
����������f(x,y)=2xy^(-2)/3��ֵ
��������Ӧ�˵��x��yֵ
����ֵ��f(x,y)=2xy^(-2)/3��ֵf 
*/
double f(double x,double y){
	double f;
	f=2*x*pow(y,-2)/3; 
	return f;
}
int main(void){
	double x[n],y[n],k[4];
	int i;
	x[0]=0;y[0]=1;/*��ֵy(0)=1*/ 
	
	/*����Ϊŷ������������̣�����ʽ����*/
	for(i=1;i<n;i++){
	y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
	x[i]=x[i-1]+h;	
	}
	printf("����ŷ����������ֵ�ֱ�Ϊ:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]); 
	printf("\n");
	
	/*����Ϊ�Ľ���ŷ������������̣�����ʽ����*/
	for(i=1;i<n;i++){
	y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
	y[i]=y[i-1]+h*(f(x[i-1],y[i-1])+f(x[i],y[i]))/2; 	
	}
	printf("����Ľ�ŷ����������ֵ�ֱ�Ϊ:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]);
	printf("\n");
	
	/*����Ϊ����R-K����������̣�����ʽ����*/
	for(i=1;i<n;i++){
	k[0]=f(x[i-1],y[i-1]);
	k[1]=f(x[i-1]+h/2,y[i-1]+h*k[0]/2);
	k[2]=f(x[i-1]+h/2,y[i-1]+h*k[1]/2);
	k[3]=f(x[i-1]+h,y[i-1]+h*k[2]);
	y[i]=y[i-1]+h*(k[0]+2*k[1]+2*k[2]+k[3])/6;
	}
	printf("\n");
	printf("���㾭��R-K��������ֵ�ֱ�Ϊ:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]); 
	
	return 0;
}
