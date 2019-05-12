// Fenwict tree 
// used to calculate prefix sum or suffix with updates 
// If we want to update of any index then we pass (ind+1,val) 
// If we want to get sum till any index then we call (ind+1) 
// Basically used in problems where we need to calculate the pairs like
// a[i]>a[j] count and etc etc
 

// Initially fenwick is fen[maxsize] = 0; 


// Function to update any index 
int update(int ind, int val)
{
	for(int i = ind;i<=maxsize; i+= i & -i)
		fen[i] += val;
}

// Function to get the prefix sum or suffix sum 
int sum(int ind)
{
	int ans = 0; 
	for(int i = ind; i > 0 ; i-= i& -i)
		ans +=fen[i]; 

	return ans; 
}
