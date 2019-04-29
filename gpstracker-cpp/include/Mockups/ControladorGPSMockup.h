
class ControladorGPSMockup {
    private:
        int pinRX = 0;
        int pinTX = 0;
    public:
        ControladorGPSMockup(int pinTX, int pinRX);
        ~ControladorGPSMockup();
};
