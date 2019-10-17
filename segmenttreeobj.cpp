int n;
int a[N], b[N]; 

// 
struct SegTree
{
     int N;
     vector<int> st;
    
     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
     }

     

     void Build(int node, int L, int R)
     {
          if (L == R)
          {
               st[node] = b[L];
               return;
          }
          int M = (L + R) / 2;
          Build(node * 2, L, M);
          Build(node * 2 + 1, M + 1, R);
          st[node] = max(st[node * 2], st[node * 2 + 1]);
     }

     void Update(int node, int L, int R, int pos, int val)
     {
          if (L == R)
          {
               st[node] += val;
               return;
          }
          int M = (L + R) / 2;
          if (pos <= M)
               Update(node * 2, L, M, pos, val);
          else
               Update(node * 2 + 1, M + 1, R, pos, val);

          st[node] = max(st[node * 2], st[node * 2 + 1]);
     }

     int Query(int node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return 0;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2; 
          return max(Query(node * 2, L, M, i, j), Query(node * 2 + 1, M + 1, R, i, j));
          
     }

     

     int query(int l, int r) { return Query(1, 1, N, l, r); }

     void update(int pos, int val) { Update(1, 1, N, pos, val); }

     void build() { Build(1, 1, N); }

};
SegTree seg;

void solve()
{
  seg.init(4 * n);
  seg.build();
}
