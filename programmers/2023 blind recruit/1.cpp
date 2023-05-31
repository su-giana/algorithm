#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> split(string s, char c)
{
    vector<string> ans;
    stringstream ss(s);
    string temp;
    
    while(getline(ss, temp, c))
    {
        ans.push_back(temp);
    }
    
    return ans;
}

vector<int> toInt(vector<string>& date)
{
    vector<int> ans;
    for(int i = 0 ; i<date.size() ; i++)
    {
        ans.push_back(stoi(date[i]));
    }
    
    return ans;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;
    vector<string> date = split(today, '.');
    vector<int> dates = toInt(date);
	
    unordered_map<string, int> rules;
    
    int m = terms.size();
    for(int i = 0 ; i<m ; i++)
    {
        vector<string> term = split(terms[i], ' ');
        rules.insert(make_pair(term[0], stoi(term[1])));
    }
    
    int n = privacies.size();
    for(int i = 0 ; i<n ; i++)
    {
        vector<string> contact = split(privacies[i], ' ');
        vector<string> privacy = split(contact[0], '.');
        
        int yyyy = stoi(privacy[0]);
        int mm = stoi(privacy[1]) - 1;
        int dd = stoi(privacy[2]);
        mm += rules[contact[1]];
        yyyy += mm/12;
        mm = mm%12 + 1;
        
        if(dates[0] > yyyy)	answer.push_back(i+1);
		else if(dates[0] == yyyy && dates[1] > mm)	answer.push_back(i+1);
        else if(dates[0]==yyyy && dates[1]==mm && dates[2] >= dd)	answer.push_back(i+1);
    }
    
    return answer;
}