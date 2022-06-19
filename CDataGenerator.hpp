#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "utils.hpp"

class Person {
    uint32_t codeA;
    uint32_t codeV;
    std::string name;
public:
    Person(uint32_t codeA, uint32_t codeV, std::string name): codeA(codeA), codeV(codeV), name(name) {}
    friend std::ostream& operator<<(std::ostream& os, Person p) {
        os << p.codeA << "|" << p.codeV << "|" << p.name;
        return os;
    }
    uint32_t getCodeA(){
        return codeA;
    }
    static Person createPerson() {
        return Person(Utils::generateRandNumber(1000,9999),Utils::generateRandNumber(10000,99999), Utils::generatePlaneR());
    }
};

class PersonRepository {
    std::string path;
    std::ofstream file;
    std::vector<Person> vecP;
private:
    void read() {
        std::string line = "";
        std::ifstream arch("output.txt");
        while (getline(arch, line)) {
            std::stringstream s(line);
            std::string aux;
            uint32_t codeA;
            uint32_t codeV;
            std::string name;
            getline(s, aux, '|');
            codeA = std::stoi(aux);
            getline(s, aux, '|');
            codeV = std::stoi(aux);
            getline(s, aux, '|');
            name=aux;
            Person t(codeA, codeV, name);
            vecP.push_back(t);
        }
        arch.close();
    }
public:
    PersonRepository(std::string path): path(path) {
        this->file.open(path);
    }
    ~PersonRepository() {
        vecP.clear();
    }
    void generateAndSaveData(size_t quantity) {
        for(size_t i = 0; i < quantity; ++i) file << Person::createPerson() << "\n";
        this->file.close();
    }
   std::vector<Person> getVec(){
        return vecP;
    }
    void readData(){
        read();
    }
};