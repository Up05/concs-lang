#include "internal.h"
#include <codecvt>

#define DBG_CONSOLE
#define DBG_PARSING
#define DBG_COMPING
#define DBG_WRITING

std::wstring full_code; 

using namespace std;

int counter = 0;
#define COUNT cout << counter ++ << endl

int main(int argc, char* argv[]){
COUNT;
#ifdef DBG_CONSOLE
    cli::Data config = cli::parse(argc, argv);
COUNT;
#else
    cli::Data config = (cli::Data) {"test\\test.coc", "test\\test.c"}; 
#endif
COUNT;
#ifdef DBG_PARSING
    full_code = io::read_all_data("boilerplate2.c");
    full_code += L"uint8_t flags[" + to_wstring(FLAG_COUNT) + L"];\n";
    full_code += L"int main(void) { \n"; 

    pair<char*, size_t> code = io::read_code(config.file_in);
    parser::parse(code.first, code.second);
#endif
COUNT;
#ifdef DBG_COMPING
    full_code += cp::compile();
#endif
COUNT;
#ifdef DBG_WRITING
    full_code += L"}";
    io::write(config.file_out, full_code);
    // system("gcc test\\test.c -o test.exe");
#endif
COUNT;
}


