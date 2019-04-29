#include "Mockups/ControladorGPSMockup.h"
#include "Utils/StringTokenizer.h"

class GPS {
    private:
        ControladorGPSMockup *controladorGPSMockup;
        float latitud = 0;
        float longitud = 0;
        boolean N = true;
        boolean W = true;
    public:
        GPS(ControladorGPSMockup *controladorGPSMockup);
        void actualizar();
        ~GPS();
};
