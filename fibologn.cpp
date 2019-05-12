

void multiply(long long F[2][2], long long M[2][2],int m);

void power(long long F[2][2], int n,int m);

/* function that returns nth Fibonacci number */
long long fib(int n,int m)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1,m);
  return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(long long F[2][2], int n,int m)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2,m);
  multiply(F, F,m);

  if (n%2 != 0)
     multiply(F, M,m);
}

void multiply(long long F[2][2], long long M[2][2],int m)
{
  long long x =  ((F[0][0]*M[0][0]) + F[0][1]*M[1][0])%m;
  long long y =  ((F[0][0]*M[0][1]) + F[0][1]*M[1][1])%m;
  long long z =  ((F[1][0]*M[0][0]) + F[1][1]*M[1][0])%m;
  long long w =  ((F[1][0]*M[0][1]) + F[1][1]*M[1][1])%m;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

/* Driver program to test above function */
int main()
{

      // in Case mod dia hua th m lena wrna remove M har jagah se 
 
      cout<<fib(n,m))%m<<endl;
  
  return 0;
}
