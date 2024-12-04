#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s, t;
   while(cin >> t)s += t;

   regex r("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");

   auto begin = sregex_iterator (s.begin(), s.end(), r);
   auto end = sregex_iterator();

   int sum = 0;

   for(auto it = begin; it != end; ++it)
   {
      smatch m = *it;

      int a = stoi(m[1].str());
      int b = stoi(m[2].str());

      sum += a * b;
   }
   cout << sum << "\n";
   return 0;
}