int n;
int a[N];
int sparse[N][30], sparse1[N][30]; 


// Fills lookup array lookup[][] in bottom up manner. 
void buildSparseTableMin() 
{ 
    // Initialize M for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        sparse[i][0] = a[i]; 
  
    // Compute values from smaller to bigger intervals 
    for (int j = 1; (1 << j) <= n; j++) { 
        // Compute minimum value for all intervals with 
        // size 2^j 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) 
          sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]); 
    } 
} 

// Returns minimum of arr[L..R] 
int querymin(int L, int R) 
{ 
    // Find highest power of 2 that is smaller 
    // than or equal to count of elements in given 
    // range. For [2, 10], j = 3 
    int j = (int)log2(R - L + 1); 
  
    // Compute minimum of last 2^j elements with first 
    // 2^j elements in range. 
    return min(sparse[L][j], sparse[R - (1 << j) + 1][j]); 
}



// Fills lookup array lookup[][] in bottom up manner. 
void buildSparseTableGcd() 
{ 
    // Initialize M for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        sparse1[i][0] = a[i]; 
  
    // Compute values from smaller to bigger intervals 
    for (int j = 1; (1 << j) <= n; j++) { 
        // Compute minimum value for all intervals with 
        // size 2^j 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) 
          sparse1[i][j] = gcd(sparse1[i][j - 1], sparse1[i + (1 << (j - 1))][j - 1]); 
    } 
} 

// Returns minimum of arr[L..R] 
int querygcd(int L, int R) 
{ 
    // Find highest power of 2 that is smaller 
    // than or equal to count of elements in given 
    // range. For [2, 10], j = 3 
    int j = (int)log2(R - L + 1); 
  
    // Compute minimum of last 2^j elements with first 
    // 2^j elements in range. 
    return gcd(sparse1[L][j], sparse1[R - (1 << j) + 1][j]); 
}  