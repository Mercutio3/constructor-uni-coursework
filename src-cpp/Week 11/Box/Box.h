/*
CH-230-A
a11_p1.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

class Box {
    private:
        double height;
        double width;
        double depth;
    public:
        //Constructors & destructor
        Box();
        Box(double, double, double);
        Box(const Box&);
        ~Box();

        //Setter methods
        void setHeight(double h);
        void setWidth(double w);
        void setDepth(double d);

        //Getter methods
        double getHeight();
        double getWidth();
        double getDepth();
};