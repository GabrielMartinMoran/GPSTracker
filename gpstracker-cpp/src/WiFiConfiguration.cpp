#include <WiFiConfiguration.h>

WiFiConfiguration::WiFiConfiguration(ISDManager *sdManager)
{
    networks = new std::vector<WiFiNetwork *>();
    this->sdManager = sdManager;
    this->loadConfiguration();
}

WiFiConfiguration::~WiFiConfiguration()
{
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        //*elementPointer devuelve un puntero a un WiFiNetwork, por eso se elimina el *elementPointer y no elementPointer directo
        delete *elementPointer;
    }
    delete networks;
}

void WiFiConfiguration::loadConfiguration()
{
    std::vector<std::string> *fileLines = sdManager->readFileLines(WIFI_CONFIGURATION_FILENAME);
    for (std::vector<std::string>::iterator elementPointer = fileLines->begin(); elementPointer != fileLines->end(); ++elementPointer)
    {
        this->addNetworkToMemory(*elementPointer);
    }

    delete fileLines;
}

bool WiFiConfiguration::addNetworkToMemory(std::string SSIDNetworkCSV)
{
    StringTokenizer tokens(SSIDNetworkCSV, DATA_SEPARATOR);
    std::string SSID;
    std::string password;
    if (tokens.hasNext())
    {
        SSID = tokens.nextToken();
    }
    else
    {
        return false;
    }
    if (tokens.hasNext())
    {
        password = tokens.nextToken();
    }
    else
    {
        return false;
    }
    //Si llego hasta aca es porque tiene SSID y PASSWORD
    networks->push_back(new WiFiNetwork(SSID, password));
    return true;
}

bool WiFiConfiguration::addNetworkFromCSVLine(std::string SSIDNetworkCSV)
{
    bool couldAdd = this->addNetworkToMemory(SSIDNetworkCSV);
    if (couldAdd)
    {
        this->saveConfiguration();
    }
    return couldAdd;
}

bool WiFiConfiguration::deleteNetwork(std::string SSID)
{
    for (size_t i = 0; i < this->getConfiguredNetworks(); i++)
    {
        if (this->getNetworkAtPosition(i)->SSID == SSID)
        {
            this->removeNetwork(i);
            return true;
        }
    }
    return false;
}

unsigned int WiFiConfiguration::getConfiguredNetworks()
{
    return networks->size();
}

WiFiNetwork *WiFiConfiguration::getNetworkAtPosition(unsigned int index)
{
    return networks->at(index);
}

void WiFiConfiguration::removeNetwork(unsigned int index)
{
    WiFiNetwork *networkToDelete;
    networkToDelete = networks->at(index);
    networks->erase(networks->begin() + index);
    delete networkToDelete;
    this->saveConfiguration();
}

void WiFiConfiguration::addNetwork(std::string SSID, std::string password)
{
    networks->push_back(new WiFiNetwork(SSID, password));
    this->saveConfiguration();
}

void WiFiConfiguration::saveConfiguration()
{
    std::string fileContent = "";
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        fileContent += (*elementPointer)->toCSVLine();
        fileContent += "\r";
    }
    this->deleteConfigurationFile();
    sdManager->writeFile(WIFI_CONFIGURATION_FILENAME, fileContent);
}

void WiFiConfiguration::deleteConfigurationFile()
{
    sdManager->deleteFile(WIFI_CONFIGURATION_FILENAME);
}

std::string WiFiConfiguration::listNetworks()
{
    std::string list = "";
    for (std::vector<WiFiNetwork *>::iterator elementPointer = networks->begin(); elementPointer != networks->end(); ++elementPointer)
    {
        list += (*elementPointer)->SSID;
        if (elementPointer + 1 != networks->end())
        {
            list += ",";
        }
    }
    return list;
}