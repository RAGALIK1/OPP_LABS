#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class OperationLogger {
public:
    virtual void log(const string& message) noexcept = 0;

    virtual ~OperationLogger() noexcept = default;
};

class FileLogger : public OperationLogger {
    string fileName;

public:
    FileLogger(const string& file) : fileName(file) {}

    void log(const string& message) noexcept override {
        ofstream logFile(fileName, ios::app);
        if (logFile.is_open()) {
            logFile << message << endl;
            logFile.close();
        } else {
            cout << "Unable to open file for logging." << endl;
        }
    }
};

class ConsoleLogger : public OperationLogger {
public:
    void log(const string& message) noexcept override {
        cout << message << endl;
    }
};

int main() {
    OperationLogger* logger1 = new ConsoleLogger();
    OperationLogger* logger2 = new FileLogger("logfile.txt");

    logger1->log("Logging to console...");
    logger2->log("Logging to file...");

    delete logger1;
    delete logger2;

    return 0;
}
