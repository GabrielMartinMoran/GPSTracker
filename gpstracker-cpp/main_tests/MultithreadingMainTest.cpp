#include <thread>
#include <mutex>
#include <iostream>
#include <Arduino.h>

#include <platformioDependent/IOManager.h>

std::mutex sum2_mutex;
long sum = 0;
long sumas = 10000;

long volatile sum2 = 0;

void set(int value)
{
    sum = value;
    for (long i = 0; i < sumas; i++)
    {
        sum++;
        delay(1);
    }
    if (sum - value != sumas)
    {
        Serial.println("race condition");
    }
}
void runThread(long value)
{
    while (true)
    {

        set(value);
        delay(1);
    }
}

void mostrarSuma()
{
    Serial.println("inicio");
    while (true)
    {
        Serial.println(sum);
        delay(1000);
    }
}

void sumarNVeces(int thread_number, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::lock_guard<std::mutex> lock(sum2_mutex);
        sum2++;
    }
    //Serial.print("Thread nº ");
    //Serial.println(thread_number);
    //Serial.println(sum2);
    delay(1);
}

void setup()
{
    Serial.begin(115200);
    int n = 50;
    /*std::thread t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = std::thread(runThread, (long)i + 1);
    }
    std::thread mostrarSumaThread = std::thread(mostrarSuma);
    for (int i = 0; i < n; i++)
    {
        t[i].join();
    }
    mostrarSumaThread.join();
    */
    std::thread t2[n];

    for (int i = 0; i < n; i++)
    {
        t2[i] = std::thread(sumarNVeces, i, sumas);
    }

    for (int i = 0; i < n; i++)
    {
        t2[i].join();
    }

    Serial.print("Suma total esperada: ");
    Serial.println(n * sumas);
    Serial.print("Suma total obtenida: ");
    Serial.println(sum2);
    if (n * sumas != sum2)
    {
        Serial.println("race condition");
    }
}

void loop()
{
}