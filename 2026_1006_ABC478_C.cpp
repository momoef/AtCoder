#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1), Max(N + 2, 0), Min(N + 2, 1e9);
    vector<bool> preOk(N + 2, true), sufOk(N + 2, true);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        Max[i] = max(Max[i - 1], A[i]);
    }

    for (int i = N; i >= 1; i--)
    {
        Min[i] = min(Min[i + 1], A[i]);
    }

    for (int i = 2; i <= N; i++)
        preOk[i] = preOk[i - 1] && A[i - 1] <= A[i];

    for (int i = N - 1; i >= 1; i--)
        sufOk[i] = sufOk[i + 1] && A[i] <= A[i + 1];

    for (int i = 1; i <= N - K + 1; i++)
    {
        if (preOk[i - 1] && sufOk[i + K] && Max[i - 1] <= Min[i] && Max[i + K - 1] <= Min[i + K])
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1), Max(N + 2, 0), Min(N + 2, 1e9);
    vector<bool> preOk(N + 2, true), sufOk(N + 2, true);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        Max[i] = max(Max[i - 1], A[i]);
    }

    for (int i = N; i >= 1; i--)
    {
        Min[i] = min(Min[i + 1], A[i]);
    }

    for (int i = 2; i <= N; i++)
        preOk[i] = preOk[i - 1] && A[i - 1] <= A[i];

    for (int i = N - 1; i >= 1; i--)
        sufOk[i] = sufOk[i + 1] && A[i] <= A[i + 1];

    for (int i = 1; i <= N - K + 1; i++)
    {
        if (preOk[i - 1] && sufOk[i + K] && Max[i - 1] <= Min[i] && Max[i + K - 1] <= Min[i + K])
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}