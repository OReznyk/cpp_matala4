#include <iostream>
using namespace std;

/*#ifndef CIRCULARINT_H
#define CIRCULARINT_H*/

class CircularInt{
	int startHour;
	int endHour;

public:
	int hour;
	CircularInt (int,int);

	CircularInt& operator=(const int a){
	    hour=startHour;
	    if(a>=startHour && a<= endHour) hour=a;
	    else if(a>0) this->operator+=(a);
	    else this->operator-=(a);
		return *this;
	}
	CircularInt& operator+(const int a){
		CircularInt copy=*this;
		return copy.operator+=(a);
	}

	CircularInt& operator+=(const int a){
		int temp=a%(endHour-startHour+1);
		if(temp==0)return *this;
		if(temp<0)return this->operator-=(a);
		else{
			if(temp+hour<=endHour) hour=hour+temp;
			else {
				int b=temp-(endHour-hour);
				hour=startHour+b-1;
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
    const CircularInt operator++(int flag_for_postfix_increment) {return this->operator++();}
    const CircularInt operator--(int flag_for_postfix_increment) {
        if(hour>startHour) hour--;
        else hour=endHour;
        return *this;
    }

	const CircularInt& operator-() {
    	CircularInt copy =*this;
    	copy.hour=endHour;
        return copy.operator-=(hour);
    }
    const CircularInt& operator-(int a) {
    	CircularInt copy =*this;
        return copy.operator-=(a);
    }
    CircularInt& operator-=(const int a){
    	int temp=a%(endHour-startHour+1);
		if(temp==0)return *this;
		else{
			if(hour-temp>=startHour) hour=hour-temp;
			else {
				int b=temp-(hour-startHour);
				hour=endHour-b+1;
			}
		}
        return *this;
    }

    CircularInt& operator*(const int a) {
        CircularInt copy=*this;
    	return copy.operator+=((a-1)*copy.hour);
    }
    CircularInt& operator*=(const int a) {
    	return this->operator+=((a-1)*this->hour);
    }

    const CircularInt operator/=(const int a) {
        if(hour%a==0){
        	int res=hour/a;
       		return operator-=((a-1)*res);
       	}
       	else{
     		throw string("Can't divide");
     		return *this;
		   }
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

    bool operator==(int a){
        return (this->hour==a);
    }
    bool operator!=(int a){
        return !(this->hour==a);
    }

    bool operator<(int a){
        return (this->hour<a);
    }
    bool operator<=(int a){
        return (this->hour<=a);
    }

    bool operator>(int a){
        return (this->hour>a);
    }
    bool operator>=(int a){
        return (this->hour>=a);
    }

	friend int operator-(int a, const CircularInt&h);
    friend const CircularInt operator-(const CircularInt& h1, const CircularInt& h2);

	friend ostream& operator<< (ostream& os, const CircularInt& h);
    friend istream& operator>> (istream& is, CircularInt& h);

	friend const CircularInt operator+ (const CircularInt& h1, const CircularInt& h2);
    friend const CircularInt operator+ (int a, const CircularInt& h2);
	friend const CircularInt operator* (CircularInt& h1, const CircularInt& h2);

    friend const CircularInt operator/ (CircularInt& h1, const CircularInt& h2);
    friend int operator/ (int a, const CircularInt& h2);

    friend const CircularInt operator+= (CircularInt& h1, const CircularInt& h2);
    friend const CircularInt operator-=(CircularInt& h1, const CircularInt& h2);
    friend const CircularInt operator*=(CircularInt& h1, const CircularInt& h2);

	friend bool operator==(const CircularInt& h1, const CircularInt& h2);
    friend bool operator==(int a,  const CircularInt&h);
	friend bool operator!=(const CircularInt& h1, const CircularInt& h2);
    friend bool operator!=(int a,  const CircularInt&h);

    friend bool operator<=(const CircularInt& h1, const CircularInt& h2);
    friend bool operator<=(int a,  const CircularInt&h);
    friend bool operator<(const CircularInt& h1, const CircularInt& h2);
    friend bool operator<(int a,  const CircularInt&h);

    friend bool operator>=(const CircularInt& h1, const CircularInt& h2);
    friend bool operator>=(int a,  const CircularInt&h);
    friend bool operator>(const CircularInt& h1, const CircularInt& h2);
    friend bool operator>(int a,  const CircularInt&h);

};

	//----------------------------------------
	// friend global binary operators
	//----------------------------------------

	inline int operator-(int a, const CircularInt& h) {
    	int ans=a-h.hour;
    	return ans;
    }
	inline const CircularInt operator-(const CircularInt& h1, const CircularInt& h2) {
		CircularInt copy=h1;
    	return copy.operator-=(h2.hour);
	}

//	inline const CircularInt operator=(const CircularInt& h1, const CircularInt& h2){return h1.operator=(h2.hour);}

    inline bool operator==(int a,  const CircularInt&h){
    CircularInt copy = h;
    return copy.operator==(a);
    }
    inline bool operator!=(int a,  const CircularInt&h){
    CircularInt copy = h;
    return !(copy.operator==(a));
    }
    inline bool operator==(const CircularInt& h1, const CircularInt& h2) {
    return (h1.hour==h2.hour);
}
	inline bool operator!=(const CircularInt& h1, const CircularInt& h2) {
    return !(h1.hour==h2.hour);
}

	inline const CircularInt operator+(const CircularInt& h1, const CircularInt& h2) {
		CircularInt copy=h1;
    	return copy.operator+=(h2.hour);
	}
    inline const CircularInt operator+ (int a, const CircularInt& h2){
        CircularInt copy=h2;
        return copy.operator+(a);}

    inline const CircularInt operator*( CircularInt& h1, const CircularInt& h2) {
        int a=h2.hour;
    	return h1.operator*(a);
	}

    inline const CircularInt operator/ (CircularInt& h1, const CircularInt& h2){return h1.operator/(h2.hour);}
    inline int operator/(int a, const CircularInt& h2){
        if(a%h2.hour==0){
       		return a/h2.hour;
       	}
       	else{
     		throw string("Can't divide");
     		return -1;
		   }
    }

	inline ostream& operator<< (ostream& os, const CircularInt& h) {
    os << h.hour ;
    return os;
	}

    inline istream& operator>> (istream& is, CircularInt& h){
    int a;
    try{
        is >> a;
        if(is.fail()) throw "input must be a number!";
        if(a < 0) throw "input must be a positive number!";
        h.operator=(a);
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    return is;
    }

    inline const CircularInt operator+= (CircularInt& h1, const CircularInt& h2){
        CircularInt copy=h1;
        copy.operator+=(h2.hour);
        h1=copy;
        return h1;}
    inline const CircularInt operator-=(CircularInt& h1, const CircularInt& h2){
        CircularInt copy=h1;
        copy.operator-=(h2.hour);
        h1=copy;
        return h1;}
    inline const CircularInt operator*=(CircularInt& h1, const CircularInt& h2){
        CircularInt copy=h1;
        copy.operator*=(h2.hour);
        h1=copy;
        return h1;}

    inline bool operator<=(const CircularInt& h1, const CircularInt& h2){return (h1.hour<=h2.hour);}
    inline bool operator<=(int a,  const CircularInt&h){return (a<=h.hour);}
    inline bool operator<(const CircularInt& h1, const CircularInt& h2){return (h1.hour<h2.hour);}
    inline bool operator<(int a,  const CircularInt&h){return (a<h.hour);}

    inline bool operator>=(const CircularInt& h1, const CircularInt& h2){return (h1.hour>=h2.hour);}
    inline bool operator>=(int a,  const CircularInt&h){return (a>=h.hour);}
    inline bool operator>(const CircularInt& h1, const CircularInt& h2){return (h1.hour>h2.hour);}
    inline bool operator>(int a,  const CircularInt&h){return (a>h.hour);}
