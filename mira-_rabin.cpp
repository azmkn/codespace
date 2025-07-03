#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;
def is_prime(n, k=5):
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    s = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        s += 1

    for _ in range(k):
        a = random.randint(2, n - 2)
        x = pow(a, d, n)

        if x == 1 or x == n - 1:
            continue
        for _ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False

    return True
    
void isprime(ll n, )

ll ro(ll try_n){ 
  
  vector<ll> primes;
  
  ll l=0;
  
  for (int i=0;i<try_n;i++){

    if (isprime(i*i+1)){

      l++;

    }

    primes.push_back(l * ((log(i) - 1) / (log(i)*log(i)))/((log(i * i + 1) - 1) / (log(i * i + 1)*log(i * i + 1))));

  }
  return primes;
}
int main(){
  ll n;
  double A = 1.0, e = 2.718281828459045/2;
  auto end = high_resolution_clock::now();
  
  auto duration = duration_cast<milliseconds>(end - start).count();
  cout << "Execution Time: " << duration << "ms" << endl;

}