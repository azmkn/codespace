#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {

    // 変数宣言
    ll l, r, p, c, m;
    double ss = 0, sb = 0;
    double e = 2.718281828459045;  // ネイピア数 e の近似値
    string s = "";

    // 入力: c, l, r
    cin >> c;
    cin >> l >> r;

    // 小数点以下15桁で出力する設定
    cout << fixed << setprecision(15) << endl;

    // ベクトルの初期化
    vector<ll> vec(3);
    vec[0] = 0;
    vec[1] = 4;
    vec[2] = 6;

    // 処理時間計測の開始
    auto start = high_resolution_clock::now();

    // p1 は l/10 から r/10 までループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {

        // ao は 0 から 9 までループ（p の下1桁を表す）
        for (ll ao = 0; ao <= 9; ao++) {
            p = p1 * 10 + ao;  // p を生成

            // p が l から r の範囲外ならスキップ
            if (l > p || p > r) {
                continue;
            }

            // 数式による計算と ss, sb の更新
            ss += ((2500000000 * log(p * p + 1) - 5209150000) /
                   (2500000000 * log(p * p + 1) * log(p * p + 1) - 5418300000 * log(p * p + 1) + 2935797489));

            sb += ((2500000000 * log(p) - 5209150000) /
                   (2500000000 * log(p) * log(p) - 5418300000 * log(p) + 2935797489));

            // p の下1桁が 4, 6, 0 のいずれかでなければスキップ
            if (not (ao == 4 or ao == 6 or ao == 0)) continue;

            // n = p^2 + 1
            ll n = p * p + 1;
            m = n;

            bool torf = true;  // 素数判定フラグ

            // 5 から p まで 4刻みでループ
            for (ll i = 5; i <= p; i += 4) {

                // n と i が同じなら false にしてループ抜ける
                if (i == m) {
                    torf = false;
                    break;
                }

                // n が i で割り切れたら false にしてループ抜ける
                if (n % i == 0) {
                    torf = false;
                    break;
                }
            }

            // torf が true ならカウンター c を増やす
            if (torf) c++;

            // p が 1000 の倍数なら計算結果を出力
            if (p % 1000 == 0) {
                double lo = (e * p * ss) / (2 * sb * (log(p) - 1.08366));
                cout << c - lo << endl;
            }
        }
    }

    // 処理時間計測の終了
    auto end = high_resolution_clock::now();

    // 処理時間をミリ秒で計算して出力
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;
}
