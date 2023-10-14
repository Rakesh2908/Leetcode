class Solution {
public:
    bool rotateString(string p, string q) 
    {
         if(p.size() != q.size())       
            return 0;     

        string temp = p+p;    
        if (temp.find(q) != -1)        
            return 1; 
                
        return 0;
    }
};