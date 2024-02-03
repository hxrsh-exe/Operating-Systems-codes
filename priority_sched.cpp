
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<< "Enter no. of processes: ";
    cin>>n;
    vector <pair <int,pair<int,pair<int,int>>>> pro;
    for(int i=0;i<n;i++)
    {
        int x,y,p;
        cout<<"Enter Arrival time, Burst time, Priority:";
        cin>>x>>y>>p;
        pro.push_back({i,{p,{x,y}}});
    }
    vector <int> tat(n,0);
    vector <int> wt(n,0);
    unordered_set <int> s;
    float totaltat = 0.0, totalwt = 0.0;
    int tp = 0,ct = 0;
    cout<< "Order of execution:";
    while(tp < n)
    {      
        int smallest = -1; 
        int prio = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            if(ct >= pro[i].second.second.first && s.find(pro[i].first) == s.end() && prio > pro[i].second.first)
            {
                prio = pro[i].second.first;
                smallest = i;
            }
        }
        
        if(smallest == INT_MAX)
        {
            ct++;
            continue;
        }
        cout<<pro[smallest].first +1<<" ";
        s.insert(pro[smallest].first);
        ct = ct + pro[smallest].second.second.second;
        tat[smallest]  = ct - pro[smallest].second.second.first;
        wt[smallest] = tat[smallest] - pro[smallest].second.second.second   ;
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
    cout<<endl;
    cout<<"Avg Waiting time : "<<totalwt/n<<endl;
    cout<<"Avg Turn Around time : "<<totaltat/n<<endl;
    return 0;
}