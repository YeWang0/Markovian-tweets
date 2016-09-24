void build_mapping(int markovLength){
    list<string> history;
    for(int i = 1; i < wordList.size() - 1; ++i){
        if(i <= markovLength){
            for(int j = 0; j < i + 1; ++j){
                history.push_back(wordList[j]);
            }
        }else{
            for(int k = i - markovLength + 1; k < i + 1; ++k ){
                history.push_back(wordList[k]);
            }
        }
        follow = wordList[i + 1];
        add_item_to_mapping(history, follow);
        history.clear();
        
        //normalize the values
    }
}
