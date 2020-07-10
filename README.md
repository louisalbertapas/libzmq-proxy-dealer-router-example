# libzmq-proxy-dealer-router-example
A basic example on dealing with dealer router pattern using ZeroMQ

This contains a proxy that accepts request from clients and
passes it to the backend server.

[1] Compile proxy.cpp, backend.cpp and frontend.cpp

[2] Optionally, you can compile demo.cpp to help execute
the three executables

[3] Execute demo if compiled e.g demo 2 3  (2 = # backend server, 3 = # frontend client).
Make sure demo is in the same directory with the other executable

[4] If demo is not compiled, execute each executable (proxy, frontend, backend) separately
