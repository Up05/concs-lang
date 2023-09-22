#include "internal.h"
#include <sstream>



using namespace std;
namespace parser { extern vector<uint16_t> tokenized, parcols; }
using namespace parser;

namespace cp {

    std::wstringstream code(L""); 

    wchar_t last_label[16];
    const wchar_t* get_label(int index){
        int i = 0;
        while(true) {
            last_label[i] = 
                (index % 64 / 32) > 0 ? 
                (index % 32) + 97 : 
                (index % 32) + 65;

            if((index /= 64) <= 0 || (++ i) > 128)
                break;
        };
        last_label[i + 1] = 0;
        return last_label;
    }

    wstring compile(/* tokenized */){
        for(int i = 0; i < tokenized.size(); i ++){

            #define GET(i) L"get(" << tokenized[i] << ')'
            // #define T tokenized
            code << "\t";

            switch( (Keyword) tokenized[i] ){
                // potential errors: dup names
                case Keyword::LABEL:
                    code << get_label(tokenized[++ i]);
                    code << L":;\n";
                    break;
                case Keyword::IF:
                    code << L"if(" GET(++ i) << " == " GET(++ i) << L") \n\t";
                    break;
                case Keyword::GOTO:
                    code << L"goto " << get_label(tokenized[++ i]) << L";\n";
                    break;
                case Keyword::SET:
                    code << L"set(" << tokenized[++ i] << ", " << tokenized[++ i] << L");\n";
                    break;
                case Keyword::PRINT:
                    code << L"print(" GET(++ i) << ");\n";
                    break;
                case Keyword::SET_FLAG:
                    if(tokenized[i + 1] > FLAG_COUNT)
                        WARN1("compiler", "Unknown flag, last flag:", FLAG_COUNT, parcols[i]);
                    code << L"flags[" << tokenized[++ i] << "] = " << tokenized[++ i] << L";\n";
                    break;
                case Keyword::ARITHMETIC:
                    code << L"set(" << tokenized[++ i] << ", " GET(++ i) << L' ';
                    switch(tokenized[++ i]) { // TODO: Customizations over perf ???
                        case 1: code << L'+'; break;
                        case 2: code << L'-'; break;
                        case 3: code << L'*'; break;
                        case 4: code << L'/'; break;
                    } 
                    code << L' ' << GET(++ i) << L");\n";
                    break;
                default:
                    // _error(ErrorType::GenericCompiler, 
                    // ("Unkown token found: " + to_string(tokenized[i])).c_str(), parcols[i - 1]);
                    ERR1("compiler", "Unexpected token found!", tokenized[i], parcols[i]);
            }
        }
        return code.str();
    }
}