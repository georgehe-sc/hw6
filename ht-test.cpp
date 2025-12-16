#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht(0.7, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    for(size_t i = 0; i < 7; i++){
        std::stringstream ss;
        ss << "hi" << i;
        ht.insert({ss.str(), i});
    }

		
		ht.reportAll(cout);

		for(size_t i = 7; i < 8; i++){
        std::stringstream ss;
        ss << "hi" << i;
        ht.insert({ss.str(), i});
    }

		ht.reportAll(cout);


	

    /*if( ht.find("hi4") != nullptr ){
        cout << "Found hi4" << endl;
        ht["hi4"] += 1;
        cout << "Incremented hi4's value to " << ht["hi4"] << endl;
    }
		else cout << "nah" << std::endl;
    if( ht.find("doesnotexist") == nullptr ){
        cout << "Did not find: doesnotexist" << endl;
    }*/

		ht.remove("hi7");

		ht.reportAll(cout);

/*
    cout << "HT size: " << ht.size() << endl;
		ht.reportAll(cout);
    ht.remove("hi9");
		ht.insert({"hi7",17});
    cout << "HT size: " << ht.size() << endl;
    if( ht.find("hi9") != nullptr ){
        cout << "Found hi9" << endl;
    }
    else {
        cout << "Did not find hi9" << endl;
    }
    
    cout << "size: " << ht.size() << endl;*/
		cout << ht.size() << endl;
    return 0;
}
