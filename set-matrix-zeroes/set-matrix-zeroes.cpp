class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int nr = matrix.size();
        int nc = matrix[0].size();

        vector<int> r(nr,1);
        vector<int> c(nc,1);

        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(matrix[i][j]==0)
                {
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(r[i]==0 || c[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};