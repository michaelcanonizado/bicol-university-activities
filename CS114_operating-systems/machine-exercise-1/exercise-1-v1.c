#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int customPrint(int fileDescriptor, const char *string) {
    /* Null string check */
    if (!string) {
        return -1;
    }

    size_t length = strlen(string);
    ssize_t writeCount = 0;
    ssize_t temp;

    /* Handle partial writes */
    while (writeCount < (ssize_t)length) {
        /* Write each character to the specified output
           whilst maintaining write count */
        temp = write(fileDescriptor, string + writeCount, length - writeCount);
        if (temp < 0) {
            return -1;
        }
        writeCount += temp;
    }
    return (int)writeCount;
}

ssize_t customScan(char *buffer, size_t size) {
    /* Read from standard input */
    ssize_t bytes = read(STDIN_FILENO, buffer, size - 1);

    /* Replace '\n' with '\0' */
    if (bytes > 0) {
        buffer[bytes] = '\0';
        char *newline = strchr(buffer, '\n');
        if (newline) *newline = '\0';
    }

    return bytes;
}

int customOpen(const char *path, const char *flag) {
    /* Write Byte */
    if (strcmp(flag, "wb") == 0) {
        return open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    } 
    /* Read Byte */
    else if (strcmp(flag, "rb") == 0) {
        return open(path, O_RDONLY);
    }
    /* Unsupported flag */
    return -1;
}

int customClose(int fd) {
    if (fd < 0) {
        return -1;
    }
    return close(fd);
}

ssize_t customRead(int fd, void *buffer, size_t count) {
    return read(fd, buffer, count);
}

ssize_t customWrite(int fd, const void *buffer, size_t count) {
    return write(fd, buffer, count);
}

int main(void) {
    char sourceFileName[256];
    char destinationFileName[256];
    int sourceFile = -1;
    int destinationFile = -1;

    /* Program Header */
    customPrint(STDOUT_FILENO, "\n--------------------------------------------------");
    customPrint(STDOUT_FILENO, "\n--------------File-Copier-Program-V1--------------");
    customPrint(STDOUT_FILENO, "\n--------------------------------------------------");

    /* Prompt for source file */
    customPrint(STDOUT_FILENO, "\nEnter source file name: ");
    if (customScan(sourceFileName, sizeof(sourceFileName)) <= 0) {
        customPrint(STDERR_FILENO, "Error: Could not read source file name.\n");
        return 1;
    }

    /* Open source file */
    sourceFile = customOpen(sourceFileName, "rb");
    if (sourceFile == -1) {
        customPrint(STDERR_FILENO, "Error: Source file could not be opened.\n");
        return 2;
    }

    /* Prompt for destination file */
    customPrint(STDOUT_FILENO, "Enter destination file name: ");
    if (customScan(destinationFileName, sizeof(destinationFileName)) <= 0) {
        customPrint(STDERR_FILENO, "Error: Could not read destination file name.\n");
        return 3;
    }

    /* Open destination file */
    destinationFile = customOpen(destinationFileName, "wb");
    if (destinationFile == -1) {
        customPrint(STDERR_FILENO, "Error: Destination file could not be opened.\n");
        customClose(sourceFile);
        return 4;
    }

    /* Copy contents of source file to desintation file */
    char buffer[1];
    ssize_t byte;
    while ((byte = customRead(sourceFile, buffer, 1)) > 0) {
        if (customWrite(destinationFile, buffer, 1) != 1) {
            customPrint(STDERR_FILENO, "Error: Something went wrong when copying data.\n");
            customClose(sourceFile);
            customClose(destinationFile);
            return 5;
        }
    }

    /* If an error occured while reading data */
    if (byte < 0) {
        customPrint(STDERR_FILENO, "Error: Reading from source file.\n");
        customClose(sourceFile);
        customClose(destinationFile);
        return 6;
    }

    /* Success Message */
    customPrint(STDOUT_FILENO, "Successfully copied data\n");

    /* Close file descriptors */
    customClose(sourceFile);
    customClose(destinationFile);
}