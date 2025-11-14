#include <bits/stdc++.h>
using namespace std;

struct Proc {
    string id;
    int at, bt, pr;
    int rt, ct, tat, wt;
};

int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;
    vector<Proc> P(n);
    for (int i=0; i<n; i++) {
        P[i].id = "P" + to_string(i+1);
        cout << "Arrival, Burst, Priority for " << P[i].id << ": ";
        cin >> P[i].at >> P[i].bt >> P[i].pr;
        P[i].rt = P[i].bt;
    }

    int time = 0, completed = 0;
    while (completed < n) {
        int idx = -1;
        for (int i=0; i<n; i++) {
            if (P[i].at <= time && P[i].rt > 0) {
                if (idx == -1 || P[i].pr > P[idx].pr) idx = i;
            }
        }
        if (idx == -1) { time++; continue; }

        P[idx].rt--;
        time++;
        if (P[idx].rt == 0) {
            P[idx].ct = time;
            P[idx].tat = P[idx].ct - P[idx].at;
            P[idx].wt  = P[idx].tat - P[idx].bt;
            completed++;
        }
    }

    double sumTAT=0, sumWT=0;
    cout << "ID\tAT\tBT\tPr\tCT\tTAT\tWT\n";
    for (auto &p: P) {
        cout << p.id << "\t" << p.at << "\t" << p.bt << "\t" << p.pr
             << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
        sumTAT += p.tat; sumWT += p.wt;
    }
    cout << "Average TAT = " << sumTAT/n << "\n";
    cout << "Average WT = " << sumWT/n << "\n";
}
