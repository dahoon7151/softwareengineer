#include <iostream>
#include <string.h>
#include "software.h"



#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"

using namespace std;

ifstream fin;
ofstream fout;

// ���� ����
FILE* in_fp, * out_fp;

int main() {
    fin.open(INPUT_FILE);
    fout.open(OUTPUT_FILE);
    doTask();

    fin.close();
    fout.close();
    return 0;
}