#include "internal.h"

using namespace std;

namespace parser {

    vector<uint16_t> tokenized;
    vector<uint16_t> parcols; // text cols for errors after tokenizer, these can be considered map

    int count(char* code, char symbol){
        int i = 0;
        for(; i < (int) Keyword::length; i ++){
            if(code[i] != symbol)
                return i;
        }
        return i;
    }

    void tokenize(char* code, int64_t size){
        
        for(int i = 0; i < size; i ++){
            uint16_t semicolons = count(code + i, ';');
            Keyword token = (Keyword) semicolons;
            tokenized.push_back((uint16_t) token);
            parcols.push_back(i + semicolons + 2);

            i += (int) token + 1;
            if(i > size) 
                ERR0("parser", "Unexpected EOF", i);

            if(code[size - 1] == '\\' && i >= size - 1) 
                break; // seems sketchy, but it works right now, so whatever

            switch(token){
                #define PARSE_VALUE \
                    semicolons = count(code + i, ';'); \
                    i += semicolons; \
                    parcols.push_back(i + 2); \
                    tokenized.push_back(semicolons);

                case Keyword::LABEL:
                case Keyword::GOTO:
                // case Keyword::GET:
                case Keyword::PRINT:
                    PARSE_VALUE;
                    break;
                case Keyword::IF:
                case Keyword::SET:
                case Keyword::SET_FLAG:
                    PARSE_VALUE; parcols.back()++; i ++;
                    PARSE_VALUE;
                    break;
                case Keyword::ARITHMETIC:
                    PARSE_VALUE; parcols.back()++; i ++;
                    PARSE_VALUE; parcols.back()++; i ++;
                    PARSE_VALUE; parcols.back()++; i ++;
                    PARSE_VALUE;
                    break;
                default:
                    WARN1("parser", "unknown token", token, parcols.back());

                #undef PARSE_VALUE
            }
        }

        parcols[0] = 1; // yep, beautiful, I know!

    }

    void parse(char* code, int64_t size){

        for(int i = 0; i < size; i ++)
            if(code[i] != ';' && code[i] != '\\') [[unlikely]] 
                ERR0("parser", "Invalid utf-8 character!", i)
        
        tokenize(code, size);

        for(auto num : tokenized)
            cout << num << " ";
        cout << endl;

        
    }

}