#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FRAMES 100

bool isCorrupted(int frameNumber, int *corruptedFrames, int numCorruptedFrames) {
    for (int i = 0; i < numCorruptedFrames; i++) {
        if (frameNumber == corruptedFrames[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int numFrames, windowSize;
    printf("Enter the number of frames to be transmitted: ");
    scanf("%d", &numFrames);
    printf("Enter the window size: ");
    scanf("%d", &windowSize);
    int corruptedFrames[MAX_FRAMES];
    printf("Enter the corrupted or lost frame numbers separated by space (enter -1 to end): ");
    int corruptedFrame;
    int numCorruptedFrames = 0;
    while (true) {
        scanf("%d", &corruptedFrame);
        if (corruptedFrame == -1 || numCorruptedFrames >= MAX_FRAMES)
            break;
        corruptedFrames[numCorruptedFrames++] = corruptedFrame;
    }
    printf("\nOutput:\n");
    int nextFrameToSend = 0;
    int lastAckedFrame = -1;

    while (nextFrameToSend < numFrames) {
        for (int i = nextFrameToSend; i < nextFrameToSend + windowSize && i < numFrames; i++) {
            printf("Frame %d has been transmitted.\n", i);
        }
        bool ackReceived = false;
        for (int i = nextFrameToSend; i < nextFrameToSend + windowSize && i < numFrames; i++) {
            if (!isCorrupted(i, corruptedFrames, numCorruptedFrames)) {
                printf("Acknowledgement received for frame %d.\n", i);
                ackReceived = true;
                lastAckedFrame = i;
            }
        }
        nextFrameToSend = lastAckedFrame + 1;
        if (nextFrameToSend >= numFrames) {
            break;
        }
    }

    return 0;
}

