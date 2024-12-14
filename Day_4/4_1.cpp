#include <bits/stdc++.h>
using namespace std;

int countOccurrences(vector<string> &v, string word)
{
   int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
   int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
   int rows = v.size();
   int cols = v[0].size();
   int count = 0;

   for (int i = 0; i < rows; ++i)
   {
      for (int j = 0; j < cols; ++j)
      {
         for (int dir = 0; dir < 8; ++dir)
         {
            int nx = i, ny = j;
            bool found = true;

            for (int k = 0; k < word.size(); ++k)
            {
               if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || v[nx][ny] != word[k])
               {
                  found = false;
                  break;
               }
               nx += dx[dir];
               ny += dy[dir];
            }

            if (found)
            {
               count++;
            }
         }
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

   int occurences = 0;

   string word = "XMAS";

   int occurrences = countOccurrences(v, word);

   cout << occurrences << endl;

   return 0;
}