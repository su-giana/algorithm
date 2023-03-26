class Solution {
public:
    int isCycle(vector<vector<int> >& map, int cur, int target, int size)
    {
        if(target == cur)
        {
            return size;
        }

        int len = -1;
        for(int i=0 ; i<map.size() ; i++)
        {
            if(map[i][cur]==1)
            {
                len = max(isCycle(map, i, target, size+1), len);
            }
        }
        return len;
    }

    int isCycle(vector<vector<int> >& map, int target, int size)
    {
        int len = -1;
        for(int i=0 ; i<map.size() ; i++)
        {
            if(map[i][target]==1)
            {
                len = max(isCycle(map, i, target, size+1), len);
            }
        }
        return len;
    }

    int longestCycle(vector<int>& edges) 
    {
        vector<vector<int> > map(edges.size(), vector<int>(edges.size(), 0));

        for(int i = 0 ; i<edges.size() ; i++)
        {
            if(edges[i]==-1)    continue;

            map[i][edges[i]] = 1;
        }

        int answer = -1;
        for(int i=0 ; i<edges.size() ; i++)
        {
            answer = max(answer, isCycle(map, i, 0));
        }

        return answer;
    }
};