// Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
//     1. 5 if a perfect square
//     2. 4 if multiple of 4 and divisible by 6
//     3. 3 if even number

// And sort the numbers based on the weight and print it as follows

// <10,its_weight>,<36,its weight><89,its weight>
#include <bits/stdc++.h>
using namespace std;
struct wt{
    int num;
    int weight;
};

bool comp(struct wt a, struct wt b){
    return a.weight<b.weight;
}

void assignVal(int arr[],struct wt ar[],int N){
    for(int i=0;i<N;i++){
            if(ceil(((double)sqrt(arr[i])))==floor((double)(sqrt(arr[i])))){
                ar[i].weight = 5;
                ar[i].num=arr[i];
            }
            else if(arr[i]%4==0 && arr[i]%6==0){
                ar[i].weight = 4;
                ar[i].num=arr[i];
            }
            else if(arr[i]%2==0){
                ar[i].weight=3;
                ar[i].num=arr[i];
            }

    }
    sort(ar,ar+N,comp);
    for(int i=0;i<N;i++){
        cout<<"<"<<ar[i].num<<","<<ar[i].weight<<">"<<endl;
    }
}
int main(){
    int arr[]={10, 36, 54, 12,88};
    struct wt ar[5];
    assignVal(arr,ar,5);
    return 0;
}