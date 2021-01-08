// ----------------------------- complex.cpp ------------------------------------

// James Truong CSS501A

// Created: October 8th, 2020

// Last Modified: October 16th 2020

// ----------------------------------------------------------------------------

// This is the implementation file of the complex class.
// A complex object that holds one real number and one imaginary number. Allows
// basic arithmetic manipulations, equal comparison, and complex number output.

// ----------------------------------------------------------------------------

// 1. Assumes inputs are valid numbers, but will error handle prompting for new
// valid inputs.
// 2. Complex dividing has a special case regarding division by zero printing
// out an error message returning the numerator. 

// ----------------------------------------------------------------------------

#include "complex.h"

/** Prints the complex object with the real and imaginary part in the form
* of X+Yi or X-Yi where X is the real part and Y with respect to its sign
* is the imaginary part. If both X and Y are zero, prints 0. If X is zero,
* will print Yi. If Y is zero, will print out X. If Y is 1, will print i
* instead and -i if Y is -1.
*/
static ostream& imaginaryChecker(ostream& output, double imaginary)
{
    if (imaginary == 1.0)
    {
        output << "i";
    }
    else if (imaginary == -1.0)
    {
        output << "-i";
    }
    else
    {
        output << imaginary << "i";
    }
    return output;
}

/** Takes 2 double inputs and sets the first value as the real part of the
* complex object and the second value as the imaginary part.
* precondition: No error checking on what is inputted.
* postcondition: a complex object now has those values as its real and
* imaginary numbers.
*/
ostream& operator<<(ostream& output, const complex& number)
{
    string tmp;
    if (number.getReal() == 0.0 && number.getImaginary() == 0.0)
    {
        output << 0 << endl;
    }
    else if (number.getReal() != 0.0)
    {
        output << number.getReal();
        if (number.getImaginary() != 0.0)
        {
            string sign = (number.getImaginary() > 0) ? "+" : "";
            output << sign;
            imaginaryChecker(output, number.getImaginary());
        }
    }
    else
    {
        imaginaryChecker(output, number.getImaginary());
    }
    output << tmp;
    return output;
}

/** Takes 2 double inputs and sets the first value as the real part of the
* complex object and the second value as the imaginary part.
* precondition: checks if both inputs are doubles, otherwise prints 
* error message and ignores previous inputs to prompt for doubles again.
* postcondition: a complex object now has those values as its real and
* imaginary numbers.
*/
istream& operator>>(istream& input, complex& number)
{
    double checkReal, checkImag;
    while (1)
    {
        input >> checkReal >> checkImag;
        if (input.fail())
        {
            input.clear();
            cout << "Bad input. Please input 2 double values again:" << endl;
            input.ignore();
        }
        else
        {
            number.real = checkReal;
            number.imaginary = checkImag;
            return input;
        }
    }
}

/** Default constructor: creates a complex object and initializes
* its real and imaginary numbers to a default value if no arguments
* is passed for both, otherwise sets the real or imaginary to the given
* values.
* precondition: 0, 1 or 2 double arguments passed as real and/or imaginary
* values.
* postcondition: A complex object with an initial real and imaginary
* number exists.
*/
complex::complex(const double& real, const double& imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

/** Gets the real part of the complex object.
* precondition: None.
* postcondition: returns the real number of the complex object.
*/
double complex::getReal() const
{
    return this->real;
}

/** Gets the imaginary part of the complex object.
* precondition: None.
* postcondition: returns the imaginary number of the complex object.
*/
double complex::getImaginary() const
{
    return this->imaginary;
}

/** Sets the real part of the complex object.
* precondition: parameter passed is a valid value.
* postcondition: sets real number of complex object to given value.
*/
void complex::setReal(const double& real)
{
    this->real = real;
}

/** Sets the imaginary part of the complex object.
* precondition: parameter passed is a valid value.
* postcondition: sets imaginary number of complex object to given value.
*/
void complex::setImaginary(const double& imaginary)
{
    this->imaginary = imaginary;
}

/** Adds complex objects together.
* precondition: another complex object.
* postcondition: returns another complex object containing the sum of the
* complex objects.
*/
complex complex::operator+(const complex& other) const
{
    complex result;
    result.real = this->real + other.real;
    result.imaginary = this->imaginary + other.imaginary;
    return result;
}

/** Subtracts complex objects.
* precondition: another complex object.
* postcondition: returns another complex object containing the net sum of
* the complex objects.
*/
complex complex::operator-(const complex& other) const
{
    complex result;
    result.real = this->real - other.real;
    result.imaginary = this->imaginary - other.imaginary;
    return result;
}

/** Multiplies complex objects.
* precondition: another complex object.
* postcondition: returns the result of multiplying the Complex objects in
* another complex object.
*/
complex complex::operator*(const complex& other) const
{
    complex result;
    result.real = this->real * other.real + 
        this->imaginary * other.imaginary * -1.0;
    result.imaginary = this->real * other.imaginary + 
        this->imaginary * other.real;
    return result;
}

/** Divides complex objects.
* precondition: another complex object.
* postcondition: if dividing by zero, outputs "DIVIDE BY ZERO ERROR!!! " and
* returns a copy of the left-side complex object of the operator, otherwise
* returns the result of dividing the complex objects in another complex
* object.
*/
complex complex::operator/(const complex& other) const
{
    complex result;
    complex numerator = *this * other.conjugate();
    // gives us a real denominator (no imaginary)
    complex denominator = other * other.conjugate();
    if (denominator.real == 0.0)
    {
        cout << "DIVIDE BY ZERO ERROR!!! ";
        return *this;
    }
    else
    {
        result.real = numerator.real / denominator.real;
        result.imaginary = numerator.imaginary / denominator.real;
    }
    return result;
}

/** Conjugates complex objects turning the positive imaginary to negative
* imaginary and vice versa.
* precondition: None.
* postcondition: returns a complex object with the real and opposite sign
* of the imaginary part of the invoked complex object.
*/
complex complex::conjugate() const
{
    complex result;
    result.real = this->real;
    result.imaginary = -this->imaginary;
    return result;
}

/** Compares complex objects and checks if they are equal.
* precondition: another complex object.
* postcondition: returns true if the other complex object is equal to this
* complex object, otherwise false.
*/
bool complex::operator==(const complex& other) const
{
    return this->real == other.real && this->imaginary == other.imaginary;
}

/** Compares complex objects and checks if they are not equal.
* precondition: another complex object.
* postcondition: returns true if the other complex object is not equal to
* this complex object, otherwise false.
*/
bool complex::operator!=(const complex& other) const
{
    return this->real != other.real && this->imaginary != other.imaginary;
}

/** Adds complex objects together making the result of the operation this
* complex object.
* precondition: another complex object.
* postcondition: returns this complex object as the sum of the complex
* objects.
*/
complex& complex::operator+=(const complex& other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

/** Subtracts complex objects making the net sum of the operation this
* complex object.
* precondition: another complex object.
* postcondition: returns this complex object as the net sum of the complex
* objects.
*/
complex& complex::operator-=(const complex& other)
{
    this->real -= other.real;
    this->imaginary -= other.imaginary;
    return *this;
}

/** Multiplies complex objects making the result of the operation this
* complex object.
* precondition: another complex object.
* postcondition: returns the result of multiplying the complex objects in
* this complex object.
*/
complex& complex::operator*=(const complex& other)
{
    double temp = this->real;
    this->real = this->real * other.real + 
        (this->imaginary * other.imaginary * -1);
    this->imaginary = temp * other.imaginary +
        this->imaginary * other.real;
    return *this;
}

/** Divides complex objects making the result of the operation this complex
* object.
* precondition: another complex object.
* postcondition: if dividing by zero, outputs "DIVIDE BY ZERO ERROR!!! " and
* returns this complex object unmodified, otherwise returns the result of
* dividing the complex objects in this complex object.
*/
complex& complex::operator/=(const complex& other)
{
    complex numerator = *this * other.conjugate();
    complex denominator = other * other.conjugate();
    if (denominator.real == 0.0) {
        cout << "DIVIDE BY ZERO ERROR!!! " ;
    }
    else {
        this->real = numerator.real / denominator.real;
        this->imaginary = numerator.imaginary / denominator.real;
    }
    return *this;
}



