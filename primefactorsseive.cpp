void SOF()
{
    SPF[1] = 1;
    for (int i=2; i<N; i++)
        SPF[i] = i;
    for (int i=4; i<N; i+=2)
        SPF[i] = 2;
 
    for (int i=3; i*i<N; i++)
        {
        if (SPF[i] == i)
            {
            for (int j=i*i; j<N; j+=i)
                if (SPF[j]==j)
                   SPF[j] = i;
            }
        }
}