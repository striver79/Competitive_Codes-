#include<bits/stdc++.h>
using namespace std; 
#define int long long 
int hashh[100]; 
int pr = 27; 
int M = 1e9+7; 

// Palindrome check for prefix 
void Prefix_palincheck_byHashing(string s)
{
	int n = s.size(); 

	for(int i = 1;i<n-1;i++)
	hashh[i] = (hashh[i-1] * pr)%M;

	int val1 = 0, val2 = 0;
    
	for(int i = 0;i<n;i++)
	{
		val1 = (val1 * pr + s[i])%M; 
		val2 = (val2 + s[i] * hashh[i])%M; 
		if(val1 == val2)
		{
		    cout << "Prefix till i is palindrome"; 
		}
	}
}

// Function to find the occurrences of pattern 
// in the string 
void rabin_karp(string s, string t)
{
	int md = 1e9 + 9;
	int p = 31; 
	int n = s.size(); 
	int m = t.size(); 
	int poww[n]; 
	poww[0] = 1; 
	for(int i = 1;i<n;i++)
		poww[i] = (poww[i-1]*p)%md; 

	int hash_value = 0;
	for(int i = 0; i < m; i++)
	{
		hash_value = (hash_value + (t[i]-'a'+1)*poww[i])%md;  
	}

	int string_hash[n+1]; 
	memset(string_hash,0,sizeof string_hash); 


	for(int i = 0;i<n;i++)
	{
		string_hash[i+1] = (string_hash[i] + (s[i]-'a'+1)*poww[i])%md; 
		
	}

    // Stores all index where the 
    // string T occurs in S
	vector<int>index_jahan_hai; 

	for(int i = 0;i<=n-m;i++)
	{
		int value = (string_hash[i+m]+md-string_hash[i])%md;
		int temp = (hash_value * poww[i])%md;
		if(value == temp)
			index_jahan_hai.push_back(i);
	}
    
    // Prints all the index where it starts 
    // from 
	for(auto it:index_jahan_hai)
		cout << it << " ";

}

signed main()
{
	string s, t; 
	s = "arajaarajjraj";
	t = "raj";
	rabin_karp(s,t);
	return 0;
}