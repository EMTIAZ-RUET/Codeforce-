class Solution {
public:
    long long countVowels(string word) {
        
        long long lastidx=-1;
        long long level=0;
        long long ans=0;
        
        for(int i=0; i<word.size(); i++)
        {
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
            {
                if(lastidx==-1)
                {
                    level=level+i+1;
                }
                else
                {
                    level=level+i-lastidx;
                }
                ans=ans+level;
            }
            else
            {
                ans=ans+level;
            }
        }
        
        return ans;
    }
};
