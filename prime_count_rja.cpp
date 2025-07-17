#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {

    // 処理開始時刻を取得
    auto start = high_resolution_clock::now();

    // 変数宣言
    ll l, r, p, c, m;
    double e = 2.718281828459045;  // ネイピア数 e の近似値
    string s = "";

    // 入力: c, l, r
    cin >> c;
    cin >> l >> r;

    // 小数点以下15桁の固定小数点表示を設定
    cout << fixed << setprecision(15) << endl;

    // 検索対象の末尾の数字を格納したベクトル
    vector<ll> vec(3);
    vec[0] = 0;
    vec[1] = 4;
    vec[2] = 6;

    // l/10 から r/10 までの p1 をループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {

        // vec 内の各末尾数字 ao に対してループ
        for (const ll& ao : vec) {

            p = p1 * 10 + ao;  // p を構築

            // 範囲外の p はスキップ
            if (l > p || p > r) {
                continue;
            }

            // n = p^2 + 1 を計算
            ll n = p * p + 1;
            m = n;

            bool torf = true;  // 素数判定フラグ

            // 5 から p まで 4刻みで割り切れるか確認
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

            // 素数判定が true ならカウンターを増やす
            if (torf) c++;

            // p が 1000 の倍数のとき、特定の計算結果を出力
            if (p % 1000 == 0) {
                double lo = (e * p *
                            ((2500000000 * log(p * p + 1) - 5209150000) /
                             (2500000000 * log(p * p + 1) * log(p * p + 1) - 5418300000 * log(p * p + 1) + 2935797489))) /
                            (2 * ((2500000000 * log(p) - 5209150000) /
                                  (2500000000 * log(p) * log(p) - 5418300000 * log(p) + 2935797489)) *
                             (log(p) - 1.08366));

                cout << c / lo << endl;
            }
        }
    }

    // 処理終了時刻を取得
    auto end = high_resolution_clock::now();

    // 実行時間をミリ秒で計算して表示
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;
}
