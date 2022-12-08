#pragma once


#ifndef VECTORS_H_
#define VECTORS_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include<algorithm>
#include <string>
#define M_PI       3.14159265358979323846

/*
#define M_HELP_1(A, B) \
	A char B\
	A unsigned char B\
	A short int B\
	A unsigned short int B\
	A int B\
	A unsigned int B\
	A long int B\
	A unsigned long int B\
	A long long int B\
	A unsigned long long int B\
	A float B\
	A double B

#define M_HELP_2(A, B, C) \
	A char B char C\
	A unsigned char B unsigned char C\
	A short int B short int C\
	A unsigned short int B unsigned short int C\
	A int B int C\
	A unsigned int B unsigned int C\
	A long int B long int C\
	A unsigned long int B unsigned long int C\
	A long long int B long long int C\
	A unsigned long long int B unsigned long long int C\
	A float B float C\
	A double B double C

#define M_DIF_HELP_2(A, B, C) \
	M_HELP_1(A char B, C)\
	M_HELP_1(A unsigned char B, C)\
	M_HELP_1(A short int B, C)\
	M_HELP_1(A unsigned short int B, C)\
	M_HELP_1(A int B, C)\
	M_HELP_1(A unsigned int B, C)\
	M_HELP_1(A long int B, C)\
	M_HELP_1(A unsigned long int B, C)\
	M_HELP_1(A long long int B, C)\
	M_HELP_1(A unsigned long long int B, C)\
	M_HELP_1(A float B, C)\
	M_HELP_1(A double B, C)
	*/
template<typename T>
inline T RadToDeg(double angle) { return T(angle * 180 / M_PI); }

template<>
inline int RadToDeg(double angle) { return int(round(angle * 180 / M_PI)); }

template<typename T>
inline T DegToRad(double angle) { return T(angle * M_PI / 180); }

template<>
inline int DegToRad(double angle) { return int(round(angle * M_PI / 180)); }


#endif