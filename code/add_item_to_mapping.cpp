#include "add_item_to_mapping.h"
using namespace std;
static unordered_map<string, unordered_map<string,double> > mapping;
void add_item_to_mapping(list<string> histroy,string word){
    string histroy_hash=function_name(histroy);
    while (histroy.size()>0) {
        if(mapping.find(histroy_hash)==mapping.end()||mapping[histroy_hash].find(word)==mapping[histroy_hash].end()){
            mapping[histroy_hash][word]=1;
        }else{
            mapping[histroy_hash][word]++;
        }
        histroy.pop_front();
        histroy_hash=function_name(histroy);
    }
}