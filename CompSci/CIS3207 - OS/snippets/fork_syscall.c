#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//for linux usage only
int main(int argc, char const *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = 0;
    //rc = fork()

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    }
    else{
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    }

    return 0;
}
