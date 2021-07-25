// Input:
// With the starting and ending time of work given find the minimum no of workers needed
// Start time[] = {0900, 0940, 0950, 1100, 1500, 1800}
// end time[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

#include <bits/stdc++.h>
using namespace std;

int findMinWorkers(int start_time[], int end_time[],int n){
    int min=1;
    for(int i=0;i<n-1;i++){
        int temp=1;
        for(int j=i+1;j<n;j++){
            if(start_time[i]>=start_time[j] && start_time[i]<=end_time[j] || start_time[j]>=start_time[i] && start_time[j]<=end_time[i]){
                temp++;
            }
            if(temp>min){
                min=temp;
            }
        }
    }
    return min;
}

int main(){
    int start_time[] = {900, 1100, 1235};
    int end_time[] ={1000, 1200, 1240};
    int size=*(&start_time+1)-start_time;
    cout<<findMinWorkers(start_time,end_time,size);
    return 0;
}