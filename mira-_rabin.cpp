#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;
ll n;

double A = 1.0, half_e = 2.718281828459045/2;

int randint(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

ll sisuu(ll a, ll b, ll c){
  ll pro = 1;
  for(ll i=0;i<b;i++){
    pro*=a;
    pro%=c;
  }
  return pro;
}
bool isprime(ll n){
  if (n < 2){

    return false;

  }else if(n < 4){

    return true;
  
  }else if (n % 2 == 0){

    return false;

  }

  ll s = 0, d = n - 1;
  
  while(d%2==0){

    d/=2;
    s++;

  } 
  for (int i=0;i<5;i++){
    ll a = randint(2,n-2);
    ll x=sisuu(a, d, n);

    if (x==1 or x==n-1){
      continue;
    }
    bool tf;
    for (ll j=0;j<s-1;j++){
      tf=true;
      x=sisuu(x,2,n);
      if (x==n-1){
        tf=false;
        break;
      }
    }
    if (not tf){
      return false;
    }
  }
  return true;

}
double Li(ll x){
  double result=x/(log(x)-A);
  return result;
}
vector<double> gauss(ll try_n){
  vector<double> lis;
  for (ll i=1;i<=try_n;i++){
    if (i<4){
      lis.push_back(0.0);
    }else{
      double y=Li(i)*half_e;
      lis.push_back(y);
    }
  }
  return lis;
}
vector<double> ro(ll try_n){ 
  
  vector<double> primes;
  
  ll l=0;
  
  for (ll i=1;i<=try_n;i++){

    if (isprime(i*i+1)){

      l++;

    }

    primes.push_back(l * ((log(i) - 1.0) / (log(i)*log(i)))/((log(i * i + 1) - 1.0) / (log(i * i + 1)*log(i * i + 1))));

  }
  return primes;
}
vector<ll> pi(ll try_n){
  vector<ll> primes;
  ll l=0;
  for (ll i=1;i<=try_n;i++){
    if (isprime(i)){
      l++;
    }
    primes.push_back(l);
  }
  return primes;
}
int main(){
  cin >> n;
  cout << fixed << setprecision(15) << endl;
  auto start = high_resolution_clock::now();
  vector<double> RO=ro(n);
  //vector<double> PI = std::vector<double>(pi(n).begin(), pi(n).end());
  //transform(PI.begin(), PI.end(), PI.begin(), [](double y) { return y * half_e; });
  vector<double> G=gauss(n);
  for(int i=1;i<=n;i++){
    cout << RO[i] << endl;
  }
  auto end = high_resolution_clock::now();
  
  auto duration = duration_cast<milliseconds>(end - start).count();
  cout << "Execution Time: " << duration << "ms" << endl;
  
}