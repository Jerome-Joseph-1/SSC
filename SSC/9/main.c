#include <stdio.h>

int n, frame_count, frames[100], sequence[100];

void getData(){
    printf("Enter the number of pages : ");
    scanf("%d", &n);
    printf("Enter the pages : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sequence[i]);
    }

    printf("Enter the number of frames : ");
    scanf("%d", &frame_count);
}

void initialize(){
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }
}

int isHit(int frame) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == frame) {
            return 1;
        }
    }
    return 0;
}

void disp(){
    for (int i = 0; i < frame_count; i++)
    {
        if(frames[i] != -1) printf("%d ", frames[i]);
    }
    printf("\n");
}

void fifo(){
    int faults = 0, ptr = 0;
    initialize();

    for (int i = 0; i < n; i++) {
        printf("For %d: ", sequence[i]);
        if (!isHit(sequence[i])) {
            frames[ptr++] = sequence[i];
            ptr %= frame_count;
            disp();
            faults++;
        } else {
            printf("No Page Fault\n");
        }
    }

    printf("Total Faults : %d\n", faults);
}

void lru(){
    initialize();
    int faults = 0;

    for (int i = 0; i < n; i++) {
        printf("For %d: ", sequence[i]);
        if (!isHit(sequence[i])) {
            int index = i, k, selected_frame_index;
            for (int j = 0; j < frame_count; j++)
            {
                int selected_frame = frames[j];
                for (k = i - 1; k > -1; k--) {
                    if (sequence[k] == selected_frame) break;
                }
                if(k < index) {
                    index = k;
                    selected_frame_index = j;
                }
            }

            frames[selected_frame_index] = sequence[i];
            faults++;
            disp();
            
        } else {
            printf("No Page Fault\n");
        }
        
    }
    printf("Total Faults : %d\n", faults);
}

int main(){
    while (1)
    {
        int choice;
        printf("Menu\n1.Fill Data\n2.FIFO\n3.LRU\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getData();
            break;
        case 2:
            fifo();
            break;
        case 3:
            lru();
            break;
        default:
            return 0;
        }
    }
    
}