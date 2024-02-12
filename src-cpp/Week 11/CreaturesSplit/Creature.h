/*
CH-230-A
a11_p4.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

class Creature {
	public:
		Creature();  
		void run() const;
        ~Creature();
	protected:
		int distance;
};

class Wizard : public Creature {
	public:
		Wizard();
		void hover() const;
        ~Wizard();
	private:
		int distFactor;
};

class JacobsStudent : public Creature {
    public:
        JacobsStudent();
        void suffer() const;
        ~JacobsStudent();
    private:
        int sufferTime;
};

class Mexican : public Creature {
    public:
        Mexican();
        void drinkTequila() const;
        ~Mexican();
    private:
        int tequilaShots;
};