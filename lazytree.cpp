#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
void lt1(int lazy[], int a, int b, int i, int j, int node,int value) {
    
    
  
  	if(lazy[node] != 0) { 
   		
 
		if(a != b) {
			lazy[node*2+1] =(lazy[node*2+1]%m+ lazy[node]%m)%m; 
    			lazy[node*2+2] =(lazy[node*2+2]%m+ lazy[node]%m)%m; 
    			  		lazy[node] = 0; 
		}
 
 
  	}
  
	if(a > b || a > j || b < i)
		return;
    
  	if(a >= i && b <= j) { 
    	
    	lazy[node] =(lazy[node]%m + value%m)%m;
     	return;
	}
 
	lt1(lazy, a, (a+b)/2, i, j, 2*node+1,value); 
	lt1(lazy, 1+(a+b)/2, b, i, j,2*node+2, value); 
}
 
 
int query_tree(int lazy[], int a, int b, int i, int j,int node) {
	
	if(a > b || a > j || b < i) return -1;
 
	if(lazy[node] != 0) { 
		
 
		if(a != b) {
		lazy[node*2+1] =(lazy[node*2+1]%m+ lazy[node]%m)%m; 
    			lazy[node*2+2] =(lazy[node*2+2]%m+ lazy[node]%m)%m;  
					lazy[node] = 0;
		}
 
 
	}
 
	if(a >= i && b <= j) 
		return lazy[node]%m;
 
	int q1 = query_tree(lazy, a, (a+b)/2, i, j,2*node+1); 
	int q2 = query_tree(lazy, 1+(a+b)/2, b, i, j,2*node+2); 
 
	int res = max(q1%m, q2%m); 
	
	return res%m;
}
 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	   
	    int n,q;
	    cin >> n>> q;
	    int i=0;
	    int h=q;
	    
	    int height = (int)(ceil(log2(n))); 
 
        int max_size = 2*(int)pow(2, height)+1 ;         
        
        int ans[max_size] = {0};
        
        int h2 = (int)(ceil(log2(h)));
        
        int maxSize = 2*(int)pow(2, h2) +1;
        
        int lazy[maxSize] = {0};
        int a[h][3];
	    while(q--)
	    {
	     cin >> a[i][0]>>a[i][1]>>a[i][2];   
	     i++;
	    }
	    
	    for(int j=h-1;j>=0;j--)
	    {
	        if (a[j][0]==2)
	        {
	            
	          lt1(lazy,0,h-1,a[j][1]-1,a[j][2]-1,0,query_tree(lazy,0,h-1,j,j,0)+1);
	        }
	        else
	        {
	           lt1(ans,0,n-1,a[j][1]-1,a[j][2]-1,0,query_tree(lazy,0,h-1,j,j,0)+1);   
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        
	      cout << query_tree(ans,0,n-1,i,i,0)<<" ";  
	    }
	    cout << endl;
	    
	}
	return 0;
} 