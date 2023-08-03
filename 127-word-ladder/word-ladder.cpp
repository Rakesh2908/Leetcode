class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) 
    {
        queue<pair<string,int>>q;
        unordered_set<string>st(words.begin(),words.end());

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
            string w = q.front().first;
            int steps = q.front().second;

            if(w==endWord)  return steps;

            q.pop();

            for(int i=0;i<beginWord.size();i++)
            {
                char original = w[i];

                for(char c='a';c<='z';c++)
                {
                    w[i]=c;
                    if(st.find(w) != st.end())
                    {
                        st.erase(w);
                        q.push({w,steps+1});
                    }
                }
                w[i]=original;
            }
        }

        return 0;
    }
};