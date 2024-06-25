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
    virtual int getId() = 0;
    virtual int getAge() = 0;
    virtual float getKey() = 0;
    virtual void increaseAge() = 0;
    virtual void info() = 0;
};

class Oak : public Tree {
private:
    int id;
    int age = 1;
    float key = 2;
public:
    Oak() :id(curId++) {}

    int getId() {
        return id;
    }

    int getAge() {
        return age;
    }

    float getKey() {
        return key;
    }

    void increaseAge() {
        age++;
    }

    void info() {
        cout << "Oak ID: " << id << ", age: " << age << endl;
    }
};

class Birch : public Tree {
private:
    int id;
    int age = 1;
    float key = 3;
public:
    Birch() :id(curId++) {}

    int getId() {
        return id;
    }

    int getAge() {
        return age;
    }

    float getKey() {
        return key;
    }

    void increaseAge() {
        age++;
    }

    void info() {
        cout << "Birch ID: " << id << ", age: " << age << endl;
    }
};

class Spruce : public Tree {
private:
    int id;
    int age = 1;
    float key = 2.5;
public:
    Spruce() :id(curId++) {}

    int getId() {
        return id;
    }

    int getAge() {
        return age;
    }

    float getKey() {
        return key;
    }

    void increaseAge() {
        age++;
    }

    void info() {
        cout << "Spruce ID: " << id << ", age: " << age << endl;
    }
};

class Forest {
private:
    vector<Tree*> trees;
public:
    void plantTree(int tree) {
        switch (tree) {
        case 1:
            trees.push_back(new Oak());
            break;
        case 2:
            trees.push_back(new Birch());
            break;
        case 3:
            trees.push_back(new Spruce());
            break;
        default:
            throw 1;
        }
    }

    int getTreeNumber(int id) {
        for (int i = 0; i < trees.size(); i++) {
            if (trees[i]->getId() == id) {
                return i;
            }
        }
    }

    int cutDownTree(int id) {
        int treeNumber = getTreeNumber(id);
        int log = trees[treeNumber]->getAge() * trees[treeNumber]->getKey() / 4;

        return log;
    }

    void increaseAge() {
        for (int i = 0; i < trees.size(); i++) {
            trees[i]->increaseAge();
        }
    }

    void info() {
        for (int i = 0; i < trees.size(); i++) {
            trees[i]->info();
        }
    }
};


int Tree::curId = 1;

int main()
{
    Forest forest;

    forest.plantTree(1);
    forest.plantTree(2);
    forest.plantTree(3);
    forest.plantTree(1);
    forest.plantTree(2);
    forest.plantTree(3);
    forest.cutDownTree(2);
    forest.info();
}