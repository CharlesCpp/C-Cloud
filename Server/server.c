#include "server.h"

int main(int ac, char **av) {

    char buff[1025];
    int counter = 0;
    size_t file_size;
    char* type = malloc(5);

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    memset(buff, '0', sizeof(buff));
    
    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;


    bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address));
    printf("[+] Binding successful\n");
    sleep(1);

    listen(server_socket, 100);
    printf("[+] Listening to connections port %d\n", htons(server_address.sin_port));

    // Receiving file type  
    while (1) {
            
        int client_socket; 
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == - 1) {
                perror("Accept");
                exit(EXIT_FAILURE);
        }

        recv(client_socket, type, sizeof(type), 0);
        printf("[+] Receiving file format: %s\n", type);
        
        // Randomise a file name using the format sent by the client
        char* file_name = Create_File_Name(type);
        printf("File name is: %s\n", file_name);

        FILE *file = fopen(file_name, "wb");
        if (file != NULL) {
            while ( (file_size = recv(client_socket, buff, 1024, 0)) > 0) {
                    counter += file_size;
                fwrite(buff, 1, file_size, file);
            }
            printf("[+] Received byte: %d\n", counter);
            if (file_size < 0) perror("Receiving");
            fclose(file);
            counter = 0;
            
            // Function that handle to send back the file link.
            link_back(file_name);
            free(file_name);
            close(server_socket);
        }
        else {
            perror("File");
        }

    }

    printf("[+] Recieved the file\n");
    free(type);
    close(server_socket);
    return 0;
}