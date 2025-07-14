//Algorithm to solve the "KGood" problem on CodinGame.
//https://www.codingame.com/training/hard/kgood
//Puzzles  Classic puzzle - Hard KGood By _NikJ
//Pass all test cases to win the game.

/*
====
Goal
====
John is one of those "super smart" kids. At least that's what his teachers, family, and friends call him. John is prone to competitions, his favourite types of competitions are those involving words. He spends his free time reading a variety of books, science papers, even things that don't actually interest him, just so he could expand his vocabulary. In 2015, he was the world champion in a game called KGood. As his best friend, I asked him how did he manage to pull off such an amazing thing. To which he replied with a smirk on his face, "I know a cool trick".

Last week, as he was riding his bike and watching a beautiful sunset, he didn't see the pole in front of him so he fell and hit his head! A few days later, John is feeling much better, but oh NO! He forgot what the trick was! Since I'm his best friend, he asked me to help him out anyway I can, because the World Championship 2016 is only 15 days away and he has to defend his title of the World Champion! Unfortunately, I am not one of those smart kids so I need Your help, else John is going to lose his title!

A string is called KGood if and only if it has no more than (ie. less than or equal to) K different characters (lowercase letters of English alphabet). Substring of a string is an array of consecutive characters of the original string. Your task is to find the length of the longest KGood substring of a given string.

For example:
Let the given string be aaaaabcdef and let K = 3.
The longest KGood substring we can form is aaaaabc, hence the output should be 7.

=====
Input
=====
Line 1: A string S whose longest KGood substring we need to find.
Line 2: An integer K, explained in the problem statement.

======
Output
======
Single line: Length of the longest KGood substring.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Kgood {
    string s;
    int k;
public:
    Kgood();
    int find_kgood();
};

int main() {
    Kgood kgood;   
    cout << kgood.find_kgood() << endl; 
}

Kgood::Kgood() {
    getline(cin, s);
    cin >> k; cin.ignore();
}
int Kgood::find_kgood() {
    vector<char> uniq;
    string substr;
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
        uniq.clear();
        substr.clear();
        for (int j = i; j < s.size(); j++) {
            if (find(uniq.begin(), uniq.end(), s[j]) == uniq.end()) {
                uniq.push_back(s[j]);
            }
            substr.push_back(s[j]);
            if (uniq.size() <= k) {
                if (substr.size() > max) {
                    max = substr.size();
                }
            }
            else break;
        }
    }
    return max;
}