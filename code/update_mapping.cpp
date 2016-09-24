# include "update_mapping.h"
using namespace std;
static unordered_map<string, unordered_map<string,double> > mapping;

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