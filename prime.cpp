#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll k,l,r,p;
  string s="";
  cin >> l >> r >> k;
  vector<ll> vec(3);
  vec[0]=0;
  vec[1]=4;
  vec[2]=6;
  ll co=l;
  if (l<=2){
    co=3;
  }
  for (ll p1 = l/10; p1 <= r/10; p1++){
    for(const ll& ao:vec){
      p=p1*10+ao;
      if (p==0){
        continue;
      }
      ll n = p * p + 1;
      ll m = n;
      bool torf = true;
      if (n%2==0){
        continue;
      }
      if (n==1){
        if (p-co>=k){
          if (co!=p-1)cout << co << " ~ " << p-1 << " " << p-co << endl;
          else cout << co << " " << 1 << endl;
        }
        co=p+1;
        continue;
      }
      for (ll i = 5; i <= p ; i += 4){
        if (i == m){
          torf = false;
          if (p-co>=k){
            if (co!=p-1)cout << co << " ~ " << p-1 << " " << p-co << endl;
            else cout << co << " " << 1 << endl;
          }
          co=p+1;
          break;
        }
        if (n % i == 0){
          torf=false;
          break;
        }
      }
      if (torf){
        if(p-co>=k){
            if (co!=p-1)cout << co << " ~ " << p-1 << " " << p-co << endl;
            else cout << co << " " << 1 << endl;
        }
        co=p+1;
        continue;
      }
    }
  }
  if(p-co>=k){
    if (co!=p-1)cout << co << " ~ " << p-1 << " " << p-co << endl;
    else cout << co << " " << 1 << endl;
  }
}
