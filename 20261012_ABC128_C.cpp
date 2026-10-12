#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> maesyori(M, 0);
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            maesyori[i] |= (1 << (x - 1));
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M; i++)
        cin >> p[i];

    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++)
    {
        bool flag = true;
        for (int i = 0; i < M; i++)
        {
            int cnt = __builtin_popcount(mask & maesyori[i]);
            if ((cnt % 2) != p[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            ans++;
    }

    cout << ans << "\n";

    return 0;
}