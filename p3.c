#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_BUF 1024

pid_t processIdP1;

void sighandler(int signum) {
   printf("Signal Recv. ___ Signal Enviado\n");
   kill(processIdP1, 2);
}

int main(int argc, char *argv[]) {
    pid_t pid = getpid();
    printf("El PID de este programa es: %d\n", pid);
    
    processIdP1 = atoi(argv[1]);
    signal(SIGINT, sighandler);

    while(1) {
      sleep(1); 
    }

    return 0;
}
