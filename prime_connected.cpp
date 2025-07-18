//prime_connected.cpp
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;

int main() {
    ll k, l, r, p, c = 0, cp = 0, m, c4 = 0, c6 = 0, c0 = 0;
    string s = "";

    // 入力を受け取る
    cin >> l >> r >> k;

    // 末尾が0, 4, 6の数字のリスト
    vector<ll> vec = {0, 4, 6};

    ll co = l;
    auto start = high_resolution_clock::now();

    // lが2以下の場合の特別処理
    if (l <= 2) {
        co = 3;
    }

    if (l <= 2) {
        cp = 3 - l;
    }

    // l/10 から r/10 までの範囲をループ
    for (ll p1 = l / 10; p1 <= r / 10; p1++) {

        // vecの各値について処理
        for (const ll& ao : vec) {

            p = p1 * 10 + ao;

            if (p == 0) {
                continue;
            }

            ll n = p * p + 1;
            m = n;

            bool torf = true;

            // nが1の場合は特別処理
            if (n == 1) {
                cp++;

                // 末尾の数字によってカウントを増やす
                if (ao == 4) {
                    c4 += 1;
                } else if (ao == 6) {
                    c6 += 1;
                } else {
                    c0 += 1;
                }

                // 範囲がk以上の場合に結果を表示
                if (p - co >= k) {
                    if (co != p - 1)
                        cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                    else
                        cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                }

                cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

                c = 0;
                co = p + 1;

                cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

                continue;
            }

            // nがmで割り切れるかチェック
            for (ll i = 5; i <= p; i += 4) {
                if (i == m) {
                    torf = false;
                    cp++;

                    // 末尾の数字によってカウントを増やす
                    if (ao == 4) {
                        c4 += 1;
                    } else if (ao == 6) {
                        c6 += 1;
                    } else {
                        c0 += 1;
                    }

                    // 範囲がk以上の場合に結果を表示
                    if (p - co >= k) {
                        if (co != p - 1)
                            cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                        else
                            cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                    }

                    cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

                    c = 0;
                    co = p + 1;

                    cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;
                    break;
                }

                // nがiで割り切れる場合
                if (n % i == 0) {
                    c++;
                    cp = 0;

                    torf = false;

                    cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

                    break;
                }
            }

            // 割り切れなかった場合の処理
            if (torf) {
                cp++;

                // 末尾の数字によってカウントを増やす
                if (ao == 4) {
                    c4 += 1;
                } else if (ao == 6) {
                    c6 += 1;
                } else {
                    c0 += 1;
                }

                // 範囲がk以上の場合に結果を表示
                if (p - co >= k) {
                    if (co != p - 1)
                        cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
                    else
                        cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
                }

                cout << "n:" << p << " n^2+1:" << m << " 連続個数:" << cp << endl;

                c = 0;
                co = p + 1;

                cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

                continue;
            }
        }
    }

    // 最後の範囲の結果を表示
    if (p - co >= k) {
        if (co != p - 1)
            cout << "範囲:" << co << " ~ " << p - 1 << " 個数:" << p - co << " 個数(0,4,6):" << c << endl;
        else
            cout << "範囲:" << co << " 個数:" << 1 << " 個数(0,4,6):" << c << endl;
    }

    // カウンターの最終表示
    cout << "Counter" << " 0:" << c0 << " 4:" << c4 << " 6:" << c6 << endl;

    // 実行時間の計測
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Execution Time: " << duration << "ms" << endl;
}

//prime_connected.cpp