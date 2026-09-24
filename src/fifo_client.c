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
    int client_fd;
    struct request req;
    char client_fifo[100];
    char response[200];

    req.client_pid = getpid();

    printf("Enter message: ");
    fgets(req.message, sizeof(req.message), stdin);

    req.message[strcspn(req.message, "\n")] = '\0';

    snprintf(client_fifo,
             sizeof(client_fifo),
             "/tmp/client_%d_fifo",
             req.client_pid);

    mkfifo(client_fifo, 0666);

    server_fd = open(SERVER_FIFO, O_WRONLY);

    if (server_fd == -1)
    {
        perror("open server FIFO");
        unlink(client_fifo);
        return 1;
    }

    write(server_fd, &req, sizeof(req));

    close(server_fd);

    client_fd = open(client_fifo, O_RDONLY);

    if (client_fd == -1)
    {
        perror("open client FIFO");
        unlink(client_fifo);
        return 1;
    }

    read(client_fd, response, sizeof(response));

    printf("Server response: %s\n", response);

    close(client_fd);

    unlink(client_fifo);

    return 0;
}
