#include "client.h"

int main(int ac, char** av) {

    long int file_len;
    struct stat st;

    if(ac != 2) {
        printf("[-] Error Parameters\nUsage: %s filename (Exemple: ./client image.jpg)\n", av[0]);
        return 1;
    }
    
    // Opening the file
    printf("--- Cloud storage made in C by CharlesCPP ---\n");
    sleep(1);
    FILE *file = fopen(av[1], "rb");
    if (file == NULL) {
        printf("[-] Could not open the file %s.\nClosing...", av[1]);
        return 1;
    }

    // Checking file length
    size_t test_s = get_length(file);
    printf("Your image is %d bytes long\n", get_length(file));
    sleep(1);

    // Checking the file type
    char* f_type = check_type(av[1]);
    sleep(1);

    // Writing file from write_file function
    

    // Create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    printf("[+] Request created successfuly \n");
    printf("IP address is: %s\n", inet_ntoa(server_address.sin_addr));

    sleep(1);
    // Checking if the connection is successful
    while (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("[-] There was an error making a connection to the remote server \nTrying again.... \n");
        sleep(5);
    }
    printf("[+] Connected successfuly to the remote server \n");

    sleep(1);
    int server_socket;
    server_socket = accept(network_socket, NULL, NULL);
    
    printf("[+] Sending the file: %s to the remote server\n", av[1]);
    send(network_socket, &test_s, sizeof(test_s), 0);
    printf("[+] Sent file size successfuly\n");

    return 0;
}