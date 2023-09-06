#include <iostream>
#include "../protocol/include/telemetry_monitor.h"

int main() {
    TelemetryMonitor monitor;
    int maxResults = 10; // Display 10 results at most
    monitor.startMonitoring(maxResults);
    // Add user interactions or data logging to a file here
    return 0;
}
