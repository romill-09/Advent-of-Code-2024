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

vp findZeroesNines(const vector<vi> &grid)
{
   vp zero, nine;

   for (int i = 0; i < sz(grid); ++i)
   {
      for (int j = 0; j < sz(grid); ++j)
      {
         if (grid[i][j] == 0)
            zero.pb({i, j});
      }
   }

   return zero;
}

int dfs(int i, int j, const vector<vi> &grid, vector<vector<bool>> &visited)
{
   if (grid[i][j] == 9)
   {
      return 1;
   }

   int dx[] = {0, -1, 0, 1}; // right, down, left, up
   int dy[] = {1, 0, -1, 0}; // right, down, left, up

   int paths = 0;
   visited[i][j] = true;

   for (int d = 0; d < 4; ++d)
   {
      int x = i + dx[d], y = j + dy[d];

      if (x >= 0 && x < sz(grid) && y >= 0 && y < sz(grid[0]) && !visited[x][y])
      {
         if (grid[x][y] == grid[i][j] + 1)
         {
            paths += dfs(x, y, grid, visited);
         }
      }
   }

   visited[i][j] = false;
   return paths;
}

int trailHeads(const vector<vi> &grid, vp &zero)
{
   int rating = 0;

   for (auto &[i, j] : zero)
   {
      vector<vector<bool>> visited(sz(grid), vector<bool>(sz(grid[0]), false));

      rating += dfs(i, j, grid, visited);
   }
   return rating;
}

void solve()
{
   vector<string> v;
   string line;

   while (getline(cin, line))
   {
      v.push_back(line);
   }

   vector<vi> grid;
   for (auto &row : v)
   {
      vi r;
      for (char c : row)
      {
         r.pb(c - '0');
      }
      grid.pb(r);
   }

   auto zero = findZeroesNines(grid);

   cout << trailHeads(grid, zero);
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   int t = 1;
   //  cin >> t;
   while (t--)
      solve();

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}
