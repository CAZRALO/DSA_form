int power(int x, int y, int p) {
	int res=1;
	x%=p;
  // Update x if it is more than or equal to p
	while (y) {
    // If y is odd, multiply x with result
		if (y&1)
			res=(res*x)%p;
		y>>=1;
		x=(x*x)%p;
	}
	return res;
}

bool rabinMiller(int n,int d) {
	int a=2+rand()%(n-4);
  // Compute a^d % n
	int x=power(a,d,n);
	if (x==1 || x==n-1) return true;
	while (d!=n-1) {
		x=(x*x)%n;
		d<<=1;
		if (x==1) return false;
		if (x==n-1) return true;
	}
	return false;
}

bool isPrime(int n,int k) {
  //k can be adjusted to a larger number to ensure the most accurate test possible
	if (n<2 || n==4) return false;
	if (n<=3) return true;
	int d=n-1;
  // Find r such that n = 2^d * r + 1 for some r >= 1
	while (d%2==0) { d>>=1; }
  // Iterate given number of 'k' times
	for (int i=1;i<=k;++i)
		if (!rabinMiller(n,d)) return false;
	return true;

}
