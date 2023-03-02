#include <fstream>
#include <stdexcept>
#include "SparseMatrix.h"
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(const std::string input_file) {
    /* TODO: Your code here. */
    ifstream sparseMatrix(input_file);
    int cnt = 0;
    int pos_l, pos_r, val;
    sparseMatrix >> mu >> nu;
    // [ 1 0 3 ]
    // [ 0 5 0 ]
    // input :
    // 2 3
    // 0 0 1
    // 0 2 3
    // 1 1 5
    string line;
    while (sparseMatrix >> pos_l) {
        sparseMatrix >> pos_r >> val;
        data[cnt].i = pos_l + 1;
        data[cnt].j = pos_r + 1;
        data[cnt++].v = val;
    }
    tu = cnt;
    sparseMatrix.close();
}

void SparseMatrix::to_file(const std::string output_file) {
    /* TODO: Your code here. */
    ofstream sparseMatrix(output_file);
    sparseMatrix << mu << ' ' << nu << endl;
    for(int i = 0; i < tu; i++)
        sparseMatrix << data[i].i - 1 << ' ' << data[i].j - 1 << ' ' << data[i].v << endl;
    sparseMatrix.close();
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix &B) {
    /* TODO: Your code here. */
//    return *this;
    SparseMatrix *C;
    int firstNZ,k;//firstNZ : 每行首个非0元素
    int temp[B.nu + 1];
    int num[B.mu + 1], rpot[B.mu + 1];
    C = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if(C == NULL)
        cerr << "申请内存空间失败\n";
    if(nu != B.mu)
        cerr << "[Invalid] multiply failed.\n";
    //calculate matrix B not zero enum number.
    for(int i = 1; i <= B.mu; i++) num[i] = 0; //初始化每行非零元素个数集num
    for(int i = 0; i < B.tu; i++) num[B.data[i].i]++; //计算B矩阵每行非零元素个数
    rpot[1] = 0;
    //calculate matrix B first not zero enum position.
    for(int i = 2; i <= B.mu; i++) rpot[i] = rpot[i - 1] + num[i - 1]; //计算B矩阵每行非零元素个数累加即第一个非零元素在data中位置
    int numNZ = 0; // Matrix *this number of not zero enum
    firstNZ = 0; // current first not zero enum position of Matrix A
    int tmp;
    //execute multiply
    for(int i = 1; i <= mu; i++) {
        //init
        for(int j = 1; j <= B.nu; j++) temp[j] = 0;
        //Cij i : enum set
        while(i == data[firstNZ].i) {
            k = data[firstNZ].j;//A : firstNZth not zero enum col
            if(k < B.mu) tmp = rpot[k + 1];
            else tmp = B.tu;
            for(int q = rpot[k]; q < tmp; q++) {
                int j = B.data[q].j;
                temp[j] += data[firstNZ].v * B.data[q].v;
            }
            firstNZ++;
        }
        //result of line i -> Matrix C
        for(int j = 1; j <= B.nu; j++) {
            if(temp[j] != 0) {
                C->data[numNZ] = {i,j,temp[j]};
                numNZ++;
            }
        }
    }
    C->mu = mu;
    C->nu = B.nu;
    C->tu = numNZ;
    return *C;


}