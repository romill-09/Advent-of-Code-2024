#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int rows, int cols)
{
   return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool check(int i, int j, int rows, int cols, const vector<string> &v)
{
   if (!is_valid(i, j, rows, cols) ||
       !is_valid(i + 2, j + 2, rows, cols) ||
       !is_valid(i + 1, j + 1, rows, cols) ||
       !is_valid(i, j + 2, rows, cols) ||
       !is_valid(i + 2, j, rows, cols))
   {
      return false;
   }

   bool dia1 = (v[i][j] == 'M' || v[i][j] == 'S') &&
                    (v[i + 1][j + 1] == 'A') &&
                    (v[i + 2][j + 2] == 'M' || v[i + 2][j + 2] == 'S') &&
                    (v[i][j] != v[i + 2][j + 2]);

   bool dia2 = (v[i][j + 2] == 'M' || v[i][j + 2] == 'S') &&
                    (v[i + 1][j + 1] == 'A') &&
                    (v[i + 2][j] == 'M' || v[i + 2][j] == 'S') &&
                    (v[i][j + 2] != v[i + 2][j]);

   return dia1 && dia2;
}

int count_xmas(const vector<string> &v)
{
   int rows = v.size(), cols = v[0].size();
   int count = 0;

   for (int i = 0; i < rows; ++i)
   {
      for (int j = 0; j < cols; ++j)
      {
         if (check(i, j, rows, cols, v))
            count++;
      }
   }

   return count;
}

int main()
{
   vector<string> v;
   string s;
   while (cin >> s)
      v.push_back(s);

   cout << count_xmas(v) << endl;

   return 0;
}
