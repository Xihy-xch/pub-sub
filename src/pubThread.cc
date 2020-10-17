#include "pubThread.h"

void* threadFun(void* arg) {
    PubNode* pub = (PubNode*)arg;
    pub->setPub();
}

void startThread(PubNode* pubNode) {
    pthread_t pubThread;
    pthread_create(&pubThread, NULL, threadFun, (void *)pubNode);
}