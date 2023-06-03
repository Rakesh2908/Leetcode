class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int i,j,i1,j1,k;

        vector<vector<int>> temp(m,vector<int>(n));

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                temp[i][j]=matrix[i][j];
            }
        }

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    temp[i][j]=0;

                    i1=i,j1=j;

                    for(k=0;k<n;k++)
                    {
                        temp[i1][k]=0;
                    }

                    for(k=0;k<m;k++)
                    {
                        temp[k][j1]=0;
                    }
                }
            }
        }

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                matrix[i][j]=temp[i][j];
            }
        }
    }
};