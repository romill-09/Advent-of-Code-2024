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

const vp dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;

bool isValid(int x, int y, vector<string> &s)
{
   return x >= 0 && x < n && y >= 0 && y < m;
}

pii bfs(int startX, int startY, vector<string> &s, vector<vector<bool>> &visited)
{
   char Type = s[startX][startY];
   queue<pair<int, int>> q;
   q.push({startX, startY});
   visited[startX][startY] = true;

   int area = 0;
   int perimeter = 0;

   while (!q.empty())
   {
      auto [x, y] = q.front();
      q.pop();
      area++;

      for (auto [dx, dy] : dir)
      {
         int nX = x + dx;
         int nY = y + dy;

        if (!isValid(nX, nY, s) || s[nX][nY] != Type)
         {
            perimeter++;
         }
         else if (!visited[nX][nY])
         {
            visited[nX][nY] = true;
            q.push({nX, nY});
         }
      }
   }

   return {area, perimeter};
}

void solve()
{
   vector<string> s;
   string line;

   while (getline(cin, line) && !line.empty())
   {
      s.push_back(line);
   }
   n = s.size();
   m = s[0].size();

   vector<vector<bool>> visited(n, vector<bool>(m, false));
   int price = 0;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (!visited[i][j])
         {
            auto [area, perimeter] = bfs(i, j, s, visited);
            price += area * perimeter;
         }
      }
   }

   cout << price << endl;
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