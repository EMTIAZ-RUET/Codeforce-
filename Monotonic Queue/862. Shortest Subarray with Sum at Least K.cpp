class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        deque<int>q;
        int ans=INT_MAX;
        vector<long long>cur;
        for(int i=0; i<nums.size(); i++)
            cur.push_back(nums[i]);
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0)
                cur[i]=cur[i]+cur[i-1];
          if(cur[i]>=k)
          {
              ans=min(ans,i+1);
          }
            while(!q.empty() && cur[i]-cur[q.front()]>=k)
            {
                ans=min(ans,i-(q.front()+1)+1);
                q.pop_front();
            }
            
            while(!q.empty() && cur[i]<cur[q.back()])
                q.pop_back();
            
            q.push_back(i);
        }
        
        if(ans==INT_MAX)
            ans=-1;
        
        return ans;
        
    }
};
