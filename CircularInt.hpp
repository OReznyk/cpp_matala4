#include <iostream>
using namespace std;

/*#ifndef CIRCULARINT_H
#define CIRCULARINT_H*/

class CircularInt{
	int startHour;
	int hour;
	int endHour;

public:
	CircularInt (int,int);
//	CircularInt (int hour=0){startHour=x;endHour=y;};
	CircularInt& operator+=(const int a){
		int temp=a%(endHour-startHour+1);
		if(temp==0)return *this;
		if(temp<0)return this->operator-=(a);
		else{
			if(temp+hour<=endHour) hour=hour+temp;
			else {
				int b=endHour-temp-hour;
				hour=startHour+((-1)*b)-1;
			}
		}
        return *this;
    }

    // prefix increment:
    CircularInt& operator++() {
        if(hour+1<=endHour)hour++;
        else hour=startHour;
        return *this;
    }

    // postfix increment:
    const CircularInt operator++(int flag_for_postfix_increment) {
        return this->operator++();
    }

    friend const CircularInt& operator - (int a, const CircularInt& h)
	{
//	    a -= h;
//      - operator logic here
        return h;
	}

    CircularInt& operator-=(const int a){
    	int temp=a%(endHour-startHour+1);
		if(temp==0)return *this;
		else{
			if(hour-temp>=startHour) hour=hour-temp;
			else {
				int b=temp+hour-startHour;
				hour=endHour+b+1;
			}
		}
        return *this;
    }

	const CircularInt operator-() const {
    	CircularInt copy = *this;
    	copy.hour=endHour;
        return copy.operator-=(this->hour);
    }

    CircularInt& operator*=(const int a) {
    	return this->operator+=((a-1)*this->hour);
    }

    const CircularInt operator/(const int a) {
        CircularInt copy = *this;
        if(copy.hour%a==0){
        	int res=copy.hour/a;
       		return copy.operator-=((a-1)*res);
       	}
       	else{
     		throw string("Can't divide");
     		return *this;
		   }
    }


	friend ostream& operator<< (ostream& os, const CircularInt& h);
	friend const CircularInt operator+ (const CircularInt& h1, const CircularInt& h2);



};

	//----------------------------------------
	// friend global binary operators
	//----------------------------------------



	inline const CircularInt operator+(const CircularInt& h1, const CircularInt& h2) {
		CircularInt copy=h1;
		copy.hour+=h2.hour;
    return copy;
	}

	inline ostream& operator<< (ostream& os, const CircularInt& h) {
    os << h.hour ;
    return os;
	}
