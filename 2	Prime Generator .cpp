#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
 
using namespace std;
 
// Function to generate all prime numbers up to sqrt(n) using Sieve of Eratosthenes
void simpleSieve(int limit, vector<int>& prime) {
    bool isPrime[limit+1];
    memset(isPrime, true, sizeof(isPrime));
 
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
 
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            prime.push_back(p);
        }
    }
}
 
// Function to generate all primes in range [m, n] using the segmented sieve
void segmentedSieve(int m, int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);
 
    bool isPrime[n - m + 1];
    memset(isPrime, true, sizeof(isPrime));
 
    for (int i : prime) {
        int lowLimit = max(i * i, (m + i - 1) / i * i);
        for (int j = lowLimit; j <= n; j += i) {
            isPrime[j - m] = false;
        }
    }
 
    if (m == 1) isPrime[0] = false;
 
    for (int i = 0; i <= n - m; i++) {
        if (isPrime[i]) {
            cout << (i + m) << endl;
        }
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        segmentedSieve(m, n);
        cout << endl;
    }
    return 0;
} 
