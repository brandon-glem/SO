#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    pid_t processIdP3;
    processIdP3 = atoi(argv[1]);

    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    while(1){
        read(fd, buf, MAX_BUF);
        if(buf[0]=='-') break;
        printf("Received: %s\n", buf);
        kill(processIdP3, 2);
    }

    kill(processIdP3, 9);
    close(fd);

    return 0;
}
