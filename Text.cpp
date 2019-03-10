#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int t[100005][15];//表示T秒时馅饼落在对应坐标的位置
int main()
{
    int N,x,T,mt;//mt是记录最大时间
    while(~scanf("%d",&N)&&N){//馅饼的总个数
        mt=0;
        memset(t,0,sizeof(t));//初始化数组t
        for(int i=0;i<N;i++){
            cin>>x>>T;
            t[T][x]++;//表示相同时间掉的饼数
            mt=max(mt,T);//取最大的时间
        }
        for(int i=mt-1;i>=0;i--){//从底层开始往上走(数塔)
            for(int j=0;j<=10;j++){//枚举坐标位置
                if(j==0)t[i][j]=max(t[i+1][j],t[i+1][j+1])+t[i][j];//只需枚举中右
                else t[i][j]=max(max(t[i+1][j],t[i+1][j+1]),t[i+1][j-1])+t[i][j];//比较下一层的三个位置的落饼数取最大
            }
        }
        cout<<t[0][5]<<endl;//输出最上层横坐标T=0最中间的结果
    }
    return 0;
}