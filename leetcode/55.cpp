class Solution 
{
public:

    int jumping(vector<int>&nums, int zeros)
    {
        if(nums.size()>0)
            cout<<nums[0]<<" "<<nums.size()<<" "<<zeros<<endl;
        int answer = 0;
        for(int i=1 ; i<=nums.size() ; i++)
        {
            if(nums[nums.size() - i] >= zeros + i)
            {
                answer = max(answer, nums[nums.size()-i] - zeros - i + 1);
            }
        }
        return answer;
    }

    bool canJump(vector<int>& nums) 
    {
        if(nums.size()==1) return true;

        int zeros = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]!= 0)
            {
                if(zeros)
                {
                    vector<int> front;
                    front.assign(nums.begin(), nums.begin() + i - zeros);
                    int jumped = jumping(front, zeros);
                    if(jumped)
                    {
                        vector<int> back;
                        back.assign(nums.begin() + i, nums.end());
                        back.insert(back.begin(), jumped);
                        if(canJump(back)) return true;
                        else return false;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                    continue;
            }
            else
            {
                zeros++;
            }
        }
        if(zeros)
        {
            vector<int> front;
            front.assign(nums.begin(), nums.begin() + nums.size() - zeros);
            return jumping(front, zeros-1);
        }
        return true;
    }
};
