//
// Created by user on 1/1/20.
//

#include "Server.h"
void startTheServer(int socketfd, sockaddr_in address, int client_socket) {
    vector<string> bufferVector = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
                                   "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
                                   "0", "0"};
    while (1) {
        Singleton *singleton = singleton->getInstance();
        for (auto e : singleton->infoFromSimulator) {
            try {
                //   singleton->infoFromSimulator.find(e.first)->second.setValue(stod(singleton->infoFromSim[singleton->simToNum[e.second.getSim()]]));
                //Variable v(e.second.getSim(), stod(singleton->infoFromSim[singleton->simToNum[e.second.getSim()]]));
                //    cout << e.second.getValue() << endl;
                //e.second = v;
                //cout << singleton->infoFromSim[35];
                if(singleton->infoFromSimulator.find(e.first)->second.getValue() < stod(singleton->infoFromSim[singleton->simToNum[e.second.getSim()]])) {
                    singleton->infoFromSimulator.find(e.first)->second.setValue(
                            stod(singleton->infoFromSim[singleton->simToNum[e.second.getSim()]]));
                    //   cout << "first : " << v.getSim() << " second : " << v.getValue() << endl;
                }
                // cout << singleton->infoFromSimulator.find("rpm")->second.getValue() << "var " << endl;
            } catch (...) {
                cout << "Eror stod" << endl;
            }
        }

        //  cout << "1" <<endl;
        vector<string> info;
        //reading from client
        // singleton->mtx.lock();
        char buffer[1024] = {0};
        //    cout << "2" <<endl;
        int valread = read(client_socket, buffer, 1024);
/*
 * split the buffer to \n
 */
        int i, counter = 0;
        //      cout << "3" <<endl;
        char newBuffer[1024] = {0};
        for (i = 0; i <= 1024; i++) {
            newBuffer[i] = buffer[i];
            counter++;
            if (buffer[i] == '\n') {
                break;
            }
        }
        //    cout << "4" <<endl;
        if (valread <= 0) {
            close(socketfd);
        }
        string s = "";
        counter = 0;
        i;
        int j = 0;
          cout << "buffer : " << newBuffer << endl;
        for (i = 0; i < 1024; i++) {
            if (newBuffer[i] == ',' || newBuffer[i] == '\n') {
                //    cout << "s on server " << s << endl;
       for (auto e : singleton->infoFromSimulator) {
                    //         cout << "first"<< e.first << "second "<< e.second.getValue() << endl;
                }
                //singleton->infoFromSim.push_back(s);
                bufferVector[counter] = s;
                s = "";
                counter++;
            } else {
                s = s + buffer[i];
            }
        }
        if (counter < 36) {
            //     cout << "counter < 36 ****************************************" << endl;
        }
        counter = 0;
        for (auto e : singleton->infoFromSim) {
            cout  << e << " ****";
        }
        cout << "\n";
        double x = stod(singleton->infoFromSim[35]);
        if (x > 0) {
            //    cout << "******************************************rmp > 0" <<endl;
        }
        singleton->set(bufferVector);
    }
}
Server::Server(int _port) {
    this->port = _port;
}
int Server::main() {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(this->port);
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    std::cout << "server : printing answer" << std::endl;    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
    }
//    vector<string> info;
//    Singleton *singleton = singleton->getInstance();
//    char buffer[1024] = {0};
//    int valread = read(client_socket, buffer, 1024);
//    if (valread <= 0) {
//
//        close(socketfd);
//    }
//    string s = "";
//    int counter = 0;
//    int i, j = 0;
//    for (i = 0; i < 1024; i++) {
//        //  cout<< "enter to for serser" << endl;
//        if (buffer[i] == ',' || buffer[i] == '\n') {
//            singleton->infoFromSim.push_back(s);
//            s = "";
//            counter++;
//        } else {
//            s = s + buffer[i];
//
//        }
//
//    }
  //  counter = 0;
    thread thread(startTheServer, socketfd, address, client_socket);
    thread.detach();
}
