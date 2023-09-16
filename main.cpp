#include "internal.h"
#include <codecvt>

#define DBG_PARSING
#define DBG_COMPING
#define DBG_WRITING

std::wstring full_code; 

using namespace std;

void _error(ErrorType t, const char* message, int col){
    cout << message;
    return;
}

int main(){
    // locale::global(locale(""));

    // wcout << cp::get_label(1) << '\n';
    // wcout << cp::get_label(2) << '\n';
    // wcout << cp::get_label(33) << '\n';
    // wcout << cp::get_label(65) << '\n';
    // wcout << cp::get_label(10000) << '\n';


#ifdef DBG_PARSING
    full_code = io::read_all_data("boilerplate2.c");
    full_code += L"uint8_t flags[" + to_wstring(FLAG_COUNT) + L"];\n";
    full_code += L"int main(void) { \n"; 

    pair<char*, size_t> code = io::read_code("test\\test.coc");
    parser::parse(code.first, code.second);
#endif

#ifdef DBG_COMPING
    full_code += cp::compile();
#endif

#ifdef DBG_WRITING
    full_code += L"}";
    io::write("test\\test.c", full_code);
    // system("gcc test\\test.c -o test.exe");
#endif
    
}


