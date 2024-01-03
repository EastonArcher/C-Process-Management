#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void createChildren(int numChildren) {
    for (int i = 0; i < numChildren; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            printf("Hello from child %d with PID %d and parent PID %d\n", i + 1, getpid(), getppid());
            exit(0);
        } else if (pid < 0) {
            // Error handling for fork failure
            perror("Fork failed");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <numChildren>\n", argv[0]);
        return 1;
    }

    int numChildren = atoi(argv[1]);

    createChildren(numChildren);

    for (int i = 0; i < numChildren; i++) {
        wait(NULL);
    }

    printf("All children have completed.\n");
    return 0;
}
