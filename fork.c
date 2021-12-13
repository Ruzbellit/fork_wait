#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int contador = 1;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        contador += 5;
    } else {
        // parent goes down this path (original process)
        contador += 2;
    }
    printf("valor de contador %d\n", contador);
    return 0;
}
