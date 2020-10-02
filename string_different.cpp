#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <fstream>
    #include <unordered_map>
    #include <unordered_set>
    #include <cmath>
#else

    #include <bits/stdc++.h>

#endif 

#define ull unsigned long long
#define ll long long
#define ld long double
#define forr(i,k,n) for(ll i=k;i<n;i++)
#define rev(i,k) for(ll i=k;i>=0;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll>

#define vpll vector<pair<ll,ll>>
#define fi first
#define se second
#define pll pair<ll,ll>
#define MX LLONG_MAX
#define MN LLONG_MIN
#define MOD 1000000007
using namespace std;
ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
bool contains(ll *arr,ll x,ll n){
    forr(i,0,n){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
ll *subtractArr(ll *b,ll *a,ll n){
    ll *res=(ll *) malloc(sizeof(ll)*n);
    rev(i,n-1){
        if(b[i]<a[i]){
            b[i]+=26;
            ll j=i-1;
            while(b[j]<=a[j]){
                b[j]+=25;
                j--;
            }
            b[j]--;
        }
        res[i]=b[i]-a[i];
    }
    return res;
}
ll solve(string b,string a){
    ll ans = 0;
    ll aArr[a.length()],bArr[a.length()];
    forr(i,0,a.length()){
        aArr[i]=a[i]-'a';
        bArr[i]=b[i]-'a';
    }
    ll tmp[a.length()];
    forr(i,0,a.length()){
        tmp[i]=0;
    }
    tmp[a.length()-1]=1;
    ll *res = subtractArr(bArr,aArr,a.length());
    res = subtractArr(res,tmp,a.length());
    rev(i,a.length()-1){
        ans=(ans%MOD+(powermodm(26,a.length()-i-1,MOD)*(res[i]%MOD))%MOD)%MOD;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<solve(b,a)<<'\n';
    }
    return 0;
}
