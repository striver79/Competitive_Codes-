typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];
int par[N],sub[N],level[N],ans[N];
int DP[LOGN][N];
int n,m;


// par[] array gives the root of the node 
// in the centroid tree 


/*Using centroid Decomposition of a tree */


/*----------- Pre-Processing ------------*/
void dfs0(int u)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=DP[0][u])
		{
			DP[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;
	DP[0][0]=0;
	dfs0(0);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b=DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}



/*-----------------Decomposition Part--------------------------*/
int nn;

// Function to run dfs 
// and count the nodes under that node
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}

// Function to decompose the tree 
// using dfs such that eevry node can be the 
// centroid of the given subtree
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}

// Function to decompose the tree 
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	par[centroid]=p;
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
	g[centroid].clear();
}