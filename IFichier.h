#include <iostream>
#include <fstream>
using namespace std;

class IFichier
{
protected:
    ifstream f_in;
    ofstream f_out;
public:
    virtual ~IFichier(){}
};