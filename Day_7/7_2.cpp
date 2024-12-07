#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

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

bool check(vector<int> &nums, int val, int idx, int current)
{
   if (idx == nums.size())
   {
      return current == val;
   }

   int next = nums[idx];

   // Addition
   if (check(nums, val, idx + 1, current + next))
   {
      return true;
   }

   // Multiplication
   if (check(nums, val, idx + 1, current * next))
   {
      return true;
   }

   // Concatenation
   string concat = to_string(current) + to_string(next);
   if (concat.size() <= 16 && check(nums, val, idx + 1, stoll(concat)))
   {
      return true;
   }

   return false;
}

void solve()
{
   vector<vi> v = input();
   int sum = 0;

   for (auto &eq : v)
   {
      int target = eq[0];
      vector<int> nums(eq.begin() + 1, eq.end());

      if (check(nums, target, 1, nums[0]))
      {
         sum += target;
      }
   }
   cout << sum << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // #ifndef ONLINE_JUDGE
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w", stdout);
   // #endif+

   solve();

   return 0;
}
