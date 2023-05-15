#include <iostream>
#include <vector>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Paper
{
    public:
    int x;
    int y;
    int n;
    vector<int> nums;

    Paper(int x_, int y_, int n_)
    {
        x = x_;
        y = y_;
        n = n_;
        
        for(int i = 0 ; i<3 ; i++)
            nums.push_back(0);
    }
};

Paper getPaper(Paper paper, vector<vector<int> >& papers)
{
    if(paper.n==1)
    {
        int num = papers[paper.x][paper.y];
        paper.nums[num+1]++;
        return paper;
    }

    bool allMinusOne = true, allZero = true, allOne = true;

    int div = paper.n/3;
    for(int i = 0 ; i<paper.n ; i += div)
    {
        for(int j = 0 ; j<paper.n ; j += div)
        {
            Paper temp = getPaper(Paper(paper.x+i, paper.y+j, div), papers);
            
            if(!(temp.nums[0] && !temp.nums[1] && !temp.nums[2]))
                allMinusOne = false;
            if(!(!temp.nums[0] && temp.nums[1] && !temp.nums[2]))
                allZero = false;
            if(!(!temp.nums[0] && !temp.nums[1] && temp.nums[2]))
                allOne = false;
            
            for(int i = 0 ; i<3 ; i++)
            {
                paper.nums[i] += temp.nums[i];
            }
        }
    }

    if(allMinusOne) paper.nums = {1, 0, 0};
    else if(allZero)    paper.nums = {0, 1, 0};
    else if(allOne)     paper.nums = {0, 0, 1};

    return paper;
}

int main()
{
    init();

    int n;
    cin>>n;
    
    vector<vector<int> > papers(n, vector<int>(n, 0));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            int paper;
            cin>>paper;
            papers[i][j] = paper;
        }
    }

    Paper ans = getPaper(Paper(0, 0, n), papers);
    for(int i = 0 ; i<3 ; i++)
    {
        cout<<ans.nums[i]<<'\n';
    }

    return 0;
}