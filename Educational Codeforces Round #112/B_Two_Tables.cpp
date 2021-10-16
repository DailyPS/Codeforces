#include <bits/stdc++.h>

using namespace std;

int t;

int main(void)
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> t;
  cout << fixed << setprecision(9);

  while(t--)
  {
    int W, H;
    int x1, y1, x2, y2;
    int w, h;

    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;

    int ans = INT_MAX;

    if ((x2 - x1) + w <= W)
    {
      ans = min(ans, max(0, w - x1));
      ans = min(ans, max(0, x2 - (W - w)));
    }

    if ((y2 - y1) + h <= H)
    {
      ans = min(ans, max(0, h - y1));
      ans = min(ans, max(0, y2 - (H - h)));
    }

    if (ans == INT_MAX)
      cout << "-1\n";

    else
      cout << double(ans) << "\n";
  }
  return 0;
}