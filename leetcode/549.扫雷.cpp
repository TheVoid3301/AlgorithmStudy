#include<iostream>
using namespace std;
int n,m;
int d[100][100]={0};
int main()
{
  cin>>n>>m;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cin>>d[i][j];
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      int count = 0;
      if(d[i][j] == 1)
      {
      cout << 9 << " "; 
      }
      else
      {
        for(int x = i-1; x <= i + 1; x++)
        {
          for(int y = j - 1; y <= j + 1; y++)
          {
            if(x >= 0 && y >= 0 && x < n && y < m && d[x][y] == 1)
            {
              count++;
            }
          }
        }
        cout << count << " ";
      }
    }
    cout << endl;
  }
} 