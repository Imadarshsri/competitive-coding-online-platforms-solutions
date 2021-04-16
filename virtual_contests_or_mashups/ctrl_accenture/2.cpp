#include<bits/stdc++.h>
using namespace std;

#define SIZE 2000006
#define MOD 998244353

//Macros
#define endl "\n"
#define fn(x,n) for(; x < n; x++)
#define fo(n) for(auto i = 0; i < n; i++)
#define debug(x) cout<< #x << " = " << (x) << "\n"
#define writeSeq(v, n) for(int i = 0; i < n; i++) cout<<v[i]<<" ";cout<< endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define look(v) cout<< #v << " : "; for(auto x : v) cout<< x << " "; cout<< endl

void SieveOfEratosthenes(vector<long long int>& prime) {
    prime[0] = 0; prime[1] = 0;
    for (long long int p = 2; p * p < SIZE; p++) {
        if(prime[p] == 1) {
            for (long long int i = p * p; i < SIZE; i += p)
                prime[i] = p;
        }
    }
}

// Review for MOD
void populateVectorwithFX(vector<long long int>& v) {
    for (long long int i = 4; i < SIZE; i++) {
        if (v[i] != 1) {
            long long int x = v[i];
            long long int y = i/v[i];
            // f(z) = y * f(x) + x * f(y)
            v[i] = y * v[x] + x * v[y];
        }
    }
}

// Review
void factors(long long int n, vector<long long int>& factorSum, vector<long long int>& fx) {
    for (long long int i = 1; i <= sqrt(n); i++) {
        if (n%i == 0) {
            if (n/i == i)
                factorSum[n] = ((factorSum[n] % MOD) + (fx[i] % MOD)) % MOD;
            else
                factorSum[n] = ((factorSum[n] % MOD) + (fx[i] % MOD) + (fx[n/i] % MOD)) % MOD;
        }
    }
    factorSum[n]--;
}

void prefixSum(vector<long long int>& prime, vector<long long int> &factorSum) {

    cout<<"factor b4 cal. summ. of all divisors: ";
    writeSeq(factorSum, 30);
    for(long long int i = 2; i < SIZE; i++) {
        if (prime[i] != 1)
            factors(i, factorSum, prime);
    }

    cout<<"factor after cal. summ. of all divisors: ";
    writeSeq(factorSum, 30);
    for(long long int i = 2; i < SIZE; i++) {
        factorSum[i] = ((factorSum[i] % MOD) + (factorSum[i - 1] % MOD)) % MOD;
    }
}


long long strange_sum (long long int L, long long int R, vector<long long int>& factorSum) {
    return factorSum[R] - factorSum[L - 1];
}

int main() {

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    vector<long long int> prime(SIZE, 1);
    vector<long long int> factorSum(SIZE, 1);
    factorSum[0] = 0;
    factorSum[1] = 0;
    cout<<"prime1: ";
    writeSeq(prime, 30);
    SieveOfEratosthenes(prime);
    cout<<"prime2: ";
    writeSeq(prime, 30);
    populateVectorwithFX(prime);
    cout<<"prime3: ";
    writeSeq(prime, 30);
    prefixSum(prime, factorSum);
    cout<<"prime4: ";
    writeSeq(prime, 30);
    cout<<"factorSum1: ";
    writeSeq(factorSum, 30);


    long long int T;
    cin >> T;
    for(long long int t_i = 0; t_i < T; t_i++)
    {
        long long int L;
        cin >> L;
        long long int R;
        cin >> R;

        long long out_;
        out_ = strange_sum(L, R, factorSum);
        cout << out_;
        cout << "\n";
    }
}