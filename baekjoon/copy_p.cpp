#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    // 논문  개수 n 떨어진 페이지 개수 m
    cin >> n >> m;

    vector<int> pages;

    // i번째 논문까지 모두 복구했을 때 드는 잉크
    // first : i번째 논문까지 출력할 때 드는 잉크의 양
    // second : 연속되게 출력할 때 처음 페이지의 번호
    vector<pair<int, int> > inks;
    // 계산을 위한 0번째 페이지를 추가한다
    inks.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++)
    {
        inks.push_back(make_pair(1001, i));     // 페이지 수대로 벡터를 삽입한다. 
    }

    for(int i=0;i<m;i++)    // 출력되어 있는 논문은 잉크 양과 페이지 번호를 0으로 설정한다. 
    {
        int page;
        cin >> page;
        inks[page].first = 0;
        inks[page].second = 0;
    }

    for(int i=1; i<=n ;i++)
    {
        if(inks[i].second == 0)     // 이미 논문이 출력되어 있는 경우 이전 잉크의 양과 시작 페이지와 정보가 동일하다
        {
            inks[i].second = inks[i-1].second;
            inks[i].first = inks[i-1].first;
        }
        else if (inks[inks[i-1].second - 1].first + (2 * (i - inks[i-1].second +1) + 5) < inks[i-1].first + 7)  // 만약 (기존 잉크의 양 + 이미 인쇄되어 있는 것을 일부러 인쇄해서라도 연속되게 출력하는데 드는 잉크의 양) < (전 페이지를 출력하는데 드는 잉크 양 + 새로 인쇄하는 7의 잉크)
        {           // 이면
            inks[i].second = inks[i-1].second;          // 연속해서 인쇄하는 것이므로 기존의 시작 페이지를 반영한다. 
            inks[i].first = inks[inks[i-1].second - 1].first + (2 * (i - inks[i-1].second + 1) + 5);    // 그리고 더 적은 잉크를 소모했던 (일부러 페이지를 더 인쇄하느라 든 잉크의 양)을 first에 대입한다. 
        }
        else    // 만약 연쇄해서 인쇄하지 않고 새로 인쇄하는 것이 더 경제적이라면
        {
            inks[i].second = i;     // 이 페이지에서 인쇄를 시작하므로 시작 페이지 번호를 현재 페이지로 메긴다
            inks[i].first = inks[i-1].first + 7;        // 더 적은 잉크를 소모했던 (그 전 잉크 + 새로운 용지를 출력하는데 드는 잉크 7)을 first로 초기화한다.
        }
    }

    cout<<inks[n].first;    // 마지막 페이지를 드는데 드는 총 잉크의 양을 출력한다. 
}