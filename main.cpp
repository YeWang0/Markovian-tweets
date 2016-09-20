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


using namespace std;

vector<string> wordList;
vector<string> beginWords;

string readTxt();
void splitContent(string s);

int main(int argc, const char * argv[]) {
    
    int markovLength = 3;
    
    string file_content = readTxt();
    splitContent(file_content);
    
    for(auto &s:wordList){
        cout << "words: "<<s<<endl;
    }
    for(auto &s:beginWords){
        cout << "begin words: "<<s<<endl;
    }
    
    cout << wordList.size()<<endl;
    cout << beginWords.size()<<endl;
    
    return 0;
}

string readTxt(){
    string filename = "/Users/Yan/GoogleDrive/0000000Fall2016/ELEG676/project1_Markov/Timeline_BarackObama.txt";
    ifstream input(filename);
    string line;
    string file_content;
    
    while(getline(input,line)){
        file_content += line;
    }
    
    return file_content;
}

void splitContent(string file_content){
    string tempWord;
    string priviousPunc;
    string punc = ".!?";
    
    bool isBegin = true;
    for(auto &c:file_content){
        //if space or punc, the word is finished
        if((c == ' ' || punc.find(c)<punc.size()-1) && !tempWord.empty()){
            if(isBegin){
                beginWords.push_back(tempWord);
                isBegin = false;
            }
            if(tempWord!=" "){
                wordList.push_back(tempWord);
            }
            if (punc.find(c)<punc.size()-1){
                string r(1,c);
                wordList.push_back(r);
                priviousPunc = r;
            }
            tempWord.clear();
        }
        //if c is punc and starts a new word
//        else if(punc.find(c)<punc.size()-1 && tempWord.empty()){
//            string r(1,c);
//            wordList.push_back(r);
//            priviousPunc = r;
//        }
        //if there is a uppercase letter after a punc
        else if(isupper(c) && !priviousPunc.empty()){
            if(tempWord.empty()){
                tempWord += c;
                isBegin = true;
            }else{
                tempWord += c;
            }
        }
        //all other letters, ignore space and double quote
        else{
            if(c!=' ' && c!='"')
                tempWord += c;
        }
    }
}
