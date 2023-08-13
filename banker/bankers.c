#include <stdio.h>

int main() {
    int i, j, n, m, max[20][20], alloc[20][20], avail[20], k, ind = 0, y;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter the number of resources\n");
    scanf("%d", &m);
    
    // Input the allocated matrix
    printf("Enter the allocated matrix\n");
    for (i = 0; i < n; i++) {
        printf("For process p%d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    // Input the max matrix
    printf("Enter the max matrix\n");
    for (i = 0; i < n; i++) {
        printf("For process p%d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    // Input the available matrix
    printf("Enter the available matrix\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }
    
    // Calculate the need matrix
    int finish[n], safesequence[n], work[m], need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
  
    
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    
    while (ind < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (y = 0; y < m; y++) {
                        work[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                    safesequence[ind++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            break; // No safe sequence exists
        }
    }
    
    // Print the safe sequence
    printf("Safe sequence:\n");
    for (i = 0; i < n; i++) {
        printf("p%d", safesequence[i] + 1); // Adding 1 to process number to match user input
        if (i != n - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
    
    return 0;
}
