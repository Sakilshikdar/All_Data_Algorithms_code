#include <bits/stdc++.h>
using namespace std;

const int n = 1e5 + 7;
int arr[n];

void marge(int l, int r, int mid)
{
    int Left_size = mid - l + 1;
    int L[Left_size + 1];

    int right_size = r - mid;
    int R[right_size + 1];
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = arr[i];
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = arr[i];
    }

    L[Left_size] = INT_MAX;
    R[right_size] = INT_MAX;
    int lp = 0;
    int rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            arr[i] = L[lp];
            lp++;
        }
        else
        {
            arr[i] = R[rp];
            rp++;
        }
    }
}

void margeShort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    margeShort(l, mid);
    margeShort(mid + 1, r);
    marge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr, arr + n);
    margeShort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}