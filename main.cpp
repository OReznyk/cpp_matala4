#include <iostream>
using namespace std;

#include "CircularInt.hpp"


int main() {
	CircularInt hour (1, 12);    //{1,12};              // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;	// 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
//	hour -= 40; cout <<"hour "<< hour << endl;
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission):
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?

	cout<<"*********** new tests ***********"<<endl;
	cout<<"***********    BOOL   ***********"<<endl;
    CircularInt hour1 (1, 10);
    CircularInt hour2 (1, 10);
    bool test1 = (hour1 == hour2);
    cout<<test1<<endl;                  //1
    CircularInt hour3 (2, 10);
    test1 = (hour3 == hour2);
    cout<<test1<<endl;                  //0
    test1 = (hour1 == 1);               //1
    cout<<test1<<endl;
    test1 = (1==hour1);               //1
    cout<<test1<<endl;
    test1 = (2==hour1);               //0
    cout<<test1<<endl;
    test1 = (1!=hour1);               //0
    cout<<test1<<endl;
    test1 = (2!=hour1);               //1
    cout<<test1<<endl;
    test1 = (hour3 != hour2);           //1
    cout<<test1<<endl;
    test1 = (hour1 != hour2);           //0
    cout<<test1<<endl;
    cout<<"***********    MAIN2   ***********"<<endl;
    CircularInt hour4 (1, 12);
    hour4 = hour4 - 3;
    cout<<hour4<<endl;                  //10
    CircularInt hour5 (1, 12);
    hour5 = 2 - hour4 ;
    cout<<hour5<<endl;                  //4
    hour4 = hour4 - hour5 ;
    cout<<hour4<<endl;                  //6

    cout<<"***********    *   ***********"<<endl;
    CircularInt hour6 (1, 12);
    hour6 = hour6 * 2;
    cout<<hour6<<endl;                  //2
    hour6 = hour6 * 3;
    cout<<hour6<<endl;                  //6
    hour6 = hour6 * 3;
    cout<<hour6<<endl;                  //6
    hour6 = hour6 * 2;
    cout<<hour6<<endl;                  //12

    hour6=1;
    cout<<hour6<<endl;                  //1
    hour6 *= 2;
    cout<<hour6<<endl;                  //2
    hour6 *= 3;
    cout<<hour6<<endl;                  //6
    hour6 *= 3;
    cout<<hour6<<endl;                  //6
    hour6 *=2;
    cout<<hour6<<endl;                  //12

    hour5=1;
    hour6=1;
    cout<<hour5<<" "<<hour6<<endl;                  //1 1
    hour6 *= hour5;
    cout<<hour6<<endl;                  //1
    hour5 *= 3; hour6 *= 2;
    hour6 *= hour5;
    cout<<hour6<<endl;                  //6
    hour6 *= hour5;
    cout<<hour6<<endl;                  //6
    hour6 *=2;
    cout<<hour6<<endl;                  //12


    cout<<"***********    =   ***********"<<endl;
    hour6 =2;
    cout<<hour6<<endl;                  //2
    hour6 =20;
    cout<<hour6<<endl;                  //9
    hour6 =20;
    cout<<hour6<<endl;                  //9
    hour6 =23;
    cout<<hour6<<endl;                  //12
    hour6 =24;
    cout<<hour6<<endl;                  //1

    cout<<"***********    >>   ***********"<<endl;
    cin>>hour6;
    cout<<hour6<<endl;                  //
}
