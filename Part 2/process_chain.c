#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void createProcessChain(int depth) {
    if (depth > 0) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            createProcessChain(depth - 1);
        } else if (pid < 0) {
            // Error handling for fork failure
            perror("Fork failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
            printf("Hello from process with PID %d and parent PID %d\n", getpid(), getppid());
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <depth>\n", argv[0]);
        return 1;
    }

    int depth = atoi(argv[1]);

    createProcessChain(depth);

    return 0;
}
