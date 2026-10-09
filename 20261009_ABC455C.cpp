#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    map<ll, ll> Map;

    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        Map[A[i]]++;
    }

    vector<ll> B(Map.size());
    ll cnt = 0;
    for (auto &[key, value] : Map)
    {
        B[cnt] = key * value;
        cnt++;
    }

    sort(B.rbegin(), B.rend());

    int unchi = K;
    if (K > Map.size())
    {
        unchi = Map.size();
    }

    for (int i = 0; i < unchi; i++)
    {
        sum -= B[i];
    }

    cout << sum << endl;

    return 0;
}