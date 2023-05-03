#include <iostream>
#include <vector>

using namespace std;

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

    int div = paper.n/3;
    for(int i = 0 ; i<paper.n ; i += div)
    {
        for(int j = 0 ; j<paper.n ; j += div)
        {
            Paper temp = getPaper(Paper(paper.x+i, paper.y+j, div), papers);
            for(int k = 0 ; k<3 ; k++)
            {
                paper.nums[k] += temp.nums[k];
            }
        }
    }

    for(int i = 0 ; i<3 ; i++)
    {
        if(paper.nums[i] == 9)  paper.nums[i] = 1;
    }
    return paper;
}

int main()
{
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