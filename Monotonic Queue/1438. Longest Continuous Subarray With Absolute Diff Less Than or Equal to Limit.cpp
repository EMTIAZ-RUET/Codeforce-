class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
       deque<int>q1;
       deque<int>q2;
       int ans=0;
       int temp=0;
        
       for(int i=0; i<nums.size(); i++)
       {
           while(!q1.empty() && nums[q1.back()]<nums[i])
           {
               q1.pop_back();
           }
           
           q1.push_back(i);
           
           while(!q2.empty() && nums[q2.back()]>nums[i])
           {
               q2.pop_back();
           }
           
           q2.push_back(i);
           
           while(!q1.empty() && !q2.empty() && nums[q1.front()]-nums[q2.front()]>limit)
           {
               if(q1.front()<q2.front())
               {
                   temp=q1.front()+1;
                   q1.pop_front();
               }
               else
               {
                   temp=q2.front()+1;
                   q2.pop_front();
               }
           }
           
           ans=max(ans,i-temp+1);
       }
        
        return ans;
        
        
        
    }
};
