#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pi 3.14159265359
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<vector<ll> > v;
vector<ll> e;
ll gcdExtended(ll a,ll b, ll *x, ll *y);
ll q;
ll lcm(ll a, ll b)  
 {  
 ll gd= __gcd(a,b);
    return (a*b)/gd;  
 }
ll powx(ll a, ll b)
{
	ll result = 1;
	    while (b != 0) {
        result *= a;
        --b;
    }
    return result;
}
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
ll gcd(ll a, ll b)
{
	ll q, r;
	while (b > 0) 
	{
		q = a / b;
		r = a - q * b;
		a = b;
		b = r;
	}
	return a;
}
/*bool isPrime(ll n)
{    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true;      
    if (n%2 == 0 || n%3 == 0) return false;   
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} */
ll generator(ll p, ll q)
{
	char ch, op;
	ll a, k;
	ll mode = 0;
	ll val;
	ll f=0;
	ll ord[50], g[50], H[50];
	bool cyclic = false;
	ll elements[100];
	ll order;
	mode = 1;	
	op = '*';
	k = 0;
	for (ll i = 0; i < p; i++)
		if (__gcd(p, i) == 1) //co-prime
			elements[k++] = i;
		//elements[k] = '\0';
	mode = 0;
	order = k;
	//	printf("\nThe order of the group is %d.\n\n", order);
	for (ll i = 0; i < k; i++) 
	{
		ll temp = 1;
		while (1) 
		{				
			val = (ll)pow(elements[i], temp);
			if (val % p == 1) 
			{
				ord[i] = temp;
				break;
			}	
			temp++;
		}
		
	}
	ll x = 0, count = 0;
	for (ll i = 0; i < k; i++)
	{
		if (ord[i] == q) 
		{
			return elements[i];
			
			g[x++] = elements[i];
			cyclic = true;
			count++;	
		}
	}	
	cout<<"No subgroup of order "<<q<<" is possible"<<endl;

//	if(f==1) ("No subgroup of Z*%d is a cyclic group.\n",p);
	return 0;
}
void generate_secrets(ll t, ll w, ll s, ll p, ll q, ll g, ll h)
{
    ll a[t]; // coffecient of variables x^0 , x^1 , x^2 .... in f(x)
    a[0]=s;
    ll a1[t]; // coffecient of variables x^0 , x^1 , x^2 .... in g(x)
    ll s1; 
    //a1[0] =std::rand() % q  ;
    ll i;
    for(i=0;i<t;i++)
    {
        a[i]=rand()%10;
    }
    for(i=0;i<t;i++)
    {
        a1[i]=rand()%10;
    }
    
    ll ans=0,ans2=0;
    //cout<<"here\n";
    v.resize(w);
    for(i=1;i<=w;i++)
    {
    	//cout << i ;
        ll j;
        ans = 0;
        ans2 = 0;
        for(j=0;j<t;j++)
        {
            ans=(ans+(a[j]*powx(i,j)))%p;
            ans2=(ans2+(a1[j]*powx(i,j)))%p;
        }
        cout<<i<<" "<<ans<<endl;
        v[i-1].push_back(i);
        v[i-1].push_back(ans);
        v[i-1].push_back(ans2);
        
    }
    //cout<<"reached\n";
    for(i=0;i<t;i++)
    {
    	e.push_back( (powx(g,a[i]) % p) * (powx(h,a1[i]) % p) % p) ;
	}
    
}
ll gather(vector<ll>index, ll p)
{
    ll y=0;
    ll i,j;
    ll num=0;
    ll den=1;
    ll num1=1,den1=1,k1,k2,lm;
    for(i=0;i<index.size();i++)
    {
        num1=1;
        den1=1;
        num1=num1*v[index[i]][1]; // y1
       // cout<<"num1-"<<num1<<endl;
        //cout<<num<<endl;
        for(j=0;j<index.size();j++)
        {
        	if(j == i)
        		continue;
           // cout<<v[(index[(i+j)%index.size()])].first<<", "<<v[index[i]].first<<endl;
//            num=num*v[(index[(i+j)%index.size()])].first;
//            den=den*( v[(index[(i+j)%index.size()])].first - v[index[i]].first );
			num1 = num1 * v[index[j]][0];
			den1 = den1 * (v[index[j]][0]-v[index[i]][0]);
        }
        cout<<"num1-"<<num1<<endl;
        cout<<"den1-"<<den1<<endl;
        //num1=num1%p;
        //den1=den1%p;
        if(num1!=0 && den1>0){
		ll gd= __gcd(num1,den1);
        num1=num1/gd;
        den1=den1/gd;}
        
		 if(num1==0)
		{
			//cout<<"here\n";
		}
		else if(num==0 && den==1)
        {//cout<<"here1\n";
        	if(den1<0)
		{//cout<<"here\n";
			num1 = num1*(-1);
			den1 = den1*(-1);}
        	num = num1;
        	den = den1;
		}
		else
		{
			//cout<<"here2\n";
			if(den1<0){
			
			num1 = num1*(-1);
			den1 = den1*(-1);}
			if(den == den1) {num = num + num1;
			
			}
        	else{
			lm = lcm(den1,den);
        	k1 = lm/den1;
        	k2 = lm/den;
        	den = den*k2;
        	num = num*k2;
        	den1 = den1*k1;
        	num1 = num1*k1;
        	num = num + num1;
        	den = lm%p;
        	num = num%p;
        }
		}
		//cout<<"num-"<<num<<"den-"<<den<<endl;
    }
        //cout << num << " " << den << endl;
        //cout<<i<<"=> (n,d) "<<num<<","<<den;
        num = num%p;
        den = den%p;
        if(num<0) {
        	num = num+p;
		}
        //cout<<"num-"<<num<<"den-"<<den<<endl;
        ll gd= __gcd(num,den);
        num=num/gd;
        den=den/gd;
        //cout<<",,, modified (n,d) "<<num<<","<<den<<", mod inverse of den ";
        ll boss=modInverse(den,p);
        //cout<<boss<<";";
        boss=(boss*num)%p;
        //cout<<boss<<" hello"; 
        y=(boss)%p;
        
    
    cout<<endl;
    //cout<<y;
    return y;
}

bool checkCommitment(vector<ll> index, ll p, ll g, ll h, ll t)
{
	ll i =0,j=0;
	for(i=0;i<index.size();i++)
	{
		ll lhs = ((powx(g,v[index[i]][1])* powx(h,v[index[i]][2])) % q);
		ll rhs = 1;
		for(j=0;j<t;j++)
		{
			rhs = rhs *(ll) pow(e[j] , pow(index[i],j)) % p;
		}
		if(lhs != rhs)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cout<<"Give me Primes P and Q such that P>Q:"<<endl;
    ll p,q;
    cin>>p>>q;
    ll g = generator(p,q);
    /*while(g==0) {
	cout<<"Enter P and Q again:\n";
	cin>>p>>q;
	g = generator(p,q);
}*/
    
    //q = 2*p +1;
   /* while(isPrime(p) == true && isPrime(q) == true)
    {
    	cout<<"They are not primes.PLease enter primes P and Q"<<endl;
	}*/
    cout<<"Give t,w"<<endl;
    ll t,w;
    cin>>t>>w;
    cout<<"Please tell the secret"<<endl;
    ll s;
    cin>>s;
    ll h=1;
    ll b;
    //ll g=1;
    //ll h=1;
    
   	
   	cout<<"g-"<<g<<endl;
    b =  std::rand() % q+1;
    cout<<"b-"<<b<<endl;
    //ll g =  1 + ( std::rand() % ( (q-1)  + 1 ) );//generator(p,q);
	h  = (ll)pow(g,b) % q;
	cout<<h<<" "<<g<<endl;
	generate_secrets(t, w, s, p, q, g, h);
	cout<<"Shares";
	cout<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Let's Gather Some Folks and Regenerate the secret"<<endl;
    cout<<"Press -1 to exit"<<endl;
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
        cout<<"You selected to move forward with "<<n<<" people"<<endl;
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
        cout<<"Now enter the indexes of people you want to invite(0 based index)"<<endl;
        ll flag=0;
        while(flag==0)
        {
            set<ll>st;
            vector<ll>index;
            for(ll i=0;i<n;i++)
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
            	cout<<"First we check if all the shares are valid\n";
            	bool a=true;//= checkCommitment(index,p,g,h,t);
            	if(a == true) cout<<"Yes the shares are valid\n";
            	else {
				cout<<"They are not valid\n";
				cout<<"enter "<<n<<" people's index again"<<endl;
				continue;
				}
                secret=gather(index ,p);    
                flag=1;
            }
            else
            {
                cout<<"You probably messed up something, enter "<<n<<" people's index again"<<endl;
            }
        }
    cout<<endl;
    cout<<"secret was "<<s<<endl;
    cout<<"***************************************************************"<<endl;
    }
}
