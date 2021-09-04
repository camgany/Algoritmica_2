#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables

using namespace std; 

// Variables static
const int MAX_N=100005;
int a[MAX_N];
int gcd(int a,int b)
{
    {
        int t;
    while(b){
        a=a%b;
         t=a;
         a=b;
         b=t;
     }
    return a;
    }
}

struct node{
    int _gcd;
    int _count;
     node(){
        _gcd=0;
        _count=0;
    }
     node(int val){
        _gcd=val;
        _count=1;
    }
    void mergee( node left,node right){
          _count=0;
       _gcd=gcd(left._gcd,right._gcd);
       if(_gcd==left._gcd)
       {
           _count+=left._count;
       }
       if(_gcd==right._gcd)
       {
           _count+=right._count;
       }

    }
    //int sum, mult , min, max;
}nod[4*MAX_N];
void build(int inicio, int final, int nodoActual)//low,high,nodoActual
{
    if(inicio>final){
         return;
    }
    
    if(inicio == final){
        nod[nodoActual]=node(a[inicio]);
        return;
    }
    int mid=inicio+final>>1;
    build(inicio,mid,2*nodoActual+1);
    build(mid+1,final,2*nodoActual+2);
    nod[nodoActual].mergee(nod[2*nodoActual+1],nod[2*nodoActual+2]);
}
 
node query(int inicio, int final, int izquierda, int derecha,int nodoActual)//int low,int high,int lq,int hq,int nodoActual
{
    if(inicio>final||inicio>derecha||final<izquierda){
         return node();
    }
    if(izquierda<=inicio && final<=derecha)     {        
         return nod[nodoActual];    
          }     
          int mid=inicio+final>>1;
    node temp=node();
    temp.mergee(query(inicio,mid,izquierda,derecha,2*nodoActual+1),query(mid+1,final,izquierda,derecha,2*nodoActual+2));
    return temp;
 
}
 
int main() {
    input;
    output;
    int n;
    scanf("%d",&n);
    register int i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    build(0,n-1,0);
    int t,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",(r-l+1)-query(0,n-1,l-1,r-1,0)._count);
    }
 
    return 0;
}
