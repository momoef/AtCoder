#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    vector<int> d(N);
    for (int i = 1; i <= N - 1; i++)
        cin >> d[i];

    if (L % 3 != 0)
    {
        cout << "0" << endl;
        return 0;
    }

    map<int, ll> Map;

    Map[1] = 1;

    int now = 1;
    for (int i = 2; i <= N; i++)
    {
        int next = now + d[i - 1];
        if (next > L)
        {
            next -= L;
        }
        Map[next]++;
        now = next;
    }

    ll ans = 0;
    for (int i = 1; i <= L / 3; i++)
    {
        if (Map[i] != 0)
        {
            ans += Map[i] * Map[i + (L / 3)] * Map[i + (2 * L / 3)];
        }
    }
    cout << ans << endl;

    return 0;
}
