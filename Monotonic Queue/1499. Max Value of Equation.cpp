class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        vector<pair<int,int>>v;
        
        for(int i=0; i<points.size(); i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            v.push_back({x,y});
        }
        
        deque<int>dq;
        int ans=INT_MIN;
        
        for(int i=0; i<v.size(); i++)
        {
            int x=v[i].first;
            int y=v[i].second;
            
            while(!dq.empty() && x-v[dq.front()].first>k)
                dq.pop_front(); 
            
            if(!dq.empty())
                ans=max(ans,x+y+v[dq.front()].second-v[dq.front()].first);
            
            while(!dq.empty() && v[dq.back()].second-v[dq.back()].first<=y-x)
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        return ans;
        
    }
};
