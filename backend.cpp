#include <iostream>
#include <unistd.h>
#include <zmq.h>

int main()
{
    std::cout << "Backend server" << std::endl;

    void *ctx = zmq_ctx_new(); // create context
    void *rep = zmq_socket(ctx, ZMQ_REP); // create a socket that sends a reply
    zmq_connect(rep, "tcp://localhost:5560"); // connect to the proxy

    while (1)
    {
        char buffer[10] = {0};
        zmq_recv(rep, buffer, 10, 0);
	    std::cout << "Received msg: " << buffer << std::endl;
        sleep(1); // emulate doing some work

        zmq_send(rep, "processed!", 10, 0);
    }

    return 0;
}


