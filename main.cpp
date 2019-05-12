#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define maxn 100010
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);

ll n,m;
int main()
{
    cin>>n>>m;
    if (n%2==1 && m%2==0&&n<m) {cout<<2; return 0;}
    else if (n%2 && m%2) cout<<1;
    else cout<<0;
    return 0;
}