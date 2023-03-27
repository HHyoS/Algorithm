#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    for(int i = 1; i <= 10; i++)
    {
    	int size, ans = 0;
        vector<string> v;
    
    	cin >> size;
        
        for(int j = 0; j < 8; j++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        if(size == 1)
            cout << "#" << i << " " << 64 << endl;
        else
        {
            for(int j = 0; j < 8; j++)
            {
            	for(int k = 0; k <= 8 - size; k++)
                {
                    bool rowKeep = true;
                
                    for(int l = 0; l < size / 2; l++)
                    {
                        if(v[j][k + l] != v[j][k + size - l - 1])
                            rowKeep = false;
                    }
                    if(rowKeep)
                        ans++;
                }
            }
            
            for(int j = 0; j <= 8 - size; j++)
            { 
                for(int k = 0; k < 8; k++)
                {
                    bool colKeep = true;
               
                    for(int l = 0; l < size / 2; l++)
                    {
                        if(v[j + l][k] != v[j + size - l - 1][k])
                            colKeep = false;
                    }
                    if(colKeep)
                        ans++;
                }
            }
        }
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}
