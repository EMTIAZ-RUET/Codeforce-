class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        deque<int>q;
        int ans=INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            while(!q.empty() && i-q.front()>k)
                q.pop_front();
            
            int mx=0;
            if(!q.empty())
             mx=max(mx,nums[q.front()]);
            nums[i]=nums[i]+mx;
            
            ans=max(ans,nums[i]);
            
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            
            q.push_back(i);
        }
        
        return ans;
        
    }
};
