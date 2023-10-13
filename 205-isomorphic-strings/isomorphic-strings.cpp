class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};
        bool mappedT[256]={0};
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==0 || mappedT[t[i]]==0){
                hash[s[i]]=t[i];
                mappedT[t[i]]=1;
            }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]!=t[i] && mappedT[t[i]]!=0){
                return false;
            }
        }
        }
        
        return true;
       
    }
};