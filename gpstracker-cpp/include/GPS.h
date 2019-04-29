#include "Mockups/ControladorGPSMockup.h"

class GPS {
    private:
        ControladorGPSMockup *controladorGPSMockup;
        float latitud = 0;
        float longitud = 0;
    public:
        GPS(ControladorGPSMockup *controladorGPSMockup);
        void actualizar();
        ~GPS();
};
