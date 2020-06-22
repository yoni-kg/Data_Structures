/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream filewords(filename);
    string str;
    if(filewords.is_open()==1){
    	while(getline(filewords, str)){
    		string key=str;
    		std::sort(key.begin(), key.end());
    		auto lookup = dict.find(key);

			  if(lookup==dict.end()){
			  	dict[key].push_back(str);
		  	}
			  else{
			  	for(size_t i = 0; i < dict.at(key).size(); i++){
				  	if(dict[key][i] == str){
					  	return;
				  	}
			  	}
			  	dict[key].push_back(str);
			  }
    	}
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for(auto &fileword: words){
		string key = fileword;
		std::sort(key.begin(), key.end());
		auto lookup=dict.find(key);
		if(lookup==dict.end()){
			dict[key].push_back(fileword);
		}
		else{
			for(size_t i = 0; i < dict.at(key).size(); i++){
				if(dict[key][i] == fileword){
					return;
				}
			}
			dict[key].push_back(fileword);
		}
	}
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string key = word;
    std::sort(key.begin(), key.end());
    auto lookup = dict.find(key);
    if(dict.find(key)!=dict.end()){
    	return dict.find(key)->second;
    }
    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> ret;
    for(auto &it: dict){
    	if(it.second.size()>1){
    		ret.push_back(it.second);
    	}
    }
    return ret;
}
