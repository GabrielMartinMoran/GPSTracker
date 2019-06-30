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

    // an http request ends with a blank line
    /*boolean currentLineIsBlank = true;
    boolean httpBody = false;
    boolean inStatus = false;

    char statusCode[4];
    int i = 0;
    */
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














/*
HTTPClient::HTTPClient(const char *_host)
{
    host = _host;
    port = 80;
    num_headers = 0;
    contentType = "application/x-www-form-urlencoded"; // default
    use_https = false;
    fingerprint = "";
}

HTTPClient::HTTPClient(const char *_host)
{
    host = _host;
    port = 80;
    num_headers = 0;
    contentType = "application/x-www-form-urlencoded"; // default
    use_https = false;
    fingerprint = "";
}

HTTPClient::HTTPClient(const char *_host, int _port)
{
    host = _host;
    port = _port;
    num_headers = 0;
    contentType = "application/x-www-form-urlencoded"; // default
    use_https = false;
    fingerprint = "";
}

int HTTPClient::begin(const char *ssid, const char *pass)
{
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    return WiFi.status();
}

// GET path
int HTTPClient::get(const char *path)
{
    return request("GET", path, NULL, NULL);
}

//GET path with response
int HTTPClient::get(const char *path, String *response)
{
    return request("GET", path, NULL, response);
}

// POST path and body
int HTTPClient::post(const char *path, const char *body)
{
    return request("POST", path, body, NULL);
}

// POST path and body with response
int HTTPClient::post(const char *path, const char *body, String *response)
{
    return request("POST", path, body, response);
}

// PUT path and body
int HTTPClient::put(const char *path, const char *body)
{
    return request("PUT", path, body, NULL);
}

// PUT path and body with response
int HTTPClient::put(const char *path, const char *body, String *response)
{
    return request("PUT", path, body, response);
}

// DELETE path
int HTTPClient::del(const char *path)
{
    return request("DELETE", path, NULL, NULL);
}

// DELETE path and response
int HTTPClient::del(const char *path, String *response)
{
    return request("DELETE", path, NULL, response);
}

// DELETE path and body
int HTTPClient::del(const char *path, const char *body)
{
    return request("DELETE", path, body, NULL);
}

// DELETE path and body with response
int HTTPClient::del(const char *path, const char *body, String *response)
{
    return request("DELETE", path, body, response);
}

void HTTPClient::setHeader(const char *header)
{
    headers[num_headers] = header;
    num_headers++;
}

void HTTPClient::setContentType(const char *contentTypeValue)
{
    contentType = contentTypeValue;
}

void HTTPClient::setSecureConnection(bool secureConn)
{
    use_https = secureConn;
}

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
// EX: CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C
void HTTPClient::setFingerprint(const char *fingerPrint)
{
    fingerprint = fingerPrint;
}

// The mother- generic request method.
//
*/