class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
       deque<int>dq;
       int cur=0;
        
       for(int i=0; i<nums.size(); i++)
       {
           cur=nums[i];
           
           if(!dq.empty())
               cur=cur+nums[dq.front()];
           
          
           
           while(!dq.empty() && nums[dq.back()]<cur)
               dq.pop_back();
           
           
           
           while(!dq.empty() && i-dq.front()>=k)
               dq.pop_front();
           
           dq.push_back(i);
           nums[i]=cur;
          
           
       }
        
        return cur;
        
    }
};
