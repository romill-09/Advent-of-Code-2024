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
   int mn = numeric_limits<int>::max();
   for (int A = 0; A <= 100; ++A)
   {
      for (int B = 0; B <= 100; ++B)
      {
         if (A * machine.a_x + B * machine.b_x == machine.prize_x &&
             A * machine.a_y + B * machine.b_y == machine.prize_y)
         {
            int cost = 3 * A + 1 * B;
            mn = min(mn, cost);
         }
      }
   }
   return (mn == LLONG_MAX) ? -1 : mn;
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
      ssA >> temp >> temp >> temp; // Skip "Button A: X+"
      machine.a_x = stoi(temp.substr(2));
      ssA >> temp; // Y+value
      machine.a_y = stoi(temp.substr(2));

      // Parse Button B
      getline(cin, line); // Read the next line for Button B
      stringstream ssB(line);
      ssB >> temp >> temp >> temp; // Skip "Button B: X+"
      machine.b_x = stoi(temp.substr(2));
      ssB >> temp; // Y+value
      machine.b_y = stoi(temp.substr(2));

      // Parse Prize
      getline(cin, line); // Read the next line for Prize
      stringstream ssPrize(line);
      ssPrize >> temp >> temp; // Skip "Prize: X="
      machine.prize_x = stoi(temp.substr(2));
      ssPrize >> temp; // Y=value
      machine.prize_y = stoi(temp.substr(2));

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