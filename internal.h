#pragma once

#include <iostream>
#include <string>
#include <vector>

void error(int, const char*, int);

enum class Keyword : uint16_t {
    LABEL,
    IF,
    GOTO,
    GET,
    SET,
    PRINT,
    ERROR
};

enum class CompileErrorType : uint8_t {
    SUCCESS,
    NEW_LINE,
    BAD_CHAR,
    UNEXPECTED_EOF,
};

class CompileError {
public:
    CompileErrorType type;
    int column;

    CompileError(CompileErrorType t, int i)
    : type(t), column(i)
    { }
};

namespace io {
    void read_code(std::string);
    void write_c(std::string, std::string);
    const char* read_all_data(std::string datafilename);
}

namespace parser {
    void parse(char*, int64_t);
}

namespace cp {
    void compile(std::vector<uint16_t>& tokenized);
}


