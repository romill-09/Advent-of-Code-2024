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

const int MOD = 1e9 + 7;

vi convertToBlocks(const string &s)
{
   vi blocks;
   int c = 0;

   for (int i = 0; i < sz(s); i++)
   {
      if (i % 2 == 0)
      {
         int j = s[i] - '0';
         for (int k = 0; k < j; k++)
            blocks.pb(c);
         c++;
      }
      else
      {
         int j = s[i] - '0';
         for (int k = 0; k < j; k++)
            blocks.pb(-1);
      }
   }
   return blocks;
}

vi compacting(vi &blocks)
{
   for (int i = sz(blocks) - 1; i >= 0; i--)
   {
      if (blocks[i] != -1)
      {
         int c = blocks[i];
         blocks[i] = -1;

         for (int j = 0; j < sz(blocks); j++)
         {
            if (blocks[j] == -1)
            {
               blocks[j] = c;
               break;
            }
         }
      }
   }
   return blocks;
}

int checksum(const vi &compact)
{
   int sum = 0;
   for (int i = 0; i < sz(compact); i++)
   {
      if (compact[i] != -1)
         sum += i * compact[i];
   }
   return sum;
}

void solve()
{
   string s;
   cin >> s;

   vi blocks = convertToBlocks(s);

   vi compact = compacting(blocks);

   int sum = checksum(compact);

   cout << sum << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   clock_t z = clock();

   int t = 1;
   while (t--)
      solve();

   return 0;
}
