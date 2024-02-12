#include <iostream>
#include <deque>

using namespace std;

class WindGauge {
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
    private:
        int history;
        deque<int> speeds;
};