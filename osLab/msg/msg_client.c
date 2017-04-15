#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MAX_SEND_SIZE 20

struct msgbuffer
{
    long mtype;
    char mtext[MAX_SEND_SIZE];
};

int main(int argc, char *argv[])
{
    key_t key=12345;
    struct msgbuffer qbuf;
    int msgqueue_id;
    int result,i;
    qbuf.mtype=1;

    msgqueue_id=msgget(key,IPC_CREAT|0666);
    if(msgqueue_id==-1)
    {
        perror("msgget");
        exit(1);
    }

    if(argc!=2)
    {
        printf("A message is necessrry\n");
        exit(1);
    }
    strcpy(qbuf.mtext,argv[1]);
    result=msgsnd(msgqueue_id,&qbuf,strlen(qbuf.mtext)+1,0);
    if(result==-1)
    {
        printf("error\n");
    }

    return 0;
}
