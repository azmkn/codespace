//miller-rabin.cpp
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
ll n;

// 定数
double A = 1.0, half_e = 2.718281828459045 / 2;

// ランダムな整数を生成する関数
int randint(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

// 累乗を計算する関数 (a^b % c)
ll sisuu(ll a, ll b, ll c) {
    ll pro = 1;
    for (ll i = 0; i < b; i++) {
        pro *= a;
        pro %= c;
    }
    return pro;
}

// Miller-Rabin法による素数判定の補助関数
bool check(ll a, ll d, ll n, ll s) {
    ll x = sisuu(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (int i = 0; i < s - 1; i++) {
        x = (x * x) % n;
        if (x == n - 1) return true;
    }
    return false;
}

// 素数判定関数 (Miller-Rabin法を使用)
bool isprime(ll n) {
    if (n < 2) {
        return false;
    } else if (n < 4) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    ll s = 0, d = n - 1;
  
    // dが奇数になるまでdを2で割る
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // 初期の試験用基数
    vector<ll> l = {2, 3, 5, 7, 11, 13, 17};
    for (const long long& a : l) {
        if (a % n == 0) continue;
        if (!check(a, d, n, s)) return false;
    }
    return true;
}

// Li関数
double Li(ll x) {
    double result = x / (log(x) - A);
    return result;
}

// Gauss関数
vector<double> gauss(ll try_n) {
    vector<double> lis;
    for (ll i = 1; i <= try_n; i++) {
        if (i < 4) {
            lis.push_back(0.0);
        } else {
            double y = Li(i) * half_e;
            lis.push_back(y);
        }
    }
    return lis;
}

// Rho関数
vector<double> ro(ll try_n) {
    vector<double> primes;
    ll l = 0;

    for (ll i = 1; i <= try_n; i++) {
        if (isprime(i * i + 1)) {
            l++;
        }

        // log計算を基にした処理
        primes.push_back(l * ((log(i) - 1.0) / (log(i) * log(i))) / ((log(i * i + 1) - 1.0) / (log(i * i + 1) * log(i * i + 1))));
    }

    return primes;
}

// Pi関数 (素数の累積和)
vector<double> pi(ll try_n) {
    vector<double> primes;
    double l = 0;

    for (ll i = 1; i <= try_n; i++) {
        if (isprime(i)) {
            l += 1;
        }
        primes.push_back(l);
    }

    return primes;
}

// メイン関数
int main() {
    // 入力の受け取り
    cin >> n;
    cout << fixed << setprecision(15) << endl;

    // 実行時間計測の開始
    auto start = high_resolution_clock::now();

    // RO, PI, Gaussの計算
    vector<double> RO = ro(n);
    vector<double> PI = pi(n);
    transform(PI.begin(), PI.end(), PI.begin(), [](double y) { return y * half_e; });
    vector<double> G = gauss(n);

    // 結果の表示
    for (int i = 0; i < n; i++) {
        cout << PI[i] - RO[i] << endl;
    }

    // 実行時間計測の終了
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;
}
//miller-rabin.cpp