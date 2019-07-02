#include <interfaces/IGPSController.h>
#include <string>
#include <queue>

class GPSControllerMockup : public IGPSController
{
private:
    std::queue<std::string> sentences;
    void rellenarSentencias()
    {
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40"); //valido

        this->sentences.push("$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"); //valido

        this->sentences.push("$GPRMC,054454,V,3654.929,N,07302.499,W,009.6,02.63,160519,00000,E*7F");
        this->sentences.push(""); //invalido

        this->sentences.push("$GPGGA,054455,3654.929,N,07302.499,W,0,00,,,M,,M,,*5E");
        this->sentences.push("$GPGLL,3654,N,07302.499,W,054456.529,V*3D");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40"); //valido

        this->sentences.push("$GPGGA,054458,3654.928,N,07302.500,W,0,00,,,M,,M,,*53");
        this->sentences.push("$GPGLL,3654,N,07302.500,W,054459.529,V*32");
        this->sentences.push("$GPRMC,054500,A,3654.907,N,07302.482,W,75.7,2.56,160519,,E*42"); //valido

        this->sentences.push("$GPGGA,054501,3654.927,N,07302.502,W,0,00,,,M,,M,,*53");
        this->sentences.push("$GPGLL,3654,N,07302.502,W,054502.529,V*30");
        this->sentences.push("$GPRMC,054503,A,3654.925,N,07302.503,W,82.8,2.57,160519,,E*4F"); //valido

        this->sentences.push("$GPGGA,054504,3654.925,N,07302.503,W,0,00,,,M,,M,,*55");
        this->sentences.push("$GPGLL,3654,N,07302.503,W,054505.529,V*34");
        this->sentences.push("$GPRMC,054506,V,3654.924,N,07302.504,W,63.9,2.51,160519,,E*43");
        this->sentences.push(""); //invalido

        this->sentences.push("$GPGGA,054507,3654.924,N,07302.504,W,0,00,,,M,,M,,*50");
        this->sentences.push("$GPGLL,3654,N,07302.504,W,054508.529,V*3F");
        this->sentences.push("$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"); //valido
        this->sentences.push("$GPGGA,054510,3654.923,N,07302.506,W,0,00,,,M,,M,,*53");
    }

public:
    GPSControllerMockup() : GPSControllerMockup(0)
    {
    }

    GPSControllerMockup(int uartNumber)
    {
        this->rellenarSentencias();
    }
    std::string getInformation()
    {
        std::string sentence;
        sentence = this->sentences.front();
        this->sentences.pop();
        return sentence;
    }

    bool isWaitingData()
    {
        if (this->sentences.empty())
        {
            this->rellenarSentencias();

            return false;
        }
        std::string sentence = this->sentences.front();
        if (sentence == "")
        {
            this->sentences.pop();
            return false;
        }
        return true;
    }
    ~GPSControllerMockup() {}
};
