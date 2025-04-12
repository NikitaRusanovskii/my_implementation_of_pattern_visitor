#include <string>
#include <iostream>


using namespace std;


class Visitor {
public:
	virtual string visitClassHero(const string &myText) = 0;
	virtual string visitClassWall(string &myText) = 0;
};

class ObjectVisitor : public Visitor {
public:
	ObjectVisitor() = default;
	~ObjectVisitor() = default;
	string visitClassHero(const string& myText) override {
		cout << myText;
		return myText;
	}
	string visitClassWall(string& myText) override {
		myText = "hello, i'm a wall\n";
		cout << myText;
		return myText;
	}
};

class Visited {
public:
	virtual void accept(Visitor* vs) = 0;
};

class Hero : public Visited {
private:
	string myText = "hello, i'm a hero\n";
public:
	Hero() = default;
	~Hero() = default;

	void accept(Visitor* vs) override {
		vs->visitClassHero(myText);
	}
};

class Wall : public Visited {
private:
	string myText = "aboba";
public:
	Wall() = default;
	~Wall() = default;

	void accept(Visitor* vs) override {
		vs->visitClassWall(myText);
		cout << myText;
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