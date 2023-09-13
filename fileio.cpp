#include "internal.h"
#include <fstream>
#include <limits>
#include <map>
#include <stdlib.h>
#include <filesystem>
using namespace std;

namespace io {

    string DATA_PATH = "";

    const char* read_all_data(string datafilename){
        
        char* buffer = new char[512];
        buffer = getenv("LocalAppData");
        DATA_PATH = buffer;

        DATA_PATH += "\\Ult1\\Concs-lang\\";
        cout << "Data path: " << DATA_PATH << endl;
        
        filesystem::create_directories(DATA_PATH);

        ifstream fin(DATA_PATH + datafilename);

        size_t size;
        try {
            size = filesystem::file_size(DATA_PATH + datafilename);
        } catch (...){ 
            cerr << "File not found: (" << (DATA_PATH + datafilename) << ")"; 
            buffer = new char[1];
            buffer[0] = 0;
            return buffer;
        }
        buffer = new char[size];
        fin.read(buffer, size);

        return (const char*) buffer;
    }


    void read_code(string filename){
        ifstream fin(filename);
        
        streamsize length;
        char* code; /* = */ {
            fin.ignore( numeric_limits<streamsize>::max() );
            length = fin.gcount();
            fin.clear();
            fin.seekg(0, ios_base::beg);
            code = new char[length];
            fin.read(code, length);
        } // partially from: stackoverflow.com/questions/22984956
        
        fin.close();

        cout << code << endl << endl;

        parser::parse(code, length);
    }

    map<string, bool> written_to; 
    void write_c(string filename, string text){
        ofstream out(filename);
        written_to.emplace(filename, 0);

        if(written_to[filename] == 0){
            ifstream temp(DATA_PATH);

            const char* bp = read_all_data("boilerplate.c");
            if(bp[0] == '\0') 
                exit(3); // probley file not found ¯\_(ツ)_/¯
            temp.close();
        }

        out << text;
        written_to[filename] = true;
    }



}