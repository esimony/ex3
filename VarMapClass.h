//
// Created by eden on 25/12/2019.
//

#ifndef EX3_VARMAPCLASS_H
#define EX3_VARMAPCLASS_H


#include <string>
#include <unordered_map>

#include "Variable.h"


using namespace std;


class VarMapClass {
    typedef unordered_map<string, Variable*>  VarMapType;

public:
    VarMapClass() {}
    ~VarMapClass() {}

    void addElement(Variable *obj, string name, string node);

    bool findByName(const string& name, Variable* &obj);
    bool findByNode(const string& node, Variable* &obj);

//private:
    VarMapType mapVarName;
    VarMapType mapVarNode;
};

extern VarMapClass varList;


#endif //EX3_VARMAPCLASS_H
