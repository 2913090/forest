#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Tree {
private:
    int id;
    int age;
    float key;
protected:
    static int curId;
public:
    ~Tree() = default;
};

class Oak : public Tree {
private:
    int id;
    int age = 1;
    float key = 2;
public:
    Oak() :id(curId++) {}
};

class Birch : public Tree {
private:
    int id;
    int age = 1;
    float key = 3;
public:

};

class Spruce : public Tree {
private:
    int id;
    int age = 1;
    float key = 2.5;
public:

};

class Forest {
private:
    vector<Tree> trees;
public:

};


int Tree::curId = 1;

int main()
{

}
