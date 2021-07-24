//
// Created by Kyle on 7/11/21.
//

#ifndef COMMODORE64EMULATOR_MEMORY_H
#define COMMODORE64EMULATOR_MEMORY_H

#include <iostream>
#include <cstdint>

class Vic;
class Cia1;
class Cia2;
class Sid;

class Memory {
private:
    uint8_t *mem_rar_;
    uint8_t *mem_rom_;
    uint8_t banks_[7];
    Vic *vic_;
    Cia1 *cia1_;
    Cia2 *cia2_;
    Sid *sid_;
public:
    Memory();
    ~Memory();
    void vic(Vic *v){vic_ = v;};
    void cia1(Cia1 *v){cia1_ = v;};
    void cia2(Cia2 *v){cia2_ = v;};

    enum kBankCfg {
        kROM,
        kRAM,
        KIO
    };

    enum Banks {
        kBankBasic = 3,
        kBankCharen = 5,
        kBankKernal = 6,
    };

    void setup_memory_banks(uint8_t v);





    uint8_t read_byte(uint16_t addr);
    uint8_t read_byte_no_io(uint16_t addr);

    void write_byte(uint16_t addr, uint8_t v);
    void write_byte_no_io(uint16_t addr, uint8_t v);

    uint16_t read_word(uint16_t addr);
    uint16_t read_word_no_io(uint16_t);

    void write_word(uint16_t addr, uint16_t v);
    void write_word_no_io(uint16_t addr, uint16_t v);

    uint8_t vic_read_byte(uint16_t addr);
    uint8_t read_byte_rom(uint16_t addr);

    void load_rom(const std::string &f, uint16_t baseaddr);
    void load_ram(const std::string &f, uint16_t baseaddr);

    void dump();
    void print_screen_text();

    static const size_t kMemSize = 0x10000l;

    static const uint16_t kBaseAddrBasic    = 0xa000;
    static const uint16_t kBaseAddrKernal   = 0xe000;
    static const uint16_t kBaseAddrStack    = 0x0100;
    static const uint16_t kBaseAddrScreen   = 0x0400;
    static const uint16_t kBaseAddrChars    = 0xd000;
    static const uint16_t kBaseAddrBitmap   = 0x0000;
    static const uint16_t kBaseAddrColorRam = 0xd800;
    static const uint16_t kAddrRestVector   = 0xfffc;
    static const uint16_t kAddrIRQVector    = 0xfffe;
    static const uint16_t kAddrNMIVector    = 0xfffa;
    static const uint16_t kAddrDataDirection = 0x0000;
    static const uint16_t kAddrMemoryLayout = 0x0001;
    static const uint16_t kAddrColorRam     = 0xd800;

    static const uint16_t kAddrZeroPage     = 0x0000;
    static const uint16_t kAddrVicFirstPage = 0xd000;
    static const uint16_t kAddrVicLastPage  = 0xd300;
    static const uint16_t kAddrCIA1Page     = 0xdc00;
    static const uint16_t kAddrCIA2Page     = 0xdd00;
    static const uint16_t kAddrBasicFirstPage = 0xa000;
    static const uint16_t kAddrBasicLastPage  = 0xbf00;
    static const uint16_t kAddrKernalFirstPage = 0xff00;

    static const uint8_t kLORAM     = 1 << 0;
    static const uint8_t kHIRAM     = 1 << 1;
    static const uint8_t kCHAREN    = 1 << 2;
};
#endif //COMMODORE64EMULATOR_MEMORY_H
