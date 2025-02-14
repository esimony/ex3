//
// Created by eden on 19/12/2019.
//

#include <algorithm>

#include "DefineVarCommand.h"
#include "Variable.h"
#include "VarMapClass.h"
#include "Interpreter.h"

using namespace std;

DefineVarCommand cmdDefineVar;

int DefineVarCommand::execute(vector<string> arr, int index) {
    // A variable can be defined in any of these 2 ways:
    //   1. var <v> -> sim("/some/path/in/simulator")
    //   2. var <v> = <expression>

    int      rc;
    Variable *v   = NULL;
    string   name = arr[index];
    string   op   = arr[index + 1];

    if (!op.compare("=")) {
        // var <v> = <expression>
        string val = arr[index + 2];
        Expression* e = interpreter.interpret(val.c_str());

        v = new Variable(name, "", DIR_IN);
        v->setVal(e->calculate());

        // We handled 3 parameters
        rc = 3;
    }
    else {
        // var <v> -> sim("/some/path/in/simulator")

        VarDirE dir = (op.compare("->")) ? DIR_IN : DIR_OUT;
        string  sim = arr[index + 3];
        sim.erase(remove(sim.begin(), sim.end(), '"'), sim.end());

        // Create a new Variable object
        v = new Variable(name, sim, dir);

        // We handled 4 parameters
        rc = 4;
    }

    // Add it to the hash maps
    if (v != NULL)
        varList.addElement(v, v->getName(), v->getNode());

    return rc;
}