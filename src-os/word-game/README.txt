Operating Systems 2023 Problem Set #10
Santiago Dominguez

Some things to note:

* server.c is my server implementation of gwg.c
* Compile using gcc -o server server.c player.c chlng.c -pthread
* The server only works with localhost clients.
* Forking mode and threading mdoe are not mutually compatible. If server is started
  with both the [-t] and [-f] flags, the last flag is chosen.
* I have used a similar approach to Prof. Schoenwaelder's echo server, but i have
  also made use of additional libraries and APIs to facilitate my implementation.