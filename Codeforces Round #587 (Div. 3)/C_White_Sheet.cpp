#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> rect;

pair<pair<int, int>, pair<int, int>> intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
  int x1, y1, x2, y2;

  x1 = max(min(a.first, b.first), min(c.first, d.first));
  y1 = max(min(a.second, b.second), min(c.second, d.second));
  x2 = min(max(a.first, b.first), max(c.first, d.first));
  y2 = min(max(a.second, b.second), max(c.second, d.second));

  if (x1 >= x2 || y1 >= y2)
    return make_pair(make_pair(0, 0), make_pair(0, 0));

  return make_pair(make_pair(x1, y1), make_pair(x2, y2));
}

long long int area(pair<int, int> a, pair<int, int> b)
{
  return (long long)1 * abs(a.first - b.first) * abs(a.second - b.second);
}

int main(void)
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 3; i++)
  {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    rect.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
  }

  pair<pair<int, int>, pair<int, int>> wb1 = intersect(rect[0].first, rect[0].second, rect[1].first, rect[1].second);
  pair<pair<int, int>, pair<int, int>> wb2 = intersect(rect[0].first, rect[0].second, rect[2].first, rect[2].second);
  pair<pair<int, int>, pair<int, int>> inter = intersect(wb1.first, wb1.second, wb2.first, wb2.second);

  long long int aw = area(rect[0].first, rect[0].second);
  long long int awb1 = area(wb1.first, wb1.second);
  long long int awb2 = area(wb2.first, wb2.second);
  long long int ai = area(inter.first, inter.second);

  if (aw > awb1 + awb2 - ai)
    cout << "YES\n";

  else
    cout << "No\n";

  return 0;
}