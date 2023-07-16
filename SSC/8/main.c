#include <stdio.h>

void disp(int MAX[][10], int need[][10], int p, int r , int avail[]) {
    for(int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", MAX[i][j]);
        }

        printf("\t\t");
        
        for (int j = 0; j < r; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvail\n");
    for (int i = 0; i < r; i++)
    {
        printf("%d ", avail[i]);
    }
    printf("\n");
}

int main(){
    int completed[10], MAX[10][10], alloc[10][10], avail[10], need[10][10], seq[10];
    int p, r;

    printf("Enter number of Processes : ");
    scanf("%d", &p);
    
    printf("Enter number of Resources : ");
    scanf("%d", &r);
    
    printf("Enter Max matrix :\n");
    for(int i = 0; i < p;  i++) {
        printf("For P%d:\n", i+1);
        for(int j = 0; j < r ; j++) {
            scanf("%d", &MAX[i][j]);
        }
    }

    
    printf("Enter Alloc matrix :\n");
    for(int i = 0; i < p;  i++) {
        completed[i] = 0;
        printf("For P%d:\n", i+1);
        for(int j = 0; j < r ; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Avail Resources :\n");
    for(int j = 0; j < r ; j++) {
        scanf("%d", &avail[j]);
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = MAX[i][j] - alloc[i][j];
        }
        
    }
    
//  5 3 7 5 3 3 2 2 7 0 2 2 2 2 4 3 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 3 3 2
    int done = 0;
    int count = 0;
    while(!done) {
        int process = -1;
        disp(MAX, alloc, p, r, avail);
        for (int i = 0; i < p; i++)
        {
            if(completed[i]) {
                continue;
            } else {
                process = i;
                for (int j = 0; j < r; j++)
                {
                    if(avail[j] < need[i][j]) {
                        process = -1;
                        break;
                    }
                }
            }
            if(process != -1) break;
        }

        if(count == p) {
            done = 1;
            break;
        }
        else if(process == -1) break;

        else {
            printf("P%d Runs to Completion!!\n", process + 1);
            completed[process] = 1;
            seq[count++] = process + 1;
            for (int j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = MAX[process][j] = 0;
            }
        }        
    }

    if(done) {
        printf("Success!!\nSafe Sequence : ");
        for(int i = 0; i < count; i++) printf("P%d ", seq[i]);
        printf("\n");
    } else {
        printf("Deadlock!!!\n");
    }
}