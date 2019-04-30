#ifndef Configuration_h
#define Configuration_h

class Configuration
{
  public:
    Configuration();
    ~Configuration();
    void loadConfiguration();
    void configure();
    bool is_configured();
};

#endif