#include <bits./stdc++.h>
using namespace std;

int main()
{
   int a, b, sum = 0;

   vector<int> x, y;
   while (cin >> a >> b)
   {
      x.push_back(a);
      y.push_back(b);
   }

   sort(x.begin(), x.end());
   sort(y.begin(), y.end());

   for(int i = 0; i < x.size(); i++)
   {
      sum += abs((x[i] - y[i]));
   }

   // for(auto &i : x)cout << i << " ";
   // cout << endl;
   // for(auto &i : y)cout << i << " ";
   // cout << endl;
   
   cout << sum << endl;
}