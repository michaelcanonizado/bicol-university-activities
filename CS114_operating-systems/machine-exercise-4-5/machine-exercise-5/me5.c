#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Cleanup handler function that runs when a thread is canceled */
void cleanupHandler(void* resource) {
    printf("[Cleanup] Releasing resource: %s\n", (char*)resource);
}

/* Worker thread function for asynchronous cancellation */
void* workerThreadAsync(void* argument) {
    /* Register cleanup handler */
    pthread_cleanup_push(cleanupHandler, "Async Resource");

    /* Set thread cancellation type to asynchronous */
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    int counter = 1;
    while (1) {
        printf("[Async Worker] Number: %d\n", counter++);
        /* Simulate some work */
        sleep(1); 
    }

    /* This will never be reached, but required for matching pthread_cleanup_push */
    pthread_cleanup_pop(1);
    return NULL;
}

/* Worker thread function for deferred cancellation */
void* workerThreadDeferred(void* argument) {
    /* Register cleanup handler */
    pthread_cleanup_push(cleanupHandler, "Deferred Resource");

    /* Set thread cancellation type to deferred */
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    int counter = 1;
    while (1) {
        printf("[Deferred Worker] Number: %d\n", counter++);
        /* Simulate some work */
        sleep(1);
        /* Explicitly check for cancellation */
        pthread_testcancel(); 
    }

    /* Matching cleanup_pop */
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

    /* Let thread run for some time */
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

    /* Let thread run for some time */
    sleep(5);

    printf("[Main] Sending cancel request to deferred thread...\n");
    pthread_cancel(deferredThread);

    pthread_join(deferredThread, NULL);
    printf("[Main] Deferred thread has been canceled.\n\n");

    return 0;
}
