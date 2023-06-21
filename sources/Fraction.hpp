#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

namespace ariel {

class Fraction{


    private:    
      //private variables
        int numerator; 
        int denominator;

    public:
       //constructors 
    Fraction(); 

    Fraction(int numerator, int denominator);

    Fraction(float number);
    

    //get function
    int getNumerator() const;
    int getDenominator() const;
    //set function
    void setNumerator(int);
    void setDenominator(int);
    
        
    
    // *** requested functions ***

    Fraction operator+(const Fraction& other) const; //Fraction+Fraction
    Fraction operator+(float number); //Fraction+float
    friend Fraction operator+(float number, const Fraction &frac); //float+Fraction

    Fraction operator-(const Fraction& other); //Fraction+Fraction
    float operator-(float number); //franct+float
    friend Fraction operator-(float number, const Fraction &frac); //float+Fraction

    Fraction operator*(const Fraction& other); //Fraction+Fraction
    float operator*(float number); //Fraction+float
    friend Fraction operator*(float number, const Fraction &frac);  //float+Fraction

    Fraction operator/(const Fraction& other); //Fraction+Fraction
    float operator/(float number); //Fraction+float
    friend Fraction operator/(float number, const Fraction &frac); //float+Fraction


    bool operator==(const Fraction& other) const;
    bool operator==(const float& number) const;

    bool operator<(const Fraction& other) const;
    bool operator<(float number) const;
    friend bool operator<(const float& number, const Fraction& frac);

    friend bool operator>(const float& number, const Fraction& frac);
    bool operator>(const Fraction& other) const;
    bool operator>(float number) const;
    
    bool operator<=(const Fraction& other) const;
    bool operator<=(float number) const;
    friend bool operator<=(const float& number, const Fraction& frac);


    friend bool operator>=(const float& number, const Fraction& frac);
    bool operator>=(const Fraction& other) const;
    bool operator>=(float number) const;
    

    Fraction& operator++(); //PREFIX

    Fraction& operator--();
    
    Fraction operator++(int); //POSTFIX
    
    Fraction operator--(int);
    
    friend std::istream& operator>>(std::istream& inpt, Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);






    // *** help function ***

        int getGcd (int number1, int number2); //get the GCD
         void reduceFraction(); //  It reduces a fraction to its simplest form by dividing both the numerator and denominator by their greatest common divisor (GCD).

};
}
   




#endif