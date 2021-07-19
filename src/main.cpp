//
// Created by Kyle on 7/14/21.
//

#include <iostream>
#include <string>
#include <algorithm>

#include "c64.h"
#include "loader.h"
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

C64 *c64;
Loader *loader;
bool wget_download_finished = false;

bool loader_cb() {
    if(!loader->emulate())
        c64->callback(nullptr);
    return true;
}

bool emscripten_loader_cb() {
    if (!loader->emulate() && wget_download_finished)
        c64->callback(nullptr);
    return true;
}

void load_file(const char *file) {
    std::string f(file);
    size_t ext_i = f.find_last_of(" . ");
    if(ext_i != std::string::npos) {
        std::string ext(f.substr(ext_i+1));
        std::transform(ext.begin(),ext.end(),ext.begin(),::tolower);
        if(ext == "bas"){
            loader->bas(f);
        } else if(ext == "prg"){
            loader->prg(f);
        }
    }
}

void wget_cb(const char *f) {
    wget_download_finished = true;
    load_file(f);
}

void emscripten_loop() {
    c64->emscripten_loop();
}

int main(int argc, char **argv) {
    c64 = new C64();
    if(argc != 1) {
        loader = new Loader(c64);
#ifdef EMSCRIPTEN
        std::string f(argv[1]);
        size_t sp = f.find_last_of("/");
        if(sp != std::string::npos) {
            std::string fname(f.substr(sp+1));
            c64->callback(emscripten_loader_cb);
            emscripten_async_wget(argv[1],fname.c_str(),wget_cb,nullptr);
        }
#else
        c64->callback(loader_cb);
        load_file(argv[1]);
#endif
    }
#ifdef EMSCRIPTEN
    emscripten_set_main_loop(emscripten_loop,0,0);
#else
    c64->start();
#endif
    return 0;
}