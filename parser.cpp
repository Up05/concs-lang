#include "internal.h"

using namespace std;

namespace parser {

    vector<uint16_t> tokenized;

    int count(char* code, char symbol){
        int i = 0;
        for(; i < 5; i ++){
            if(code[i] != symbol)
                return i;
        }
        return i;
    }

    CompileError tokenize(char* code, int64_t size){
        
        for(int i = 0; i < size; i ++){
            uint16_t semicolons = count(code + i, ';');
            Keyword token = (Keyword) semicolons;
            tokenized.push_back((uint16_t) token);

            i += (int) token + 1;
            if(i > size) 
                return CompileError(CompileErrorType::UNEXPECTED_EOF, i - 1); 

            switch(token){
                #define PARSE_VALUE \
                    semicolons = count(code + i, ';'); \
                    i += semicolons; \
                    tokenized.push_back(semicolons);

                case Keyword::LABEL:
                case Keyword::GOTO:
                case Keyword::GET:
                case Keyword::PRINT:
                    PARSE_VALUE;
                    break;
                case Keyword::IF:
                case Keyword::SET:
                    PARSE_VALUE; i ++;
                    PARSE_VALUE;
                    break;
                default:
                    ;

                #undef PARSE_VALUE
            }
            // i += semicolons;
        }
        return CompileError(CompileErrorType::SUCCESS, 0);
    }

    void parse(char* code, int64_t size){
        CompileError exitCode(CompileErrorType::SUCCESS, 0);

        for(int i = 0; i < size; i ++){
            if(code[i] != ';' && code[i] != '\\') [[unlikely]] {
                error(1, "Invalid utf-8 character found!", i);
            }
        }

        exitCode = tokenize(code, size);
        cout << "exited: " << (int) exitCode.type << ' ' << exitCode.column << endl;

        for(auto num : tokenized)
            cout << num << " ";
        cout << endl;

        cp::compile(tokenized);

        

    }

}