#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void childProcessInstructions(void);
void parentProcessInstructions(void);

int main() {
    pid_t pid;

    /* Create new process */
    pid = fork();

    /* Check if creating a child-process failed */
    if (pid < 0) {
        perror("Creating child process failed!");
        return 1;;
    } 

    /* Child process */
    else if (pid == 0) {
        childProcessInstructions();
    } 

    /* Parent process */
    else {
        parentProcessInstructions();
    }

    return 0;
}

void childProcessInstructions(void) {
    for (int i = 0; i < 10; i++) {
        printf("[CHILD] : PID %d, PPID %d\n", getpid(), getppid());
        sleep(1);
    }
}

void parentProcessInstructions(void) {
    for (int i = 0; i < 10; i++) {
            printf("[PARENT] : PID %d, PPID %d\n", getpid(), getppid());
            sleep(1);
    }
}