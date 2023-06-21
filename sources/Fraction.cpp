#include "Fraction.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>


namespace ariel
{

//OUTLINE CONSTRUCTORS implementation

Fraction :: Fraction(){
    this -> numerator = 0;
    this -> denominator = 1;
}

//OUTLINE CONSTRUCTORS implementation

Fraction :: Fraction(int numerator , int denominator){
    if (denominator == 0 && numerator != 0){ //check divide in 0
        throw std::invalid_argument(" denominator can not be 0(cant divide in 0)");
    }
    if (numerator > INT_MAX || denominator > INT_MAX){ //check number is not int
        throw std::overflow_error("number is too large(need to be INT)");
    }
    if (denominator < 0){  //make the numerator to negetive if demoinator negetive
        this ->numerator = -1* numerator;
        this ->denominator = -1 * denominator;
    }
    else{
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    reduceFraction();  //  It reduces a fraction to its simplest form by dividing both the numerator and denominator by their greatest common divisor (GCD).

}



//OUTLINE CONSTRUCTORS implementation

Fraction::Fraction(float numerator) {
    this -> numerator = std :: round(numerator*1000);
    this -> denominator = 1000;
    reduceFraction();
}

 //*** GET Functions ***
int Fraction :: getNumerator() const{
    return this -> numerator;
}

int Fraction :: getDenominator() const{
    return this -> denominator;
}

 //*** SET Functions ***
void Fraction :: setNumerator(int numerator){
    this -> numerator = numerator;
}

void Fraction :: setDenominator(int denominator){
    if (denominator == 0){
        throw std :: runtime_error (" denominator cant be 0");
    }
    this -> denominator = denominator;
}



// *** requested functions ***

//OPERATOR+
Fraction Fraction::operator+(const Fraction& frac) const{

    long calculate1 = (long(this -> numerator) * frac.denominator) + (long(frac.getNumerator()) * this -> denominator);
    long calculate2 = long(this->denominator) * frac.denominator;
     if (calculate1 > INT_MAX || calculate2 > INT_MAX ||  calculate1 < INT_MIN || calculate2 < INT_MIN){
        throw std::overflow_error ("you need to use INT numbers ");
    }
    int newNumerator = (this -> numerator * frac.denominator) + (frac.getNumerator() * this -> denominator);
    int newDenominator = this -> denominator * frac.denominator;
    return Fraction(newNumerator,newDenominator);
}

Fraction Fraction::operator+(float number){

    Fraction frac(number);
    Fraction newResult(*this+frac); //frac+frac

    return newResult;
}

Fraction operator+(float number, const Fraction &frac){ 

    return (double(frac.getNumerator())/frac.getDenominator()) + (number);

}


//OPERATOR-
Fraction Fraction::operator-(const Fraction& frac) {

    long calculate1 = (long(this -> numerator) * frac.getDenominator()) - (long(frac.getNumerator()) * this -> denominator);
    long calculate2 = long(this->denominator) * frac.getDenominator();

     if (calculate1 > INT_MAX || calculate2 > INT_MAX ||  calculate1 < INT_MIN || calculate2 < INT_MIN){
        throw std::overflow_error ("  you need to use INT numbers ");
    }

    int newNumerator = (this-> numerator * frac.getDenominator()) - (frac.getNumerator() * this -> denominator);
    int newDenominator = this -> denominator * frac.getDenominator();
    
    return Fraction(newNumerator, newDenominator);
}

float Fraction::operator-(float number){
    float numerator = this -> numerator - number * this->denominator;
    return ((numerator)/this -> denominator);
}

Fraction operator-(float number, const Fraction &frac){
    return (number) - (double(frac.getNumerator())/frac.getDenominator());
}


//OPERATOR*
Fraction Fraction::operator*(const Fraction& frac){

    long calculate1 = long(this->numerator) * frac.getNumerator();
    long calculate2 = long(this->denominator) * frac.getDenominator();

     if (calculate1 > INT_MAX || calculate2 > INT_MAX ||  calculate1 < INT_MIN || calculate2 < INT_MIN){
        throw std::overflow_error ("  you need to use INT numbers ");
    }
    int newNumerator = (this->numerator * frac.getNumerator());
    int newDenominator = this ->denominator * frac.getDenominator();
    return Fraction(newNumerator, newDenominator);
}

float Fraction::operator*(float num){
    double numerator = double(this->numerator)*num;
    return numerator/this->denominator;
}


Fraction operator*(float number, const Fraction &frac){
    return (double(frac.getNumerator())/frac.getDenominator())*number;
}


//OPERATOR/
Fraction Fraction::operator/(const Fraction& frac)  {

    if (frac.getNumerator() == 0){
        throw std::runtime_error("denominator can not be 0(cant divide in 0)");
    }

    long calculate1 = long(this->numerator) * frac.getDenominator();
    long calculate2 = long(this->denominator) * frac.getNumerator();

     if (calculate1 > INT_MAX || calculate2 > INT_MAX ||  calculate1 < INT_MIN || calculate2 < INT_MIN){
        throw std::overflow_error ("  we're using INTEGERS");
    }
    int newNumerator = this -> numerator * frac.denominator;
    int newDenominator = this -> denominator * frac.getNumerator();
    return Fraction(newNumerator, newDenominator);
}

float Fraction::operator/(float num){

    if (num == 0){
        throw std::runtime_error("denominator can not be 0(cant divide in 0");
    }

    Fraction number(num);
    float fract1 = double(numerator)/denominator;
    float floatToFrac = double(number.getNumerator())/number.getDenominator();
    float calculateFrac = double(fract1)/floatToFrac;
    return calculateFrac;
}

Fraction operator/(float number, const Fraction &frac){

    return number/(double(frac.getNumerator())/frac.getDenominator());
}

//OPERATOR==
bool Fraction :: operator==(const Fraction& frac) const{

    if (this ->numerator == 0 && frac.getNumerator() == 0){
        return true;
    }

    double fract1 = std::round(double(this->numerator)/this->denominator * 1000) / 1000.0;
    double fract2 = std::round(double(frac.getNumerator())/frac.getDenominator() * 1000) / 1000.0;
    
    if (fract1 == fract2){
        return true;
    }
    return false;
}


bool Fraction :: operator==(const float& number) const{

    double fract1 = std::round(double(this->numerator)/this->denominator*1000) / 1000.0;
    double fract2 = std::round(number *1000)/1000.0;
    
    if (fract1 != fract2){
        return false;
    }
    return true;
}


 


//OPERATOR<=
bool Fraction :: operator<=(const Fraction& frac) const{

    if ((this -> numerator* frac.getDenominator()) <= (frac.getNumerator()*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<=(float number) const{
    if (this -> numerator <= number*this -> denominator){
        return true;
    } 
    return false;
}

bool operator<=(const float &number, const Fraction &frac){

    return frac >= number;
}


//OPERATOR<
bool Fraction :: operator<(const Fraction& frac) const{

    if ((this -> numerator* frac.getDenominator()) < (frac.getNumerator()*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator<(float number) const{

    if (this -> numerator < number*this -> denominator){
        return true;
    } 

    return false;
}

bool operator<(const float& number, const Fraction& frac){
    
    return frac > number;
}

//OPERATOR>=
bool Fraction :: operator>=(const Fraction& frac) const{ 

    if ((this -> numerator* frac.getDenominator()) >= (frac.getNumerator()*this -> denominator)){
        return true;
    } 

    return false;
}

bool Fraction :: operator>=(float number) const{

    if (this -> numerator >= number * this -> denominator){
        return true;
    } 
    return false;
}


bool operator>=(const float &number, const Fraction &frac){

    return frac <= number;
}


//OPERATOR>
bool Fraction :: operator>(const Fraction& frac) const{
    if ((this -> numerator* frac.getDenominator()) > (frac.getNumerator()*this -> denominator)){
        return true;
    } 
    return false;
}

bool Fraction :: operator>(float number) const{

    if (this -> numerator > number* this->denominator){
        return true;
    } 
    return false;
}

bool operator>(const float &number, const Fraction &frac){

    return frac < number;
}


//OPERATOR++
Fraction& Fraction ::operator++(){
    this -> numerator += this -> denominator;
    return *this;
}


Fraction Fraction::operator++(int) { 

    Fraction fract(*this); 
    this -> numerator += this -> denominator;
    return fract;

}

//OPERATOR--
Fraction& Fraction ::operator--(){
    this -> numerator -= this -> denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
    Fraction frac(*this); 
    this -> numerator -= this -> denominator;
    return frac;
}


std::ostream& operator<<(std::ostream& output, const Fraction& fraction){
    return (output << fraction.getNumerator()<< '/' << fraction.getDenominator());
}

std::istream& operator>>(std::istream& inpt, Fraction& fraction){

    int numerator, denominator;

    if (inpt.peek() == EOF){
        throw std::runtime_error ("no numbers enter");
    }
    inpt >> numerator;
    if (inpt.peek() == EOF){
        throw std::runtime_error ("enter more 1 number");
    }
    inpt >> denominator;
    if (denominator < 0){
        numerator = -1* numerator;
        denominator = -1 * denominator;
    }
    fraction.setNumerator(numerator);
    fraction.setDenominator(denominator);
	return inpt;
}

// help function - get gcd number
    int Fraction :: getGcd (int numerator, int denominator){

        if (numerator < 0){
            numerator = abs(numerator);
        }
        if (denominator < 0){
            denominator = abs(denominator);
        }
        if (denominator == 0){
            return numerator;
        }
        return (this->getGcd(denominator, numerator%denominator));
        
    }

//help function - //  It reduces a fraction to its simplest form by dividing both the numerator and denominator by their greatest common divisor (GCD).
    void Fraction :: reduceFraction(){

        int gcd = this->getGcd(this -> numerator, this -> denominator);
        this -> numerator /= gcd;
        this -> denominator /= gcd;
        
    }

};