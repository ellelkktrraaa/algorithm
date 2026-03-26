//def Matrix class
    /*
    body<vector<vector<float>>>
    index<vector<int>>
    swap(int,int){swap the pos of two index}
    checkRev(){}
    toTri(int){make sure the index(i) line's [0,i-1]=0}
    reverseSol(){}

    public:
    Matrix(int x, int y){}
    set(int x, int y, float v){}
    solve(){}
    print(){}
    */
//
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<float>> body;   // 真实矩阵数据
    vector<int> index;           // 行索引（只交换行）
    int rows, cols;

    // 交换两行索引
    void swap(int i, int j) {
        int temp = index[i];
        index[i] = index[j];
        index[j] = temp;
    }

    // 检查是否可逆（满秩）
    bool checkRev() {
        for (int i = 0; i < rows; i++) {
            if (body[index[i]][i] == 0) return false;
        }
        return true;
    }

    // 第 i 行消元，变成上三角
    void toTri(int i) {
        // 选主元（向下找第一个非零行交换）
        for (int k = i; k < rows; k++) {
            if (body[index[k]][i] != 0) {
                swap(i, k);
                break;
            }
        }

        float pivot = body[index[i]][i];
        if (pivot == 0) return;

        // 消去下方所有行
        for (int r = i + 1; r < rows; r++) {
            float factor = body[index[r]][i] / pivot;
            for (int c = i; c < cols; c++) {
                body[index[r]][c] -= factor * body[index[i]][c];
            }
        }
    }

    // 回代求解
    vector<float> reverseSol() {
        vector<float> res(rows);
        for (int i = rows - 1; i >= 0; i--) {
            float sum = 0;
            for (int j = i + 1; j < rows; j++) {
                sum += body[index[i]][j] * res[j];
            }
            res[i] = (body[index[i]][cols - 1] - sum) / body[index[i]][i];
        }
        return res;
    }

public:
    Matrix(int x, int y) {
        rows = x;
        cols = y;
        body.resize(x, vector<float>(y, 0));
        index.resize(x);
        for (int i = 0; i < x; i++) index[i] = i;
    }

    ~Matrix(){
        body.clear();
        index.clear();
        rows=0;cols=0;
    }

    // 设置值
    void set(int x, int y, float v) {
        body[x][y] = v;
    }

    // 解方程入口
    vector<float> solve() {
        // 消元成上三角
        for (int i = 0; i < rows; i++) {
            toTri(i);
        }

        if (!checkRev()) {
            cout << "matrx is not reversable" << endl;
            return {};
        }

        return reverseSol();
    }

    // 打印矩阵
    void print() {
        for (int i = 0; i < rows; i++) {
            int r = index[i];
            for (int j = 0; j < cols; j++) {
                cout << body[r][j] << "\t";
            }
            cout << endl;
        }
    }
};
