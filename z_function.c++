#include<bits/stdc++.h> 
using namespace std; 

// Z array stores the max length prefix that
// matches with substring starting at index i 
vector<int> z_func(string s)
{
	int n = s.size(); 
	vector<int>z(n,0); 
	int l = 0, r = 0;

	// Iterate to create the Z function 
	for(int i = 1;i < n;i++)
	{

		// Copy till previous 
		// is does not exceeds range 
		if(i<=r)
			z[i] = min(r-i+1,z[i-l]); 
        
        // Re-start comparison 
		while(i + z[i] < n && s[z[i]] == s[i+z[i]])
		{
			z[i]++;
		}

		if(i+z[i]-1>r)
		{
			l = i; 
			r = i+z[i]-1; 
		}
	}
	return z;
}

int main()
{
	string s = "ddcdddc";
	vector<int> z = z_func(s); 
	for(auto it:z)
		cout << it << " ";
}