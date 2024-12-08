#include <bits/stdc++.h>

using namespace std;

#define rl09 romill_09
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define vinput(a)    \
   for (auto &i : a) \
      cin >> i;
#define print(a)        \
   for (auto x : a)     \
      cout << x << " "; \
   cout << endl
#define printP(a)   \
   for (auto x : a) \
   cout << x.F << " " << x.S << endl
#define printR(a, x, y)        \
   for (int i = x; i < y; i++) \
      cout << a[i] << " ";     \
   cout << endl

inline int power(int a, int b)
{
   int x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
   const char *comma = strchr(names + 1, ',');
   cout.write(names, comma - names) << " : " << arg1 << " | ";
   __f(comma + 1, args...);
}

const int N = 200005;

void solve()
{
   vector<string> v;
   string s;

   while (getline(cin, s) && !s.empty())
      v.push_back(s);

   int rows = sz(v);
   int cols = sz(v[0]);

   vp antennas;
   spi antiNodes;

   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         if (v[i][j] != '.')
            antennas.push_back({i, j});
      }
   }

   for (int i = 0; i < antennas.size(); i++)
   {
      for (int j = i + 1; j < antennas.size(); j++)
      {
         int x1 = antennas[i].F, y1 = antennas[i].S;
         int x2 = antennas[j].F, y2 = antennas[j].S;

         if (v[x1][y1] != v[x2][y2])
            continue;

         int dx = x2 - x1;
         int dy = y2 - y1;

         int antiNode_x1 = x1, antiNode_y1 = y1;
         int antiNode_x2 = x2, antiNode_y2 = y2;

         while((antiNode_x1 >= 0 && antiNode_x1 < rows) && (antiNode_y1 >= 0 && antiNode_y1 < cols))
         {
            antiNodes.insert({antiNode_x1, antiNode_y1});
            antiNode_x1 -= dx;
            antiNode_y1 -= dy;
         }

         while((antiNode_x2 >= 0 && antiNode_x2 < rows) && (antiNode_y2 >= 0 && antiNode_y2 < cols))
         {
            antiNodes.insert({antiNode_x2, antiNode_y2});
            antiNode_x2 += dx;
            antiNode_y2 += dy;
         }
      }
   }

   cout << sz(antiNodes) << endl;
   return;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   solve();

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}