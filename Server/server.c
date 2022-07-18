#include "server.h"

int main(int ac, char **av) {

    FILE *file = NULL;
    sleep(1);

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address));
    printf("[+] Binding successful\n");
    sleep(1);

    listen(server_socket, 100);
    printf("[+] Listening to connections\n");
    size_t file_size;
    while (1) {
        
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        recv(client_socket, &file_size, sizeof(file_size), 0);
        break;
    }
    printf("File size is: %d long", file_size);


    close(server_socket);
    return 0;
}