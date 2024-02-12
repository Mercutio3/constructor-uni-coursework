/*
CH-230-A
a11_p2.cpp
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

//Creature class definition
class Creature {
	public:
		Creature();  
		void run() const;
        ~Creature();
	protected:
		int distance;
};

//Creature constructor
Creature::Creature(): distance(10){
    cout << "Creature default constructor called." << endl;
}    

//Creature method using properties
void Creature::run() const
{ 
    cout << "running " << distance << " meters!\n";
}  

//Creature destructor
Creature::~Creature(){
    cout << "Creature destructor called." << endl;
}

//Wizard class definition
class Wizard : public Creature {
	public:
		Wizard();
		void hover() const;
        ~Wizard();
	private:
		int distFactor;
};

//Wizard constructor
Wizard::Wizard() : distFactor(3){
    cout << "Wizard default constructor called." << endl;
}  

//Wizard method using properties
void Wizard::hover() const
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

//Wizard destructor
Wizard::~Wizard(){
    cout << "Wizard destructor called." << endl;
}

//JacobsStudent class definition
class JacobsStudent : public Creature {
    public:
        JacobsStudent();
        void suffer() const;
        ~JacobsStudent();
    private:
        int sufferTime;
};

//JacobsStudent constructor
JacobsStudent::JacobsStudent() : sufferTime(4) {
    cout << "JacobsStudent default constructor called." << endl;
}

//JacobsStudent method using properties
void JacobsStudent::suffer() const{
    cout << "suffering for " << (distance * sufferTime) << " hours!\n";
}

//Jacobsstudent destructor
JacobsStudent::~JacobsStudent(){
    cout << "JacobsStudent destructor called." << endl;
}

//Mexican class definition
class Mexican : public Creature {
    public:
        Mexican();
        void drinkTequila() const;
        ~Mexican();
    private:
        int tequilaShots;
};

//Mexican constructor
Mexican::Mexican() : tequilaShots(5) {
    cout << "Mexican default constructor called." << endl;
}

//Mexican method using properties
void Mexican::drinkTequila() const{
    cout << "drinking " << (distance/tequilaShots) << " shots of tequila!\n";
}

//Mexican destructor
Mexican::~Mexican(){
    cout << "Mexican destructor called." << endl;
}

int main()
{ 
    //Create the four creatures and test properties

    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating a Jacobs Student.\n";
    JacobsStudent j;
    j.run();
    j.suffer();

    cout << "\nCreating a Mexican.\n";
    Mexican m;
    m.run();
    m.drinkTequila();

    cout << endl;

    return 0;
} 