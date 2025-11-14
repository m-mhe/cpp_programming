#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int AT[n], BT[n], CT[n], TAT[n], WT[n];
    for(int i=0; i<n; i++) {
        cout << "Enter AT and BT for P" << i+1 << ": ";
        cin >> AT[i] >> BT[i];
    }

    int time = 0;
    for(int i=0; i<n; i++) {
        if(time < AT[i]) time = AT[i];
        CT[i] = time + BT[i];
        time = CT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i]  = TAT[i] - BT[i];
    }

    float avgTAT=0, avgWT=0;
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i<n; i++) {
        cout << "P" << i+1 << "\t" << AT[i] << "\t" << BT[i]
             << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
        avgTAT += TAT[i];
        avgWT  += WT[i];
    }
    cout << "Average TAT = " << avgTAT/n << endl;
    cout << "Average WT = " << avgWT/n << endl;
}

