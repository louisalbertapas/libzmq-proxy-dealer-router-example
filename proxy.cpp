#include <zmq.h>
#include <cassert>
#include <iostream>

int main()
{
    void *ctx = zmq_ctx_new();
    void *frontend = zmq_socket(ctx, ZMQ_ROUTER); //create a socket for front end
    assert(frontend);
    void *backend = zmq_socket(ctx, ZMQ_DEALER); // create socket for backend
    assert(backend);

    // bind sockets respectively
    assert (zmq_bind(frontend, "tcp://*:5559") == 0);
    assert (zmq_bind(backend, "tcp://*:5560") == 0);

    std::cout << "Starting proxy" << std::endl;
    zmq_proxy(frontend, backend, NULL);
}
