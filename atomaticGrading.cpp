#include<bits/stdc++.h>
#define int long long
using namespace std;

#define FNAME ""

int rd(int l,int r) {
    return rand()*1ll*rand()%(r-l+1);
} 

void createTestcase() {
    ofstream inp(FName".INP");
    //inp>>;
/*
    sample : 
    int n,m;
    n=rd(1,1000); m=d(1,1000);
    inp<<n<<m;
*/
    inp.close();
}

signed main() {
    srand(NULL);
    for (int iTest = 1; iTest <= 100; ++iTest) {
        createTestcase();
        system(ans".exe");
        system(FName".exe");
        if (system("fc "+ans".OUT " + FName".OUT")) {
            cout<<iTest<<" WA";
            return 0;
        } else {
            cout<<iTest<<" AC\n";
        }
    }
}
