#include <interfaces/IGPSController.h>
#include <string>
#include <queue>

class GPSControllerMockup2 : public IGPSController
{
private:
    std::queue<std::string> sentences;
    void rellenarSentencias()
    {
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40"); //valido
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054457,A,3654.928,N,07302.500,W,41.7,2.65,160519,,E*40");
        this->sentences.push("$GPRMC,054509,A,3654.923,N,07302.506,W,51.1,2.54,160519,,E*42"); //valido
        this->sentences.push("");
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
    ~GPSControllerMockup2() {}
};
