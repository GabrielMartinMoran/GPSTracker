#include <BluetoothServer.h>

BluetoothServer::BluetoothServer(IWiFiConfiguration *wifiConfiguration, IBluetooth *bluetooth, ISerialController *serialController)
{
    this->wifiConfiguration = wifiConfiguration;
    this->bluetooth = bluetooth;
    this->serialController = serialController;
}

BluetoothServer::~BluetoothServer()
{
    if (bluetooth->isConnected())
    {
        this->stop();
    }
}

void BluetoothServer::start()
{
    bluetooth->start(this);
}

void BluetoothServer::stop()
{
    bluetooth->stop();
}

bool BluetoothServer::isCommand(std::string request, std::string command)
{
    if (command.length() > request.length())
    {
        return false;
    }
    return command == request || command == request.substr(0, command.length());
}

std::string BluetoothServer::getData(std::string request, std::string command)
{
    if (command.length() >= request.length())
    {
        return "";
    }
    return request.substr(command.length());
}

void BluetoothServer::onRequest(std::string request)
{
    serialController->println("REQUEST: " + std::string(request.c_str()));
    if (request.length() > 0)
    {
        if (isCommand(request, DELETE_NETWORK))
        {
            std::string networkToDelete = getData(request, DELETE_NETWORK);
            bool deleted = wifiConfiguration->deleteNetwork(networkToDelete);
            if (deleted)
            {
                sendResponse(OK);
            }
            else
            {
                sendResponse(ERROR);
            }
            return;
        }
        if (isCommand(request, LIST_NETWORKS))
        {
            sendResponse(wifiConfiguration->listNetworks());
            return;
        }
        if (isCommand(request, ADD_NETWORK))
        {
            bool networkAdded = wifiConfiguration->addNetworkFromCSVLine(getData(request, ADD_NETWORK));
            if (networkAdded)
            {
                sendResponse(OK);
            }
            else
            {
                sendResponse(ERROR);
            }
            return;
        }
        if (request == END_CONFIGURATION)
        {
            if (this->endConfigurationCallback != NULL)
            {
                this->endConfigurationCallback->endConfiguration();
            }
            sendResponse(OK);
            return;
        }
        if (isCommand(request, ECHO))
        {
            sendResponse(getData(request, ECHO));
            return;
        }
        if (isCommand(request, CLIENT_CONNECTED))
        {
            endConfigurationCallback->setDeviceConnected();
            sendResponse(OK);
            return;
        }
        serialController->println("Unrecognized Bluetooth request: " + std::string(request.c_str()));
        sendResponse(ERROR);
    }
}

void BluetoothServer::sendResponse(std::string response)
{
    bluetooth->transmitData(response);
}

void BluetoothServer::setEndConfigurationCallback(EndConfigurationCallback *endConfigurationCallback)
{
    this->endConfigurationCallback = endConfigurationCallback;
}