
#include <bits/stdc++.h>
using namespace std;

struct P {
    string id;
    int at, bt, rt, ct = -1;
};

int main() {
    int n, q;
    cout << "Number of processes: ";
    cin >> n;
    cout << "Time quantum: ";
    cin >> q;

    vector<P> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].id = "P" + to_string(i + 1);
        cout << "Arrival and Burst for " << a[i].id << ": ";
        cin >> a[i].at >> a[i].bt;
        a[i].rt = a[i].bt;
    }

    // Sort by arrival to process in order
    stable_sort(a.begin(), a.end(), [](const P& x, const P& y){ return x.at < y.at; });

    queue<int> rq;
    int time = 0, done = 0, i = 0, N = n;

    auto enqueue_arrivals = [&](int upto){
        while (i < N && a[i].at <= upto) rq.push(i++); // push indices
    };

    // start: if nothing ready, jump to first arrival
    if (i < N && rq.empty()) { time = a[i].at; enqueue_arrivals(time); }

    while (done < N) {
        if (rq.empty()) { time = a[i].at; enqueue_arrivals(time); continue; }
        int k = rq.front(); rq.pop();

        int run = min(q, a[k].rt);
        int start = time, endt = time + run;

        // Arrivals during execution will be enqueued right after we advance time
        a[k].rt -= run;
        time = endt;
        enqueue_arrivals(time);

        if (a[k].rt > 0) rq.push(k);
        else { a[k].ct = time; ++done; }
    }

    double sumT=0, sumW=0;
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : a) {
        int tat = p.ct - p.at;
        int wt  = tat - p.bt;
        sumT += tat; sumW += wt;
        cout << p.id << '\t' << p.at << '\t' << p.bt << '\t'
             << p.ct << '\t' << tat << '\t' << wt << '\n';
    }
    cout << "Average TAT = " << sumT/N << "\n";
    cout << "Average WT  = " << sumW/N << "\n";
    return 0;
}
