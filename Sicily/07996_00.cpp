// Problem#: 7996
// Submission#: 3378188
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string>
#include <iostream>
using namespace std;

class Hardwares{
private:
    string CPU;
    string memory;
    string disk;
public:
    void setCPU(string CPU) {
        this->CPU = CPU;
    }
    void setMemory(string memory) {
        this->memory = memory;
    }
    void setDisk(string disk) {
        this->disk = disk;
    }
    void print() {
        cout << "Hardwares : " << endl;
        cout << "-CPU:" << CPU << endl;
        cout << "-memory:" << memory << endl;
        cout << "-disk:" << disk << endl;
    }   
};

class Softwares{
private:
    string OS;
    string browser;
public:
    void setOS(string OS) {
        this->OS = OS;
    }
    void setBrowser(string browser) {
        this->browser = browser;
    }
    void print() {
        cout << "Softwares : " << endl;
        cout <<"-OS:" << OS << endl;
        cout << "-browser:" << browser << endl;
    }
};

class Computer{
private:
    string supplier;//商家
    Hardwares hardwares;//硬件
    Softwares softwares;//软件
public:
    Computer(string supplier) {
        this->supplier = supplier;
    }
    void changeHardware(string hardwareType, string hardwareName) {
        if (hardwareType == "CPU") hardwares.setCPU(hardwareName);
        if (hardwareType == "memory") hardwares.setMemory(hardwareName);
        if (hardwareType == "disk") hardwares.setDisk(hardwareName);
    }
    void changeSoftware(string softwareType, string softwareName) {
        if (softwareType == "OS") softwares.setOS(softwareName);
        if (softwareType == "browser") softwares.setBrowser(softwareName);
    }
    void print() {
        cout << "supplier : " << supplier << endl;
        hardwares.print();
        softwares.print();
        cout << endl;
    }
};                                 