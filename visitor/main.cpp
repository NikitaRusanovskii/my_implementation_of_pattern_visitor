#include <string>
#include <iostream>

using namespace std;

class Visitor { // interface for all visitors
public:
	virtual string visitClassHero(const string& myText) = 0;
	virtual string visitClassWall(string& myText) = 0;
};

class ObjectVisitor : public Visitor { // implementation of one of the visitors
public:
	ObjectVisitor() = default;
	~ObjectVisitor() = default;

	string visitClassHero(const string& myText) override { // when visiting the Hero class, just print its text
		cout << myText;
		return myText;
	}

	string visitClassWall(string& myText) override { // when visiting the Wall class, change the value of its myText field
		myText = "hello, i'm a wall\n";
		cout << myText;
		return myText;
	}
};

class Visited { // interface for visitable classes
public:
	virtual void accept(Visitor* vs) = 0; // method that invokes a specific visitor
};

class Hero : public Visited {
private:
	string myText = "hello, i'm a hero\n";
public:
	Hero() = default;
	~Hero() = default;

	void accept(Visitor* vs) override {
		vs->visitClassHero(myText); // call the ObjectVisitor with the visitClassHero method
	}
};

class Wall : public Visited {
private:
	string myText = "aboba";
public:
	Wall() = default;
	~Wall() = default;

	void accept(Visitor* vs) override {
		vs->visitClassWall(myText); // call the ObjectVisitor with the visitClassWall method
		cout << myText; // check if ObjectVisitor worked correctly
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
