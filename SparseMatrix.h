#pragma once

#include <string>
#include <vector>
#include <unordered_map>

const int DefaultSize = 100;

struct SPNode{//https://blog.csdn.net/sinat_34927324/article/details/53648050?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-53648050-blog-102872430.pc_relevant_vip_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-53648050-blog-102872430.pc_relevant_vip_default&utm_relevant_index=1
    int i, j;
    int v;
};

class SparseMatrix {
private:
    int mu, nu, tu;
    SPNode data[1024];
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