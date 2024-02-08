#include <stdio.h>
#include <stdlib.h>
#include "processes.h"

void printProcesses(void) {
    printf("Processes:\n");
    for (int i = 0; i < processCount; i++) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create new process\n");
        printf("2. Print processes\n");
        printf("3. Stop process\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH + 1];
                scanf("%s", name);

                int id = createNewProcess(name);
                if (id == 0) {
                    printf("Maximum number of processes reached. Stop a process to create a new one.\n");
                } else {
                    printf("Process created with ID: %d\n", id);
                }
                break;
            }
            case 2:
                printProcesses();
                break;

            case 3: {
                int processId;
                printf("Enter process ID to stop: ");
                scanf("%d", &processId);

                stopProcess(processId);
                printf("Process with ID %d stopped.\n", processId);
                break;
            }

            case 0:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
