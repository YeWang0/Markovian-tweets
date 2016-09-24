#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;
int main(){
    list<string> mylist;
    list<string>::iterator it;
    
    // set some initial values:
    for (int i=1; i<=3; ++i) mylist.push_back("haha"+to_string(i)); // 1 2 3 4 5
    
    it = mylist.begin();
//    ++it;       // it points now to number 2           ^
    
//    mylist.insert (it,10);                        // 1 10 2 3 4 5
    
    // "it" still points to number 2                      ^
//    mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
    
//    --it;       // it points now to the second 20            ^
    
//    std::vector<int> myvector (2,30);
//    mylist.insert (it,myvector.begin(),myvector.end());
    // 1 10 20 30 30 20 2 3 4 5
    //               ^
    cout << "mylist contains:";
    for (it=mylist.begin(); it!=mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    
    cout<<mylist.size()<<endl;
    
    
    unordered_map<string, unordered_map<string,double> > mapping;
    unordered_map<string,double> word_frequency;
    unordered_map<string,double> word_frequency2;

    word_frequency["w4.1"]=1;
    word_frequency["w4.2"]=2;
    word_frequency["w4.3"]=3;
    mapping["w1w2w3"]=word_frequency;
    word_frequency2["w14.1"]=1;
    word_frequency2["w14.2"]=2;
    word_frequency2["w14.3"]=3;
    mapping["w11w12w13"]=word_frequency2;
    
    cout<<mapping["w1w2w3"]["w4.1"];
    if(mapping.find("w1w2w3")==mapping.end()){
        cout<<"not find"<<endl;
    }else{
        cout<<" find"<<endl;
    }
    if(mapping.find("w1w2w")==mapping.end()){
        cout<<"not find"<<endl;
    }else{
        cout<<"find"<<endl;
    }
    
//    string histroy_hash="w1w2w3";//function_name(histroy);
//    string word="w4.3";
//    if(mapping.find(histroy_hash)==mapping.end()||mapping[histroy_hash].find(word)==mapping[histroy_hash].end()){
//        mapping[histroy_hash][word]=1;
//    }else{
//        mapping[histroy_hash][word]++;
//    }
//    cout<<endl;
//    cout<<mapping[histroy_hash][word];
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
    
    cout<<"Iteration mapping"<<endl;
    for(auto elem : mapping)
    {
        cout << elem.first<<endl;
        cout<<elem.second.size()<<endl;
        for(auto e : elem.second){
//            cout<<e.size()<<endl;
            cout <<e.first<<endl;
            cout <<e.second<<endl;
        }
        cout<<endl;
    }

    
    
    return 0;
}