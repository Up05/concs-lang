#include "internal.h"
#include <string.h>
using namespace std;

#define IS(a, b, c) strcmp(a, b) >= 0 || strcmp(a, c) >= 0

namespace cli {
    // I guess, I just don't know how to write a proper cli this time arround... 
    Data parse(int argc, char* argv[]){
        Data data = {"", ""};

        if(argc > 1) data.file_in = argv[1];
        else         wcout << io::read_all_data("help.txt") << endl;

        if(argc > 2) data.file_out = argv[2];    
        else         wcout << io::read_all_data("help.txt") << endl;

        cout << "data: \"" << data.file_in << "\" -> \"" << data.file_out << "\"\n";

        return data;
    }

}