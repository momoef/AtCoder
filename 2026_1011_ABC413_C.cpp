#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> D(Q);
    queue<pair<ll, ll>> A;

    ll cnt = 0;
    for (int i = 0; i < Q; i++)
    {
        ll query;
        cin >> query;
        if (query == 1)
        {
            int x, c;
            cin >> c >> x;
            D[cnt].first = c;
            D[cnt].second = x;
            A.push(D[cnt]);
            cnt++;
        }
        else
        {
            ll k, sum = 0;
            cin >> k;
            while (k > 0)
            {
                if (k >= A.front().first)
                {
                    sum += A.front().first * A.front().second;
                    k -= A.front().first;
                    A.pop();
                }
                else
                {
                    sum += A.front().second * k;
                    A.front().first -= k;
                    break;
                }
            }
            cout << sum << "\n";
        }
    }

    return 0;
}