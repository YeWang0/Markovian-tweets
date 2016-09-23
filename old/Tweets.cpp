//
//  Tweets.cpp
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/18/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//

#include "Tweets.h"

Tweets::Tweets(){
    tweetSentences.clear();
    tweetWords.clear();
    begins.clear();
}

Tweets::Tweets(string filename){
    tweetSentences.clear();
    tweetWords.clear();
    begins.clear();
    readTxt(filename);
}

void Tweets::readTxt(string filename){
    ifstream input(filename);
    string line;
    
    while(getline(input,line)){
        splitSentence(line);
        tweetSentences.push_back(line);
    }
}

void Tweets::splitSentence(string s){
    string tempWord;
    bool isBegin = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '&& !tempWord.empty()){
            if(isBegin == 0){
                updateBeginList(tempWord);
                isBegin = 1;
            }
            updateWordList(tempWord);
            tempWord.clear();
        }else{
            tempWord += s[i];
        }
    }

}

void Tweets::updateWordList(string word){
    map<string,int>::iterator it=tweetWords.find(word);
    if(it == tweetWords.end()){
        tweetWords.insert(pair<string,int>(word,1));
        cout<<"Successfully insert "<<word<<endl;
    }else{
        it->second +=1;
    }
}

void Tweets::updateBeginList(string word){
    map<string,int>::iterator it=begins.find(word);
    if(it == begins.end()){
        begins.insert(pair<string,int>(word,1));
    }else{
        it->second +=1;
    }
}

void Tweets::printTweets(){
    cout<<"---------Sentences---------"<<endl;
    for(string& s:tweetSentences){
        cout<<s<<endl;
    }
    cout<<"---------Words---------"<<endl;
    for(auto elem:tweetWords){
        cout<<elem.first<<":"<<elem.second<<endl;
    }
    cout<<"---------First Words---------"<<endl;
    for(auto elem:begins){
        cout<<elem.first<<":"<<elem.second<<endl;
    }
    
}