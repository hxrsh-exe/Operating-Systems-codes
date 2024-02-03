#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of processes: ";
    cin>>n;
    vector <pair<int,pair<int,int>>> pro;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"Enter Arrival & Burst time for process "<<i+1<<endl;
        cin>>x>>y;
        pro.push_back({i,{x,y}});
    }
    int timeQuanta;
    cout<<"Enter Time quanta:";
    cin>>timeQuanta;
    unordered_set <int> s;
    queue <int> q;
    vector <int> rt;
    vector <int> wt(n,0);
    vector <int> tat(n,0);
    for(int i=0;i<n;i++){
        rt.push_back(pro[i].second.second);
    }
    float totaltat = 0, totalwt = 0;
    int tp = 0;
    int ct = 0;
    while(tp < n)
    {
        for(int i=0;i<pro.size();i++)
        {
            if(ct >= pro[i].second.first && rt[i] > 0 && s.find(pro[i].first) == s.end())
            {
                q.push(i);
                s.insert(pro[i].first);
            }
        }
        if(!q.empty())
        {
        int pehla = q.front();
        q.pop();    
        for(int i=0;i<timeQuanta;i++)
        {
            rt[pehla] = rt[pehla] - 1;
            ct = ct + 1;
            for(int i=0;i<pro.size();i++)
            {
            if(ct >= pro[i].second.first && rt[i] > 0 && s.find(pro[i].first) == s.end())
                {
                q.push(pro[i].first);
                s.insert(pro[i].first);
                }
            }
            if(rt[pehla] == 0)
            {
                tat[pehla] = ct - pro[pehla].second.first;
                wt[pehla] = tat[pehla] - pro[pehla].second.second;
                tp++;
                break;
            }
            
        }
        if(rt[pehla] > 0)
        {
            q.push(pehla);
        }
        }else{
            ct++;
        }
        
    }
    cout<<"WT: ";
    for(int i=0;i<n;i++)
    {
        cout<<wt[i]<<" ";
        totalwt += wt[i];
    }
        cout<<endl;
    cout<<"TAT: ";
    for(int i=0;i<n;i++)
    {
        cout<<tat[i]<<" ";
        totaltat += tat[i];
    }
        cout<<endl;
    
    cout<<"Avg waiting time : "<<totalwt/n<<endl;
    cout<<"Avg turn around time : "<<totaltat/n<<endl;
    return 0;
}

