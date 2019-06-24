//
//  codepoint.hpp
//  AVMtest
//
//  Created by Harry Kalodner on 6/23/19.
//

#ifndef codepoint_h
#define codepoint_h

#include "value.hpp"

struct Operation {
    OpCode opcode;
    std::unique_ptr<value> immediate;
    
    Operation() = default;
    Operation(OpCode opcode_) : opcode(opcode_) {}
    Operation(OpCode opcode_, value val);
    
    Operation(const Operation &);
    Operation(Operation &&);
    Operation& operator=(const Operation &);
    Operation& operator=(Operation &&);
    ~Operation();
};

struct CodePoint {
    uint64_t pc;
    Operation op;
    uint256_t nextHash;
    
    CodePoint() {}
    CodePoint(uint64_t pc_, Operation op_, uint256_t nextHash_) : pc(pc_), op(op_), nextHash(nextHash_) {}
};

uint256_t hash(const CodePoint &cp);

#endif /* codepoint_h */
