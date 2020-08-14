//
// Created by tao hu on 2020/8/13.
//
#include <vector>
using namespace std;

vector<vector<vector<int>>> conv(vector<vector<vector<int>>> &input,vector<vector<vector<int>>> &kernel)
{
  // 假设输入是W*H*IC 卷积核是K*K*C2 那么输出是W*H*OC
  int OW=input.size(),OH=input[0].size(),IC=input[0][0].size();
  int KH=kernel.size(),KW=kernel[0].size(),OC=kernel[0][0].size();
  vector<vector<vector<int>>> out(OW,vector<vector<int>>(OH,vector<int>(OC,0)));

  for (int oh = 0; oh < OH; oh++) {
    for (int ow = 0; ow < OW; ow++) {
      for (int oc = 0; oc < OC; oc++) {
        for (int kh = 0; kh < KH, kh++){
          for (int kw = 0; kw < KW, kw++){
            for (int ic = 0; ic < IC, ic++){
              out[oh][ow][oc] += A[oh+kh][ow+kw][ic] * B[kh][kw][ic];
            }
          }
        }
      }
    }
  }

  return out;
}