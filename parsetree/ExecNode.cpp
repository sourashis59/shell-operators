#pragma once
#include "Command.cpp"
#include "../util/SystemCallWrapper.cpp"
#include "../config.cpp"


class ExecNode: public Command {
    vector<string> args; 

public:
    ExecNode(const vector<string> &args): args(args) {
        for (string &arg: this->args)
            strip_quotes(arg);
    }

    virtual void run() {
        if (Config::get_instance().get_debug_mode() == true) {
            cout << "[DEBUG]: ExecNode.run(";    
            for (const string& arg: args)
                cout << arg << " ";
            cout << ")" << endl;
        }

        if (args.size() && args[0].size())
            SystemCallWrapper::execvp_wrapper(args[0], args);
        // exit(1);
    }

    virtual void print() {
        cout << "(";
        for (const auto &str: args)
            cout << str << " ";
        cout << ")";
    }

    //* TODO
    void strip_quotes(string &str) {
        if (str.size() == 0 
            || (str.back() != '\'' && str.back() != '\"' && str.front() != '\'' || str.front() != '\"')) 
            return;

        if (str.back() == '\'' || str.back() == '\"') str.pop_back();
        if (str.front() == '\'' || str.front() == '\"') str = str.substr(1, str.size() - 1);
        strip_quotes(str);        
    }
};