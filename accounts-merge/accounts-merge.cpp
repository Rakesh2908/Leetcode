class DisjointSet
{
    vector<int> parent, rank, size;

public:
    // constructor to initialize parent, rank, and size arrays
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        
        // initialize parent array such that each node is its own parent
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // find the parent node of the given node
    int findUPar(int node)
    {
        // if node is its own parent, return node
        if(node == parent[node])
            return node;

        // path compression: set the parent of the current node to its grandparent
        // this flattens the tree and reduces the time complexity of future findUPar calls
        return parent[node] = findUPar(parent[node]);
    }

    // union two sets by their rank
    void UnionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) // if nodes are already in the same set, no need to merge
            return;

        if(rank[pu] < rank[pv]) // if the rank of the parent of u is less than that of the parent of v, attach u to v
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) // if the rank of the parent of v is less than that of the parent of u, attach v to u
        {
            parent[pv] = pu;
        }
        else // if the ranks are equal, attach v to u and increase the rank of u
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // union two sets by their size
    void UnionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) // if nodes are already in the same set, no need to merge
            return;

        if(size[pu] < size[pv]) // if size of set containing u is less than that of set containing v, attach u to v
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else // if size of set containing v is less than or equal to that of set containing u, attach v to u
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);

        //i -> node
        //we traverse j(emails) from 1 because index 0 is name
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];

                //if the mail has not previously found, map it to node
                if(mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }

                //if it is previously found, do union to both nodes
                else
                {
                    ds.UnionBySize(i,mapMailNode[mail]);
                }
            }
        }
        //as per now, the disjoint set has been created

        //we need to store all the merged mails in a list form
        vector<string> mergedMail[n];
        for(auto it: mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        //we now has to attach the names to the merged list of emails
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            //if it is empty, just continue
            if(mergedMail[i].size()==0)
                continue;
            
            //we have to sort all the mails 
            sort(mergedMail[i].begin(),mergedMail[i].end());

            //lets take a temp vector to map names to mergedMail
            vector<string> temp;

            //push_back name as name is stored in 1st index
            temp.push_back(accounts[i][0]);

            //traverse to mergedMail and pushback mails wrt to names
            for(auto it: mergedMail[i])
            {
                temp.push_back(it);
            }

            //store the entire name-email list to ans
            ans.push_back(temp);
        }

        return ans;
    }
};
