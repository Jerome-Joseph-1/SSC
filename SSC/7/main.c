#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct proc{
    int id;
    int arrival;
    int burst;
    int rem;
    int tat;
    int wait;
    int finish;
} process;

int min(int a, int b) {
    return (a<b)?a:b;
}

void sort(process *p, int n) {
    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
}

int isEmpty(process* p, int n){
    for(int i = 0; i < n; i++) {
        if(p[i].rem) return 0;
    }
    return 1;
}

int find_next_process(process* p, int n) {
    int time = 9999, next_process = -1;
    for (int i = 0; i < n; i++)
    {
        if(p[i].rem && p[i].rem < time) {
            time = p[i].rem;
            next_process = i;
        }
    }
    return next_process;
    
}

void srtf() {
    process p[100];
    int n;

    printf("Enter number of processes : ");
    scanf("%d", &n);

    printf("Enter process Arrival and Burst times\n");
    for(int i = 0; i < n; i++) {
        p[i].id = i;
        scanf("%d%d", &p[i].arrival, &p[i].burst);
        p[i].rem = p[i].burst;
        p[i].wait = 0;
    }

    sort(p, n);

    int arrived = -1, time = 0, current_process = -1;
    while(!isEmpty(p, n)) {
        while (p[arrived + 1].arrival == time) {
            arrived++;
            if(current_process != -1 && !p[current_process].rem) p[current_process].finish = time;
            current_process = find_next_process(p, arrived + 1);
        }

        if(arrived > -1 && current_process != -1) {
            if(p[current_process].rem) {
                p[current_process].rem--;
                for (int i = 0; i < arrived + 1; i++)
                {
                    if(p[i].rem && i != current_process) p[i].wait++;
                }
            } 
            else {
                p[current_process].finish = time;
                time--;
                current_process = find_next_process(p, arrived + 1);
            }
        }
        time++;
    }
    p[current_process].finish = time;
    printf("ID\tARRIVAL\tBURST\tFINISH\tWAIT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id + 1, p[i].arrival, p[i].burst, p[i].finish, p[i].wait, p[i].finish - p[i].arrival);
    }
    
}

void rr(){
    int n, time = 0, tq;
    process p[100];
    printf("Enter Number of processes and time quantum : ");
    scanf("%d%d", &n, &tq);

    printf("Enter Burst Times : ");
    for(int i = 0; i < n; i++) {
        p[i].id = 0;
        scanf("%d", &p[i].burst);
        p[i].rem = p[i].burst;
    }

    while(!isEmpty(p, n)) {
        for (int i = 0; i < n; i++) {
            if(p[i].rem) {
                int run_time = min(p[i].rem, tq);
                p[i].rem -= run_time;
                time += run_time;
                p[i].tat = time;
            }
        }
    }

    printf("ID\tBurst\tWait\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].id + 1, p[i].burst, p[i].tat - p[i].burst, p[i].tat);
    }
}

int main(){
    int choice;
    while(1) {
        printf("Menu\n1.SRTF\n2.Round Robin\nChoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            srtf();
            break;
        
        case 2:
            rr();
            break;
        default:
            return 0;
        }
    }
}