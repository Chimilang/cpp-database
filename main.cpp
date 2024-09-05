#include <iostream>
#include <fstream>
#include <string>

struct Record {
    std::string id;
    std::string name;
    std::string age;
};

void addRecord(const std::string& filename, const Record& record) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << record.id << "," << record.name << "," << record.age << "\n";
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void readRecords(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

int main() {
    std::string filename = "database.txt";
    Record r1 = {"1", "Alice", "30"};
    Record r2 = {"2", "Bob", "25"};
    addRecord(filename, r1);
    addRecord(filename, r2);
    readRecords(filename);
    return 0;
}
