#include <stdio.h> 

int findIndex(int incomingStream[], int curr, int pages, int temp[], int frames){
    int index;
    int count = frames - 1;
    int temp_vis[3] = {0};
    for(int i = curr+1; i <= pages; i++){
        for(int j=0; j<frames; j++){
            if(incomingStream[i] == temp[j]){
                temp_vis[j] = 1;
                count --;
            }
        }
        if(count==0){
            break;
        }
    }
    for(int i=0; i<frames; i++){
        if(temp_vis[i] == 0){
            index = i;
        }
    }
    return index;
}

int main()
{
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");
    int temp[frames];
    for (m = 0; m < frames; m++){
        temp[m] = -1;
    }

    int tempIndex = 0;
    for (m = 0; m < pages; m++){
        s = 0;
        for (n = 0; n < frames; n++){
            if (incomingStream[m] == temp[n]){
                s++;
                pageFaults--;
            }
        }
    
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0)){
            temp[tempIndex] = incomingStream[m];
            tempIndex++;
        }
        else if (s == 0){
            tempIndex = findIndex(incomingStream, m, pages, temp, frames);
            temp[tempIndex] = incomingStream[m];
            // temp[(pageFaults - 1) % frames] = incomingStream[m];
            // tempIndex++;
        }
        
        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);

        for (n = 0; n < frames; n++){
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }

    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}


