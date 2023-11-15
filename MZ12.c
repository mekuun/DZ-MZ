#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define CLOSEFD(f1, f2) close(f1[0]); close(f1[1]);close(f2[0]);close(f2[1]);

int main(int argc, char *argv[]) {
    int j = 0;
    int point[2] = {0, 0};

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "|")) {
            point[j] = i;
            j++;
            if (j == 3) {
                fprintf(stderr, "WRONG INPUT");
                return 1;
            }
        }
    }
    if (j != 2) {
        fprintf(stderr, "WRONG INPUT");
        return 1;
    }


    char **prog1 = (char **) malloc((point[0]) * sizeof(char *));
    char **prog2 = (char **) malloc((point[1] - point[0]) * sizeof(char *));
    char **prog3 = (char **) malloc((argc - point[1]) * sizeof(char *));
    if (!prog1 || !prog2 || !prog3) {
        fprintf(stderr, "MEMORY ALLOCATION ERROR");
        return 1;
    }

    for (int i = 1; i < point[0]; i++) {
        prog1[i - 1] = argv[i];
    }
    for (int i = 1; i < point[1] - point[0]; i++) {
        prog2[i - 1] = argv[i + point[0]];
    }
    for (int i = 1; i < argc - point[1]; i++) {
        prog3[i - 1] = argv[i + point[1]];
    }

    prog1[point[0] - 1] = NULL;
    prog2[point[1] - point[0] - 1] = NULL;
    prog3[(argc - point[1]) - 1] = NULL;

    int fd1[2], fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("PIPE CREATION ERROR");
        return 1;
    }


    if (fork() == 0) {
        dup2(fd1[1], 1);
        CLOSEFD(fd1, fd2)
        execvp(prog1[0], prog1);
        perror("EXEC ERROR");
        return 1;
    }

    if (fork() == 0) {
        dup2(fd1[0], 0);
        dup2(fd2[1], 1);
        CLOSEFD(fd1, fd2)
        execvp(prog2[0], prog2);
        perror("EXEC ERROR");
        return 1;
    }

    if (fork() == 0) {
        dup2(fd2[0], 0);
        CLOSEFD(fd1, fd2)
        execvp(prog3[0], prog3);
        perror("EXEC ERROR");
        return 1;
    }
    CLOSEFD(fd1, fd2)
    wait(NULL);
    wait(NULL);
    wait(NULL);
    free(prog1);
    free(prog2);
    free(prog3);
    return 0;
}