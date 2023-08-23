class Solution {
public:
    string reorganizeString(string s) 
    {
        int n = s.size();
        string ans="";

        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }

        while(!pq.empty())
        {
            int cnt = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            if(ans.empty() ||  c != ans.back())
            {
                ans += c;
                cnt--;

                if(cnt>0)   pq.push({cnt,c});
            }

            else
            {
                if(pq.empty())  return "";

                int cnt2=pq.top().first;
                char c2=pq.top().second;
                pq.pop();

                ans += c2;
                cnt2--;

                if(cnt2>0)  pq.push({cnt2,c2});
                pq.push({cnt,c});
            }
        }

        return ans;
    }
};