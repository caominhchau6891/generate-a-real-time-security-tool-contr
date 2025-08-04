#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class RealTimeSecurityToolController {
private:
    bool systemStatus;
    string systemMessage;

public:
    RealTimeSecurityToolController() {
        systemStatus = true;
        systemMessage = "System is online.";
    }

    void startSystem() {
        systemStatus = true;
        systemMessage = "System is online.";
        cout << "Real-time security tool controller started." << endl;
        monitorSystem();
    }

    void stopSystem() {
        systemStatus = false;
        systemMessage = "System is offline.";
        cout << "Real-time security tool controller stopped." << endl;
    }

    void monitorSystem() {
        while (systemStatus) {
            // Simulate real-time system monitoring
            cout << "System status: " << systemMessage << endl;
            this_thread::sleep_for(chrono::seconds(5));
        }
    }

    void alertSystem(string alertMessage) {
        if (systemStatus) {
            systemMessage = "Alert: " + alertMessage;
            cout << "Alert: " << alertMessage << endl;
        }
    }
};

int main() {
    RealTimeSecurityToolController controller;

    controller.startSystem();

    // Simulate real-time security threats
    this_thread::sleep_for(chrono::seconds(10));
    controller.alertSystem("Unusual network activity detected.");
    this_thread::sleep_for(chrono::seconds(10));
    controller.alertSystem("Malware detected in system logs.");
    this_thread::sleep_for(chrono::seconds(10));
    controller.stopSystem();

    return 0;
}