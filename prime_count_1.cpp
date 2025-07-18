//prime_count_1.cpp
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {
    // 処理の開始時間を記録
    auto start = high_resolution_clock::now();

    ll l, r, p, c, m, lou, lod;
    double e = 2.718281828459045;
    string s = "";

    // 入力を受け取る
    cin >> c;
    cin >> l >> r;

    // 出力の精度設定
    cout << fixed << setprecision(15) << endl;

    // vecには特定の数字を設定（0, 4, 6）
    vector<ll> vec = {0, 4, 6};

    // l / 10 から r / 10 までループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {
        
        // vecに含まれる数字に対してループ
        for (const ll& ao : vec) {
            p = p1 * 10 + ao;

            // p が範囲外ならスキップ
            if (l > p || p > r) {
                continue;
            }

            // 数学的な計算
            ll n = p * p + 1;
            m = n;
            bool torf = true;

            // 素数判定（i は5から p まで4刻み）
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

            // 素数の場合、カウントをインクリメント
            if (torf) c++;

            // p が10000の倍数であれば結果を出力
            if (p % 10000 == 0) {
                double lo = (e * p * ((log(p * p + 1) - 2) / (log(p * p + 1) * log(p * p + 1) - 2 * log(p * p + 1) + 1))) /
                           (2 * ((log(p) - 2) / (log(p) * log(p) - 2 * log(p) + 1)) * (log(p) - 1));
                cout << c / lo << endl;
            }
        }
    }

    // 終了時間を記録
    auto end = high_resolution_clock::now();

    // 実行時間を計算して表示
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;

    return 0;
}
//prime_count_1.cpp