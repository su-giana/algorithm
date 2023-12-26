#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node{
  public:
  string name; // state node name

  int cnt;
  int minScope;
  int maxScope;

  bool transited; // for syncronization
  bool state; // 0: deactivated, 1: activated
  bool isTerminal; // 0: terminal, 1: non-terminal
  
  char match; // target character for matching

  vector<node*> next; // next link 


  void init(const string &_name, bool _isTerminal, char _match, int _minScope, int _maxScope) {
    this->name = _name;

    isTerminal = _isTerminal;
    match = _match;

    cnt = 0;
    minScope = _minScope;
    maxScope = _maxScope;
    state = transited = 0;
  }

  void changeName(int n) {
    this->name = to_string(n) + "th";
  }

  void addNode(node *_next){
    next.push_back(_next);
  }
 
  // for syncronization
  node& transition() { 
    transited = 1; 
    return *this;
  }
  void activation(){
    state = transited;
    transited = 0;
  }

  void input(const char &ch){
    if (state && (match == ch || match == '.'))  cnt++;
    bool isActivated = false;

    if(state && minScope == 0){
      if(isTerminal){
        cout << "  >>>> accepted by " << this->name << endl;
      }

      if (cnt < maxScope) {
        this->transition();
        isActivated = true;
      }
      if (cnt >= minScope && cnt <= maxScope) {
        for(int i = 0 ; i < next.size(); i++){
          next[i]->transition();
        }
      }
    }

    else if (state && (match == '.' || match == ch)) {
      if(isTerminal && cnt>=minScope && cnt<=maxScope) {
        cout << "  >>>> accepted by " << this->name << endl;
      }

      if (cnt < maxScope) {
        this->transition();
        isActivated = true;
      }
      if (cnt >= minScope && cnt <= maxScope) {
        for(int i = 0 ; i < next.size(); i++){
          next[i]->transition();
        }
      }
    }
    
    if (!isActivated) state = 0; // deactivate this node after matching
  }
};

vector<node> wholeNodes;

void test(vector<node> &s, const string &str){
  cout << "test for ' " << str << "'" << endl;

  for(int i = 0 ; i < str.length() ; i++){
    cout<< "  >> input " << str[i] << endl;
    
    // epsilon activation for s0
    s[s.size() - 1].transition().activation();
    if (str.size() > 0 && str[1] == '|')  s[s.size() - 2].transition().activation();
   
    // give ch all nodes
    for(int j = 0 ; j < s.size(); j++)
      s[j].input( str[i] );
    
    // determine transited state
    for(int j = 0 ; j < s.size(); j++)
      s[j].activation();

  }
}

void initRegexTree(string regex) {
  queue<vector<pair<char, pair<int, int> > > > s;
  bool isOrMode = false;
  int idx = 0;

  int cntAlp = 0;
  for (int i = 0 ; i<regex.size() ; i++) {
    if (regex[i]>='A' && regex[i]<='Z') cntAlp++;
    if (regex[i] == '.')  cntAlp++;
  }

  wholeNodes = vector<node>(cntAlp);

  while (idx < regex.size( )) {
    if ((regex[idx]>='A' && regex[idx]<='Z') || regex[idx] == '.') {
      if (isOrMode) {
        s.front( ).push_back(make_pair(regex[idx], make_pair(1, 1)));
        isOrMode = false;
      }
      else {
        s.push(vector<pair<char, pair<int, int> > >(1, make_pair(regex[idx], make_pair(1, 1))));
      }
    }
    if(regex[idx] == '*') {
      vector<pair<char, pair<int, int> > > cur = s.front( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(0, INT_MAX);
      s.push(cur);
    }
    if(regex[idx] == '+') {
      vector<pair<char, pair<int, int> > > cur = s.front( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(1, INT_MAX);
      s.push(cur);
    }
    if(regex[idx] == '{') {
      int start = idx;
      while (regex.size() > idx && regex[idx] != '}') idx++;
      string sp = regex.substr(start+1, idx);
      int n = stoi(sp.substr(0, sp.find(',')));
      int m = stoi(sp.substr(sp.find(' ')+1));

      vector<pair<char, pair<int, int> > > cur = s.front( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(n, m);
      s.push(cur);
    }
    if (regex[idx] == '|') {
      isOrMode = true;
    }

    idx++;
  }

  int cur = 0;
  int now = 0;
  idx = 0;  

  while (s.size( ) > 1) {
    cur = idx;
    int curCnt = 0;
    for(pair<char, pair<int, int> > p : s.front( )) {
      string name = to_string(idx) + "th";
      wholeNodes[idx].init(name, 0, p.first, p.second.first, p.second.second);
      for (int i = 1 ; i<=now ; i++) {
        wholeNodes[idx].addNode(&wholeNodes[cur - i]);
      }
      curCnt++;
      idx++;
    }

    now = curCnt; 
    s.pop( );
  }

  for(pair<char, pair<int, int> > p : s.front( )) {
      string name = to_string(idx) + "th";
      wholeNodes[idx].init(name, 1, p.first, p.second.first, p.second.second);
      idx++;
      now++;
    }
    s.pop( );
}

int main(){
  string regex;
  getline(cin, regex);

  initRegexTree(regex);

  // set test cases
  string test1 = "ABBD";

  test(wholeNodes, test1);
}
