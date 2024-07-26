#pragma once
#include "../config.h"
#include "../util/SystemCallWrapper.cpp"
#include<iostream>

/*
 * Composite pattern:
 * --------------------------- 
 * Component --> Command (interface)
 * Leaf node --> ExecNode
 * Composite nodes -> BackgroundNode, RedirectNode, SeparatorNode, Pipe 
 * 
 * 
*/
class Command {
public:
    virtual ~Command() {
        if (Config::get_instance().debug_mode == true) {
            cout << "[DEBUG]: processId: " << SystemCallWrapper::getpid_wrapper() << ", Destructor called for " << "Command" << endl;
        }
    }

    //* this run() functin should never return.
    //* must always exit
    virtual void run() = 0;

    virtual void print() = 0;
};