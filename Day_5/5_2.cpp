#include <bits/stdc++.h>

using namespace std;

#define rl09 romill_09
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define mii map<int, int>
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define vinput(a)    \
   for (auto &i : a) \
      cin >> i;
#define print(a)        \
   for (auto x : a)     \
      cout << x << " "; \
   cout << endl
#define printPair(a) \
   for (auto x : a)  \
   cout << x.first << " " << x.second << endl
#define print2(a, x, y)        \
   for (int i = x; i < y; i++) \
      cout << a[i] << " ";     \
   cout << endl

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
   cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
   const char *comma = strchr(names + 1, ',');
   cout.write(names, comma - names) << " : " << arg1 << " | ";
   __f(comma + 1, args...);
}

bool checkOrder(const vp &v, const vi &copy)
{
   unordered_map<int, int> position;
   for (int i = 0; i < sz(copy); ++i)
   {
      position[copy[i]] = i;
   }

   for (const auto &[x, y] : v)
   {
      if (position.count(x) && position.count(y))
      {
         if (position[x] > position[y])
         {
            return true;
         }
      }
   }
   return false;
}

int middNum(const vi &update)
{
   vi copy = update;
   int num = copy[sz(copy) / 2];
   return num;
}

vi topoSort(const vi &update, const vp &v)
{
   unordered_map<int, vi> adj;
   unordered_map<int, int> inDegree;
   queue<int> q;
   vi result;
   unordered_set<int> updateSet(all(update));

   for (const auto &[x, y] : v)
   {
      if (updateSet.count(x) && updateSet.count(y))
      {
         adj[x].push_back(y);
         inDegree[y]++;
      }
   }

   for (int num : update)
   {
      if (inDegree[num] == 0)
      {
         q.push(num);
      }
   }

   while (!q.empty())
   {
      int curr = q.front();
      q.pop();
      result.push_back(curr);

      for (int neighbor : adj[curr])
      {
         if (--inDegree[neighbor] == 0)
         {
            q.push(neighbor);
         }
      }
   }

   return result;
}

int sum(const vp &v, vector<vi> &update)
{
   int n = sz(update);
   int add = 0;
   for (int i = 0; i < n; ++i)
   {
      if (checkOrder(v, update[i]))
      {
         vi sortedUpdate = topoSort(update[i], v);
         add += middNum(sortedUpdate);
      }
   }
   return add;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);

   cin.tie(0);
   cout.tie(0);

   string s;
   vp v;
   vector<vi> update;

   while (getline(cin, s))
   {
      if (s.find(',') != string::npos)
      {
         stringstream ss(s);
         vi row;
         string temp;
         while (getline(ss, temp, ','))
         {
            row.push_back(stoi(temp));
         }
         update.push_back(row);
      }
      else
      {
         regex r("([0-9]{2})\\|([0-9]{2})");
         auto begin = sregex_iterator(s.begin(), s.end(), r);
         auto end = sregex_iterator();

         for (auto it = begin; it != end; ++it)
         {
            smatch m = *it;

            int a = stoi(m[1].str());
            int b = stoi(m[2].str());

            v.push_back({a, b});
         }
      }
   }

   cout << sum(v, update) << endl;
   return 0;
}
