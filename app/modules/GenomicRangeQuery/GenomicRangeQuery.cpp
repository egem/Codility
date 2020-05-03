#include "gtest/gtest.h"

#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution2(string &S, vector<int> &P, vector<int> &Q);

TEST(add, test1)
{
    string input1 = "CAGCCTA";
    vector<int> input2 = {2, 5, 0};
    vector<int> input3 = {4, 5, 6};

    vector<int> result = {2, 4, 1};

    ASSERT_EQ(result, solution2(input1, input2, input3));
}

TEST(add, test2)
{
    string input1 = "CAGCCTA";
    vector<int> input2 = {2, 0, 0};
    vector<int> input3 = {4, 5, 6};

    vector<int> result = {2, 1, 1};

    ASSERT_EQ(result, solution2(input1, input2, input3));
}

TEST(add, test3)
{
    string input1 = "CAGCCTA";
    vector<int> input2 = {0};
    vector<int> input3 = {6};

    vector<int> result = {1};

    ASSERT_EQ(result, solution2(input1, input2, input3));
}

TEST(add, test4)
{
    string input1 = "CAGCCTA";
    vector<int> input2 = {0, 2};
    vector<int> input3 = {6, 5};

    vector<int> result = {1, 2};

    ASSERT_EQ(result, solution2(input1, input2, input3));
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    static std::map<char, int> impactFactor = {
        std::pair<char, int>('A', 1),
        std::pair<char, int>('C', 2),
        std::pair<char, int>('G', 3),
        std::pair<char, int>('T', 4)
    };

    multimap<int, int> PQ;
    multimap<int, int> QP;

    map<int, int> minImpactFactor;
    map<int, bool> underCalculation;

    for(unsigned int i = 0; i < P.size(); ++i)
    {
        PQ.insert(std::pair<int, int>(P[i], i));
        QP.insert(std::pair<int, int>(Q[i], i));
        minImpactFactor[i] = 4;
    }

    for(unsigned int i = 0; i < S.length(); ++i)
    {
        auto ret = PQ.equal_range(i);

        for(auto it = ret.first; it != ret.second; ++it)
        {
            minImpactFactor[it->second] = impactFactor[S[i]];
            underCalculation[it->second] = true;
        }

        ret = QP.equal_range(i);

        for(auto it = ret.first; it != ret.second; ++it)
        {
            if(minImpactFactor[it->second] > impactFactor[S[i]])
            {
                minImpactFactor[it->second] = impactFactor[S[i]];
            }

            underCalculation[it->second] = false;
        }

        for(auto it = underCalculation.begin(); it != underCalculation.end(); ++it)
        {
            if(it->second)
            {
                if(minImpactFactor[it->first] > impactFactor[S[i]])
                {
                    minImpactFactor[it->first] = impactFactor[S[i]];
                }
            }
        }
    }

    vector<int> result;

    for(auto it = minImpactFactor.begin(); it != minImpactFactor.end(); ++it)
    {
        result.push_back(it->second);
    }

    return result;
}

/* This code is taken from https://sites.google.com/site/spaceofjameschen/home/codibility/5-3-genomicrangequery */
vector<int> solution2(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> pre_sum_A;
    vector<int> pre_sum_C;
    vector<int> pre_sum_G;

    int cnt_A = 0;
    int cnt_C = 0;
    int cnt_G = 0;

    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A') cnt_A++;
        else if (S[i] == 'C') cnt_C++;
        else if (S[i] == 'G') cnt_G++;

        pre_sum_A.push_back(cnt_A);
        pre_sum_C.push_back(cnt_C);
        pre_sum_G.push_back(cnt_G);
    }

    vector<int> result(P.size());
    for (int i = 0; i < int(P.size()); i++)
    {
        int A = (S[P[i]] == 'A') ? 1 : 0;
        int C = (S[P[i]] == 'C') ? 1 : 0;
        int G = (S[P[i]] == 'G') ? 1 : 0;
        if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0) result[i] = 1;
        else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0) result[i] = 2;
        else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0) result[i] = 3;
        else result[i] = 4;
    }

    return result;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}