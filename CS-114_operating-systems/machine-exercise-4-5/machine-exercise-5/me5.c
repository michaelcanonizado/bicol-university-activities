#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Cleanup handler function that runs when a thread is canceled */
void cleanupHandler(void* resource) {
    FILE* fp = (FILE*)resource;
    if (fp != NULL) {
        printf("[Cleanup] Closing file\n");
        fclose(fp);
    }
}

/* Worker thread function for asynchronous cancellation */
void* workerThreadAsync(void* argument) {
    FILE* fp = fopen("async_output.txt", "w");
    if (!fp) {
        perror("Failed to open async_output.txt");
        return NULL;
    }

    pthread_cleanup_push(cleanupHandler, fp);

    /* Set thread cancellation type to asynchronous */
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    int i = 0;
    while(1) {
        fprintf(fp, "Writing line %d\n", i);
        fflush(fp);

        fprintf(fp, "Start critical section %d\n", i);
        sleep(1); // <-- async may interrupt here
        fprintf(fp, "End critical section %d\n", i);
        fflush(fp);  
        i++;
    }

    pthread_cleanup_pop(1);
    return NULL;
}

/* Worker thread function for deferred cancellation */
void* workerThreadDeferred(void* argument) {
    FILE* fp = fopen("deferred_output.txt", "w");
    if (!fp) {
        perror("Failed to open deferred_output.txt");
        return NULL;
    }

    pthread_cleanup_push(cleanupHandler, fp);

    /* Set thread cancellation type to deferred */
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    int i = 0;
    while (1) {
        fprintf(fp, "Writing line %d\n", i);
        fflush(fp);

        fprintf(fp, "Start critical section %d\n", i);
        fprintf(fp, "End critical section %d\n", i);
        fflush(fp);
        /* Safe cancellation point */
        pthread_testcancel();
        sleep(1);
        i++;
    }

    pthread_cleanup_pop(1);
    return NULL;
}

int main() {
    pthread_t asyncThread, deferredThread;

    /* Demonstrate asynchronous cancellation */
    printf("\n===============| Asynchronous Cancellation |===============\n");
    if (pthread_create(&asyncThread, NULL, workerThreadAsync, NULL) != 0) {
        perror("Failed to create asynchronous thread");
        exit(EXIT_FAILURE);
    }

    sleep(5);

    printf("[Main] Sending cancel request to asynchronous thread...\n");
    pthread_cancel(asyncThread);

    pthread_join(asyncThread, NULL);
    printf("[Main] Asynchronous thread has been canceled.\n");

    /* Demonstrate deferred cancellation */
    printf("\n==========| Demonstrating Deferred Cancellation |==========\n");
    if (pthread_create(&deferredThread, NULL, workerThreadDeferred, NULL) != 0) {
        perror("Failed to create deferred thread");
        exit(EXIT_FAILURE);
    }

    sleep(5);

    printf("[Main] Sending cancel request to deferred thread...\n");
    pthread_cancel(deferredThread);

    pthread_join(deferredThread, NULL);
    printf("[Main] Deferred thread has been canceled.\n\n");

    printf("Check 'async_output.txt' and 'deferred_output.txt' to see the difference.\n");

    return 0;
}
