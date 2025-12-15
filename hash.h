#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here

			HASH_INDEX_T wValues[5] = {0, 0, 0, 0, 0};
			HASH_INDEX_T hash = 0;
			int offset = k.length() % 6;
			int pos = 4;

			for (int i = k.length()-6; i > -6; i -= 6) {


				std::string hash_string;

				if (i < 0) {

					std::string current_string = k.substr(0, offset);
					hash_string = "^^^^^^";

					// start from beginning and hash it
					for (int j = offset-1; j >= 0; j--) {
						hash_string[5-offset+1+j] = current_string[j];
					}

				}
				else {
					hash_string = k.substr(i, 6);
				}
				
				HASH_INDEX_T hash = letterDigitToNumber(hash_string[0]);

				for (int j = 1; j < 6; j++) {
					hash *= 36;
					int next = letterDigitToNumber(hash_string[j]);
					hash += next;
				}

				wValues[pos] = hash;
				pos--;
		 }

		 for (int i = 0; i < 5; i++) {

			hash += (wValues[i] * rValues[i]);

		 }

		 return hash;

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
				
				if (letter > 47 && letter < 58) {
					// digits 0 through 9
					return letter - 22;
				}
				if (letter > 64 && letter < 91) {
					// uppercase letters
					return letter - 65;
				}
				if (letter > 96 && letter < 123) {
					// lowercase letters
					return letter - 97;
				}
				if (letter == '^') {
					return 0;
				}

    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
