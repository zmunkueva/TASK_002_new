#include "pch.h"
#include <iostream>
#include "LorentzVector.h"
#include <cmath>
using namespace std;
int main()
{
	LorentzVector lv(1, 1, 1, 1);
	LorentzVector lv2(0, 0, 0, 1);
	double a;
	LorentzVector lv1 = lv;
	lv1 += lv2;
	cout << "lv + lv2 = " << lv1 << endl;

	cout << "-lv = " << -lv << endl;
	LorentzVector lv4 = lv;
	lv4 -= lv2;
	cout << "lv - lv2 = " << lv4 << endl;
	LorentzVector lv3 = lv;
	cout << "input your scalar" << endl;
	cin >> a;
	lv3 *= a;
	cout << "lv * scalar = " << lv3 << endl;
	
	LorentzVector sum = lv + lv2;
	LorentzVector sub = lv - lv2;
	LorentzVector mul = a * lv;
	cout << "sum = " << sum << endl;
	cout << "sub = " << sub << endl;
	cout << "mul = " << mul << endl;

	double sclr = lv.scalar(lv2);
	cout << "scalar product = " << sclr << endl;
	double norm = lv.scalar(lv);
	cout << "norm = " << norm << endl;
	cout << "input your beta " << endl;
	double beta;
	cin >> beta;
	LorentzVector Zboost = lv.zboost(beta);
	cout << "zboost = " << Zboost << endl;
}


