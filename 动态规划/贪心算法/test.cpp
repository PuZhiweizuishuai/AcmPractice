#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define maxN 10010

int a[maxN];
using namespace std;
typedef long long ll;
void HeapAdjust ( int i ,int size ){
    int lchild = i<<1 ;
    int rchild = lchild+1 ;
    int max = i ;
    if(i<=(size>>1)){
        if(a[max]>a[lchild] && lchild<=size){ 
            max = lchild ;
        }
        if(a[max]>a[rchild] && rchild<=size){
            max = rchild ;
        }
        if(max!=i){
            swap( a[i] ,a[max]); 
            HeapAdjust ( max , size );
        }
    }
    
} 
void BuildHeap (int size){
    for(int i=(size>>1); i>=1;--i ){
        HeapAdjust( i , size );
    }
    
}
ll work(int size ){
    ll ans=0;
    BuildHeap( size );
    int tmp = size ,temp=0;
    for(int i=1 ; i<=size-1 ; ++i){
        
        temp=a[1];
        a[1]=a[tmp--];
        HeapAdjust ( 1 , tmp ) ;
        a[1]+=temp;
        ans+=a[1];
        HeapAdjust ( 1 , tmp ) ;
        
    }
    return ans;
}
int main() {
    int size ;
    std::ios::sync_with_stdio(false);
    
    cin>> size ;
    for(int i=1 ;i<=size ; ++i ){
        cin >>a[i] ;
    }
    
    cout << work ( size )<<endl;
    return 0;
}