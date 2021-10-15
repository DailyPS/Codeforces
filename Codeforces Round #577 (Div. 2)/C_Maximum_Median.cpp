#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long arr[200005];

bool check_median(long long median)
{
    long long add_oper = 0;

    for (int i = n / 2; i < n; i++)
    {
        if (median - arr[i] > 0)
            add_oper += median - arr[i];

        if (add_oper > k)
            return false;
    }

    if (add_oper > k)
        return false;

    else
        return true;
}

int main(void)
{
    scanf("%lld %lld", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    sort(arr, arr + n);

    long long left = 1;
    long long right = 2000000000;

    while (left != right)
    {
        long long mid = (left + right + 1) / 2;

        if (check_median(mid))
            left = mid;
        
        else
            right = mid - 1;
    }

    printf("%d", left);

    return 0;
}