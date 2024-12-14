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

const int MOD = 1e9 + 7;

struct Robot
{
   int px, py;
   int vx, vy;
};

vector<Robot> input()
{
   vector<Robot> robots;
   string line;
   while (getline(cin, line))
   {
      Robot robot;
      stringstream ss(line);

      string temp;
      ss >> temp;

      size_t comma = temp.find(',');
      robot.px = stoi(temp.substr(2, comma - 2));
      robot.py = stoi(temp.substr(comma + 1));

      ss >> temp >> temp;
      comma = temp.find(',');
      robot.vx = stoi(temp.substr(2, comma - 2));
      robot.vy = stoi(temp.substr(comma + 1));

      robots.push_back(robot);
   }
   return robots;
}

void updateGrid(vector<Robot> &robots, vector<vector<char>> &grid, int width, int height)
{
   for (int i = 1; i < 10000; ++i)
   {
      map<pair<int, int>, bool> locations;
      bool duplicate = false;

      for (auto &robot : robots)
      {
         robot.px = (robot.px + robot.vx) % width;
         robot.py = (robot.py + robot.vy) % height;

         if (robot.px < 0)
         {
            robot.px += width;
         }

         if (robot.py < 0)
         {
            robot.py += height;
         }

         if (locations[{robot.px, robot.py}])
         {
            duplicate = true;
            continue;
         }
         locations[{robot.px, robot.py}] = true;
         grid[robot.py][robot.px] = '#';
      }

      if (duplicate)
         continue;

      cout << "Iteration: " << i << endl;
      for (auto &row : grid)
      {
         for (auto &c : row)
         {
            cout << c;
         }
         cout << endl;
      }

      string temp;
      getline(cin, temp);
   }
}

void solve()
{
   const int width = 101, height = 103, seconds = 100;

   vector<Robot> robots = input();

   vector<vector<char>> grid(height, vector<char>(width, '.'));

   updateGrid(robots, grid, width, height);
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   clock_t z = clock();

   int t = 1;
   // cin >> t;
   while (t--)
      solve();

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}