#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sendFrame(int frameNo, int data, int waitingTime) {
    printf("%d %d Yes ", frameNo, data);
    if (waitingTime == 0) {
        printf("0 ");
    } else {
        for (int i = 1; i <= waitingTime; i++) {
            printf("%d", i);
            if (i < waitingTime) {
                printf(", ");
            }
            fflush(stdout); 
            sleep(1);
        }
    }

    int acknowledged = rand() % 2;

    if (acknowledged) {
        printf("Yes No\n");
    } else {
        printf("No Yes\n");
    }

    return acknowledged;
}

int main() {
    int choice;
    do {
        int totalFrames;
        printf("Enter the number of frames to be transmitted: ");
        scanf("%d", &totalFrames);

        int *data = (int*)malloc(totalFrames * sizeof(int));
        int *waitingTimes = (int*)malloc(totalFrames * sizeof(int));

        printf("Enter data to send (separated by spaces): ");
        for (int i = 0; i < totalFrames; ++i) {
            scanf("%d", &data[i]);
        }

        printf("Enter the waiting time for an acknowledgment to data (separated by spaces): ");
        for (int i = 0; i < totalFrames; ++i) {
            scanf("%d", &waitingTimes[i]);
        }

        printf("Frame_No Data Sent Waiting Time (Sec) Acknowledged Resent\n");

        int resentFrames = 0;
        int totalTransmittedFrames = 0;

        for (int i = 0; i < totalFrames; ++i) {
            int acknowledged = 0;
            int attempts = 0;
            do {
                acknowledged = sendFrame(i+1, data[i], waitingTimes[i]);
                totalTransmittedFrames++;
                if (!acknowledged) {
                    resentFrames++;
                }
                attempts++;
            } while (!acknowledged && attempts < 3); 
        }

        printf("The total number of frames that need to be transmitted is %d\n", totalTransmittedFrames);

        free(data);
        free(waitingTimes);

        printf("Do you want to go again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}



