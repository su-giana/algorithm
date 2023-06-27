#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<unsigned long long> Tree(1500000, 0);
vector<unsigned long long> Lazy(1500000, 0);

vector<string> split(string s, char delimeter)
{
    vector<string> answer;
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, delimeter))
    {
        answer.push_back(temp);
    }
    
    return answer;
}

void push(unsigned long long node, long long begin, long long end)
{
    if(Lazy[node]!=0)
    {
        Tree[node] += (end - begin + 1) * Lazy[node];
        if(begin!=end)
        {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}

void refresh(unsigned long long node, long long begin, long long end, long long start, long long finish)
{
    push(node, begin, end);
    if(end < start || begin > finish)	return;
    if(begin>=start && end<=finish)
    {
        Lazy[node] += 1;
        push(node, begin, end);
        return;
    }
    
    int mid = begin + (end - begin) / 2;
    refresh(node*2, begin, mid, start, finish);
    refresh(node*2+1, mid+1, end, start, finish);
    Tree[node] = Tree[node*2] + Tree[node*2 + 1];
}

unsigned long long query(long long node, long long begin, long long end, long long left, long long right)
{
    push(node, begin, end);
    if(begin>right || end < left)	return 0;
    if(left<=begin && end<=right)	return Tree[node];
    
    int mid = begin + (end - begin) / 2;
    return query(2*node, begin, mid, left, right) + query(2*node+1, mid+1, end, left, right);
}

string convertToStr(unsigned long long num)
{
    string answer = "";
    
    answer += to_string(num/3600).length()==1 ? "0" + to_string(num/3600) : to_string(num/3600);
    num %= 3600;
    answer += ":";
    answer += to_string(num/60).length()==1 ? "0" + to_string(num/60) : to_string(num/60);
    num %= 60;
    answer += ":";
    answer += to_string(num).length()==1 ? "0" + to_string(num) : to_string(num);
    
    return answer;
}

unsigned long long convertToNum(string s)
{
    vector<string> times = split(s,':');
    return stoi(times[0]) * 3600 + stoi(times[1]) * 60 + stoi(times[2]);
}

string solution(string play_time, string adv_time, vector<string> logs) 
{
    unsigned long long maxTime = 0;
	unsigned long long ans;
    unsigned long long advTime = convertToNum(adv_time)-1;
    unsigned long long m = logs.size();
    unsigned long long playTime = convertToNum(play_time)-1;
   
    for(int i = 0 ; i<m ; i++)
    {
        vector<string> times = split(logs[i], '-');
        unsigned long long start = convertToNum(times[0]);
        unsigned long long finish = convertToNum(times[1])-1;
        
        refresh(1, 0, playTime, start, finish);
    }
    
    for(int i = 0 ; i+advTime<=playTime ; i++)
    {
        unsigned long long temp = query(1, 0, playTime, i, i+advTime);
		if(temp > maxTime)
        {
            maxTime = temp;
            ans = i;
        }
    }
    
    return convertToStr(ans);
}