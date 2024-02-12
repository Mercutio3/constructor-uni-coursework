#include <stdio.h>

typedef struct coffee {
    int id;
    char property;
}coffee;

void set_coffee_property(struct coffee* c, const unsigned char property){
    if(c->property&property){
        return;
    } else {
        c->property ^= property;
    }
}

void unset_coffee_property(struct coffee* c, const unsigned property){
    if(!(c->property&property)){
        c->property ^= property;
    } else {
        return;
    }
}

int main(){
    const unsigned char regular = 1<<0;
    const unsigned char espresso = 1<<1;
    const unsigned char double_espresso = 1<<2;
    const unsigned char milk = 1<<3;
    const unsigned char cream = 1<<4;
    const unsigned char soy_milk = 1<<5;
    const unsigned char sugar = 1<<6;
    const unsigned char sweetener = 1<<7;

    coffee c;
    c.id = 1;
    c.property = 0;
    set_coffee_property(&c, regular);
    set_coffee_property(&c, milk);
    set_coffee_property(&c, sugar);
    printf("%d\n", c.property);

    return 0;
}