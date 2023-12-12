#include <iostream>
#include <vector>
#include <stack>
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
    name = _name;

    isTerminal = _isTerminal;
    match = _match;

    cnt = 0;
    minScope = _minScope;
    maxScope = _maxScope;
    state = transited = 0;
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
    
    if(state && (match == ch)){
      if(isTerminal){
        cout << "  >>>> accepted by " << name << endl;
      }

      for(int i = 0 ; i < next.size(); i++){
        next[i]->transition();
      }
    }
    if (state && (match == '.')) {
        if(isTerminal) {
        cout << "  >>>> accepted by " << name << endl;
      }

      for(int i = 0 ; i < next.size(); i++){
        next[i]->transition();
      }
    }
    
    state = 0; // deactivate this node after matching
  }
};

void test(vector<node> &s, const string &str){
  cout << "test for ' " << str << "'" << endl;

  for(int i = 0 ; i < str.length() ; i++){
    cout<< "  >> input " << str[i] << endl;
    
    // epsilon activation for s0
    s[0].transition().activation();
   
    // give ch all nodes
    for(int j = 0 ; j < s.size(); j++)
      s[j].input( str[i] );
    
    // determine transited state
    for(int j = 0 ; j < s.size(); j++)
      s[j].activation();
  }
  cout << endl;
}

vector<node> initRegexTree(string regex) {
  stack<vector<pair<char, pair<int, int> > > > s;
  bool isOrMode = false;
  int idx = 0;

  while (idx < regex.size( )) {
    if ((regex[idx]>='A' && regex[idx]<='Z') || regex[idx] == '.') {
      if (isOrMode) {
        s.top( ).push_back(make_pair(regex[idx], make_pair(1, 1)));
        isOrMode = false;
      }
      else {
        s.push(vector<pair<char, pair<int, int> > >(1, make_pair(regex[idx], make_pair(1, 1))));
      }
    }
    if(regex[idx] == '*') {
      vector<pair<char, pair<int, int> > > cur = s.top( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(0, INT_MAX);
      s.push(cur);
    }
    if(regex[idx] == '+') {
      vector<pair<char, pair<int, int> > > cur = s.top( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(1, INT_MAX);
      s.push(cur);
    }
    if(regex[idx] == '{') {
      int start = idx;
      while (regex[idx] != '}') idx++;
      string sp = regex.substr(start+1, idx);
      int n = stoi(sp.substr(0, sp.find(',')));
      int m = stoi(sp.substr(sp.find(' ')+1));

      vector<pair<char, pair<int, int> > > cur = s.top( );
      s.pop( );

      cur[cur.size( ) - 1].second = make_pair(n, m);
      s.push(cur);
    }
    if (regex[idx] == '|') {
      isOrMode = true;
    }

    idx++;
  }

  vector<node> wholeNodes;
  vector<node> preNodes;
  while (s.size( ) > 2) {
    vector<node> nodes;
    for(pair<char, pair<int, int> > p : s.top( )) {
      node* nd = new node;
      nd->init(p.first + "", 0, p.first, p.second.first, p.second.second);
      for (node n : preNodes) {
        nd->addNode(&n);
      }
      nodes.push_back(*nd);
      wholeNodes.push_back(*nd);
    }

    s.pop( );
    preNodes = nodes;
  }

  if (s.size( ) == 1) {
    vector<node> nodes;
    for(pair<char, pair<int, int> > p : s.top( )) {
      node* nd = new node;
      nd->init(p.first + "", 1, p.first, p.second.first, p.second.second);
      for (node n : preNodes) {
        nd->addNode(&n);
      }
      nodes.push_back(*nd);
      wholeNodes.push_back(*nd);
    }
    preNodes = nodes;
  }

  reverse(wholeNodes.begin(), wholeNodes.end());
  return wholeNodes;
}

int main(){
  string regex;
  cin>>regex;

  vector<node> initTree = initRegexTree(regex);
 
  // set test cases
  string test1 = "ACDEB";

  test(initTree, test1);
}
