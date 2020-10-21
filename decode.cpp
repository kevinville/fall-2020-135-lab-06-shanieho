#include <iostream>
using namespace std;
#include <vector>
#include "caesar.h"
#include <string>
#include <cctype>
#include <cmath>
#include <climits>

int count(string str, char c){
    int count = 0;
    for (int i = 0; i < str.length(); i ++){
        if (str[i] == c || str[i] == char((int)c -32)){
            count ++;
        }
    }
    return count;
}

double distance (double count []){
    double distance = 0;
    //via wikipedia
    double freq []={.017, .044, .052, .032, .028,
                    .04, .016, .042, .073,
                    .0051, .0086, .024, .038,
                    .023, .076, .043, .0022,
                    .028, .067, .16, .012, 
                    .0082, .055, .00045, .0076, .00045};
    for (int i = 0; i < 26; i ++){
        distance += pow(count[i] - freq[i], 2);
    }
    return distance;
}

string decode (string str){
    string phrases [26];
    double minDist = INT_MAX;
    string lowDistPhrase;
    double frequency [26];
    double c;

    for (int i = 0; i < 26; i ++){
        phrases[i] = encryptCaesar(str, i);

        //count num of letters for each string
        for (int letter = 97; letter < 123; letter ++){
            c = count(phrases[i], char(letter));
            frequency[letter-97] = c / str.length();
        }

        //set distance to the max number possible and then compare 
        //distance with distance of each possible outcome
        //set min distance to the lowest and the lowDistPhrase to the string where
        //distance is currently the lowest
        double dist = distance(frequency);
        if (dist < minDist){
            minDist = dist;
            lowDistPhrase = phrases[i];
            //cout << lowDistPhrase <<endl;
        }
    } 
    return lowDistPhrase;
}
