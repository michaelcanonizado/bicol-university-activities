#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void reverseStringCasing(char *string);

int main(void) {
    /* Parent -> Child */
    int parentToChildPipe[2];
    /* Child -> Parent */
    int childToParentPipe[2];

    /* Create pipes. If error creating either, exit. */
    if (pipe(parentToChildPipe) == -1 || pipe(childToParentPipe) == -1) {
        perror("pipe failed");
        exit(1);
    }

    /* Create child process */
    pid_t pid = fork();
    /* Check if error creating child process */
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    
    /* Child process */
    if (pid == 0) {
        /* Close unused pipes */
        close(parentToChildPipe[1]);
        close(childToParentPipe[0]);

        size_t userStringLength;
        /* Read string length */
        read(
            parentToChildPipe[0],
            &userStringLength,
            sizeof(size_t)
        );

        /* Dynamically allocate memory for the string. */
        char *userString = malloc(userStringLength + 1);
        if (!userString) {
            perror("Allocating child copy of string failed!");
            exit(1);
        }

        /* Read actual string */
        read(
            parentToChildPipe[0],
            userString,
            userStringLength
        );
        /* Terminate with null */
        userString[userStringLength] = '\0';
        

        printf("CHILD(%d) : Recieved message\n", getpid());
        
        printf("CHILD(%d) : Reversing the case of the string\n", getpid());
        
        /* Reverse string */
        reverseStringCasing(userString);
        
        printf("CHILD(%d) : Sending string to PARENT(%d)\n", getpid(), getppid());
        write(
            childToParentPipe[1],
            userString,
            userStringLength
        );

        free(userString);
        close(parentToChildPipe[0]);
        close(childToParentPipe[1]);
    }

    /* Parent process */
    else {
        /* Close unused pipe ends */
        close(parentToChildPipe[0]);
        close(childToParentPipe[1]);


        /* Get string from user. Use getLine so the input can be dynamic and include spaces */
        char *userString = NULL;
        size_t length = 0;
        printf("Enter a string : ");
        ssize_t nread = getline(&userString, &length, stdin);

        /* If error reading */
        if (nread == -1) {
            perror("getline failed.");
            free(userString);
            exit(1);
        }

        /* Replace '\n' with '\0' */
        if (userString[nread - 1] == '\n') {
            userString[nread - 1] = '\0';
        }
        /* Get length of string */
        size_t userStringLength = strlen(userString);

        printf("PARENT(%d) : Sending [ %s ] to CHILD(%d)\n", getpid(), userString, pid);

        /* Write length to child process */
        write(
            parentToChildPipe[1],
            &userStringLength,
            sizeof(size_t)
        );

        /* Write string to child process */
        write(
            parentToChildPipe[1],
            userString,
            userStringLength
        );

        read(
            childToParentPipe[0],
            userString,
            userStringLength
        );

        printf("PARENT(%d): Received [ %s ] from CHILD(%d)\n", getpid(), userString, pid);

        free(userString);
        close(parentToChildPipe[1]);
        close(childToParentPipe[0]);
    }
}

void reverseStringCasing(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        /* Uppercase to Lowercase */
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
        /* Lowercase to Uppercase */
        else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32;
        }
    }
}