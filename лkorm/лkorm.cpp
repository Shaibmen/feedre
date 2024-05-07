
#include <iostream>

using namespace std;


class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
};

class Pet {
public:
    virtual void Feed(int food) = 0;
};

class Dog : public Animal, public Pet {
    int randomNumber;
public:
    Dog(string n, int rnd) : Animal(n), randomNumber(rnd) {}
    void Feed(int food) override {
        if (randomNumber >= food - 10 && randomNumber <= food + 10) {
            cout << "Собака: " << name << " Живая. Кушает." << endl;
        }
        else {
            cout << "Собака: " << name << " Не живая." << endl;
        }
    }
};

class Cat : public Animal, public Pet {
    int randomNumber;
public:
    Cat(std::string n, int rn) : Animal(n), randomNumber(rn) {}
    void Feed(int food) override {
        if (randomNumber >= food - 10 && randomNumber <= food + 10) {
            cout << "Кшк: " << name << " Живая. Кушает." << endl;
        }
        else {
            cout << "Кшк: " << name << " Не живая." << endl;
        }
    }
};

int main()
{
    while (true)
    {
	    setlocale(LC_ALL, "RUS");
        srand(static_cast<unsigned int>(time(0)));
        int food;
        string dogName, catName;

        cout << "Введите количество еды для животного (0-100): ";
        cin >> food;
        cout << "введите имя собачки: ";
        cin >> dogName;
        cout << "введите имя кшки: ";
        cin >> catName;


        Dog dog(dogName, rand() % 101);
        Cat cat(catName, rand() % 101);

        dog.Feed(food);
        cat.Feed(food);

    }
}
