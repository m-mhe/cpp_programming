
#include <bits/stdc++.h>
using namespace std;

struct Proc {
    int id;     // 0..n-1
    int at;     // arrival time
    int bt;     // original burst time
    int rem;    // remaining time
    int ct = 0; // completion time
};

struct GanttSeg {
    int start;
    int end;
    int pid; // -1 for idle
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Number of processes: " << flush;
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid number of processes. Exiting.\n";
        return 1;
    }

    vector<Proc> P(n);
    for (int i = 0; i < n; ++i) {
        P[i].id = i;
        cout << "Process " << i+1 << " arrival time: " << flush;
        while (!(cin >> P[i].at)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an integer for arrival time: " << flush;
        }
        cout << "Process " << i+1 << " burst time: " << flush;
        while (!(cin >> P[i].bt) || P[i].bt <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive integer for burst time: " << flush;
        }
        P[i].rem = P[i].bt;
    }

    // Order processes by arrival time (stable)
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (P[a].at != P[b].at) return P[a].at < P[b].at;
        return P[a].id < P[b].id;
    });

    // Min-heap keyed by (remaining time, arrival time, id)
    using T = tuple<int,int,int>; // rem, at, id
    auto cmp = [](const T &x, const T &y){ return x > y; }; // min-heap
    priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

    int idx = 0;          // next arrival index in order[]
    int time = 0;         // current time
    int completed = 0;
    vector<GanttSeg> gantt;

    while (completed < n) {
        // push arrived processes into heap
        while (idx < n && P[order[idx]].at <= time) {
            int id = order[idx];
            pq.emplace(P[id].rem, P[id].at, id);
            ++idx;
        }

        if (pq.empty()) {
            // CPU idle -> jump to next arrival
            int nextAt = (idx < n) ? P[order[idx]].at : time;
            if (nextAt > time) {
                gantt.push_back({time, nextAt, -1});
                time = nextAt;
            }
            continue;
        }

        // take top (copy first to avoid const-ref structured-binding issue)
        auto topElem = pq.top(); pq.pop();
        int rem  = get<0>(topElem);
        int id   = get<2>(topElem);

        // time of next arrival (if any)
        int nextArrival = (idx < n) ? P[order[idx]].at : INT_MAX;

        // run either until process finishes or until next arrival
        int run = (nextArrival == INT_MAX) ? rem : min(rem, nextArrival - time);
        if (run <= 0) run = 1; // safeguard to move forward

        // record Gantt (coalesce contiguous segments of same pid)
        if (!gantt.empty() && gantt.back().pid == id && gantt.back().end == time) {
            gantt.back().end = time + run;
        } else {
            gantt.push_back({time, time + run, id});
        }

        // advance time and update remaining time
        time += run;
        P[id].rem -= run;

        // push any processes that arrived up to the new time
        while (idx < n && P[order[idx]].at <= time) {
            int nid = order[idx];
            pq.emplace(P[nid].rem, P[nid].at, nid);
            ++idx;
        }

        if (P[id].rem == 0) {
            P[id].ct = time;
            ++completed;
        } else {
            // push back with updated remaining time
            pq.emplace(P[id].rem, P[id].at, id);
        }
    }

    // compute TT and WT and averages
    vector<int> tt(n), wt(n);
    long long sumTT = 0, sumWT = 0;
    for (int i = 0; i < n; ++i) {
        tt[i] = P[i].ct - P[i].at;
        wt[i] = tt[i] - P[i].bt;
        sumTT += tt[i];
        sumWT += wt[i];
    }
    double avgTT = (double)sumTT / n;
    double avgWT = (double)sumWT / n;

    // Output results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << i+1 << "\t"
             << P[i].at << "\t"
             << P[i].bt << "\t"
             << P[i].ct << "\t"
             << tt[i] << "\t"
             << wt[i] << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time = " << avgTT << "\n";
    cout << "Average Waiting Time    = " << avgWT << "\n";

    // Print textual Gantt chart
    cout << "\nGantt Chart (start-end : PID)\n";
    for (auto &s : gantt) {
        if (s.pid == -1) cout << s.start << "-" << s.end << ": idle\n";
        else            cout << s.start << "-" << s.end << ": P" << s.pid+1 << "\n";
    }

    return 0;
}
