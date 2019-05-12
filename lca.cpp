// Taken from striver_79's github repo 
// Stores the parent of every node 
int par[N][21];

// Stores the dept 
int dep[N];

// Stores the tree 
vector<int> g[N];

// Function to pre-compute DFS
void dfs(int v, int p = 0)
{

    // First parent
    par[v][0] = p;

    // Finds the parent at 2^i
    for (int i = 1; i <= 20; i++)
        par[v][i] = par[par[v][i - 1]][i - 1];

    // Call DFS function
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        // Already visited
        if (to == p)
            continue;
        
        // Find the depth 
        dep[to] = dep[v] + 1;
        
        // Call the Dfs Function 
        dfs(to, v);
    }
}




// Function to find the lca of a and b 
int lca(int a, int b)
{

    // If a is higher than b then swap them 
    // Tree me a niche rahegi and b upar hamesha 
    if (dep[a] < dep[b])
        swap(a, b);

    // Make both of them at equal height 
    for (int i = 20; i >= 0; i--)
    {
        if (dep[a] - (1 << i) >= dep[b])
            a = par[a][i];
    }

    // Now traverse till up 
    // till we donot get parent same 
    for (int i = 20; i >= 0; --i)
    {
        if (par[a][i] != par[b][i])
        {
            a = par[a][i],
            b = par[b][i];
        }
    }
    
    // Till now not same 
    if (a != b)
        a = par[a][0];

    return a;
}

// Function to find the distance between a and b 
int solve(int a, int b)
{
    if (a == b)
        return 0;

    if (dep[a] < dep[b])
        swap(a, b);

    // Find lca
    int q = lca(a, b);
    int dist = dep[a] + dep[b] - 2 * dep[q];
    return dist;
}
