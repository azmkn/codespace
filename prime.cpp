#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main(){

  auto start = high_resolution_clock::now();
  
  ll k, l, r, p, c = 0;
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
  
  for (ll p1 = l / 10; p1 <= r / 10; p1++){
    
    for(const ll& ao:vec){
    
      p = p1 * 10 + ao;
      
      if (p<l || p>r) continue;
      
      if (p == 0){
        continue;
      }
    
      ll n = p * p + 1;
      ll m = n;
    
      bool torf = true;
    
      if (n % 2 == 0){
        continue;
      }
    
      if (n == 1){
    
        if (p - co >= k){
    
          if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
          else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
    
        }
    
        c = 0;
        co = p + 1;
    
        continue;
    
      }
    
      for (ll i = 5; i <= p ; i += 4){
    
        if (i == m){
    
          torf = false;
    
          if (p - co >= k){
      
            if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
            else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
      
          }
      
          c = 0;
          co = p + 1;
      
          break;
      
        }
      
        if (n % i == 0){
      
          c++;
          torf = false;
      
          break;
      
        }
      
      }
      
      if (torf){
      
        if(p - co >= k){
          
          if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
          else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
      
        }
      
        c = 0;
        co = p + 1;
        
        continue;
      
      }
    
    }
    
  }
  
  if(p - co >= k){
  
    if (co != p - 1)cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
    else cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
  
  }
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start).count();
  
  cout << "Execution Time: " << duration << "ms" << endl;

}