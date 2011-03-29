#ifndef NAUTRUALNUM_H
#define NAUTRUALNUM_H

class NatrualNum
{
public:
	int val;
	int maximun;
	int operator+(int addnum);
	int operator-(int minnum);
	NatrualNum(int valref,int max);
	NatrualNum(int max);
protected:
private:
};
#endif