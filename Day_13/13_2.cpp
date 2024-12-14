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

struct Machine
{
   int a_x, a_y;
   int b_x, b_y;
   int prize_x, prize_y;
};

int solveMachine(const Machine &machine)
{
   int det = machine.a_x * machine.b_y - machine.a_y * machine.b_x;

   if (det == 0)
      return -1;

   int aPress = (machine.prize_x * machine.b_y - machine.prize_y * machine.b_x) / det;
   int bPress = (machine.a_x * machine.prize_y - machine.a_y * machine.prize_x) / det;

   if (aPress >= 0 && bPress >= 0 &&
       machine.a_x * aPress + machine.b_x * bPress == machine.prize_x &&
       machine.a_y * aPress + machine.b_y * bPress == machine.prize_y)
   {
      return aPress * 3 + bPress;
   }

   return -1;
}

void solve()
{
   vector<Machine> machines;
   string line;

   while (getline(cin, line) && !line.empty())
   {
      Machine machine;

      // Parse Button A
      stringstream ssA(line);
      string temp;
      ssA >> temp >> temp >> temp;         // Skip "Button A: X+"
      machine.a_x = stoll(temp.substr(2)); // Get X value for Button A
      ssA >> temp;                         // Y+value
      machine.a_y = stoll(temp.substr(2)); // Get Y value for Button A

      // Parse Button B
      getline(cin, line);
      stringstream ssB(line);
      ssB >> temp >> temp >> temp; // Skip "Button B: X+"
      machine.b_x = stoll(temp.substr(2));
      ssB >> temp; // Y+value
      machine.b_y = stoll(temp.substr(2));

      getline(cin, line);
      stringstream ssPrize(line);
      ssPrize >> temp >> temp; // Skip "Prize: X="
      machine.prize_x = stoll(temp.substr(2)) + 10000000000000;
      ssPrize >> temp; // Y=value
      machine.prize_y = stoll(temp.substr(2)) + 10000000000000;

      machines.push_back(machine);

      // Consume any empty line between machines
      getline(cin, line);
   }

   int totalCost = 0;
   int prizes = 0;

   for (const auto &machine : machines)
   {
      int cost = solveMachine(machine);
      if (cost != -1)
      {
         totalCost += cost;
         prizes++;
      }
   }

   cout << totalCost << endl;
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