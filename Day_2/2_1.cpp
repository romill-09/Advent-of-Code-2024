#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<vector<int>> v;
   string line;

   while (getline(cin, line))
   {
      stringstream ss(line);
      vector<int> row;
      int num;

      while (ss >> num)
         row.push_back(num);

      v.push_back(row);
   }

   int safe = 0;

   for (const auto &row : v)
   {
      int count = 0;
      for (size_t j = 0; j < row.size() - 1; j++)
      {
         int diff = row[j + 1] - row[j];
         if (diff > 0 && diff >= 1 && diff <= 3)
         {
            count--;
         }
         else if (abs(diff) >= 1 && abs(diff) <= 3)
         {
            count++;
         }
         else
         {
            count = 0;
            break;
         }
      }

      if (count == static_cast<int>(row.size() - 1) || count == -(static_cast<int>(row.size() - 1)))
         safe++;
   }

   cout << safe << endl;
   return 0;
}
