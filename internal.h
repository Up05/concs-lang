#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define FLAG_COUNT 16

extern "C" { size_t __cdecl strlen(const char *); }
#define __co(stage) 9 -                             \
    ((sizeof(stage) != sizeof(char*)) ?             \
      sizeof(stage) :  strlen((const char*) stage)) // dw 'bout it

#define WARN0(stage, message, col)                          \
    fprintf(stderr, "WARNING: [%s] %*s %s (col: %i)\n",     \
    stage, __co(stage), "", message, col)

#define WARN1(stage, message, value, col)                   \
    fprintf(stderr, "WARNING: [%s] %*s %s %d (col: %i)\n",  \
    stage, __co(stage), "", message, value, col)

#define ERR0(stage, message, col)                           \
    {fprintf(stderr, "ERROR:   [%s] %*s %s (col: %i)\n",    \
    stage, __co(stage), "", message, col);                  \
    exit(-1);}

#define ERR1(stage, message, value, col)                    \
    {fprintf(stderr, "ERROR:   [%s] %*s %s %d (col: %i)\n", \
    stage, __co(stage), "", message, value, col);           \
    exit(-1);}

enum class Keyword : uint16_t {
    LABEL,
    IF,
    GOTO,
    GET,
    SET,
    PRINT,
    SET_FLAG,
    ARITHMETIC,
    error,
    length // to determine amount of elements here!
};

namespace io {
    std::pair<char*, size_t> read_code(std::string);
    void write(std::string, std::wstring&);
    const std::wstring read_all_data(std::string);
}

namespace parser {
    void parse(char*, int64_t);
}

namespace cp {
    /**
     * parser::parse() has to be run before hand!
     * Otherwise parser::tokenized is not generated.
    */
    const wchar_t* get_label(int index);
    std::wstring compile();
}

namespace cli {

    struct Data {
        std::string 
            file_in,
            file_out;
    };

    Data parse(int argc, char* argv[]);
}


