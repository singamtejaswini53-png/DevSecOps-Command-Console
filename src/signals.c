#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../include/signals.h"

static void handle_sigint(int sig)
{
    (void)sig;
    printf("\n");
    printf("DevSecOps Command Console: Ctrl+C detected. Shell is still running.\n");
}

static void handle_sigchld(int sig)
{
    (void)sig;

    while (waitpid(-1, NULL, WNOHANG) > 0)
    {
        /* Reap completed child processes */
    }
}

void initialize_signals(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGCHLD, handle_sigchld);
}
