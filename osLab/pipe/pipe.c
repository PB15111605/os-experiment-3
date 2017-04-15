#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "This is a pipe!\n";
        char    readbuffer[80];

        pipe(fd);

        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                printf("Child process is about to write the message\n");
                write(fd[1], string, (strlen(string)+1));

                exit(0);
        }
        else
        {
                close(fd[1]);
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                printf("Parent process have received the message: %s", readbuffer);
        }
        return(0);
}
