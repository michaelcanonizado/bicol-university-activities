#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("[CHILD]: PID %d, starts counting:\n", getpid());

    for (int i = 1; i <= 10; i++) {
        printf("[CHILD] : i = %d\n", i);
        sleep(1);
    }
    return 0;
}