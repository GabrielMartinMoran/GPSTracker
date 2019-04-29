#include "Mockups/ControladorGPSMockup.h"
#include "Utils/StringTokenizer.h"

class GPS {
    private:
        ControladorGPSMockup *controladorGPSMockup;
        byte hora = 0;
        byte minuto = 0;
        byte segundo = 0;
        byte dia = 0;
        byte mes = 0;
        byte anio = 0;
        float latitud = 0;
        float longitud = 0;
        boolean N = true;
        boolean W = true;
        void parsearTiempo(String tiempo, byte *horaDia, byte *minutoMes, byte *sengundoAnio);
    public:
        GPS(ControladorGPSMockup *controladorGPSMockup);
        void actualizar();
        byte getHora();
        byte getMinuto();
        byte getSegundo();
        byte getDia();
        byte getMes();
        byte getAnio();
        ~GPS();
};
