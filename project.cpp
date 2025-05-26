#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int trow[] = {-2,-2,-1,1,2,2,-1,1,0,1,-1,0,-1,1,1,-1};
int tcol[] = {-1,1,2,2,1,-1,-2,-2,1,0,0,-1,1,1,-1,-1};

bool isvalid(int row,int col,int n)
{
    return row>=0 && col>=0 && row<n && col<n;
}

int main()
{
    vector<vector<int>>chess(8,vector<int>(8,0));
    
    int srcrow,srccol,destrow,destcol;
    cout<<"Enter the src row:";
    cin>>srcrow;
    cout<<"Enter the src col:";
    cin>>srccol;
    cout<<"Enter the dest row:";
    cin>>destrow;
    cout<<"Enter the dest col:";
    cin>>destcol;

    if(srcrow==destrow && srccol==destcol)
    {
        cout<<"Minimum number of moves will be 0 as src and dest both are same"<<endl;
        return 0;
    }

    queue<pair<int,int>>q;
    q.push({srcrow,srccol});
    int steps=0;

    while(!q.empty())
    {
        int count = q.size();

        while(count--)
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int k=0;k<16;k++)
            {
                int n_row = row+trow[k];
                int n_col = col+tcol[k];

                if(isvalid(n_row,n_col,8) && !chess[n_row][n_col])
                {
                    if(n_row==destrow && n_col==destcol)
                    {
                        cout<<"Minimum number of moves required to reach the destination"<<steps+1<<endl;
                        return 0;
                    }
                    chess[n_row][n_col]=1;
                    q.push({n_row,n_col});
                }

            }
        }
        steps++;
    }
}










