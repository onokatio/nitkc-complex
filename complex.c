#include <stdio.h>

typedef struct Complex {
	int real;
	int imaginaly;
} Complex;

int Complex_getReal(Complex *complex){
	return complex->real;
}

int Complex_getImaginaly(Complex *complex){
	return complex->imaginaly;
}

Complex Complex_new(int real, int imaginaly){
	Complex complex = {.real = real, .imaginaly = imaginaly};
	return complex;
}

Complex Complex_add(Complex *complexA, Complex *complexB){
	Complex complexC;
	complexC.real = complexA->real + complexB->real;
	complexC.imaginaly = complexA->imaginaly + complexB->imaginaly;
	return complexC;
}

Complex Complex_sub(Complex *complexA, Complex *complexB){
	Complex complexC;
	complexC.real = complexA->real - complexB->real;
	complexC.imaginaly = complexA->imaginaly - complexB->imaginaly;
	return complexC;
}

Complex Complex_mul(Complex *complexA, Complex *complexB){
	Complex complexC;
	complexC.real = (complexA->real * complexB->real) - (complexA->imaginaly * complexB->imaginaly);
	complexC.imaginaly = (complexA->real * complexB->imaginaly) + (complexA->imaginaly * complexB->real);
	return complexC;
}

Complex Complex_getConjugate(Complex *complexA){
	Complex complexB = {.real = complexA->real, .imaginaly = complexA->imaginaly * (-1)};
	return complexB;
}

Complex Complex_div(Complex *complexA, Complex *complexB){
	Complex complexA_bar_val = Complex_getConjugate(complexA);
	Complex *complexA_bar = &complexA_bar_val;

	Complex numerator = Complex_mul(complexB,complexA_bar);
	Complex denominator = Complex_mul(complexA,complexA_bar);
	print(&numerator);
	print(&denominator);

	Complex complexC;
	complexC.real = numerator.real / denominator.real;
	complexC.imaginaly = numerator.imaginaly / denominator.real;
	return complexC;
}


void print(Complex *complex){
	int real = Complex_getReal(complex);
	int imaginaly = Complex_getImaginaly(complex);
	if(imaginaly >= 0){
		printf("%d+%di\n",real,imaginaly);
	}else{
		printf("%d%di\n",real,imaginaly);
	}
}

int main(void){
	Complex complexA = Complex_new(2,3);
	Complex complexB = Complex_new(3,4);
	print(&complexA);
	print(&complexB);
	Complex complexC = Complex_add(&complexA, &complexB);
	Complex complexD = Complex_sub(&complexA, &complexB);
	Complex complexE = Complex_mul(&complexA, &complexB);
	Complex complexF = Complex_div(&complexA, &complexB);
	print(&complexF);
}
