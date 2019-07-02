#include <GPS/GPSData.h>

GPSData::GPSData(std::string data)
{
    this->rawData = std::string(data);

    std::string sentences;
    std::string checksum;

    StringTokenizer dataTokens = StringTokenizer(data, "*");
    try
    {
        sentences = dataTokens.nextToken();
        checksum = dataTokens.nextToken();

        if (calculateChecksum(sentences) == checksum)
        {
            StringTokenizer tokenSentences = StringTokenizer(sentences, ",");

            std::string time;
            std::string date;
            std::string signedLatitude;
            std::string signedLongitude;

            if (tokenSentences.nextToken() == "$GPRMC")
            {
                time = std::string(tokenSentences.nextToken()); // 08:18:36 UTC
                unsigned int hour, minute, second;
                parseTime(time, &hour, &minute, &second);

                if (tokenSentences.nextToken() == "A")
                {
                    signedLatitude = std::string(tokenSentences.nextToken());
                    double latitude = parseCoordinate(signedLatitude);

                    if (tokenSentences.nextToken() == "S")
                    {
                        latitude *= -1;
                    }
                    signedLongitude = std::string(tokenSentences.nextToken());
                    double longitude = parseCoordinate(signedLongitude);

                    if (tokenSentences.nextToken() == "W")
                    {
                        longitude *= -1;
                    }

                    this->coordinate = new Coordinate(latitude, longitude);

                    tokenSentences.nextToken();

                    tokenSentences.nextToken(); //Course Made Good, True

                    date = std::string(tokenSentences.nextToken()); //13 Sep 1998

                    unsigned int day, month, year;
                    parseTime(date, &day, &month, &year);

                    this->dateTime = new DateTime(day, month, year, hour, minute, second);
                    tokenSentences.nextToken(); //Magnetic variation 20.3 deg

                    tokenSentences.nextToken(); //East
                }
            }
        }
        else
        {
            invalidate();
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        invalidate();
    }
}

std::string GPSData::calculateChecksum(std::string sentences)
{
    const char *s = sentences.c_str();
    s++;
    int c = 0;

    while (*s)
        c ^= *s++;

    unsigned int t = 3;
    char buffer[t];
    snprintf(buffer, t, "%X", c);

    return std::string(buffer);
}

void GPSData::invalidate()
{
    delete this->coordinate;
    this->coordinate = nullptr;

    delete this->dateTime;
    this->dateTime = nullptr;
}

void GPSData::parseTime(std::string time, unsigned int *hourDay, unsigned int *minuteMonth, unsigned int *secondYear)
{
    *hourDay = stringToNumber<unsigned int>(time.substr(0, 2));
    *minuteMonth = stringToNumber<unsigned int>(time.substr(2, 2));
    *secondYear = stringToNumber<unsigned int>(time.substr(4, 2));
}

double GPSData::parseCoordinate(std::string coordinate)
{
    int separator = coordinate.find(".") - 2;
    double degrees = stringToNumber<double>(coordinate.substr(0, separator));
    double minutes = stringToNumber<double>(coordinate.substr(separator, coordinate.length() - separator));
    return degrees + minutes / 60;
}

DateTime GPSData::getDateTime()
{
    if (!this->isValid())
    {
        throw InvalidReadGPSDataException();
    }
    return *this->dateTime;
}

Coordinate GPSData::getCoordinate()
{
    if (!this->isValid())
    {
        throw InvalidReadGPSDataException();
    }
    return *this->coordinate;
}

bool GPSData::isValid()
{
    return this->coordinate != nullptr && this->dateTime != nullptr;
}

void GPSData::motionless()
{
    this->_motionless = true;
}

bool GPSData::isMotionless()
{
    if (!this->isValid())
    {
        throw InvalidReadGPSDataException();
    }
    return this->_motionless;
}

std::string GPSData::getRawData()
{
    return this->rawData;
}

std::string GPSData::getNormalizedData()
{
    if (!this->isValid())
    {
        throw InvalidReadGPSDataException();
    }
    unsigned int t = 43;
    char buffer[t];
    snprintf(buffer, t, "%02d-%02d-%02d %02d:%02d:%02d,%c%09.5f,%c%09.5f,%c\n",
             getDateTime().getYear(), getDateTime().getMonth(), getDateTime().getDay(),
             getDateTime().getHour(), getDateTime().getMinute(), getDateTime().getSecond(),
             getCoordinate().getLatitude() > 0 ? '+' : '-',
             std::abs(getCoordinate().getLatitude()),
             getCoordinate().getLongitude() > 0 ? '+' : '-',
             std::abs(getCoordinate().getLongitude()),
             this->isMotionless() ? '1' : '0');
    return std::string(buffer);
}

GPSData::~GPSData()
{
    delete this->coordinate;
    delete this->dateTime;
}