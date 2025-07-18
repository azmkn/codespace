//prime.cpp
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {
    // 開始時間の記録
    auto start = high_resolution_clock::now();

    ll k, l, r, p, c = 0;
    string s = "";

    // 入力を受け取る
    cin >> l >> r >> k;

    // vecに0, 4, 6を設定
    vector<ll> vec(3);
    vec[0] = 0;
    vec[1] = 4;
    vec[2] = 6;

    ll co = l;

    // lが2以下の場合、coを3に設定
    if (l <= 2) {
        co = 3;
    }

    // l/10からr/10までループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {

        // vecの各要素でループ
        for (const ll& ao : vec) {

            p = p1 * 10 + ao;

            // pがl未満またはr超過の場合はスキップ
            if (p < l || p > r) continue;

            // pが0の場合はスキップ
            if (p == 0) {
                continue;
            }

            ll n = p * p + 1;
            ll m = n;

            bool torf = true;

            // nが偶数の場合はスキップ
            if (n % 2 == 0) {
                continue;
            }

            // nが1の場合
            if (n == 1) {

                // 範囲に一致する場合
                if (p - co >= k) {
                    if (co != p - 1) {
                        cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                    } else {
                        cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                    }
                }

                c = 0;
                co = p + 1;
                continue;
            }

            // 5からpまで4ずつ増加してチェック
            for (ll i = 5; i <= p; i += 4) {

                // iがmと一致する場合、torfをfalseに設定
                if (i == m) {
                    torf = false;

                    // 範囲に一致する場合
                    if (p - co >= k) {
                        if (co != p - 1) {
                            cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                        } else {
                            cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                        }
                    }

                    c = 0;
                    co = p + 1;
                    break;
                }

                // nがiで割り切れる場合
                if (n % i == 0) {
                    c++;
                    torf = false;
                    break;
                }
            }

            // torfがtrueの場合
            if (torf) {

                // 範囲に一致する場合
                if (p - co >= k) {
                    if (co != p - 1) {
                        cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                    } else {
                        cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                    }
                }

                c = 0;
                co = p + 1;
                continue;
            }
        }
    }

    // 最後の範囲が条件を満たす場合
    if (p - co >= k) {
        if (co != p - 1) {
            cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
        } else {
            cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
        }
    }

    // 終了時間の記録
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    // 実行時間を表示
    cout << "Execution Time: " << duration << "ms" << endl;

    return 0;
}
//prime.cpp