// Time complexity : O(ElogV)
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
 
vii *G;   // Graph
vi Dist;  // for storing the distance of every other node from source.
/*==========================================*/
void Dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.first;
            int w = c.second;
            if(Dist[v] > Dist[u]+w){
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}
/*===========================================*/
int main() {
    int N, M, u, v, w, source;  // N-total no of nodes, M-no. of edges, 
    cin >> N >> M;              // u,v and w are the end vertices and the weight associated with an edge
    G = new vii[N+1];
    
    for(int i=0;i<M;++i){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    cin >> source;
    Dijkstra(source,N);
    
    for(int i=0;i<N;i++)
        cout<<Dist[i]<<" ";
    cout<<endl;
    
    return 0;
}