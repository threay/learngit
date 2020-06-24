#include<stdio.h>
#include<math.h>
const double h=0.1;/*定义常变量步长h*/ 
const int n=11;/*定义根据步长计算的点的个数常变量n*/
/*
函数名称：f
描述：计算f(x,y)=2xy^(-2)/3的值
参数：对应端点的x和y值
返回值：f(x,y)=2xy^(-2)/3的值f 
*/
double f(double x,double y){
	double f;
	f=2*x*pow(y,-2)/3; 
	return f;
}
int main(void){
	double x[n],y[n],k[4];
	int i;
	x[0]=0;y[0]=1;/*初值y(0)=1*/ 
	
	/*以下为欧拉方法计算过程，依公式进行*/
	for(i=1;i<n;i++){
	y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
	x[i]=x[i-1]+h;	
	}
	printf("各点欧拉方法计算值分别为:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]); 
	printf("\n");
	
	/*以下为改进的欧拉方法计算过程，依公式进行*/
	for(i=1;i<n;i++){
	y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
	y[i]=y[i-1]+h*(f(x[i-1],y[i-1])+f(x[i],y[i]))/2; 	
	}
	printf("各点改进欧拉方法计算值分别为:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]);
	printf("\n");
	
	/*以下为经典R-K方法计算过程，依公式进行*/
	for(i=1;i<n;i++){
	k[0]=f(x[i-1],y[i-1]);
	k[1]=f(x[i-1]+h/2,y[i-1]+h*k[0]/2);
	k[2]=f(x[i-1]+h/2,y[i-1]+h*k[1]/2);
	k[3]=f(x[i-1]+h,y[i-1]+h*k[2]);
	y[i]=y[i-1]+h*(k[0]+2*k[1]+2*k[2]+k[3])/6;
	}
	printf("\n");
	printf("各点经典R-K方法计算值分别为:\n");
	for(i=0;i<n;i++)
	printf("X%d=%lf,y(X%d)=%lf\n",i,x[i],i,y[i]); 
	
	return 0;
}
