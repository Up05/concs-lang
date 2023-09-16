#include "internal.h"
#include <fstream>
#include <limits>
#include <map>
#include <stdlib.h>
#include <filesystem>
#include <codecvt>

using namespace std;

namespace io {

    string DATA_PATH = "";

    const wstring read_all_data(string datafilename){
        char* buffer = new char[512];
        buffer = getenv("LocalAppData");
        DATA_PATH = buffer;

        DATA_PATH += "\\Ult1\\Concs-lang\\";
        cout << "Data path: " << DATA_PATH << endl;
        
        filesystem::create_directories(DATA_PATH);

        // delete[] buffer; Causes random-ass crash?

        wifstream wif(DATA_PATH + datafilename);
        wif.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
        wstringstream wss;
        wss << wif.rdbuf();
        return wss.str();
        // from: https://stackoverflow.com/questions/4775437/read-unicode-utf-8-file-into-wstring
    }


    pair<char*, size_t> read_code(string filename){
        ifstream fin(filename);
        
        streamsize length;
        char* code; /* = */ {
            fin.ignore( numeric_limits<streamsize>::max() );
            length = fin.gcount();
            fin.clear();
            fin.seekg(0, ios_base::beg);
            code = new char[length + 1];
            fin.read(code, length);
        } // partially from: stackoverflow.com/questions/22984956
        
        code[length] = 0;

        fin.close();
        cout << code << endl << length << endl;

        return pair<char*, size_t>(code, (size_t) length);

    }


    void write(std::string filename, std::wstring& text){
        wofstream out(filename);
        out.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

        if(!out.is_open()) cout << "[cp::write] File not open!\n"; 
        if(out.bad())     cout << "[cp::write] File bad!\n"; 

        filesystem::create_directories (
            ( (filesystem::path) filename ).parent_path()
        );

        out << text;

        out.close();
    }

}