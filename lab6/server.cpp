#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "algo.h"
#define PORT 9090

void* process_client(void *arg){
    int client = *((int*)arg);
    char buffer[1024] = {0};
    int valread = read( client, buffer, 1024);
    printf("RECEIVED : %s\n", buffer);
    std::string res = "";
    for(int i = 0; i < 1024; i++){
        res += convert(buffer[i]);
    }
    int n = res.length();
    char char_array[n + 1];
    strcpy(char_array, res.c_str());

    send(client, char_array, strlen(char_array), 0);
    printf("SENT : %s\n", char_array);
}

int main(int argc, char const *argv[]){
    int server_fd, valread;
    sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(true){
        int new_socket;
        if((new_socket = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen)) < 0){
            perror("accept");
            exit(EXIT_FAILURE);
        }
        pthread_t pid;
        pthread_create(&pid, nullptr, process_client, &new_socket);
        // process_client(&new_socket);
    }
    return 0;
}