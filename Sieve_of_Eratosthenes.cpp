int Prime[100000],N=0;
bool isPrime[1000005];

void Sieve_of_Eratosthenes(int k) {
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false; isPrime[1]=false;
    for (int i=2;i<=k;++i)
        if (isPrime[i]) {
            ++N;
            Prime[N]=i;
            for (int j=i*i;j<=k;j+=i)
                isPrime[j]=false;
        }
}
