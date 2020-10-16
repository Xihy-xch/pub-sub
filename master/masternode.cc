#include "master.h"

int main() {



    Master master;
    master.init(HOST_IP,MASTER_PORT);
    master.run();    
}