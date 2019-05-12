int power(int a, int b)
{
	if(!b)
		return 1;
	int ans = power(a, b/2);
	ans = (ans*ans)%mod;
	if(b%2)
		ans = (ans*a)%mod;
	return ans;
}
int inv(int x){
    return power(x,mod-2);
}