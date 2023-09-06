#ifndef TELEMETRY_MONITOR_H
#define TELEMETRY_MONITOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

struct SensorData {
    double engineTemperature;
    double vehicleSpeed;
    // Add more sensor variables here
};

class TelemetryMonitor {
public:
    TelemetryMonitor();
    void startMonitoring(int maxResults);
    void stopMonitoring();
    void logDataToFile(const std::string& filename);

private:
    void addToBuffer(const SensorData& data);
    SensorData generateRandomSensorData();

    const int BUFFER_SIZE = 100;
    std::vector<SensorData> dataBuffer;
    int front = 0;
    int rear = 0;
    bool bufferFull = false;
    bool isMonitoring = false;
    const int dataLogIntervalMs = 1000; // Log data every 1 second
};

#endif // TELEMETRY_MONITOR_H
