class Solution {
public:
    
    bool solve(vector<int>&task,vector<int>&worker,int pills,int strength,int mid)
    {
         
        deque<int>dq;
        int i=worker.size()-1;
        
        for(int j=mid; j>=0; j--)
        {
            while(i>=0 && worker[i]+strength>=task[j])
            {
                dq.push_front(worker[i]);
                i--;
            }
            
            if(dq.size()==0)
                return 0;
            
            if(dq.back()>=task[j])
            {
                dq.pop_back();
            }
            else
            {
                if(pills==0)
                    return 0;
                pills--;
                dq.pop_front();
            }
        }
        
        return 1;
    }
    
    
    
    int maxTaskAssign(vector<int>& task, vector<int>& worker, int pills, int strength) {
        
        int low=0;
        int high=min((int)task.size(),(int)worker.size())-1;
        sort(task.begin(),task.end());
        sort(worker.begin(),worker.end());
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(solve(task,worker,pills,strength,mid))
                low=mid+1;
            else
                high=mid-1;
            
        }
          
        return low;   
        
    }
};
