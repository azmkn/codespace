#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main(){

  auto start = high_resolution_clock::now();

  ll k, l, r, p, c = 0, cp = 0, m, c4 = 0, c6 = 0, c0 = 0;
  string s = "";

  cin >> l >> r >> k;

  vector<ll> vec(3);
  vec[0] = 0;
  vec[1] = 4;
  vec[2] = 6;

  ll co = l;

  if (l <= 2){

    co = 3;

  }

  if (l <= 2){

    cp = 3 - l;

  }

  for (ll p1 = l / 10; p1 <= r / 10; p1++){

    for(const ll& ao : vec){

      p = p1 * 10 + ao;

      if (p == 0){

        continue;

      }

      ll n = p * p + 1;
      m = n;

      bool torf = true;

      if (n == 1){

        cp++;

        if (ao == 4){

          c4 += 1;

        }else if (ao == 6){

          c6 += 1;

        }else{

          c0 += 1;

        }

        if (p - co >= k){

          if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
          else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;

        }

        cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

        c = 0;
        co = p + 1;

        cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

        continue;

      }

      for (ll i = 5; i <= p ; i += 4){

        if (i == m){

          torf = false;
          cp++;

          if (ao == 4){

            c4 += 1;

          }else if (ao == 6){

            c6 += 1;

          }else{

            c0 += 1;

          }

          if (p - co >= k){

            if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
            else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
  
          }
  
          cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

          c = 0;
          co = p + 1;

          cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

          break;

        }

        if (n % i == 0){

          c++;
          cp = 0;

          torf = false;

          cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

          break;

        }

      }

      if (torf){

        cp++;

        if (ao == 4){

          c4 += 1;

        }else if (ao == 6){

          c6 += 1;

        }else{

          c0 += 1;

        }

        if(p - co >= k){

          if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
          else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;

        }

        cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

        c = 0;
        co = p + 1;

        cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

        continue;

      }

    }

  }

  if(p - co >= k){

    if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
    else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;

  }

  cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

  auto end = high_resolution_clock::now();
  
  auto duration = duration_cast<milliseconds>(end - start).count();
  cout << "Execution Time: " << duration << "ms" << endl;

}