#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int con = 1;
int fd;
char * myfifo = "/tmp/myfifo";
    
void fifo_send(){
    //char text[20] = "hola hola guagua";
    int num=rand() % 1001;
    printf("%d->(%d) ", con++, num);
    char text[15];
    sprintf(text, "%d", num);

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    write(fd, text, sizeof(text));
}

int main()
{
    pid_t pid = getpid();
    printf("El PID de este programa es: %d\n", pid);
    fd = open(myfifo, O_WRONLY);
    
    srand(time(NULL)); 
    signal(SIGINT, fifo_send);
    //fifo_send();
    
    while(con<=10) {
      sleep(1); 
    }

    sleep(10);
    printf("\nEnd program ABC");

    char text[10] = "-";
    mkfifo(myfifo, 0666);
    write(fd, text, sizeof(text));

    close(fd);

    /* remove the FIFO */
    unlink(myfifo);
    return 0;
}

