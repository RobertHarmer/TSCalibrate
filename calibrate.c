#include <stdio.h>

// Variable declaration:
float minX = 85;
float maxX = 2047;
float minY = 256;
float maxY = 2047;

float dw = 1280;
float dh = 720;

float xd1 = 99.5f;
float xd2 = 1088.3f;
float xd3 = 355.6f;

float yd1 = 233.1;
float yd2 = 160.5;
float yd3 = 511.2;

float x1 = 230;
float x2 = 1671;
float x3 = 611;

float y1 = 1068;
float y2 = 898;
float y3 = 1659;

int main ()
{
	float xs1 = minX + ((xd1*((maxX - minX) + 1.0f))/dw);
	float xs2 = minX + ((xd2*((maxX - minX) + 1.0f))/dw);
	float xs3 = minX + ((xd3*((maxX - minX) + 1.0f))/dw);

	float ys1 = minY + ((yd1*((maxY - minY) + 1.0f))/dh);
	float ys2 = minY + ((yd2*((maxY - minY) + 1.0f))/dh);
	float ys3 = minY + ((yd3*((maxY - minY) + 1.0f))/dh);

	printf("value of xs1 : %f \n", xs1);
	printf("value of xs2 : %f \n", xs2);
	printf("value of xs3 : %f \n", xs3);

	printf("value of ys1 : %f \n", ys1);
	printf("value of ys2 : %f \n", ys2);
	printf("value of ys3 : %f \n", ys3);


	/*

	    x1 y1 1
	A = x2 y2 1
	    x3 y3 1


	|A| = x1(y2-y3) - y1(x2-x3) + x2y3 - y2x3

	*/


	float z11 = y2 - y3;
	float z12 = x2 - x3;
	float z13 = x2*y3 - y2*x3;

	float z21 = y1 - y3;
	float z22 = x1 - x3;
	float z23 = x1*y3 - y1*x3;

	float z31 = y1 - y2;
	float z32 = x1 - x2;
	float z33 = x1*y2 - y1*x2;

	float detA = (x1*(y2-y3)) - (y1*(x2-x3)) + (x2*y3) - (y2*x3);

	printf("value of detA : %f \n", detA);

	z11 /= detA;
	z12 /= -detA;
	z13 /= detA;

	z21 /= -detA;
	z22 /= detA;
	z23 /= -detA;

	z31 /= detA;
	z32 /= -detA;
	z33 /= detA;


	float t11 = z11;
	float t12 = z12;
	float t13 = z13;

	float t21 = z21;
	float t22 = z22;
	float t23 = z23;

	float t31 = z31;
	float t32 = z32;
	float t33 = z33;

	z11 = t11;
	z12 = t21;
	z13 = t31;

	z21 = t12;
	z22 = t22;
	z23 = t32;

	z31 = t13;
	z32 = t23;
	z33 = t33;

	printf("value of z11 : %f \n", z11);
	printf("value of z12 : %f \n", z12);
	printf("value of z13 : %f \n", z13);

	printf("value of z21 : %f \n", z21);
	printf("value of z22 : %f \n", z22);
	printf("value of z23 : %f \n", z23);

	printf("value of z31 : %f \n", z31);
	printf("value of z32 : %f \n", z32);
	printf("value of z33 : %f \n", z33);

	float a = z11*xs1 + z12*xs2 + z13*xs3;
	float b = z21*xs1 + z22*xs2 + z23*xs3;
	float c = z31*xs1 + z32*xs2 + z33*xs3;

	float d = z11*ys1 + z12*ys2 + z13*ys3;
	float e = z21*ys1 + z22*ys2 + z23*ys3;
	float f = z31*ys1 + z32*ys2 + z33*ys3;


	printf("value of a : %f \n", a);
	printf("value of b : %f \n", b);
	printf("value of c : %f \n", c);

	printf("value of d : %f \n", d);
	printf("value of e : %f \n", e);
	printf("value of f : %f \n", f);

	return 0;
}
