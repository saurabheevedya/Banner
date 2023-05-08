// Program for Non-Preemptive Shortest Job First CPU Scheduling. 

#include <iostream>
using namespace std;

int main(){
    printf("Harshvardhan Kendre\n Roll No: 55\n");

    // Matrix for storing Process Id, Burst
    // Time, Average Waiting Time & Average
    // Turn Around Time.
    int A[100][5];
    int i, j, n, total = 0, index;
    float avg_wt, avg_tat;

    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"Enter Burst Time and Priority of Processes: "<<endl;

    // User Input Burst Time and alloting Process Id.
    for(i=0; i<n; i++){
        cout<<"P"<<i+1<<": ";
        cin>>A[i][1];
        cout<<"Priority: ";
        cin>>A[i][4];
        A[i][0] = i+1;
    }

    // Sorting processes acc to Burst times
    for(i=0; i<n; i++){
        index = i;
        for(j=i+1; j<n; j++){
            if(A[j][4] < A[index][4]){
                index = j;
            }
        }
        swap(A[i][4], A[index][4]);
        swap(A[i][1], A[index][1]);
        swap(A[i][0], A[index][0]);
    }

    // Calculating Waiting time
    A[0][2] = 0;
    for(i=1; i<n; i++){
        A[i][2] = A[i-1][1] + A[i-1][2];
        total += A[i][2];
    }
    avg_wt = (float)total / n;
    total = 0;
    cout << "P     BT     WT     TAT" << endl;

    // Calculating TAT
    for(i=0; i<n; i++){
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        cout<<"P" << A[i][0] << "     " << A[i][1] << "     " << A[i][2] << "      " << A[i][3] << endl;
    }

    avg_tat = (float)total / n;
    cout<<"Average Waiting Time: "<<avg_wt<<endl;
    cout<<"Average Turn Around Time: "<<avg_tat<<endl;
    
}


