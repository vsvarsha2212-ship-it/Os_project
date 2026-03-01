#include <stdio.h>

int main() {
    int n, m;
    int i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n], work[m];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &req[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Initialize finish array
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Deadlock Detection Algorithm
    int found;
    do {
        found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;
                for(j = 0; j < m; j++) {
                    if(req[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while(found);

    // Check for deadlock
    int deadlock = 0;
    printf("\nDeadlocked Processes:\n");
    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(!deadlock) {
        printf("No Deadlock Detected");
    }

    printf("\n");
    return 0;
}