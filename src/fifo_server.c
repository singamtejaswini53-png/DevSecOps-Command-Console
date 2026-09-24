#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SERVER_FIFO "/tmp/server_fifo"

struct request
{
    pid_t client_pid;
    char message[100];
};

int main()
{
    int server_fd;
    struct request req;
    char client_fifo[100];
    char response[200];

    mkfifo(SERVER_FIFO, 0666);

    printf("FIFO Server started...\n");
    printf("Waiting for client requests...\n");

    server_fd = open(SERVER_FIFO, O_RDWR);

    if (server_fd == -1)
    {
        perror("open");
        return 1;
    }

    while (1)
    {
        ssize_t bytes_read = read(server_fd, &req, sizeof(req));

        if (bytes_read <= 0)
        {
            continue;
        }

        printf("Client %d sent: %s\n",
               req.client_pid,
               req.message);

        snprintf(client_fifo,
                 sizeof(client_fifo),
                 "/tmp/client_%d_fifo",
                 req.client_pid);

        snprintf(response,
                 sizeof(response),
                 "Server received your message: %s",
                 req.message);

        int client_fd = open(client_fifo, O_WRONLY);

        if (client_fd == -1)
        {
            perror("open client FIFO");
            continue;
        }

        write(client_fd, response, strlen(response) + 1);

        close(client_fd);

        printf("Response sent to client %d\n", req.client_pid);
    }

    close(server_fd);
    unlink(SERVER_FIFO);

    return 0;
}
