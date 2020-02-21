#include "utils.h"
#include <fstream>

using namespace std;

void redirect_in_to_file(istream& in, string filename) {
  static ifstream fin;
  fin.open(filename);
  in.rdbuf(fin.rdbuf());
}
