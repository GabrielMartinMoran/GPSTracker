#include <interfaces/IGPSController.h>
#include <string>
#include <queue>

class GPSControllerMockup2 : public IGPSController
{
private:
    std::queue<std::string> sentencias;
    void rellenarSentencias()
    {
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40"); //valido
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentencias.push("$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"); //valido
        this->sentencias.push("");
    }

public:
    GPSControllerMockup2() : GPSControllerMockup2(0)
    {
    }

    GPSControllerMockup2(int uartNumber)
    {
        this->rellenarSentencias();
    }
    std::string getInformation()
    {
        std::string sentencia;
        sentencia = this->sentencias.front();
        this->sentencias.pop();
        return sentencia;
    }

    bool isDataWaiting()
    {
        if (this->sentencias.empty())
        {
            this->rellenarSentencias();

            return false;
        }
        std::string sentencia = this->sentencias.front();
        if (sentencia == "")
        {
            this->sentencias.pop();
            return false;
        }
        return true;
    }
    ~GPSControllerMockup2() {}
};
