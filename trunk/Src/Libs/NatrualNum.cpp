#include "NatrualNum.h"

int NatrualNum::operator+(int addnum)
{ 
	return val=val+addnum>=maximun?maximun:val+addnum;
// 	if (val+addnum>=maximun)
// 	{
// 		return maximun;
// 	}
// 	return val+addnum;
}

int NatrualNum::operator-(int minnum)
{
	val=val-minnum>0?val-minnum:0;
	return val;
}

NatrualNum::NatrualNum(int valref,int max)
{
	this->val=valref;
	maximun=max;
}

NatrualNum::NatrualNum(int max)
{
	val=max;
	maximun=max;
}