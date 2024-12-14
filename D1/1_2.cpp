#include <bits./stdc++.h>
using namespace std;

int main()
{
   int a, b, sum = 0, sim = 0;

   vector<int> x, y;
   map<int, int> mp;
   while (cin >> a >> b)
   {
      x.push_back(a);
      y.push_back(b);
   }

   sort(x.begin(), x.end());
   sort(y.begin(), y.end());

   for (auto &i : y)
      mp[i]++;

   for (int i = 0; i < x.size(); i++)
   {
      if (mp.find(x[i]) != mp.end())
      {
         sim += x[i] * mp[x[i]];
         // cout << j.second << " ";
      }
   }
   cout << sim << endl;

   return 0;
}