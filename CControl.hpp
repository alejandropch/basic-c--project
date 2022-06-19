#include "CDataGenerator.hpp"
#include "CUsuario.hpp"
using DataStructures::BinarySearchTree;
using namespace std;

class CControl
{
private:
    PersonRepository* repo;
    BinarySearchTree<int, Person>* bst;
public:
    CControl(){
        repo = new PersonRepository("output.txt");
        bst = new BinarySearchTree<int, Person>(
                [](int a, int b) -> bool { return a < b;},
                [](Person p) -> void { std::cout << p << " "; },
                [](int a, int b) -> bool { return a == b; }
        );
    }
    ~CControl(){
        delete repo;
    }

    void generateData(int num){
        repo->generateAndSaveData(num);
        //repo->readData();
    }

    void indexData(){
        for (int i = 0; i < repo->getVec().size(); i++) {
            bst->insert(repo->getVec().at(i).getCodeA(),repo->getVec().at(i));
        }
        bst->display();
    }

    void sortByID(){

    }

    void generateHT(){

    }
};