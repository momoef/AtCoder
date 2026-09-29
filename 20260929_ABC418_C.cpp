#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(Q);

    ll maxA = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }

    sort(A.begin(), A.end());

    vector<ll> presum(maxA + 1), nokori(maxA + 1);
    presum[0] = 0, nokori[0] = N;
    ll point = 0;
    for (int i = 1; i <= maxA; i++)
    {
        presum[i] = presum[i - 1];
        nokori[i] = nokori[i - 1];
        if (A[point] == i)
        {
            while (point < N && A[point] == i)
            {
                presum[i] += A[point];
                nokori[i] -= 1;
                point++;
            }
        }
        else
            presum[i] = presum[i - 1];
    }

    for (ll i = 0; i < Q; i++)
    {
        cin >> B[i];
        if (B[i] == 1)
        {
            cout << "1\n";
            continue;
        }

        if (B[i] > maxA)
        {
            cout << "-1\n";
            continue;
        }

        cout << presum[B[i] - 1] + nokori[B[i] - 1] * (B[i] - 1) + 1 << "\n";
    }

    return 0;
}