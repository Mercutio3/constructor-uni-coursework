#include <iostream>

using namespace std;

class worker{
    private:
        int id;
        string name;
    public:
        worker(int, string);
        ~worker();
        friend ostream& operator<<(ostream&, const worker&);
};

worker::worker(int nId, string nName){
    id = nId;
    name = nName;
}

worker::~worker(){}

ostream& operator<<(ostream& out, const worker& wo){
    out << "Name: " << wo.name << "; ID: " << wo.id << endl;
    return out;
}

int main() {
    worker a(234, "John McEnroe");
    worker b(324, "Jack Nicholson");
    cout << a << b;
    return 0;
}