#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pi 3.14159265359
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<pair<ll,ll>> v;

ll gcdExtended(ll a,ll b, ll *x, ll *y);

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
    { cout << "Inverse doesn't exist"; 
        return -1;
    }
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        //cout << "Modular multiplicative inverse is " << res; 
        return res;
    } 
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a,ll b,ll *x,ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

void generate_secrets(ll t, ll w, ll s, ll p)
{
    ll a[t]; // coffecient of variables x^0 , x^1 , x^2 ....
    a[0]=s;
    ll i;
    for(i=1;i<t;i++)
    {
        a[i]=rand()%10;
    }
    
    ll ans=0;
    for(i=1;i<=w;i++)
    {
        ll j;
        ll ans=0;
        for(j=0;j<t;j++)
        {
            ans=((ll)(ans+(a[j]*pow(i,j))))%p;
        }
        v.push_back(make_pair(i,ans));
    }
    
}

ll gather(vector<ll>index, ll p)
{
    ll y=0;
    ll i,j;
    for(i=0;i<index.size();i++)
    {
        ll num=1;
        ll den=1;
        num=v[index[i]].second; // y1
        //cout<<num<<endl;
        for(j=1;j<index.size();j++)
        {
           // cout<<v[(index[(i+j)%index.size()])].first<<", "<<v[index[i]].first<<endl;
            num=num*v[(index[(i+j)%index.size()])].first;
            den=den*( v[(index[(i+j)%index.size()])].first - v[index[i]].first );
        }
        num=num%p;
        den=den%p;
        //cout<<i<<"=> (n,d) "<<num<<","<<den;
        ll gd= __gcd(num,den);
        num=num/gd;
        den=den/gd;
        //cout<<",,, modified (n,d) "<<num<<","<<den<<", mod inverse of den ";
        ll boss=modInverse(den,p);
        //cout<<boss<<";";
        boss=(boss*num)%p;
        cout<<boss<<" "; 
        y=y+boss;
        
    }
    cout<<endl;
    //cout<<y;
    return y;
}

int main() {
    cout<<"Give me Prime P"<<endl;
    ll p;
    cin>>p;
    cout<<"Give t,w"<<endl;
    ll t,w;
    cin>>t>>w;
    cout<<"Please tell the secret"<<endl;
    ll s;
    cin>>s;
    ll i;
    generate_secrets(t,w,s,p);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    //cout<<modInverse(3,11);
    cout<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Let's Gather Some Folks and Regenerate the secret"<<endl;
    cout<<"Press -1 to exit";
    ll n;
    
    cout<<"Select the number of people which are going to gather?"<<endl;
    n=1;
    while(n!=-1)
    {
        cin>>n;
        if(n==-1)
        {
            cout<<"GoodBye, Take Care!!"<<endl;
            break;
        }
        cout<<"You seleceted to move forward with "<<n<<" people"<<endl;
        ll secret;
        while(n<t)
        {
            cout<<"We need to gather atleat "<<t<<" people to regenerate the secret"<<endl;
            cin>>n;
            if(n<t)
            {
                continue;
            }
        }
        // now n>=t
        cout<<"Now enter the index of person you want to invite(0 based index)"<<endl;
        ll flag=0;
        while(flag==0)
        {
            set<ll>st;
            vector<ll>index;
            for(i=0;i<n;i++)
            {
                ll x;
                cin>>x;
                st.insert(x);
            }
            set<ll>::iterator it;
            for(it=st.begin();it!=st.end();it++)
            {
                index.push_back(*it);
            }
            if(index.size()>=t)
            {
                secret=gather(index ,p);    
                flag=1;
            }
            else
            {
                cout<<"You probable messed up something, enter "<<n<<" people's index again"<<endl;
            }
        }
    cout<<endl;
    cout<<"secret was "<<secret<<endl;
    cout<<"***************************************************************"<<endl;
    }
    return 0;
}