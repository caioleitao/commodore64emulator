//
// Created by Kyle on 7/14/21.
//

#ifndef COMMODORE64EMULATOR_DEBUGGER_H
#define COMMODORE64EMULATOR_DEBUGGER_H

#include "cpu.h"
#include "memory.h"

#include <vector>
#include <string>

class Debugger {
private:
    int ss_;
    uint16_t offset_;
    Cpu *cpu_;
    Memory *mem_;
    uint16_t emu_seek(uint16_t offset,int whence);
    uint8_t * emu_read_mem(size_t sz);
    std::string emu_handle_cmd(const std::string &s);
    void emu_write_mem(uint8_t *mem, size_t sz);
    std::vector<std::string> split_cmd(const std::string &s);
    std::string regs_cmd();
public:
    Debugger();
    ~Debugger();
    void cpu(Cpu *v){cpu_=v;};
    void memory(Memory *v){mem_=v;};
    bool emulate();
    static const int kDbgPort = 9999;
    static const int kMaxCmdLen = 256;
    enum kDbgCommands{
        RAP_RMT_OPEN = 0x01,
        RAP_RMT_READ,
        RAP_RMT_WRITE,
        RAP_RMT_SEEK,
        RAP_RMT_CLOSE,
        RAP_RMT_CMD,
        RAP_RMT_REPLY = 0x80,
        RAP_RMT_MAX = 4096
    };
};
#endif //COMMODORE64EMULATOR_DEBUGGER_H
