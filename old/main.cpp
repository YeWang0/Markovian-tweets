//
//  main.cpp
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/17/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>


#include "Tweets.h"
#include "Word.h"



using namespace std;


int main(int argc, const char * argv[]) {
    
    string filename = "/Users/Yan/GoogleDrive/0000000Fall2016/ELEG676/project1_Markov/Markovian-tweets/Timeline_BarackObama.txt";
    Tweets* tw = new Tweets(filename);
    tw->printTweets();
    
    return 0;
}
