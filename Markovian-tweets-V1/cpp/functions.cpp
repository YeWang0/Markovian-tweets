//
//  functions.cpp
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/24/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//

#include "Header.h"

static vector<string> wordList;
static vector<string> beginWords;
static unordered_map<string, unordered_map<string,double> > mapping;


static int GET_RANDOM_INT(int lower, int upper)
{
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(lower,upper-1);
    return dist6(rng);
}

string read_txt(string file_path){

    ifstream input(file_path);
    string line;
    string file_content;
    
    while(getline(input,line)){
        file_content += line;
    }
    
    return file_content;
}

void split_content(string file_content){
    string tempWord;
    string priviousPunc;
    string punc = ".!?";
    
    bool isBegin = true;
    for(auto &c:file_content){
        //if space or punc, the word is finished
        if((c == ' ' || punc.find(c)<punc.size()) && !tempWord.empty()){
            if(isBegin){
                beginWords.push_back(tempWord);
                priviousPunc.clear();
                isBegin = false;
            }
            if(tempWord!=" "){
                wordList.push_back(tempWord);
            }
            if (punc.find(c)<punc.size()){
                string r(1,c);
                wordList.push_back(r);
                priviousPunc = r;
            }
            tempWord.clear();
        }
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

string convert_list_to_string(list<string> ss)
{
    string hashString;
    int i=0;
    for(string s:ss){
        hashString += char (i+'0') + s;
        i++;
    }
    return hashString;
}

string convert_vector_to_string(vector<string> ss)
{
    string hashString;
    int i=0;
    for(string s:ss){
        hashString += char (i+'0') + s;
        i++;
    }
    return hashString;
}


string generate_sentence(int markovLength)
{
    string sentence;
    list<string> prevWords;
    string punc = ",.!?;";
    
    /**get a random word as start**/
    int randomIndex = GET_RANDOM_INT(0,int (beginWords.size()));
    //    int randomIndex = rand() % ((int) beginWords.size());
    string curr = beginWords[randomIndex];
    sentence += curr;
    
    prevWords.push_back(curr);
    
    while (curr!="."){
        curr = get_next_word(prevWords);
        prevWords.push_back(curr);
        
        if(prevWords.size()>markovLength){
            prevWords.pop_front();
        }
        if(punc.find(curr)>punc.size()){
            sentence+=" ";
        }
        sentence+=curr;
    }
    
    
    return sentence;
}

string get_next_word(list<string> prevWords)
{
    double sum = 0.0;
    string nextWord = "";
    unordered_map<string, unordered_map<string,double>>:: iterator it;
    
    double cutPos = (double) GET_RANDOM_INT(1,10000)/10000;
    
    string hashString = convert_list_to_string(prevWords);
    
    it = mapping.find(hashString);
    while (it == mapping.end()){
        if(!prevWords.empty()){
            prevWords.pop_front();
            hashString = convert_list_to_string(prevWords);
        }
        else{
            cout<<"Key NOT found!!!!!!!!!!!"<<endl; //should never happen
            exit(1);
        }
    }
    
    for (auto &i:it->second){
        sum+=i.second;
        if (sum>=cutPos && nextWord==""){
            nextWord = i.first;
        }
    }
    
    return nextWord;
}

void build_mapping(int markovLength){
    list<string> history;
    string follow = "";
    for(int i = 0; i < wordList.size() - 1; ++i){
        if(i < markovLength){
            for(int j = 0; j < i+1; ++j){
                history.push_back(wordList[j]);
            }
        }else{
            for(int k = i - markovLength + 1; k < i+1 ; ++k){
                history.push_back(wordList[k]);
            }
        }
        follow = wordList[i + 1];
        add_item_to_mapping(history, follow);
        history.clear();
    }
    update_mapping();
}

void add_item_to_mapping(list<string> histroy,string word){
    string histroy_hash = convert_list_to_string(histroy);
    while (histroy.size()>0) {
        if(mapping.find(histroy_hash)==mapping.end()||mapping[histroy_hash].find(word)==mapping[histroy_hash].end()){
            mapping[histroy_hash][word]=1;
        }else{
            mapping[histroy_hash][word]++;
        }
        histroy.pop_front();
        histroy_hash = convert_list_to_string(histroy);
    }
}

void update_mapping(){
    double count;
    for(auto elem : mapping)
    {
        count=0;
        for(auto e : elem.second){
            count+=e.second;
        }
        for(auto e : elem.second){
            mapping[elem.first][e.first]=e.second/count;
        }
    }
}

void printWordList()
{
    for(auto &s:wordList){
        cout << "words: "<<s<<endl;
    }
    for(auto &s:beginWords){
        cout << "begin words: "<<s<<endl;
    }
    
    cout << wordList.size()<<endl;
    cout << beginWords.size()<<endl;
}

void printMapping()
{
    for(auto elem : mapping)
    {
        cout << elem.first<<": "<< elem.second.size()<<endl;
        for(auto e : elem.second){
            //            cout<<e.size()<<endl;
            cout <<"  "<< e.first<<": "<< e.second<<endl;
        }
        cout<<endl;
    }
    cout << "Finish Mapping!!"<< mapping.size()<<endl;
}