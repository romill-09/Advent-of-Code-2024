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
#define print1(a)   \
   for (auto x : a) \
   cout << x.F << " " << x.S << endl
#define print2(a, x, y)        \
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
   vector<vector<char>> v;
   string line;

   while (getline(cin, line) && !line.empty())
   {
      vector<char> row(all(line));
      v.push_back(row);
   }

   int n = v.size(), m = v[0].size();
   pair<int, int> initial = {-1, -1};
   int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         if (v[i][j] == '^')
            initial = {i, j};
      }
   }

   if (initial.first == -1 || initial.second == -1)
   {
      cout << "Invalid input: No guard found." << endl;
      return;
   }

   int i = initial.first, j = initial.second, track = 0;
   set<pii> visited;
   visited.insert({i, j});

   while (true)
   {
      int x = i + dx[track], y = j + dy[track];

      if (x < 0 || y < 0 || x >= n || y >= m)
         break;

      if (v[x][y] == '#')
      {
         track = (track + 1) % 4;
      }
      else
      {
         i = x;
         j = y;
         visited.insert({i, j});
      }
   }

   cout << visited.size() << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   int t = 1;
   // cin >> t;
   while (t--)
      solve();

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}