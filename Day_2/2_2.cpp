#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int> &row)
{
   int count = 0;
   for (int j = 0; j < row.size() - 1; j++)
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
         return false;
      }
   }
   return count == static_cast<int>(row.size() - 1) || count == -(static_cast<int>(row.size() - 1));
}

bool isSafeWithDampener(const vector<int> &row)
{
   if (isSafe(row))
      return true;
   for (int i = 0; i < row.size(); i++)
   {
      vector<int> modified = row;
      modified.erase(modified.begin() + i);
      if (isSafe(modified))
         return true;
   }
   return false;
}

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
      if (isSafeWithDampener(row))
         safe++;
   }

   cout << safe << endl;
   return 0;
}
