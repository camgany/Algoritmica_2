#include<bits/stdc++.h>
#define     pb                      push_back
#define     mkp                     make_pair
#define     inf                     1000000007
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     fr                      first
#define     sc                      second
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     pi                      3.141592653589793
#define     gc                      getchar
 
using       namespace               std;
 
typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;
 
//_________________________________________
 
ll n;
const int N = 1e5 + 10;
ll a[ N << 2 ];
ll place[ N << 2 ];
struct tree{
    ll firstMax, secMax , sum;
};
tree t[ N << 2 ];
tree merge(tree foo, tree bar){
    vi v;
    v.pb(foo.firstMax);
    v.pb(bar.firstMax);
    v.pb(bar.secMax);
    v.pb(foo.secMax);
    sort(v.begin(), v.end());
    tree ret;
    ret.firstMax = v[3];
    ret.secMax = v[2];
    ret.sum = v[3] + v[2];
    return ret;
}
 
 
void constructSegmentTree(ll low, ll high, ll sgmnt){
    if(low == high){
        t[sgmnt].firstMax = a[low];
        t[sgmnt].secMax = 0;
        t[sgmnt].sum = a[low];
        place[low] = sgmnt;
        return;
    }
 
    int mid = low + (high - low) / 2;
    constructSegmentTree(low, mid, sgmnt*2+1);
    constructSegmentTree(mid+1, high, sgmnt*2+2);
    tree foo = t[sgmnt*2+1];
    tree bar = t[sgmnt*2+2];
    t[sgmnt] = merge(foo, bar);
}
 
void update(ll low, ll high, ll index, ll sgmnt){
    ll v = place[index];
    t[v].firstMax = t[v].sum = a[index];
    if(v & 1)
        v /= 2;
    else{
        v = v/2-1;
    }
    while(v >= 0){
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
        if(v & 1)
           v /= 2;
        else{
            v = v/2-1;
        }
    }
}
 
 
tree query(ll low, ll high, ll x, ll y, ll sgmnt){
    if (x <= low && y >= high)
        return t[sgmnt];
    if(low > y || high < x){
        tree temp;
        temp.firstMax = temp.secMax = 0;
        temp.sum = 0;
        return temp;
    }
    int mid = low + (high - low) / 2;
    if(y <= mid){
        return query(low, mid, x, y, sgmnt * 2 + 1);
    }
    else if(x > mid){
        return query(mid+1, high, x, y, sgmnt * 2 + 2);
    }else{
        return merge(query(low, mid, x, y, sgmnt * 2 + 1), query(mid+1, high, x, y, sgmnt * 2 + 2));
    }
}
 
void solve(){
    cin >> n;
    ll i;
    rep(i,n) {
        cin >> a[i];
    }
    constructSegmentTree(0, n-1, 0);
    ll q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        if(c == 'Q'){
            // Query
            ll x, y;
            cin >> x >> y;
            tree foo = query(0, n-1, x-1, y-1, 0);
            cout << foo.sum << endl;
        }else{
            // UPDATE A VALUE
            ll index, value;
            cin >> index >> value;
            index --;
            a[index] = value;
            update(0, n-1, index, 0);
        }
    }
 
}
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    solve();
}