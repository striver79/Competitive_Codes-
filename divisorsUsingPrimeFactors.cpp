#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long
int main()
{
long long n;
cin >> n;
ll a[n];
ll sum=1ll;
for(ll i=0;i<n;i++)
{
cin >> a[i];
sum=(sum*(a[i]+1))%m;
}

ll sum1=1ll;
//cout << sum1<<endl;
for(int i=0;i<n;i++)
{
sum1=((sum1)%m*((((((sum%m) *500000004)%m)*a[i])%m)+1)%m);
}
cout << sum1;


return 0;
}