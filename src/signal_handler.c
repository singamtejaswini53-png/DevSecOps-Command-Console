#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t sigint_received = 0;
volatile sig_atomic_t sigterm_received = 0;
volatile sig_atomic_t sigusr1_received = 0;

void handle_signal(int sig)
{
    if (sig == SIGINT)
    {
        sigint_received = 1;
    }
    else if (sig == SIGTERM)
    {
        sigterm_received = 1;
    }
    else if (sig == SIGUSR1)
    {
        sigusr1_received = 1;
    }
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);

    printf("Signal Handler started.\n");
    printf("PID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while (1)
    {
        pause();

        if (sigint_received)
        {
            printf("SIGINT received.\n");
            sigint_received = 0;
        }

        if (sigterm_received)
        {
            printf("SIGTERM received. Exiting...\n");
            break;
        }

        if (sigusr1_received)
        {
            printf("SIGUSR1 received.\n");
            sigusr1_received = 0;
        }
    }

    return 0;
}
