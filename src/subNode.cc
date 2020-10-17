#include "subNode.h"

void SubNode::setSub(std::string topic) {
    int clinetSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in masterAddress;
    setSocAddress(HOST_IP, MASTER_PORT, masterAddress);
    socklen_t masterAddressLength = sizeof(masterAddress);
    int ret = connect(clinetSocket, (struct sockaddr*)&masterAddress, masterAddressLength);
    if (ret == -1) {
        std::cout << "connect error" << std::endl;
    }
    std::string msg = std::to_string(SUB) + topic;
    ret = send(clinetSocket, msg.c_str(), msg.size(), 0);
    bool state = false;
    int port = 0;
    char buf[1024];
    while (!state) {
        
        bzero(buf, 1024);
        ret = recv(clinetSocket, buf, 1024, 0);
        std::cout << buf << std::endl;
        if (ret == -1) {
            std::cout << "recv error" << std::endl;
            return;
        }
        port = std::atoi(std::string(buf).substr(5).c_str());
        if (port != 0) {
            state = true;
        }
    }

    std::cout << port << std::endl;

    int subSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in pubAddress;
    setSocAddress(HOST_IP, port, pubAddress);
    ret = connect(subSocket, (struct sockaddr*)&pubAddress, sizeof(pubAddress));
    if (ret == -1) {
        std::cout << "connect error" << std::endl;

    }

    state = false;
    while (!state) {
        bzero(buf, 1024);
        ret = recv(subSocket, buf, 1024, 0);
        if (ret == -1) {
            std::cout << "recv error" << std::endl;
            state = true;
        }
        std::cout << buf << std::endl;

    }

    close(clinetSocket);
    close(subSocket);



}