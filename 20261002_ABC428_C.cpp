#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T;

    ll Q, cnt = 0;
    cin >> Q;
    vector<ll> presum(Q + 1), minsum(Q + 1);
    presum[0] = 0;
    minsum[0] = 0;
    for (ll i = 0; i < Q; i++)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            char c;
            cin >> c;
            if (c == '(')
            {
                presum[cnt + 1] = presum[cnt] + 1;
            }
            else
            {
                presum[cnt + 1] = presum[cnt] - 1;
            }
            minsum[cnt + 1] = min(minsum[cnt], presum[cnt + 1]);
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (presum[cnt] == 0 && minsum[cnt] >= 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}