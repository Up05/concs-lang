#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define FLAG_COUNT 16

enum class ErrorType : uint8_t {
    Nevermind,
    GeneralError,
    GenericParser,
    GenericCompiler,
    UnknownFlag
};

void _error(ErrorType t, const char* message, int col);


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


