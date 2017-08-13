#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const long long MAXN = 47000;
vector<int> all_primes;
vector<int> primes;
bool isprime[MAXN];

void sieve() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    
    for (int i=2; i<MAXN; i++)
        if (isprime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (int j=i+i; j<MAXN; j+=i)
                isprime[j] = false;
                
    all_primes.push_back(2);
    for (int i = 3; i < MAXN; i+=2) {
        if (isprime[i]) {
            all_primes.push_back(i);
        }
    }
}

bool is_prime(int value) {
    if(value < MAXN) {
        return isprime[value];
    }
    for(int i = 0; i < all_primes.size() && all_primes[i] < value; ++i) { //大於質數表範圍的數字 ，使用質數表裡的質數去%以判斷是否為質數 
        if(value % all_primes[i] == 0) return false;
    }
    return true;
}

void calc(int from, int to) {
    primes.clear(); //Removes all elements from the vector,leaving the container with a size of 0.
    for (long long i = from; i <= to; i++) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
}

int main() {
    int from, to;
    sieve();
    while (scanf("%d%d", &from, &to) != EOF) {
        calc(from, to);
        if (primes.size() <= 1) {
            printf("There are no adjacent primes.\n");
            continue;
        }
        int minV = to-from+1;
        int maxV = 0;
        int minfrom, maxfrom, minto, maxto;
        for (int i = 1; i < primes.size(); ++i) {
            if (primes[i] - primes[i-1] < minV) {
                minV = primes[i] - primes[i-1];
                minfrom = primes[i-1];
                minto = primes[i];
            }
            if (primes[i] - primes[i-1] > maxV) {
                maxV = primes[i] - primes[i-1];
                maxfrom = primes[i-1];
                maxto = primes[i];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n",
            minfrom, minto, maxfrom, maxto);
    }
    return 0;
}
