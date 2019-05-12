#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000]={0};

void tree(int low,int high,int pos)
{
    if(low==high)
    {
        b[pos]=a[high];
        return ;
    }
    int mid=(high+low)/2;
    
    tree(low,mid,2*pos+1);
    tree(mid+1,high,2*pos+2);
    b[pos]=b[2*pos+1]+b[2*pos+2];
    
}

int sum(int s, int e, int low, int high, int pos)
{
    
    if (low<= s && high >= e)
        return b[pos];
    if (e < low || s > high)
        return 0;
    int mid = (s+e)/2;
    return (sum( s, mid, low, high, 2*pos+1) + sum( mid+1, e, low,high, 2*pos+2));
}
void update(int low,int high,int i,int diff,int pos)
{
    if(i<low or i>high) return;
    b[pos]+=diff;
    if(low!=high)
    {
        int mid=(low+high)/2;
        update(low,mid,i,diff,2*pos+1);
        update(mid+1,high,i,diff,2*pos+2);
    }
}
 
int main()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
      cin >>a[i];
  }
  
  tree(0,n-1,0);
  cout << sum(0,n-1,2,3,0)<<endl;
  int d=1;
  update(0,n-1,2,a[2]-d,0);
   cout << sum(0,n-1,2,3,0);
  
  
}