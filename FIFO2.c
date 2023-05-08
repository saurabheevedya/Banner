#include<conio.h>
#include<stdio.h>
int cachehit(int pages, int queue[]){
    for (int i = 0; i < 3; i++)
    {
        if (queue[i]==pages)
        {
            return 1;
        }
        
    }
    return 0;
    
}

void printframe(int pages[] , int queue[] , int occupied, int k){
    printf("%d:\t\t\t" , pages[k]);
    // printf("%d\n",occupied);
    for (int i = 0; i < occupied; i++)
    {
        printf("%d\t\t\t" , queue[i]);
    }
    printf("\n");
}

int main(){
    int pages[] = {1 ,2 , 3 ,2 , 1 , 5 , 2 , 1 , 6};
    int occupied = 0 , pagefaults  = 0;
    int n = sizeof(pages)/sizeof(pages[0]);
    int queue[n];
    int frames = 3;
    int distance[n];
    printf("pages\t\t\tframe1\t\t\tframe2\t\t\tframe3\t\t\t\n");
    for (int i = 0; i < n; i++)
    {
        int c = cachehit(pages[i] , queue);
        if(c==1){
            printframe(pages, queue,occupied,i);
        }
        else if(occupied<frames){
            queue[occupied] = pages[i];
            occupied++;
            printframe(pages, queue,occupied,i);
            pagefaults++;
        }
        else{
            int max = -1;
            int index;
            for (int j = 0; j < frames; j++)
            {
                distance[j]=0;
                for (int k = i-1; k >=0; k--)
                {
                    if (queue[j]==pages[k])
                    {
                        ++distance[j];
                    }
                }
                if(distance[j]>max){
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = pages[i];
            pagefaults++;
            printframe(pages, queue,occupied,i);
        }
    }
 
}