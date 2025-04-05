#include <stdio.h>

// Global variables
int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void wait() {
    mutex = 0;
}

void signal() {
    mutex = 1;
}

void producer() {
    wait();         // lock
    full++;
    empty--;
    x++;
    printf("Producer produces item: %d\n", x);
    signal();       // unlock
}

void consumer() {
    wait();         // lock
    full--;
    empty++;
    printf("Consumer consumes item: %d\n", x);
    x--;
    signal();       // unlock
}

int main() {
    int n;

    printf("1. Press 1 for Producer\n");
    printf("2. Press 2 for Consumer\n");
    printf("3. Press 3 to Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full!\n");
                break;

            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(n != 3);

    return 0;
}
