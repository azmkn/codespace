//prime_count_1_sum.cpp
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {
    // 開始時間の記録
    auto start = high_resolution_clock::now();

    ll l, r, p, c, m;
    double ss = 0, sb = 0;
    double e = 2.718281828459045;
    string s = "";

    // 入力を受け取る
    cin >> c;
    cin >> l >> r;

    // 出力精度を設定
    cout << fixed << setprecision(15) << endl;

    vector<ll> vec(3);
    vec[0] = 0;
    vec[1] = 4;
    vec[2] = 6;

    // l/10 から r/10 までループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {
        
        // 0〜9の数字でループ
        for (ll ao = 0; ao <= 9; ao++) {
            p = p1 * 10 + ao;

            // p が範囲外ならスキップ
            if (l > p || p > r) {
                continue;
            }

            // 数学的な計算
            ss += ((log(p * p + 1) - 2) / (log(p * p + 1) * log(p * p + 1) - 2 * log(p * p + 1) + 1));
            sb += ((log(p) - 2) / (log(p) * log(p) - 2 * log(p) + 1));

            // 特定の数字（0, 4, 6）でない場合スキップ
            if (!(ao == 4 || ao == 6 || ao == 0)) continue;

            ll n = p * p + 1;
            m = n;
            bool torf = true;

            // 素数判定
            for (ll i = 5; i <= p; i += 4) {
                if (i == m) {
                    torf = false;
                    break;
                }
                if (n % i == 0) {
                    torf = false;
                    break;
                }
            }

            // 素数なら c をインクリメント
            if (torf) c++;

            // p が1000の倍数であれば結果を出力
            if (p % 1000 == 0) {
                double lo = (e * p * ss) / (2 * sb * (log(p) - 1.08366));
                cout << c - lo << endl;
            }
        }
    }

    // 終了時間の記録
    auto end = high_resolution_clock::now();
    
    // 実行時間を計算して出力
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;

    return 0;
}
//prime_count_1_sum.cpp