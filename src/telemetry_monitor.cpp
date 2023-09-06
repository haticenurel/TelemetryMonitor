#include "../protocol/include/telemetry_monitor.h"


TelemetryMonitor::TelemetryMonitor() : dataBuffer(BUFFER_SIZE) {
    // The constructor body is empty, as in-class initializers handle the data member initialization.
}

void TelemetryMonitor::startMonitoring(int maxResults) {
    int resultCount = 0;
    isMonitoring = true;

    while (isMonitoring && resultCount < maxResults) {
        SensorData newData = generateRandomSensorData();
        addToBuffer(newData);

        // Print real-time sensor data (you can modify this to display on a UI)
        std::cout << "Engine Temperature: " << newData.engineTemperature << " C | ";
        std::cout << "Vehicle Speed: " << newData.vehicleSpeed << " km/h" << std::endl;

        resultCount++;
        std::this_thread::sleep_for(std::chrono::milliseconds(dataLogIntervalMs));
    }

    if (resultCount == maxResults) {
        std::cout << "Maximum results reached. Stopping monitoring." << std::endl;
    }
}

void TelemetryMonitor::stopMonitoring() {
    isMonitoring = false;
}

void TelemetryMonitor::addToBuffer(const SensorData& data) {
    dataBuffer[rear] = data;
    rear = (rear + 1) % BUFFER_SIZE;
    if (rear == front) {
        bufferFull = true;
        front = (front + 1) % BUFFER_SIZE;
    }
}

SensorData TelemetryMonitor::generateRandomSensorData() {
    SensorData data;
    data.engineTemperature = rand() % 100 + 50; // Random temperature between 50 and 150
    data.vehicleSpeed = rand() % 120; // Random speed between 0 and 120 km/h
    // Add more simulated sensor data here
    return data;
}
