// ----------------------------- complex.h ------------------------------------

// James Truong CSS501A

// Created: October 8th, 2020

// Last Modified: October 16th 2020

// ----------------------------------------------------------------------------

// A complex object that holds one real number and one imaginary number
// (a number multiplied by i). Allows basic arithmetic manipulations,
// equal comparison, and complex number output.

// ----------------------------------------------------------------------------

// 1. Assumes inputs are valid numbers, but will error handle prompting for new
// valid inputs.
// 2. Complex dividing has a special case regarding division by zero printing
// out an error message returning the numerator.

// ----------------------------------------------------------------------------

#pragma once
#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
using namespace std;

class complex
{
	/** Prints the complex object with the real and imaginary part in the form
	* of X+Yi or X-Yi where X is the real part and Y with respect to its sign
	* is the imaginary part. If both X and Y are zero, prints 0. If X is zero,
	* will print Yi. If Y is zero, will print out X. If Y is 1, will print i
	* instead and -i if Y is -1.
	*/
	friend ostream& operator<<(ostream& output, const complex& number);

	/** Takes 2 double inputs and sets the first value as the real part of the
	* complex object and the second value as the imaginary part.
	* precondition: checks if both inputs are doubles, otherwise prints 
	* error message and ignores previous inputs to prompt for doubles again.
	* postcondition: a complex object now has those values as its real and
	* imaginary numbers.
	*/
	friend istream& operator>>(istream& input, complex& number);

public:
	/** Default constructor: creates a complex object and initializes
	* its real and imaginary numbers to a default value if no arguments
	* is passed for both, otherwise sets the real or imaginary to the given
	* values.
	* precondition: 0, 1 or 2 double arguments passed as real and/or imaginary
	* values.
	* postcondition: A complex object with an initial real and imaginary
	* number exists.
	*/
	complex(const double& real = 0.0, const double& imaginary = 0.0);

	/** Gets the real part of the complex object.
	* precondition: None.
	* postcondition: returns the real number of the complex object.
	*/
	double getReal() const;

	/** Gets the imaginary part of the complex object.
	* precondition: None.
	* postcondition: returns the imaginary number of the complex object.
	*/
	double getImaginary() const;

	/** Sets the real part of the complex object.
	* precondition: parameter passed is a valid value.
	* postcondition: sets real number of complex object to given value.
	*/
	void setReal(const double& real);

	/** Sets the imaginary part of the complex object.
	* precondition: parameter passed is a valid value.
	* postcondition: sets imaginary number of complex object to given value.
	*/
	void setImaginary(const double& imaginary);

	/** Adds complex objects together.
	* precondition: another complex object.
	* postcondition: returns another Complex object containing the sum of the
	* Complex objects.
	*/
	complex operator+(const complex& other) const;

	/** Subtracts complex objects.
	* precondition: another complex object.
	* postcondition: returns another Complex object containing the net sum of
	* the Complex objects.
	*/
	complex operator-(const complex& other) const;

	/** Multiplies complex objects.
	* precondition: another Complex object.
	* postcondition: returns the result of multiplying the Complex objects in
	* another Complex object.
	*/
	complex operator*(const complex& other) const;

	/** Divides complex objects.
	* precondition: another Complex object.
	* postcondition: if dividing by zero, outputs "DIVIDE BY ZERO ERROR!!! "
	* and returns a copy of the left-side complex object of the operator,
	* otherwise returns the result of dividing the complex objects in another
	* complex object.
	*/
	complex operator/(const complex& other) const;

	/** Conjugates complex objects turning the positive imaginary to negative
	* imaginary and vice versa.
	* precondition: None.
	* postcondition: returns a complex object with the real and opposite sign
	* of the imaginary part of the invoked complex object.
	*/
	complex conjugate() const;

	/** Compares complex objects and checks if they are equal.
	* precondition: another complex object.
	* postcondition: returns true if the other complex object is equal to this
	* Complex object, otherwise false.
	*/
	bool operator==(const complex& other) const;

	/** Compares complex objects and checks if they are not equal.
	* precondition: another complex object.
	* postcondition: returns true if the other complex object is not equal to
	* this Complex object, otherwise false.
	*/
	bool operator!=(const complex& other) const;

	/** Adds complex objects together making the result of the operation this
	* complex object.
	* precondition: another complex object.
	* postcondition: returns this complex object as the sum of the complex
	* objects.
	*/
	complex& operator+=(const complex& other);

	/** Subtracts complex objects making the net sum of the operation this
	* complex object.
	* precondition: another complex object.
	* postcondition: returns this complex object as the net sum of the complex
	* objects.
	*/
	complex& operator-=(const complex& other);

	/** Multiplies complex objects making the result of the operation this
	* Complex object.
	* precondition: another complex object.
	* postcondition: returns the result of multiplying the complex objects in
	* this complex object.
	*/
	complex& operator*=(const complex& other);

	/** Divides complex objects making the result of the operation this complex
	* object.
	* precondition: another complex object.
	* postcondition: if dividing by zero, outputs "DIVIDE BY ZERO ERROR!!! "
	* and returns this complex object unmodified, otherwise returns the result
	* of dividing the complex objects in this complex object.
	*/
	complex& operator/=(const complex& other);

private:
	double real;
	double imaginary;
	static ostream& imaginaryChecker(ostream& output, double imaginary);
};

#endif