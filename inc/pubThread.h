#ifndef PUBTHREAD_H
#define PUBTHREAD_H

#include "common.h"
#include "pubNode.h"


void* threadFun(void* arg);
void startThread(PubNode* pubNode);
#endif