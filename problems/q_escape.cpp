/*
Problem statement: change the delimiter in a csv input from
',' to '|'. Allow for fields in quotes. Allow for escaping quotes
by using two quotes. (Use double-quote char, not single)
*/
vector < string > parse(vector < string > records) {
    enum Location {OUT_OF_QUOTE, IN_QUOTE} loc;
    vector<string> retval;
    loc=OUT_OF_QUOTE;
    char last_char=0;
    const int N=records.size();
    for(int r = 0;r < N;++r) {
        string rec = records[r];
        string out_str;
        const int L=records[r].length();
        for(int i = 0;i < L; ++i) {
            const char c = rec[i];
            if(c != ',' && c != '"') {
                out_str += c;
            } else if (c == ',') {
                if(loc == OUT_OF_QUOTE){
                    out_str += '|';
                } else {
                    out_str += c;
                }
                
            } else if (c == '"') {
                
                if(loc == OUT_OF_QUOTE) {
                    loc = IN_QUOTE;
                    if(last_char == '"'){
                        out_str += '"';
                    }
                } else {
                    loc = OUT_OF_QUOTE;
                }
            }
            last_char=rec[i];
        }
        retval.push_back(out_str);
    }
    return retval;

}
