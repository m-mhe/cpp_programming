
#include <bits/stdc++.h>
using namespace std;

struct Proc
{
    string id;
    int at; // arrival time
    int bt; // burst time
    int pr; // priority (smaller = higher priority)
    int ct=0, tat=0, wt=0;
    bool done=false;
};

int main()
{
    int n;
    cout << "Number of processes: ";
    cin >> n;
    vector<Proc> P(n);
    for (int i=0; i<n; i++)
    {
        P[i].id = "P" + to_string(i+1);
        cout << "Arrival, Burst, Priority for " << P[i].id << ": ";
        cin >> P[i].at >> P[i].bt >> P[i].pr;
    }
    // stable sort by arrival time to keep input order for ties
    stable_sort(P.begin(), P.end(), [](const Proc &a, const Proc &b)
    {
        return a.at < b.at;
    });

    int time = 0, completed = 0;
    while (completed < n)
    {
        // collect ready processes
        int idx = -1;
        for (int i=0; i<n; i++)
        {
            if (!P[i].done && P[i].at <= time)
            {
                if (idx == -1 || P[i].pr < P[idx].pr || (P[i].pr == P[idx].pr && P[i].at < P[idx].at))
                    idx = i;
            }
        }
        if (idx == -1)
        {
            // no process ready — jump to next arrival
            int nxt = INT_MAX;
            for (int i=0; i<n; i++) if (!P[i].done) nxt = min(nxt, P[i].at);
            time = nxt;
            continue;
        }
        // run selected process to completion (non-preemptive)
        P[idx].ct = time + P[idx].bt;
        time = P[idx].ct;
        P[idx].tat = P[idx].ct - P[idx].at;
        P[idx].wt  = P[idx].tat - P[idx].bt;
        P[idx].done = true;
        completed++;
    }

    double sumTAT=0, sumWT=0;
    cout << "ID\tAT\tBT\tPr\tCT\tTAT\tWT\n";
    for (auto &p: P)
    {
        cout << p.id << '\t' << p.at << '\t' << p.bt << '\t' << p.pr << '\t'
             << p.ct << '\t' << p.tat << '\t' << p.wt << '\n';
        sumTAT += p.tat;
        sumWT += p.wt;
    }
    cout << "Average TAT = " << (sumTAT/n) << "\nAverage WT = " << (sumWT/n) << endl;
    return 0;
}
