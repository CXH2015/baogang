#ifndef POLYVAL_HPP_
#define POLYVAL_HPP_
#include"fit.hpp"
double mean(size_t size, vector<double>::iterator itebegin, vector<double>::iterator iteend)               //求vector的平均值函数
{
	if(size==0)return 0;
	if(iteend<itebegin)return 0;
	double sum = 0; double y = 0;
	for (vector<double>::iterator ite = itebegin; ite != iteend; ite++)
	{
		sum = sum + (*ite);
	}
	y = sum / size;
	return y;
}
double sq(size_t size, vector<double>::iterator itebegin, vector<double>::iterator iteend)
{
	double aver = mean(size, itebegin, iteend);
	double s = 0;
	double t = 0;
	for (vector<double>::iterator ite = itebegin; ite<iteend; ite++)
	{
		t = ((*ite) - aver);
		t = t*t;
		s += t;
	}
	return s / size;
}
double sstd(size_t size, vector<double>::iterator itebegin, vector<double>::iterator iteend)
{
	return sqrt(sq(size,itebegin,iteend));
}
vector<double> polyval(vector<double> &p,vector<double> &x)
{
	vector<double> yy;
	double sum=0,xt=0;
	double x0=p[0];
	double x1=p[1];
	double x2=p[2];
	for(vector<double>::iterator ite=x.begin();ite<x.end();ite++)
	{
		xt=*ite;
		sum=x2*xt*xt+x1*xt+x0;
		yy.push_back(sum);
	}
	return yy;
}
#endif /* POLYVAL_HPP_ */
