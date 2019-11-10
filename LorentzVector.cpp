#include "pch.h"
#include <iostream>
#include "LorentzVector.h"

double LorentzVector::get_x() const { return x; }
double LorentzVector::get_y() const { return y; }
double LorentzVector::get_z() const { return z; }
double LorentzVector::get_t() const { return t; }
double LorentzVector::get_norm() const { return norm; }

LorentzVector::LorentzVector() {
	x = y = z = t = norm = 0;
}
LorentzVector::LorentzVector(double x, double y, double z, double t) :
	x(x), y(y), z(z), t(t) {}
void LorentzVector:: operator+= (const LorentzVector& rhs) {
	x = x + rhs.x;
	y = y + rhs.y;
	z = z + rhs.z;
	t = t + rhs.t;
}
void LorentzVector:: operator-= (const LorentzVector& rhs) {
	x = x - rhs.x;
	y = y - rhs.y;
	z = z - rhs.z;
	t = t - rhs.t;
}
void LorentzVector:: operator*= (double a) {
	x = x * a;
	y = y * a;
	z = z * a;
	t = t * a;
}
LorentzVector LorentzVector:: operator+ (const LorentzVector& rhs) const {
	LorentzVector result(x + rhs.x, y + rhs.y, z + rhs.z, t + rhs.t);
	return result;
}
LorentzVector LorentzVector:: operator- (const LorentzVector& rhs) const {
	LorentzVector result(x - rhs.x, y - rhs.y, z - rhs.z, t - rhs.t);
	return result;
}
LorentzVector LorentzVector:: operator-() const {
	LorentzVector result(-x, -y, -z, -t);
	return result;
}
LorentzVector operator* (double b, const LorentzVector& lv) {
	LorentzVector result(b * lv.x, b * lv.y, b * lv.z, b * lv.t);
	return result;
}
LorentzVector LorentzVector::mul(double a) const {
	LorentzVector result(a * t, a * x, a * y, a * z);
	return result;
}
double LorentzVector::scalar(const LorentzVector & rhs) const {
	return t * rhs.t - x * rhs.x - y * rhs.y - z * rhs.z;
}
LorentzVector LorentzVector::zboost(double beta) const {
	double c = 1;
	if (sqrt(beta*beta) < 1) {
		LorentzVector l((t - beta * z / c) / sqrt(1 - beta * beta), x, y, (z - beta * t) / sqrt(1 - beta * beta));
		return l;
	}
	else {
		printf("input another beta\n");
		LorentzVector lv(0., 0., 0., 0.);
		return lv;
	}
}

std::ostream &operator << (std::ostream& os, const LorentzVector& lv)
{
	os << lv.x <<" "<< lv.y <<" "<< lv.z << " "<< lv.t << std::endl;
	return os;
}