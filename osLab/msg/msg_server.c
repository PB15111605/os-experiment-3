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

int main()
{
    key_t key=12345;
    struct msgbuffer qbuf;
    int msgqueue_id;
    int result;
    qbuf.mtype=1;
    msgqueue_id=msgget(key,IPC_CREAT|0666);
    if(msgqueue_id==-1)
    {
        perror("msgget");
        exit(1);
    }


    while(1)
    {
        result=msgrcv(msgqueue_id, &qbuf, MAX_SEND_SIZE, qbuf.mtype, 0);
        if(result!=-1)
        {
            printf("Received message:%s\n",qbuf.mtext);
        }
        if(strcmp(qbuf.mtext,"quit")==0)
        {
            break;
        }
    }
    if(msgctl(msgqueue_id, IPC_RMID, 0) == -1)
    {
        exit(1);
    }
}
