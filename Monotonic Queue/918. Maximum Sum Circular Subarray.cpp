class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>temp(2*n+1,0);
        for(int i=1; i<=2*n; i++)
        {
            temp[i]=nums[(i-1)%n];
        }
        
        deque<int>q;
        q.push_back(0);
        int ans=INT_MIN;
        
        for(int i=1; i<=2*n; i++)
        {
            temp[i]=temp[i]+temp[i-1];
            
            while(!q.empty() && q.front()<i-n)
                q.pop_front();
            
            while(!q.empty() && temp[i]<=temp[q.back()])
               q.pop_back();
            
            ans=max(ans,temp[i]-temp[q.front()]);
            
            q.push_back(i);
            
        }
        
        return ans;
        
    }
};
