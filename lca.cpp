// Stores the parent of every node 
long par[2*1e5+10][20];

// Stores the dept 
long dep[2*1e5+10];

// Stores the tree 
vector<long> g[2*1e5+10];

// Function to pre-compute DFS
void dfs(long v, long p = 1)
{

    // First parent
    par[v][0] = p;

    // Finds the parent at 2^i
    for (int i = 1; i <= l; i++)
        par[v][i] = par[par[v][i - 1]][i - 1];

    // Call DFS function
    for (int i = 0; i < g[v].size(); i++) {
        long to = g[v][i];

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
long lca(long a, long b)
{

    // If a is higher than b then swap them 
    // Tree me a niche rahegi and b upar hamesha 
    if (dep[a] < dep[b])
        swap(a, b);

    // Make both of them at equal height 
    for (int i = l; i >= 0; i--)
    {
        if (dep[a] - (1 << i) >= dep[b])
            a = par[a][i];
    }

    // Now traverse till up 
    // till we donot get parent same 
    for (int i = l; i >= 0; --i)
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
long solve(long a, long b)
{
    if (a == b)
        return 0;

    if (dep[a] < dep[b])
        swap(a, b);

    // Find lca
    long q = lca(a, b);
    long dist = dep[a] + dep[b] - 2 * dep[q];
    return dist;
}