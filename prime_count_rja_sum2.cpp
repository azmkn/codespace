#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main(){

  auto start = high_resolution_clock::now();

  ll l, r, p ,c ,m;
  double sum = 0;
  double e = 2.718281828459045;
  string s = "";
  cin >> c;
  cin >> l >> r;
  cout << fixed << setprecision(15) << endl;
  vector<ll> vec(3);
  vec[0] = 0;
  vec[1] = 4;
  vec[2] = 6;
  for (ll p1 = l / 10; p1 <= r / 10; p1++){

    for(long long ao = 0; ao <= 9; ao++){
      p = p1 * 10 + ao;

      if (l>p || p>r){

        continue;

      }

      sum += ((2500000000*log(p*p+1)-5209150000)/(2500000000*log(p*p+1)*log(p*p+1)-5418300000*log(p*p+1)+2935797489))/((2500000000*log(p)-5209150000)/(2500000000*log(p)*log(p)-5418300000*log(p)+2935797489));
      
      if (not(ao == 4 or ao == 6 or ao == 0)) continue;
      
      ll n = p * p + 1;
      m = n;

      bool torf = true;

      for (ll i = 5; i <= p ; i += 4){

        if (i == m){

          torf = false;
          break;

        }

        if (n % i == 0){

          torf = false;

          break;

        }

      }
      if (torf) c++;
      if (p%1000==0){
        double lo=(e*sum)/(2*(log(p)-1.08366));

        cout << c/lo << endl;
      }

    }

  }

  auto end = high_resolution_clock::now();
  
  auto duration = duration_cast<milliseconds>(end - start).count();
  cout << "Execution Time: " << duration << "ms" << endl;

}