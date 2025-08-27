#include <bits/stdc++.h>

using namespace std;

struct item
{
    string itemName;
    float weight;
    float profit;
    float profitByWeightRatio;
    float fraction;
    bool flag;
};

void DescendingInsertionSortAlgo(struct item* items, int n)
{
    for(int i=1; i<n; i++)
    {
        struct item key = items[i];
        float keyRatio = items[i].profitByWeightRatio;
        int j = i-1;

        while(j >= 0 && keyRatio > items[j].profitByWeightRatio)
        {
            items[j+1] = items[j];
            j--;
        }
        items[j+1] = key;
    }
}

void knapsackAlgo(struct item* items,int n, float capacity, float* netProfit)
{
    for(int i=0; i<n; i++)
    {
        if(items[i].weight<=capacity)
        {
            capacity = capacity - items[i].weight;
            *netProfit = *netProfit + items[i].profit;
            items[i].fraction = 1;
            items[i].flag= true;
        }
        else
        {
            float fraction = capacity/items[i].weight;

            float weight = items[i].weight*fraction;
            float profit = items[i].profit*fraction;

            capacity = capacity - weight;
            *netProfit = *netProfit+profit;
            items[i].profit = profit;
            items[i].fraction = fraction;
            items[i].flag= true;
            break;
        }
    }
}

int main()
{
    int totalObject, capacity;
    float netProfit = 0;
    cout<<"Knapsack capacity: ";
    cin>>capacity;
    cout<<"How many objects do you have: ";
    cin>>totalObject;
    struct item items[totalObject];
    cout<<"Enter objects (name weight profit):"<<endl;

    //Object entry
    for(int i=0; i < totalObject; i++)
    {
        cin>>items[i].itemName;
        cin>>items[i].weight;
        cin>>items[i].profit;
        items[i].profitByWeightRatio = (items[i].profit / items[i].weight);
        items[i].fraction = 1;
        items[i].flag = false;
    }
    //Object entry

    DescendingInsertionSortAlgo(items, totalObject);//sort

    //Object showcase
    cout<<"Sorted: "<<endl;
    for(int i=0; i < totalObject; i++)
    {
        cout<<items[i].itemName<<" ";
        cout<<items[i].weight<<" ";
        cout<<items[i].profit<<" ";
        cout<<items[i].profitByWeightRatio<<endl;
    }
    //Object showcase


    knapsackAlgo(items, totalObject, capacity, &netProfit);//main algorithm


    //MAIN OUTPUT
    cout << fixed << setprecision(3);
    cout<<endl<<endl<<"In our Knapsack we have: "<<endl;
    for(int i=0; i < totalObject; i++)
    {
        if(items[i].flag == true)
        {
            cout<<"Name: "<<items[i].itemName<<"\t";
            cout<<"Fraction: "<<items[i].fraction<<"\t";
            cout<<"Weight: "<<items[i].weight<<"\t";
            cout<<"Profit: "<<items[i].profit<<"\t";
            cout<<"Profit by weight ratio: "<<items[i].profitByWeightRatio<<endl;
        }
    }
    cout<<"Net profit: "<<netProfit<<" UNIT";
    //MAIN OUTPUT
}
