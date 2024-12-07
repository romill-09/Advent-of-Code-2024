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

vector<vi> input()
{
   string s;
   vector<string> v;

   while (getline(cin, s) && !s.empty())
   {
      v.push_back(s);
   }

   regex r(R"((\d+):([\s\d]+))");

   vector<vi> nums;

   for (const auto &line : v)
   {
      smatch m;
      if (regex_search(line, m, r))
      {
         int before_colon = stoll(m[1].str());

         string numbers = m[2].str();
         regex num_regex(R"(\d+)");
         auto begin = sregex_iterator(numbers.begin(), numbers.end(), num_regex);
         auto end = sregex_iterator();

         vector<int> curr;
         curr.push_back(before_colon);

         for (auto it = begin; it != end; ++it)
         {
            curr.push_back(stoll(it->str()));
         }
         nums.push_back(curr);
      }
   }

   return nums;
}

bool check(vector<int> &nums, int val)
{
   int n = nums.size() - 1;

   for (int mask = 0; mask < (1 << n); mask++)
   {
      int result = nums[0];

      for (int i = 0; i < n; i++)
      {
         if (mask & (1 << i))
         {
            result *= nums[i + 1];
         }
         else
         {
            result += nums[i + 1];
         }
      }

      if (result == val)return true;
   }

   return false;
}

void solve()
{
   vector<vi> v = input();

   int sum = 0;

   for (auto &eq : v)
   {
      int val = eq[0];
      vector<int> nums(eq.begin() + 1, eq.end());

      if (check(nums, val))sum += val;
   }

   cout << sum << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   solve();

   return 0;
}