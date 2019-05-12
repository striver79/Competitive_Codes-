#include<bits/stdc++.h>
using namespace std;
vector<int> get_prefix(string s)
{
    int n = s.size(); 
    vector<int>prefix(n,0); 
    int j = 0; 
    for(int i = 1;i<n;i++)
    {
        int j = prefix[i-1];
        while(s[i]!=s[j] && j>0)
        {
            j = prefix[j-1]; 
        }

        if(s[i]==s[j])
            j++;

        prefix[i] = j; 
    }

    return prefix; 
}

int main() 
{
    string s = "abcdxyaaxyabcd"; 
    vector<int>prefix = get_prefix(s);
    for(auto it:prefix)
        cout << it << " ";
}