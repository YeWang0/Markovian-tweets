//
//  Header.h
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/24/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <unordered_map>
#include <random>

using namespace std;


string read_txt(string fn);
void split_content(string s);

string convert_list_to_string(list<string> ss);
string convert_vector_to_string(vector<string> ss);

string generate_sentence(int markovLength);
string get_next_word(list<string> prevWords);

void build_mapping(int markovLength);
void add_item_to_mapping(list<string> histroy,string word);
void update_mapping();

//For testing
void printWordList();
void printMapping();


#endif /* Header_h */
