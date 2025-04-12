#include <string>
#include <iostream>


using namespace std;


class Visitor { // интерфейс для всех посетителей
public:
	virtual string visitClassHero(const string &myText) = 0;
	virtual string visitClassWall(string &myText) = 0;
};

class ObjectVisitor : public Visitor { // реализация одного из посетителей
public:
	ObjectVisitor() = default;
	~ObjectVisitor() = default;
	string visitClassHero(const string& myText) override { // при посещении класса Hero просто распечатаем его текст
		cout << myText;
		return myText;
	}
	string visitClassWall(string& myText) override { // при посещении класса Wall мы поменяем значение его поля myText
		myText = "hello, i'm a wall\n";
		cout << myText;
		return myText;
	}
};

class Visited { // интерфейс посещаемого класса
public:
	virtual void accept(Visitor* vs) = 0; // метод, вызывающий конкретного посетителя
};

class Hero : public Visited {
private:
	string myText = "hello, i'm a hero\n";
public:
	Hero() = default;
	~Hero() = default;

	void accept(Visitor* vs) override {
		vs->visitClassHero(myText); // вызываем посетителя ObjectVisitor с методом visitClassHero
	}
};

class Wall : public Visited {
private:
	string myText = "aboba";
public:
	Wall() = default;
	~Wall() = default;

	void accept(Visitor* vs) override {
		vs->visitClassWall(myText); // вызываем посетителя ObjectVisitor с методом visitClassWall
		cout << myText; // проверяем, правильно ли сработал посетитель ObjectVisitor
	}
};


int main() {

	ObjectVisitor* ov = new ObjectVisitor;
	Hero hero;
	Wall wall;

	hero.accept(ov);
	wall.accept(ov);

	return 0;
}