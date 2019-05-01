#include <WiFiConfiguration.h>

WiFiConfiguration::WiFiConfiguration()
{
    networks = new std::vector<WiFiNetwork *>();
    sdManager = new SDManager();
}

WiFiConfiguration::~WiFiConfiguration()
{
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        //*elementPointer devuelve un puntero a un WiFiNetwork, por eso se elimina el *elementPointer y no elementPointer directo
        delete *elementPointer;
    }
    delete networks;
    delete sdManager;
}

void WiFiConfiguration::loadConfiguration()
{
    std::vector<String> *fileLines = sdManager->readFileLines(WIFI_CONFIGURATION_FILENAME);
    for (std::vector<String>::iterator elementPointer = fileLines->begin(); elementPointer != fileLines->end(); ++elementPointer)
    {
        StringTokenizer tokens(*elementPointer, DATA_SEPARATOR);
        String SSID;
        String password;
        if (tokens.hasNext())
        {
            SSID = tokens.nextToken();
            SSID.replace("\r", "");
            SSID.replace("\n", "");
        }
        else
        {
            continue;
        }
        if (tokens.hasNext())
        {
            password = tokens.nextToken();
            password.replace("\r", "");
            password.replace("\n", "");
        }
        else
        {
            continue;
        }
        //Si llego hasta aca es porque tiene SSID y PASSWORD
        networks->push_back(new WiFiNetwork(SSID, password));
    }

    delete fileLines;
}

void WiFiConfiguration::printConfiguratedNetworks()
{
    Serial.println("Listando las redes configuradas:");
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        Serial.println((*elementPointer)->toString());
    }
}

unsigned int WiFiConfiguration::getConfiguredNetworks()
{
    return networks->size();
}

WiFiNetwork *WiFiConfiguration::getNetworkAtPosition(unsigned int index)
{
    return networks->at(index);
}

void WiFiConfiguration::removeNetwork(unsigned int index){
    WiFiNetwork *networkToDelete;
    networkToDelete = networks->at(index);
    networks->erase (networks->begin() + index);
    delete networkToDelete;
    this->saveConfiguration();
}

void WiFiConfiguration::addNetwork(String SSID, String password){
    networks->push_back(new WiFiNetwork(SSID, password));
    this->saveConfiguration();
}

void WiFiConfiguration::saveConfiguration(){
    String fileContent = "";
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        fileContent += (*elementPointer)->toCSVLine();
        fileContent += "\r";
    }
    this->deleteConfigurationFile();
    sdManager->writeFile(WIFI_CONFIGURATION_FILENAME, fileContent);
}

void WiFiConfiguration::deleteConfigurationFile(){
    sdManager->deleteFile(WIFI_CONFIGURATION_FILENAME);
}