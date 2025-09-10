#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    /* Creating new process */
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    
    /* Child process */
    if (pid == 0) {
        /* Replace its memory with new program */
        char *args[] = {"./child-counter", NULL};
        execv(args[0], args);

        /* If exec fails */
        perror("Execution of external binary failed");
        exit(1);
    } 
    
    /* Parent process */
    else {
        printf("[PARENT]: PID %d, waits for child with PID %d\n", getpid(), pid);

        /* Sleep until child finishes */
        int status;
        waitpid(pid, &status, 0);

        printf("[PARENT]: Child with PID %d finished and unloaded\n", pid);
    }

    return 0;
}
