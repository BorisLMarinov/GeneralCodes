#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 5
#define MAX_NAME_LENGTH 30

struct Process{
    int id;
    char name[MAX_NAME_LENGTH + 1];
}

extern Process processes[MAX_PROCESSES];
extern int processCount;

int nextProcessId();
int createNewProcess(char *name);
void stopProcess(int processId);

#endif
