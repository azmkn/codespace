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
bool check(ll a,ll d,ll n,ll s){
  ll x=sisuu(a,d,n);
  if (x==1 or x==n-1)return true;
  for (int i=0;i<s-1;i++){
    x=(x*x)%n;
    if (x==n-1)return true;
  }
  return false;
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

  vector<ll> l;
  l.push_back(2);
  l.push_back(3);
  l.push_back(5);
  l.push_back(7);
  l.push_back(11);
  l.push_back(13);
  l.push_back(17);
  for (const long long& a:l){
    if (a%n==0)continue;
    if (not check(a,d,n,s))return false;
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
vector<double> pi(ll try_n){
  vector<double> primes;

  double l=0;
  for (ll i=1;i<=try_n;i++){
    if (isprime(i)){
      l+=1;
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
  vector<double> PI = pi(n);
  transform(PI.begin(), PI.end(), PI.begin(), [](double y) { return y * half_e; });
  vector<double> G=gauss(n);
  for(int i=1;i<=n;i++){
    cout << PI[i]-RO[i] << endl;
  }
  auto end = high_resolution_clock::now();
  
  auto duration = duration_cast<milliseconds>(end - start).count();
  cout << "Execution Time: " << duration << "ms" << endl;
  
}