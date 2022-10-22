#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void simple_action(int signum)
{
    printf("Oh, sheat!\nThis is disposition of signal=(%d)!\n", signum);
}


int main (void)
{
    struct sigaction act, old_act;
    act.sa_handler = &simple_action;
    act.sa_mask.__val[SIGINT] = 1;


    if(sigaction(SIGTERM, &act, &old_act) == -1)
    {
        printf("ops!\n");
        exit(EXIT_FAILURE);
    }
}

