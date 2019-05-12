vector<int>prime; 

void process(){
    int N = sqrt(1e10)+5;
    int prm[N+2];
    memset(prm,0,sizeof prm); 
    for(int i=2;i<=N;i++){
        if(!prm[i]){
            prime.pb(i);
            for(int j=i;j<=N;j+=i){
                prm[j]=1;
            }
        }
    }
}
int NOD(int x){
    int temp = x,ret=1;
    for(auto i:prime){
        if(i*i>temp || temp==1)
            break;
        int cnt=0;
        while(temp%i==0) temp/=i,cnt++;
        ret*=(cnt+1);
    }
    if(temp>1)
        ret*=2;
    return ret;
}