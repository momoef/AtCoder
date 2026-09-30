#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> hist;
    hist.reserve(N + Q);
    for (int i = N; i >= 1; i--)
        hist.push_back({i, 0});

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            char C;
            cin >> C;
            auto [x, y] = hist.back();
            if (C == 'R')
                x++;
            else if (C == 'L')
                x--;
            else if (C == 'U')
                y++;
            else if (C == 'D')
                y--;
            hist.push_back({x, y});
        }
        else
        {
            int p;
            cin >> p;
            auto [x, y] = hist[hist.size() - p];
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}