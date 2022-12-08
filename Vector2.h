#pragma once

#include "pch.h"

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include "Vectors.h"

template <typename T>
struct Vector2 {
	T x;
	T y;
	
	Vector2() { x = 0; y = 0; }
	Vector2(T x) { this->x = x; this->y = x; }
	template<typename Tv>
	Vector2(Vector2<Tv> v) { this->x = Tv(v.x); this->y = Tv(v.y); }
	Vector2(T x, T y) { this->x = x; this->y = y; }
	template<typename Tx, typename Ty>
	Vector2(Tx x, Ty y) { this->x = T(x); this->y = T(y); }
	template<typename Tx>
	Vector2(Tx x) { this->x = T(x); this->y = T(x); }
	
	static Vector2 zero;

	static Vector2 right;
	static Vector2 left;
	static Vector2 up;
	static Vector2 down;

	static Vector2 right_up;
	static Vector2 right_down;
	static Vector2 left_up;
	static Vector2 left_down;

	static Vector2 fourDir[4];
	static Vector2 eightDir[8];
	static Vector2 rectDir[9];

	void Round() { x = round(x); y = round(y); }

	template<typename result_T =T>
	result_T Length() { return result_T(sqrt(pow(x, 2) + pow(y, 2))); }
	int Length() { return round(sqrt(pow(x, 2) + pow(y, 2))); }

	template<typename Ta=int>
	void IncreaseLength(Ta a) {
		double ang = AngleR();
		x += cos(ang) * a;
		y += sin(ang) * a;
	}
	template<typename Ta=int>
	void SetLength(Ta a) {
		double ang = AngleR();
		a = a > 0 ? a : 0;
		x = cos(ang) * a;
		y = sin(ang) * a;
	}
	template<typename Ta=int>
	void MultiplyLength(Ta a) {
		SetLength<Ta>(a * Length<Ta>());
	}

	inline std::string Text() { return std::to_string(x) + " " + std::to_string(y); }
	inline std::string Text(bool is_marked) { return is_marked ? (("x: " + std::to_string(x) + " y: " + std::to_string(y))) : (std::to_string(x) + " " + std::to_string(y)); }

	template<typename Ta=int>
	static Vector2<T> UnitCircleD(Ta angle) { return Vector2<T>(cos(DegToRad(angle)), sin(DegToRad(angle))); }
	template<typename Ta = int>
	static Vector2<T> UnitCircleR(Ta angle) { return Vector2<T>(cos(angle), sin(angle)); }

	template<typename result_T=int>
	result_T AngleD() { return RadToDeg<Ta>(atan2(y, x)); }
	template<typename result_T = double>
	result_T AngleR() { return Ta(atan2(y, x)); }

	template<typename Ta=int, typename accuracy = float>
	void SetAngleD(Ta angle) { RotateD<Ta, accuracy>(angle - AngleD<Ta>()); }
	template<typename Ta = int, typename accuracy = float>
	void SetAngleR(Ta angle) { RotateR<Ta, accuracy>(angle - AngleR<Ta>()); }

	template<typename Ta, typename accuracy=float>
	void RotateD(Ta angle) {
		accuracy old_x = x;
		accuracy old_y = y;
		double angl = DegToRad(angle);
		x = old_x * cos(angl) - old_y * sin(angl);
		y = old_x * sin(angl) + old_y * cos(angl);
	}
	template<typename Ta, typename accuracy = float>
	void RotateR(Ta angle) {
		accuracy old_x = x;
		accuracy old_y = y;
		x = old_x * cos(angle) - old_y * sin(angle);
		y = old_x * sin(angle) + old_y * cos(angle);
	}

	template<typename Ta = int, typename accuracy = float>
	void RotateAroundR(Vector2<T> v, Ta angle) {
		accuracy x_t = x;
		accuracy y_t = y;
		x = (x_t - v.x) * cos(angle) - (y_t - v.y) * sin(angle) + v.x;
		y = (x_t - v.x) * sin(angle) + (y_t - v.y) * cos(angle) + v.y;
	}
	template<typename Tx = int, typename Ty = int, typename Ta = int, typename accuracy = float>
	void RotateAroundR(Tx x_, Ty y_, Ta angle) {
		accuracy x_t = x;
		accuracy y_t = y;
		x = (x_t - x_) * cos(angle) - (y_t - y_) * sin(angle) + x_;
		y = (x_t - x_) * sin(angle) + (y_t - y_) * cos(angle) + y_;
	}
	template<typename Ta = int, typename accuracy = float>
	void RotateAroundD(Vector2<T> v, Ta angle) {
		accuracy x_t = x;
		accuracy y_t = y;
		double angl = DegToRad<double>(angle);
		x = (x_t - v.x) * cos(angl) - (y_t - v.y) * sin(angl) + v.x;
		y = (x_t - v.x) * sin(angl) + (y_t - v.y) * cos(angl) + v.y;
	}
	template<typename Tx = int, typename Ty = int, typename Ta = int, typename accuracy = float>
	void RotateAroundD(Tx x_, Ty y_, Ta angle) {
		accuracy x_t = x;
		accuracy y_t = y;
		double angl = DegToRad<double>(angle);
		x = (x_t - x_) * cos(angl) - (y_t - y_) * sin(angl) + x_;
		y = (x_t - x_) * sin(angl) + (y_t - y_) * cos(angl) + y_;
	}

#if true
	// + Vector operations
	inline Vector2<T> operator+ (Vector2<T> v) { return Vector2<T>(x + v.x, y + v.y); }
	template<typename Ta = int>
	inline Vector2<T> operator+ (Vector2<Ta> v) { return Vector2<Ta>(x + Ta(v.x), y + Ta(v.y)); }
	// + Numeric operations
	inline Vector2<T> operator+ (T a) { return Vector2<T>(x + a, y + a); }
	template<typename Ta = int>
	inline Vector2<T> operator+ (Ta a) { return Vector2<T>(x + T(a), y + T(a)); }

	// - Vector operations
	inline Vector2<T> operator- (Vector2<T> v) { return Vector2<T>(x - v.x, y - v.y); }
	template<typename Ta = int>
	inline Vector2<T> operator- (Vector2<Ta> v) { return Vector2<Ta>(x - Ta(v.x), y - Ta(v.y)); }
	// - Numeric operations
	inline Vector2<T> operator- (T a) { return Vector2<T>(x - a, y - a); }
	template<typename Ta = int>
	inline Vector2<T> operator- (Ta a) { return Vector2<T>(x - T(a), y - T(a)); }

	// * Vector operations
	inline Vector2<T> operator* (Vector2<T> v) { return Vector2<T>(x * v.x, y * v.y); }
	template<typename Ta = int>
	inline Vector2<T> operator* (Vector2<Ta> v) { return Vector2<Ta>(x * Ta(v.x), y * Ta(v.y)); }
	// * Numeric operations
	inline Vector2<T> operator* (T a) { return Vector2<T>(x * a, y * a); }
	template<typename Ta = int>
	inline Vector2<T> operator* (Ta a) { return Vector2<T>(x * T(a), y * T(a)); }

	// / Vector operations
	inline Vector2<T> operator/ (Vector2<T> v) { return Vector2<T>(x / v.x, y / v.y); }
	template<typename Ta = int>
	inline Vector2<T> operator/ (Vector2<Ta> v) { return Vector2<Ta>(x / Ta(v.x), y / Ta(v.y)); }
	// / Numeric operations
	inline Vector2<T> operator/ (T a) { return Vector2<T>(x / a, y / a); }
	template<typename Ta = int>
	inline Vector2<T> operator/ (Ta a) { return Vector2<T>(x / T(a), y / T(a)); }

	// += Vector operations
	inline void operator+= (Vector2<T> v) { x += v.x; y += v.y; }
	template<typename Ta = int>
	inline void operator+= (Vector2<Ta> v) { x += Ta(v.x); y += Ta(v.y); }
	// += Numeric operations
	inline void operator+= (T a) { x += a; y += a; }
	template<typename Ta = int>
	inline void operator+= (Ta a) { x += Ta(a); y += Ta(a); }

	// -= Vector operations
	inline void operator-= (Vector2<T> v) { x -= v.x; y -= v.y; }
	template<typename Ta = int>
	inline void operator-= (Vector2<Ta> v) { x -= Ta(v.x); y -= Ta(v.y); }
	// -= Numeric operations
	inline void operator-= (T a) { x -= a; y -= a; }
	template<typename Ta = int>
	inline void operator-= (Ta a) { x -= Ta(a); y -= Ta(a); }

	// *= Vector operations
	inline void operator*= (Vector2<T> v) { x *= v.x; y *= v.y; }
	template<typename Ta = int>
	inline void operator*= (Vector2<Ta> v) { x *= Ta(v.x); y *= Ta(v.y); }
	// *= Numeric operations
	inline void operator*= (T a) { x *= a; y *= a; }
	template<typename Ta = int>
	inline void operator*= (Ta a) { x *= Ta(a); y *= Ta(a); }

	// /= Vector operations
	inline void operator/= (Vector2<T> v) { x /= v.x; y /= v.y; }
	template<typename Ta = int>
	inline void operator/= (Vector2<Ta> v) { x /= Ta(v.x); y /= Ta(v.y); }
	// /= Numeric operations
	inline void operator/= (T a) { x /= a; y /= a; }
	template<typename Ta = int>
	inline void operator/= (Ta a) { x /= Ta(a); y /= Ta(a); }

	// == Vector operations
	template<typename Ta = int>
	inline bool operator== (Vector2<Ta> v) { return x == v.x && y == v.y; }
	// == Numeric operations
	template<typename Ta = int>
	inline bool operator== (Ta a) { return x == a && y == a; }

	// != Vector operations
	template<typename Ta = int>
	inline bool operator!= (Vector2<Ta> v) { return x != v.x || y != v.y; }
	// != Numeric operations
	template<typename Ta = int>
	inline bool operator!= (Ta a) { return x != a || y != a; }

	// > Vector operations
	template<typename Ta = int>
	inline bool operator> (Vector2<Ta> v) { return x > v.x && y > v.y; }
	// > Numeric operations
	template<typename Ta = int>
	inline bool operator> (Ta a) { return x > a && y > a; }

	// < Vector operations
	template<typename Ta = int>
	inline bool operator< (Vector2<Ta> v) { return x < v.x && y < v.y; }
	// < Numeric operations
	template<typename Ta = int>
	inline bool operator< (Ta a) { return x < a && y < a; }

	// >= Vector operations
	template<typename Ta = int>
	inline bool operator>= (Vector2<Ta> v) { return x >= v.x && y >= v.y; }
	// >= Numeric operations
	template<typename Ta = int>
	inline bool operator>= (Ta a) { return x >= a && y >= a; }

	// <= Vector operations
	template<typename Ta = int>
	inline bool operator<= (Vector2<Ta> v) { return x <= v.x&& y <= v.y; }
	// <= Numeric operations
	template<typename Ta = int>
	inline bool operator<= (Ta a) { return x <= a&& y <= a; }

	inline void operator++ (int a) { x++; y++; }
	inline void operator-- (int a) { x--; y--; }
#endif
};
template<> template<typename Tx, typename Ty> Vector2<int>::Vector2(Tx x, Ty y) { this->x = round(x); this->y = round(y); }
template<> template<typename Tx> Vector2<int>::Vector2(Tx x) { this->x = round(x); this->y = round(x); }

template<> template<typename result_T> result_T Vector2<int>::AngleR() { return round(atan2(y, x)); }
template<> template<typename result_T> result_T Vector2<int>::AngleD() { return RadToDeg<int>(atan2(y, x)); }

#if true
// +
template<> template<typename Ta> Vector2<int> Vector2<int>::operator+ (Vector2<Ta> v) { return Vector2<int>(x + round(v.x), y + round(v.y)); }
template<> template<typename Ta> Vector2<int> Vector2<int>::operator+ (Ta a) { return Vector2<int>(x + round(a), y + round(a)); }
// -
template<> template<typename Ta> Vector2<int> Vector2<int>::operator- (Vector2<Ta> v) { return Vector2<int>(x - round(v.x), y - round(v.y)); }
template<> template<typename Ta> Vector2<int> Vector2<int>::operator- (Ta a) { return Vector2<int>(x - round(a), y - round(a)); }
// *
template<> template<typename Ta> Vector2<int> Vector2<int>::operator* (Vector2<Ta> v) { return Vector2<int>(x * round(v.x), y * round(v.y)); }
template<> template<typename Ta> Vector2<int> Vector2<int>::operator* (Ta a) { return Vector2<int>(x * round(a), y * round(a)); }
// /
template<> template<typename Ta> Vector2<int> Vector2<int>::operator/ (Vector2<Ta> v) { return Vector2<int>(x / round(v.x), y / round(v.y)); }
template<> template<typename Ta> Vector2<int> Vector2<int>::operator/ (Ta a) { return Vector2<int>(x / round(a), y / round(a)); }
// +=
template<> template<typename Ta> void Vector2<int>::operator+= (Vector2<Ta> v) { x += round(v.x); y += round(v.y); }
template<> template<typename Ta> void Vector2<int>::operator+= (Ta a) { x += round(a); y += round(a); }
// -=
template<> template<typename Ta> void Vector2<int>::operator-= (Vector2<Ta> v) { x -= round(v.x); y -= round(v.y); }
template<> template<typename Ta> void Vector2<int>::operator-= (Ta a) { x -= round(a); y -= round(a); }
// *=
template<> template<typename Ta> void Vector2<int>::operator*= (Vector2<Ta> v) { x *= round(v.x); y *= round(v.y); }
template<> template<typename Ta> void Vector2<int>::operator*= (Ta a) { x *= round(a); y *= round(a); }
// /=
template<> template<typename Ta> void Vector2<int>::operator/= (Vector2<Ta> v) { x /= round(v.x); y /= round(v.y); }
template<> template<typename Ta> void Vector2<int>::operator/= (Ta a) { x /= round(a); y /= round(a); }
#endif



#define DECLAR(TYPE) \
Vector2<TYPE> Vector2<TYPE>::zero = Vector2<TYPE>(0, 0);\
Vector2<TYPE> Vector2<TYPE>::right = Vector2<TYPE>(1, 0);\
Vector2<TYPE> Vector2<TYPE>::left = Vector2<TYPE>(-1, 0);\
Vector2<TYPE> Vector2<TYPE>::up = Vector2<TYPE>(0, 1);\
Vector2<TYPE> Vector2<TYPE>::down = Vector2<TYPE>(0, -1);\
Vector2<TYPE> Vector2<TYPE>::right_up = Vector2<TYPE>(1, 1);\
Vector2<TYPE> Vector2<TYPE>::right_down = Vector2<TYPE>(1, -1);\
Vector2<TYPE> Vector2<TYPE>::left_up = Vector2<TYPE>(-1, 1);\
Vector2<TYPE> Vector2<TYPE>::left_down = Vector2<TYPE>(-1, -1);\
Vector2<TYPE> Vector2<TYPE>::fourDir[4] = { Vector2<TYPE>::right, Vector2<TYPE>::up, Vector2<TYPE>::left, Vector2<TYPE>::down };\
Vector2<TYPE> Vector2<TYPE>::eightDir[8] = { Vector2<TYPE>::right, Vector2<TYPE>::right_up, Vector2<TYPE>::up, Vector2<TYPE>::left_up, Vector2<TYPE>::left, Vector2<TYPE>::left_down, Vector2<TYPE>::down, Vector2<TYPE>::right_down };\
Vector2<TYPE> Vector2<TYPE>::rectDir[9] = { Vector2<TYPE>::zero, Vector2<TYPE>::right, Vector2<TYPE>::right_up, Vector2<TYPE>::up, Vector2<TYPE>::left_up, Vector2<TYPE>::left, Vector2<TYPE>::left_down, Vector2<TYPE>::down, Vector2<TYPE>::right_down };

DECLAR(char)
DECLAR(unsigned char)
DECLAR(short int)
DECLAR(unsigned short int)
DECLAR(int)
DECLAR(unsigned int)
DECLAR(long)
DECLAR(unsigned long)
DECLAR(long long)
DECLAR(unsigned long long)
DECLAR(float)
DECLAR(double)
#undef DECLAR

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

inline int round(int a) { return a; }
template<typename T>
inline Vector2<int> round(Vector2<T> v) { return Vector2<int>(v.x, v.y); }
template<typename T>
void VectorSwap(Vector2<T>* v1, Vector2<T>* v2) {
	Vector2<T> temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

#endif // !VECTOR2_H_
