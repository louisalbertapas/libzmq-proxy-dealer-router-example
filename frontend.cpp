#include <zmq.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <time.h>

int main()
{
    std::cout << "Client" << std::endl;
    void *ctx = zmq_ctx_new();
    void *req = zmq_socket(ctx, ZMQ_REQ);
    zmq_connect(req, "tcp://localhost:5559"); // connect to the proxy

    srand(time(0));
    for(;;)
    {
        char buffer[10];
        std::string msg;

        int rnd = rand() % 100;
        msg = "msg" + std::to_string(rnd);
        // simulate client sending a request
        // with indefinite time
        sleep(rnd % 10);
        std::cout << "Sending " << msg << std::endl;
        zmq_send(req, msg.c_str(), msg.length(), 0);
        zmq_recv(req, buffer, 10, 0);
        std::cout << "Received from server: " << buffer << std::endl;
    }

    return 0;
}
