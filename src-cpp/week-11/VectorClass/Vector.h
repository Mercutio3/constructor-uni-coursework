/*
CH-230-A
a11_p6.h
Santiago Dominguez
sdominguez@jacobs-university.de
 */

class Vector{
    private:
        int numComponents;
        double *compArray;
    public:
        //Consructors, copy constructor, destructor
        Vector();
        ~Vector();
        Vector(int numComponents, double* vecArray);
        Vector(const Vector&);

        //Setters and getters
        void setSize(int size);
        void setComponents(double* comps);
        int getSize();
        double* getComponents();
        
        //Operation methods
        double norm();
        Vector add(const Vector) const;
        Vector difference(const Vector) const;
        double scalProd(const Vector) const;
        
        void print();
};