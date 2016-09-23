//
//  Tweets.hpp
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/18/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//

#ifndef Tweets_h
#define Tweets_h

#include <stdio.h>
#include <vector>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>

#include "Word.h"

using namespace std;


class Tweets{
public:
    vector<string> tweetSentences;
    map<string,int> tweetWords;
    map<string, int> begins;
    
    Tweets();
    Tweets(string filename);
    void readTxt(string filename);
    void splitSentence(string s);
    void updateWordList(string w);
    void updateBeginList(string w);
    
    void printTweets();

};

#endif /* Tweets_h */
