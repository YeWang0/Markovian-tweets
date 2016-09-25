//
//  main.cpp
//  Markovian_tweets
//
//  Created by Yan Zheng on 9/17/16.
//  Copyright © 2016 Yan Zheng. All rights reserved.
//


#include "Header.h"

int main(int argc, const char * argv[]) {
    
    if(argc!=3) {
        printf("Argument Error!\n");
        exit(0);
    }
    
//    string file_name = argv[1];
    int markovLength = atoi(argv[2]);
    
    string file_path =argv[1];
    string file_content = read_txt(file_path);
    split_content(file_content);
//    printWordList();
    
    build_mapping(markovLength);
//    printMapping();
    
    cout << generate_sentence(markovLength)<<endl;
    
    return 0;
}


