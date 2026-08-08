class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxheap;

        for(auto point:points){
            int x= point[0];
            int y= point[1];

            int dist= x*x + y*y;
           
            maxheap.push({dist,point});

            if(maxheap.size()>k)
            maxheap.pop();
        }
        vector<vector<int>> ans;

        while(!maxheap.empty()){
        ans.push_back(maxheap.top().second);
        maxheap.pop();
        }
        return ans;

    }
};
