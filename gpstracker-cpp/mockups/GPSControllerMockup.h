#include <interfaces/IGPSController.h>
#include <string>
#include <queue>

class GPSControllerMockup : public IGPSController
{
private:
    std::queue<std::string> sentencias;
    void rellenarSentencias()
    {
        this->sentencias.push("$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62");
        this->sentencias.push("$GPRMC,054454.529,V,3654.929,N,07302.499,W,9.6,2.63,160519,,E*7F");
        this->sentencias.push("$GPGGA,054455.529,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E");
        this->sentencias.push("$GPGLL,3654.929,N,07302.499,W,054456.529,V*3D");
        this->sentencias.push("$GPRMC,054457.529,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*47");
        this->sentencias.push("$GPGGA,054458.529,3654.928,N,07302.500,W,0,00,,,M,,M,,*53");
        this->sentencias.push("$GPGLL,3654.928,N,07302.500,W,054459.529,V*32");
        this->sentencias.push("$GPRMC,054500.529,A,3654.927,N,07302.502,W,75.7,2.56,160519,,E*4E");
        this->sentencias.push("$GPGGA,054501.529,3654.927,N,07302.502,W,0,00,,,M,,M,,*53");
        this->sentencias.push("$GPGLL,3654.927,N,07302.502,W,054502.529,V*30");
        this->sentencias.push("$GPRMC,054503.529,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*48");
        this->sentencias.push("$GPGGA,054504.529,3654.925,N,07302.503,W,0,00,,,M,,M,,*55");
        this->sentencias.push("$GPGLL,3654.925,N,07302.503,W,054505.529,V*34");
        this->sentencias.push("$GPRMC,054506.529,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43");
        this->sentencias.push("$GPGGA,054507.529,3654.924,N,07302.504,W,0,00,,,M,,M,,*50");
        this->sentencias.push("$GPGLL,3654.924,N,07302.504,W,054508.529,V*3F");
        this->sentencias.push("$GPRMC,054509.529,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*45");
        this->sentencias.push("$GPGGA,054510.529,3654.923,N,07302.506,W,0,00,,,M,,M,,*53");
    }

public:
    GPSControllerMockup() : GPSControllerMockup(0, 0)
    {
    }

    GPSControllerMockup(int pinTX, int pinRX)
    {
        this->rellenarSentencias();
    }
    std::string getInformation()
    {
        std::string sentencia = this->sentencias.front();
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
        return true;
    }
        ~GPSControllerMockup() {}
    };
