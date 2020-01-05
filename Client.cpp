//
// Created by user on 1/1/20.
//

#include <sstream>
#include "Client.h"
//#include <stringstream>
int connectToServer(int client_socket) {
    //if here we made a connection
    Singleton *singleton = singleton->getInstance();
    int i;
    //const char *hello;
   // string string_;
    while (true) {
        //singleton->mtx.lock();
        for (auto e: singleton->infoFromSimulator) {
           // cout <<"********" << e.first << " " << e.second.getValue()<< endl;
        }
       for (auto element : singleton->infoFromSimulator) {
     //if (singleton->infoFromSimulator.find("warp") = singleton->infoFromSimulator.end()) {
         double value = element.second.getValue();
         string sim = element.second.getSim();

         //   string s = "set " + si ;
        // string valuStr = to_string(value);
         //cout << "************" << valuStr <<endl;
         //stringstream ss;
         //ss << "set " << sim  << " " << value << "\r\n";
         //cout <<"befor " <<  ss.str().c_str() << endl;
        //  ss.str();
         //= "set " + sim + " " +  "3200.0000" + "\r\n";

         //string s = "set /sim/time/warp 32000.000000\r\n";
//            for (i = 0; i < s.size(); i++) {
//                cout <<"hello" << endl;
//                hello
//                cout <<"thss " << hello << endl;
//
//            }
    //     hello = ss.str().c_str();
    stringstream ss;
    ss << "set " << sim << " " << value << "\r\n";
    string str = ss.str();
    char const * hello = str.c_str();
         int is_sent = send(client_socket, hello, strlen(hello), 0);
         if (is_sent == -1) {
             cout << "Error sending message" << endl;
         } else {
            // cout << "ths s " << hello << endl;
         }
     }
        }
    //    singleton->mtx.unlock();
    }
Client::Client(string ip, int port) {
    this->_port = port;
    this->_ip = ip;
}
int Client::main() {
    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        return -1;
    }
    char *ip = const_cast<char *>((const char *) _ip.c_str());
    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
    address.sin_port = htons(_port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cerr << "Could not connect to host server" << endl;
        return -2;
    } else {
        cout << "Client is now connected to server" << endl;
    }
    //    connectToServer(client_socket);
    thread thread(connectToServer, client_socket);
    thread.detach();
}