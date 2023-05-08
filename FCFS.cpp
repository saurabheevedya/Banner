#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]){
    wt[0] = 0;
    for(int i=1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }
}

void findavgTime(int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 

    findWaitingTime(processes, n, bt, wt);

    findTurnaroundTime(processes, n, bt, wt, tat);

    cout<<"Processes "<<" Burst Time "<<" Waiting Time "<<" Turn around time\n";

    for(int i=0; i<n; i++){
        cout<<"   "<< i+1<< "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout<<"Average waiting time: "<< (float)total_wt/(float)n<<endl;
    cout<<"Average Turn around time: "<< (float)total_tat/(float)n<<endl;
}

int main(){
    printf("Harshvardhan Kendre\n Roll No: 55\n");
    int processes[] = {1, 2, 3};
    int n = sizeof(processes)/ sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    findavgTime(processes, n, burst_time);
    return 0;
}

