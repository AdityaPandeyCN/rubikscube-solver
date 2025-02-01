#include <bits/stdc++.h>
//#include "Model/RubiksCube3dArray.cpp"
//#include "Model/RubiksCube1dArray.cpp"
//#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
//#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {

    string fileName = "/home/aditya/rubikscubesolver/rubikscube-solver/Databases/cornerDepth5V1.txt";

//    Code to create Corner Database
//    CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();

    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomShuffleCube(13);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";


    return 0;
}