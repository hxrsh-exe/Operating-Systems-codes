#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of processes: ";
    cin>>n;
    vector <pair <int,pair<int,int>>> pro;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"Enter Arrival & Burst time for process "<<i+1<<":"<<endl;
        cin>>x>>y;
        pro.push_back({i+1,{x,y}});
    }
    sort(pro.begin(),pro.end(),[&] (auto &a,auto &b) {
        return a.second.second < b.second.second;
    });
    vector <int> wt(n,0);
    vector <int> tat(n,0);
    unordered_set <int> s;
    float totaltat = 0, totalwt = 0;
    int ct = 0;
    int tp = 0;
    while(tp < n)
    {   
        int smallest = -1;
        for(int i=0;i<pro.size();i++)
        {
            if(ct >= pro[i].second.first && s.find(pro[i].first) == s.end())
            {
                smallest = i;
                break;
            }
        }
        if(smallest == -1)
        {
            ct++;
            continue;
        }
        s.insert(pro[smallest].first);
        ct = ct + pro[smallest].second.second;
        tat[smallest] = ct - pro[smallest].second.first;
        wt[smallest] = tat[smallest] - pro[smallest].second.second;
        tp++;
    }
    for(int i=0;i<n;i++)
    {
        totaltat += tat[i];
    }
    for(int i=0;i<n;i++)
    {
        totalwt += wt[i];
    }
    cout<<"Avg waiting time : "<<totalwt/n<<endl;
    cout<<"Avg turn around time : "<<totaltat/n<<endl;
    return 0;
}