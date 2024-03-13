#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solve(vector<int> &v)
{
    
    vector<vector<int>> ans;
    vector<int> v1;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if ((v[i] + v[j] + v[k] == 0) && (i != j) && (i != k) &&(j!=k) )
                {
                    v1.push_back(v[i]);
                    v1.push_back(v[j]);
                    v1.push_back(v[k]);
                    if(v1.size()==3)
                    {
                        ans.push_back(v1);
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> v2 = solve(v);
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}