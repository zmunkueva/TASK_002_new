#pragma once
#include "pch.h"
#include <iostream>
#include "cmath"

class LorentzVector {
private: double x, y, z, t, norm;
public: 	LorentzVector();
			LorentzVector(double x, double y, double z, double t);

			double get_x() const;
			double get_y() const;
			double get_z() const;
			double get_t() const;
			double get_norm() const;
		
			void operator+= (const LorentzVector& rhs);
			void operator-= (const LorentzVector& rhs);
			void operator*= (double a);

			LorentzVector operator+ (const LorentzVector& rhs) const;
			LorentzVector operator- (const LorentzVector& rhs) const;
			LorentzVector operator-() const;
			friend LorentzVector operator* (double b, const LorentzVector & a);

			LorentzVector mul(double a) const;
			double scalar(const LorentzVector & rhs) const;
			LorentzVector zboost(double beta) const;

			friend std::ostream& operator << (std::ostream& os, const LorentzVector& lv);
};
