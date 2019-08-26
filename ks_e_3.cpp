#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<unordered_map>
using namespace std;

int main()
{
    int T, D, S;
    int eff[2][2];
    int code, eat;
    int coder_index, eater_index;
    double code_pct, eat_pct;
    double eat_sum, code_sum;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> D >> S;
        for (int i = 0; i < S; i++)
        {
            cin >> eff[i][0] >> eff[i][1];
        }
        cout << "Case #" << t << ": ";
        for (int i = 0; i < D; i++)
        {
            cin >> code >> eat;
            if (S == 1)
            {
                if (code > eff[0][0])
                {
                    cout << "N";
                    continue;
                }
                code_pct = 1.0 * code / eff[0][0];
                eat_pct = 1.0 - code_pct;
                if (eat_pct * eff[0][1] >= eat)
                    cout << "Y";
                else
                    cout << "N";
            }
            else
            {
                eat_sum = 0;
                if (1.0 * eff[0][0] / eff[0][1] < 1.0*eff[1][0] / eff[1][1])
                    coder_index = 1;
                else
                    coder_index = 0;
                eater_index = 1 - coder_index;
                if (eff[coder_index][0] > code)
                {
                    code_pct = 1.0*code / eff[coder_index][0];
                    eat_pct = 1.0 - code_pct;
                    eat_sum = eat_pct * eff[coder_index][1];
                    if (eat_sum + eff[eater_index][1] >= eat)
                        cout << "Y";
                    else
                        cout << "N";
                }
                else
                {
                    code_sum = eff[coder_index][0];
                    if (code_sum + eff[eater_index][0] < code)
                        cout << "N";
                    else
                    {
                        code_pct = 1.0*(code - code_sum) / eff[eater_index][0];
                        eat_pct = 1.0 - code_pct;
                        eat_sum = eat_pct * eff[eater_index][1];
                        if (eat_sum >= eat)
                            cout << "Y";
                        else
                            cout << "N";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}