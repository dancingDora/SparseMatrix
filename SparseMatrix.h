#pragma once
#include <string>
#include <vector>
#include <unordered_map>

const int DefaultSize = 100;
const int MAX_SIZE = 80000;

struct SPNode{
    int i, j;
    int v;
};

class SparseMatrix {
private:
    int mu, nu, tu;
    SPNode data[MAX_SIZE];
    /* TODO: Add any necessary data structure here. */
public:
    SparseMatrix(){
        mu = nu = tu = 0;
        for(int i = 0; i < 1024; i++) {
            data[i].i = data[i].j = data[i].v = 0;
        }
    };

    SparseMatrix(const std::string input_file);

    void to_file(const std::string output_file);

    SparseMatrix operator*(const SparseMatrix &right);

};
