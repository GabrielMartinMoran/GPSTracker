#ifndef HTTPClient_h
#define HTTPClient_h

#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <iostream>

class HTTPClient
{
private:
    WiFiClient client;
    int port;
    int num_headers;
    const char *headers[10];
    const char *contentType;
    const char *host;
    int readResponse(String *);
    void write(const char *);  
    int request(const char *method, const char *path, const char *body);

public:
    HTTPClient(const char * host);
    ~HTTPClient();
    int post(std::string path, std::string body);
};

#endif