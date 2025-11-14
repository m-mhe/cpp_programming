#include <bits/stdc++.h>

using namespace std;

/*
Higher the priority number higher the priority.
*/





struct process
{
    string pID;
    int arivalTime;
    int priority;
    int burstTime;
    float completionTime;
    int turnAroundTime;
    float waitingTime;
    bool flag;
};

void sortArivalAscending(struct process* processes, int n)
{
    for(int i = 1; i<n; i++)
    {
        struct process key = processes[i];
        int j = i-1;
        while(j>=0 && key.arivalTime <= processes[j].arivalTime)
        {
            processes[j+1] = processes[j];
            j--;
        }
        processes[j+1] = key;
    }
}

void priorityScheduling(struct process* processes, int n)
{
    int currentTime = 0;
    //currentTime = processes[0].arivalTime;
    for(int i = 0; i < n; i++)
    {
        struct process* currentPriority = &processes[i]; //could be i instead of 0.
        for(int j = 0; j < n; j++)
        {
            if(currentTime >= processes[i].arivalTime && currentPriority->priority < processes[i].priority && processes[i].flag == false)
            {
                currentPriority = &processes[i];
            }
        }
        if(currentPriority->flag == false)
        {
            currentTime = currentTime + currentPriority->burstTime;
            currentPriority->flag = true;
            currentPriority->completionTime = currentTime;
            currentPriority->turnAroundTime = currentPriority->completionTime - currentPriority->arivalTime;
            currentPriority->waitingTime = currentPriority->turnAroundTime - currentPriority->burstTime;
        }

    }
}



int main()
{
    int processAmount, totalTAT, totalWT;
    totalTAT = 0;
    totalWT = 0;
    float averageTAT, averageWT;
    cout<<"Process amount: ";
    cin>>processAmount;
    struct process processes[processAmount];

    cout<<"Enter Process one by one(PID AT P BT): "<<endl;
    for(int i=0; i<processAmount; i++)
    {
        cin>>processes[i].pID;
        cin>>processes[i].arivalTime;
        cin>>processes[i].priority;
        cin>>processes[i].burstTime;
        processes[i].flag = false;
        processes[i].completionTime = 0;
        processes[i].turnAroundTime = 0;
        processes[i].waitingTime = 0;
    }

    sortArivalAscending(processes, processAmount); //Sorting by arrival time
    priorityScheduling(processes, processAmount); //Main function.

    for(int i=0; i<processAmount; i++)
    {
        totalTAT = totalTAT+processes[i].turnAroundTime;
        totalWT = totalWT + processes[i].waitingTime;
        cout<<processes[i].pID<<"\t"<<processes[i].arivalTime<<"\t"<<processes[i].priority<<"\t"<<processes[i].burstTime<<"\t"<<processes[i].completionTime<<"\t"<<processes[i].turnAroundTime<<"\t"<<processes[i].waitingTime<<"\t"<<endl;
    }
    averageTAT = totalTAT/processAmount;
    averageWT = totalWT/processAmount;
    cout<<"Average Turnaround time: "<<averageTAT<<", Average Waiting time: "<<averageWT<<endl;
}
