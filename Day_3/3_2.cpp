#include <bits/stdc++.h>
using namespace std;

int mul(string a,string b)
{
   return stoi(a) * stoi(b);
}

int main()
{
   string s, t;
   while (cin >> t)
      s += t;

   regex r("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)|do\\(\\)|don't\\(\\)");

   auto begin = sregex_iterator(s.begin(), s.end(), r);
   auto end = sregex_iterator();

   int sum = 0;

   bool dos = true;
   for (auto it = begin; it != end; ++it)
   {
      smatch m = *it;


      if (m.str(0) == "do()")
      {
         dos = true;
      }
      else if (m.str(0) == "don't()")
      {
         dos = false;
      }
      else if(m.str(0).find("mul(") == 0 && dos)
      {
         sum += mul(m.str(1), m.str(2));
      }
   }
   cout << sum << "\n";
   return 0;
}