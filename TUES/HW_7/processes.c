#include <stdio.h>
#include "processes.h"

Process processes[MAX_PROCESSES];
int processCount = 0;

static int nextId = 1;

int nextProcessId() {
    return (nextId <= MAX_PROCESSES) ? nextId++ : 0;
}

int createNewProcess(char *name) {
    if (processCount >= MAX_PROCESSES) {
        return 0;
    }

    int id = nextProcessId();

    if (id != 0) {
        processes[processCount].id = id;

        int i;
        for (i = 0; i < MAX_NAME_LENGTH - 1 && name[i] != '\0'; i++) {
            processes[processCount].name[i] = name[i];
        }
        processes[processCount].name[i] = '\0';

        processCount++;
    }

    return id;
}

void stopProcess(int processId) {
    if (processId <= 0 || processId > nextId) {
        return;
    }

    for (int i = 0; i < processCount; i++) {
        if (processes[i].id == processId) {
            for (int j = i; j < processCount - 1; j++) {
                processes[j] = processes[j + 1];
            }
            processCount--;
            nextId--;
            break;
        }
    }
}

