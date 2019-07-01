#include "platformioDependent/HTTPClient.h"


HTTPClient::HTTPClient(const char * host)
{
    this->host = host;
    num_headers = 0;
    port = 80;
    contentType = "application/json";
}

HTTPClient::~HTTPClient()
{
}

int HTTPClient::request(const char *method, const char *path, const char *body)
{
    //Normal connection
    if (!client.connect(host, port))
    {
        return 0;
    }

    // Make a HTTP request line:
    write(method);
    write(" ");
    write(path);
    write(" HTTP/1.1\r\n");
    for (int i = 0; i < num_headers; i++)
    {
        write(headers[i]);
        write("\r\n");
    }
    write("Host: ");
    write(host);
    write("\r\n");
    write("Connection: close\r\n");

    if (body != NULL)
    {
        char contentLength[30];
        sprintf(contentLength, "Content-Length: %d\r\n", strlen(body));
        write(contentLength);

        write("Content-Type: ");
        write(contentType);
        write("\r\n");
    }

    write("\r\n");

    if (body != NULL)
    {
        write(body);
        write("\r\n");
        write("\r\n");
    }

    //make sure you write all those bytes.
    delay(100);

    String *response;
    int statusCode = readResponse(response);

    //cleanup
    num_headers = 0;
    client.stop();
    delay(50);
    return statusCode;
}

void HTTPClient::write(const char *string)
{
    client.print(string);
}

int HTTPClient::readResponse(String *response)
{
    int code = 0;

    while (client.connected())
    {
        if (client.available())
        {
            String readed = client.readString();
            if (readed.length() > 0)
            {
                String code = readed.substring(9, 12);
                return atoi(code.c_str());
            }
            return 0;        
        }
    }
    return code;
}

int HTTPClient::post(std::string path, std::string body)
{
    return request("POST", path.c_str(), body.c_str());
}