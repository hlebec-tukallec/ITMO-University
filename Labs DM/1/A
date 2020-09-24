#include<iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int>dizz;
vector<int>ans;
int count = 0;
void table (int n, vector<int>consty) {
    if (n == 1) {
        for (int i = 0; i < 2; i++){
            vector<int>dizz(consty);
            while (dizz.size() > 0) {
                int x1, y1;
                if (dizz[dizz.size()-1] < 0) {
                    x1 = ~i +2;
                }
                else
                    x1 = i;
                if (dizz[dizz.size()-2] < 0) {
                    y1 = ~i +2;
                }
                else
                    y1 = i;

                if (x1 + y1 == 0) {
                    count++;
                    break;
                }
                dizz.resize(dizz.size()-2);
            }
            if (count > 0)
                ans.push_back(0);
            else {
                return;
            }
            count = 0;
        }

    }

    else if (n == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                vector<int>dizz(consty);
                while (dizz.size() > 0) {
                    int x1, y1;
                    if (dizz[dizz.size()-1] < 0) {
                        if (dizz[dizz.size()-1] == -1)
                            x1 = ~j+2;
                        else
                            x1 = ~i+2;
                    }
                    else {
                        if (dizz[dizz.size() - 1] == 1)
                            x1 = j;
                        else
                            x1 = i;
                    }
                    if (dizz[dizz.size()-2] < 0) {
                        if (dizz[dizz.size()-2] == -1)
                            y1 = ~j+2;
                        else
                            y1 = ~i+2;
                    }
                    else {
                        if (dizz[dizz.size() - 2] == 1)
                            y1 = j;
                        else
                            y1 = i;
                    }

                    if (x1 + y1 == 0) {
                        count++;
                        break;
                    }
                    dizz.resize(dizz.size()-2);
                }
                if (count > 0)
                    ans.push_back(0);
                else {
                    return;
                }
                count = 0;
            }
        }
    }
    else if (n == 3) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    vector<int>dizz(consty);
                    while (dizz.size() > 0) {
                        int x1, y1;
                        if (dizz[dizz.size()-1] < 0) {
                            if (dizz[dizz.size()-1] == -1)
                                x1 = ~k+2;
                            else if (dizz[dizz.size()-1] == -2)
                                x1 = ~j+2;
                            else
                                x1 = ~i+2;
                        }
                        else {
                            if (dizz[dizz.size() - 1] == 1)
                                x1 = k;
                            else if (dizz[dizz.size() - 1] == 2)
                                x1 = j;
                            else
                                x1 = i;
                        }

                        if (dizz[dizz.size()-2] < 0) {
                            if (dizz[dizz.size()-2] == -1)
                                y1 = ~k+2;
                            else if (dizz[dizz.size()-2] == -2)
                                y1 = ~j+2;
                            else
                                y1 = ~i+2;
                        }
                        else {
                            if (dizz[dizz.size() - 2] == 1)
                                y1 = k;
                            else if (dizz[dizz.size() - 2] == 2)
                                y1 = j;
                            else
                                y1 = i;
                        }

                        if (x1 + y1 == 0) {
                            count++;
                            break;
                        }
                        dizz.resize(dizz.size()-2);
                    }
                    if (count > 0)
                        ans.push_back(0);
                    else {
                        return;
                    }
                    count = 0;
                }
            }
        }
    }
    else if (n == 4) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        vector<int>dizz(consty);
                        while (dizz.size() > 0) {
                            int x1, y1;
                            if (dizz[dizz.size()-1] < 0) {
                                if (dizz[dizz.size()-1] == -1)
                                    x1 = ~t+2;
                                else if (dizz[dizz.size()-1] == -2)
                                    x1 = ~k+2;
                                else if (dizz[dizz.size()-1] == -3)
                                    x1 = ~j+2;
                                else
                                    x1 = ~i+2;
                            }
                            else {
                                if (dizz[dizz.size() - 1] == 1)
                                    x1 = t;
                                else if (dizz[dizz.size() - 1] == 2)
                                    x1 = k;
                                else if (dizz[dizz.size() - 1] == 3)
                                    x1 = j;
                                else
                                    x1 = i;
                            }

                            if (dizz[dizz.size()-2] < 0) {
                                if (dizz[dizz.size()-2] == -1)
                                    y1 = ~t+2;
                                else if (dizz[dizz.size()-2] == -2)
                                    y1 = ~k+2;
                                else if (dizz[dizz.size()-2] == -3)
                                    y1 = ~j+2;
                                else
                                    y1 = ~i+2;
                            }
                            else {
                                if (dizz[dizz.size() - 2] == 1)
                                    y1 = t;
                                else if (dizz[dizz.size() - 2] == 2)
                                    y1 = k;
                                else if (dizz[dizz.size() - 2] == 3)
                                    y1 = j;
                                else
                                    y1 = i;
                            }

                            if (x1 + y1 == 0) {
                                count++;
                                break;
                            }
                            dizz.resize(dizz.size()-2);
                        }
                        if (count > 0)
                            ans.push_back(0);
                        else {
                            return;
                        }
                        count = 0;
                    }
                }
            }
        }
    }
    else if (n == 5) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            vector<int>dizz(consty);
                            while (dizz.size() > 0) {
                                int x1, y1;
                                if (dizz[dizz.size()-1] < 0) {
                                    if (dizz[dizz.size()-1] == -1)
                                        x1 = ~r+2;
                                    else if (dizz[dizz.size()-1] == -2)
                                        x1 = ~t+2;
                                    else if (dizz[dizz.size()-1] == -3)
                                        x1 = ~k+2;
                                    else if (dizz[dizz.size()-1] == -4)
                                        x1 = ~j+2;
                                    else
                                        x1 = ~i+2;
                                }
                                else {
                                    if (dizz[dizz.size() - 1] == 1)
                                        x1 = r;
                                    else if (dizz[dizz.size() - 1] == 2)
                                        x1 = t;
                                    else if (dizz[dizz.size() - 1] == 3)
                                        x1 = k;
                                    else if (dizz[dizz.size() - 1] == 4)
                                        x1 = j;
                                    else
                                        x1 = i;
                                }

                                if (dizz[dizz.size()-2] < 0) {
                                    if (dizz[dizz.size()-2] == -1)
                                        y1 = ~r+2;
                                    else if (dizz[dizz.size()-2] == -2)
                                        y1 = ~t+2;
                                    else if (dizz[dizz.size()-2] == -3)
                                        y1 = ~k+2;
                                    else if (dizz[dizz.size()-2] == -4)
                                        y1 = ~j+2;
                                    else
                                        y1 = ~i+2;
                                }
                                else {
                                    if (dizz[dizz.size() - 2] == 1)
                                        y1 = r;
                                    else if (dizz[dizz.size() - 2] == 2)
                                        y1 = t;
                                    else if (dizz[dizz.size() - 2] == 3)
                                        y1 = k;
                                    else if (dizz[dizz.size() - 2] == 4)
                                        y1 = j;
                                    else
                                        y1 = i;
                                }

                                if (x1 + y1 == 0) {
                                    count++;
                                    break;
                                }
                                dizz.resize(dizz.size()-2);
                            }
                            if (count > 0)
                                ans.push_back(0);
                            else {
                                return;
                            }
                            count = 0;
                        }
                    }
                }
            }
        }
    }
    else if (n == 6) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                vector<int>dizz(consty);
                                while (dizz.size() > 0) {
                                    int x1, y1;
                                    if (dizz[dizz.size()-1] < 0) {
                                        if (dizz[dizz.size()-1] == -1)
                                            x1 = ~y+2;
                                        else if (dizz[dizz.size()-1] == -2)
                                            x1 = ~r+2;
                                        else if (dizz[dizz.size()-1] == -3)
                                            x1 = ~t+2;
                                        else if (dizz[dizz.size()-1] == -4)
                                            x1 = ~k+2;
                                        else if (dizz[dizz.size()-1] == -5)
                                            x1 = ~j+2;
                                        else
                                            x1 = ~i+2;
                                    }
                                    else {
                                        if (dizz[dizz.size() - 1] == 1)
                                            x1 = y;
                                        else if (dizz[dizz.size() - 1] == 2)
                                            x1 = r;
                                        else if (dizz[dizz.size() - 1] == 3)
                                            x1 = t;
                                        else if (dizz[dizz.size() - 1] == 4)
                                            x1 = k;
                                        else if (dizz[dizz.size() - 1] == 5)
                                            x1 = j;
                                        else
                                            x1 = i;
                                    }

                                    if (dizz[dizz.size()-2] < 0) {
                                        if (dizz[dizz.size()-2] == -1)
                                            y1 = ~y+2;
                                        else if (dizz[dizz.size()-2] == -2)
                                            y1 = ~r+2;
                                        else if (dizz[dizz.size()-2] == -3)
                                            y1 = ~t+2;
                                        else if (dizz[dizz.size()-2] == -4)
                                            y1 = ~k+2;
                                        else if (dizz[dizz.size()-2] == -5)
                                            y1 = ~j+2;
                                        else
                                            y1 = ~i+2;
                                    }
                                    else {
                                        if (dizz[dizz.size() - 2] == 1)
                                            y1 = y;
                                        else if (dizz[dizz.size() - 2] == 2)
                                            y1 = r;
                                        else if (dizz[dizz.size() - 2] == 3)
                                            y1 = t;
                                        else if (dizz[dizz.size() - 2] == 4)
                                            y1 = k;
                                        else if (dizz[dizz.size() - 2] == 5)
                                            y1 = j;
                                        else
                                            y1 = i;
                                    }

                                    if (x1 + y1 == 0) {
                                        count++;
                                        break;
                                    }
                                    dizz.resize(dizz.size()-2);
                                }
                                if (count > 0)
                                    ans.push_back(0);
                                else {
                                    return;
                                }
                                count = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 7) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    vector<int>dizz(consty);
                                    while (dizz.size() > 0) {
                                        int x1, y1;
                                        if (dizz[dizz.size()-1] < 0) {
                                            if (dizz[dizz.size()-1] == -1)
                                                x1 = ~e+2;
                                            else if (dizz[dizz.size()-1] == -2)
                                                x1 = ~y+2;
                                            else if (dizz[dizz.size()-1] == -3)
                                                x1 = ~r+2;
                                            else if (dizz[dizz.size()-1] == -4)
                                                x1 = ~t+2;
                                            else if (dizz[dizz.size()-1] == -5)
                                                x1 = ~k+2;
                                            else if (dizz[dizz.size()-1] == -6)
                                                x1 = ~j+2;
                                            else
                                                x1 = ~i+2;
                                        }
                                        else {
                                            if (dizz[dizz.size() - 1] == 1)
                                                x1 = e;
                                            else if (dizz[dizz.size() - 1] == 2)
                                                x1 = y;
                                            else if (dizz[dizz.size() - 1] == 3)
                                                x1 = r;
                                            else if (dizz[dizz.size() - 1] == 4)
                                                x1 = t;
                                            else if (dizz[dizz.size() - 1] == 5)
                                                x1 = k;
                                            else if (dizz[dizz.size() - 1] == 6)
                                                x1 = j;
                                            else
                                                x1 = i;
                                        }

                                        if (dizz[dizz.size()-2] < 0) {
                                            if (dizz[dizz.size()-2] == -1)
                                                y1 = ~e+2;
                                            else if (dizz[dizz.size()-2] == -2)
                                                y1 = ~y+2;
                                            else if (dizz[dizz.size()-2] == -3)
                                                y1 = ~r+2;
                                            else if (dizz[dizz.size()-2] == -4)
                                                y1 = ~t+2;
                                            else if (dizz[dizz.size()-2] == -5)
                                                y1 = ~k+2;
                                            else if (dizz[dizz.size()-2] == -6)
                                                y1 = ~j+2;
                                            else
                                                y1 = ~i+2;
                                        }
                                        else {
                                            if (dizz[dizz.size() - 2] == 1)
                                                y1 = e;
                                            else if (dizz[dizz.size() - 2] == 2)
                                                y1 = y;
                                            else if (dizz[dizz.size() - 2] == 3)
                                                y1 = r;
                                            else if (dizz[dizz.size() - 2] == 4)
                                                y1 = t;
                                            else if (dizz[dizz.size() - 2] == 5)
                                                y1 = k;
                                            else if (dizz[dizz.size() - 2] == 6)
                                                y1 = j;
                                            else
                                                y1 = i;
                                        }

                                        if (x1 + y1 == 0) {
                                            count++;
                                            break;
                                        }
                                        dizz.resize(dizz.size()-2);
                                    }
                                    if (count > 0)
                                        ans.push_back(0);
                                    else {
                                        return;
                                    }
                                    count = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 8) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        vector<int>dizz(consty);
                                        while (dizz.size() > 0) {
                                            int x1, y1;
                                            if (dizz[dizz.size()-1] < 0) {
                                                if (dizz[dizz.size()-1] == -1)
                                                    x1 = ~g+2;
                                                else if (dizz[dizz.size()-1] == -2)
                                                    x1 = ~e+2;
                                                else if (dizz[dizz.size()-1] == -3)
                                                    x1 = ~y+2;
                                                else if (dizz[dizz.size()-1] == -4)
                                                    x1 = ~r+2;
                                                else if (dizz[dizz.size()-1] == -5)
                                                    x1 = ~t+2;
                                                else if (dizz[dizz.size()-1] == -6)
                                                    x1 = ~k+2;
                                                else if (dizz[dizz.size()-1] == -7)
                                                    x1 = ~j+2;
                                                else
                                                    x1 = ~i+2;
                                            }
                                            else {
                                                if (dizz[dizz.size() - 1] == 1)
                                                    x1 = g;
                                                else if (dizz[dizz.size() - 1] == 2)
                                                    x1 = e;
                                                else if (dizz[dizz.size() - 1] == 3)
                                                    x1 = y;
                                                else if (dizz[dizz.size() - 1] == 4)
                                                    x1 = r;
                                                else if (dizz[dizz.size() - 1] == 5)
                                                    x1 = t;
                                                else if (dizz[dizz.size() - 1] == 6)
                                                    x1 = k;
                                                else if (dizz[dizz.size() - 1] == 7)
                                                    x1 = j;
                                                else
                                                    x1 = i;
                                            }

                                            if (dizz[dizz.size()-2] < 0) {
                                                if (dizz[dizz.size()-2] == -1)
                                                    y1 = ~g+2;
                                                else if (dizz[dizz.size()-2] == -2)
                                                    y1 = ~e+2;
                                                else if (dizz[dizz.size()-2] == -3)
                                                    y1 = ~y+2;
                                                else if (dizz[dizz.size()-2] == -4)
                                                    y1 = ~r+2;
                                                else if (dizz[dizz.size()-2] == -5)
                                                    y1 = ~t+2;
                                                else if (dizz[dizz.size()-2] == -6)
                                                    y1 = ~k+2;
                                                else if (dizz[dizz.size()-2] == -7)
                                                    y1 = ~j+2;
                                                else
                                                    y1 = ~i+2;
                                            }
                                            else {
                                                if (dizz[dizz.size() - 2] == 1)
                                                    y1 = g;
                                                else if (dizz[dizz.size() - 2] == 2)
                                                    y1 = e;
                                                else if (dizz[dizz.size() - 2] == 3)
                                                    y1 = y;
                                                else if (dizz[dizz.size() - 2] == 4)
                                                    y1 = r;
                                                else if (dizz[dizz.size() - 2] == 5)
                                                    y1 = t;
                                                else if (dizz[dizz.size() - 2] == 6)
                                                    y1 = k;
                                                else if (dizz[dizz.size() - 2] == 7)
                                                    y1 = j;
                                                else
                                                    y1 = i;
                                            }

                                            if (x1 + y1 == 0) {
                                                count++;
                                                break;
                                            }
                                            dizz.resize(dizz.size()-2);
                                        }
                                        if (count > 0)
                                            ans.push_back(0);
                                        else {
                                            return;
                                        }
                                        count = 0;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 9) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            vector<int>dizz(consty);
                                            while (dizz.size() > 0) {
                                                int x1, y1;
                                                if (dizz[dizz.size()-1] < 0) {
                                                    if (dizz[dizz.size()-1] == -1)
                                                        x1 = ~w+2;
                                                    else if (dizz[dizz.size()-1] == -2)
                                                        x1 = ~g+2;
                                                    else if (dizz[dizz.size()-1] == -3)
                                                        x1 = ~e+2;
                                                    else if (dizz[dizz.size()-1] == -4)
                                                        x1 = ~y+2;
                                                    else if (dizz[dizz.size()-1] == -5)
                                                        x1 = ~r+2;
                                                    else if (dizz[dizz.size()-1] == -6)
                                                        x1 = ~t+2;
                                                    else if (dizz[dizz.size()-1] == -7)
                                                        x1 = ~k+2;
                                                    else if (dizz[dizz.size()-1] == -8)
                                                        x1 = ~j+2;
                                                    else
                                                        x1 = ~i+2;
                                                }
                                                else {
                                                    if (dizz[dizz.size() - 1] == 1)
                                                        x1 = w;
                                                    else if (dizz[dizz.size() - 1] == 2)
                                                        x1 = g;
                                                    else if (dizz[dizz.size() - 1] == 3)
                                                        x1 = e;
                                                    else if (dizz[dizz.size() - 1] == 4)
                                                        x1 = y;
                                                    else if (dizz[dizz.size() - 1] == 5)
                                                        x1 = r;
                                                    else if (dizz[dizz.size() - 1] == 6)
                                                        x1 = t;
                                                    else if (dizz[dizz.size() - 1] == 7)
                                                        x1 = k;
                                                    else if (dizz[dizz.size() - 1] == 8)
                                                        x1 = j;
                                                    else
                                                        x1 = i;
                                                }

                                                if (dizz[dizz.size()-2] < 0) {
                                                    if (dizz[dizz.size()-2] == -1)
                                                        y1 = ~w+2;
                                                    else if (dizz[dizz.size()-2] == -2)
                                                        y1 = ~g+2;
                                                    else if (dizz[dizz.size()-2] == -3)
                                                        y1 = ~e+2;
                                                    else if (dizz[dizz.size()-2] == -4)
                                                        y1 = ~y+2;
                                                    else if (dizz[dizz.size()-2] == -5)
                                                        y1 = ~r+2;
                                                    else if (dizz[dizz.size()-2] == -6)
                                                        y1 = ~t+2;
                                                    else if (dizz[dizz.size()-2] == -7)
                                                        y1 = ~k+2;
                                                    else if (dizz[dizz.size()-2] == -8)
                                                        y1 = ~j+2;
                                                    else
                                                        y1 = ~i+2;
                                                }
                                                else {
                                                    if (dizz[dizz.size() - 2] == 1)
                                                        y1 = w;
                                                    else if (dizz[dizz.size() - 2] == 2)
                                                        y1 = g;
                                                    else if (dizz[dizz.size() - 2] == 3)
                                                        y1 = e;
                                                    else if (dizz[dizz.size() - 2] == 4)
                                                        y1 = y;
                                                    else if (dizz[dizz.size() - 2] == 5)
                                                        y1 = r;
                                                    else if (dizz[dizz.size() - 2] == 6)
                                                        y1 = t;
                                                    else if (dizz[dizz.size() - 2] == 7)
                                                        y1 = k;
                                                    else if (dizz[dizz.size() - 2] == 8)
                                                        y1 = j;
                                                    else
                                                        y1 = i;
                                                }

                                                if (x1 + y1 == 0) {
                                                    count++;
                                                    break;
                                                }
                                                dizz.resize(dizz.size()-2);
                                            }
                                            if (count > 0)
                                                ans.push_back(0);
                                            else {
                                                return;
                                            }
                                            count = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 10) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                vector<int>dizz(consty);
                                                while (dizz.size() > 0) {
                                                    int x1, y1;
                                                    if (dizz[dizz.size()-1] < 0) {
                                                        if (dizz[dizz.size()-1] == -1)
                                                            x1 = ~o+2;
                                                        else if (dizz[dizz.size()-1] == -2)
                                                            x1 = ~w+2;
                                                        else if (dizz[dizz.size()-1] == -3)
                                                            x1 = ~g+2;
                                                        else if (dizz[dizz.size()-1] == -4)
                                                            x1 = ~e+2;
                                                        else if (dizz[dizz.size()-1] == -5)
                                                            x1 = ~y+2;
                                                        else if (dizz[dizz.size()-1] == -6)
                                                            x1 = ~r+2;
                                                        else if (dizz[dizz.size()-1] == -7)
                                                            x1 = ~t+2;
                                                        else if (dizz[dizz.size()-1] == -8)
                                                            x1 = ~k+2;
                                                        else if (dizz[dizz.size()-1] == -9)
                                                            x1 = ~j+2;
                                                        else
                                                            x1 = ~i+2;
                                                    }
                                                    else {
                                                        if (dizz[dizz.size() - 1] == 1)
                                                            x1 = o;
                                                        else if (dizz[dizz.size() - 1] == 2)
                                                            x1 = w;
                                                        else if (dizz[dizz.size() - 1] == 3)
                                                            x1 = g;
                                                        else if (dizz[dizz.size() - 1] == 4)
                                                            x1 = e;
                                                        else if (dizz[dizz.size() - 1] == 5)
                                                            x1 = y;
                                                        else if (dizz[dizz.size() - 1] == 6)
                                                            x1 = r;
                                                        else if (dizz[dizz.size() - 1] == 7)
                                                            x1 = t;
                                                        else if (dizz[dizz.size() - 1] == 8)
                                                            x1 = k;
                                                        else if (dizz[dizz.size() - 1] == 9)
                                                            x1 = j;
                                                        else
                                                            x1 = i;
                                                    }

                                                    if (dizz[dizz.size()-2] < 0) {
                                                        if (dizz[dizz.size()-2] == -1)
                                                            y1 = ~o+2;
                                                        else if (dizz[dizz.size()-2] == -2)
                                                            y1 = ~w+2;
                                                        else if (dizz[dizz.size()-2] == -3)
                                                            y1 = ~g+2;
                                                        else if (dizz[dizz.size()-2] == -4)
                                                            y1 = ~e+2;
                                                        else if (dizz[dizz.size()-2] == -5)
                                                            y1 = ~y+2;
                                                        else if (dizz[dizz.size()-2] == -6)
                                                            y1 = ~r+2;
                                                        else if (dizz[dizz.size()-2] == -7)
                                                            y1 = ~t+2;
                                                        else if (dizz[dizz.size()-2] == -8)
                                                            y1 = ~k+2;
                                                        else if (dizz[dizz.size()-2] == -9)
                                                            y1 = ~j+2;
                                                        else
                                                            y1 = ~i+2;
                                                    }
                                                    else {
                                                        if (dizz[dizz.size() - 2] == 1)
                                                            y1 = o;
                                                        else if (dizz[dizz.size() - 2] == 2)
                                                            y1 = w;
                                                        else if (dizz[dizz.size() - 2] == 3)
                                                            y1 = g;
                                                        else if (dizz[dizz.size() - 2] == 4)
                                                            y1 = e;
                                                        else if (dizz[dizz.size() - 2] == 5)
                                                            y1 = y;
                                                        else if (dizz[dizz.size() - 2] == 6)
                                                            y1 = r;
                                                        else if (dizz[dizz.size() - 2] == 7)
                                                            y1 = t;
                                                        else if (dizz[dizz.size() - 2] == 8)
                                                            y1 = k;
                                                        else if (dizz[dizz.size() - 2] == 9)
                                                            y1 = j;
                                                        else
                                                            y1 = i;
                                                    }

                                                    if (x1 + y1 == 0) {
                                                        count++;
                                                        break;
                                                    }
                                                    dizz.resize(dizz.size()-2);
                                                }
                                                if (count > 0)
                                                    ans.push_back(0);
                                                else {
                                                    return;
                                                }
                                                count = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 11) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                for (int a = 0; a < 2; a++) {
                                                    vector<int>dizz(consty);
                                                    while (dizz.size() > 0) {
                                                        int x1, y1;
                                                        if (dizz[dizz.size()-1] < 0) {
                                                            if (dizz[dizz.size()-1] == -1)
                                                                x1 = ~a+2;
                                                            else if (dizz[dizz.size()-1] == -2)
                                                                x1 = ~o+2;
                                                            else if (dizz[dizz.size()-1] == -3)
                                                                x1 = ~w+2;
                                                            else if (dizz[dizz.size()-1] == -4)
                                                                x1 = ~g+2;
                                                            else if (dizz[dizz.size()-1] == -5)
                                                                x1 = ~e+2;
                                                            else if (dizz[dizz.size()-1] == -6)
                                                                x1 = ~y+2;
                                                            else if (dizz[dizz.size()-1] == -7)
                                                                x1 = ~r+2;
                                                            else if (dizz[dizz.size()-1] == -8)
                                                                x1 = ~t+2;
                                                            else if (dizz[dizz.size()-1] == -9)
                                                                x1 = ~k+2;
                                                            else if (dizz[dizz.size()-1] == -10)
                                                                x1 = ~j+2;
                                                            else
                                                                x1 = ~i+2;
                                                        }
                                                        else {
                                                            if (dizz[dizz.size() - 1] == 1)
                                                                x1 = a;
                                                            else if (dizz[dizz.size() - 1] == 2)
                                                                x1 = o;
                                                            else if (dizz[dizz.size() - 1] == 3)
                                                                x1 = w;
                                                            else if (dizz[dizz.size() - 1] == 4)
                                                                x1 = g;
                                                            else if (dizz[dizz.size() - 1] == 5)
                                                                x1 = e;
                                                            else if (dizz[dizz.size() - 1] == 6)
                                                                x1 = y;
                                                            else if (dizz[dizz.size() - 1] == 7)
                                                                x1 = r;
                                                            else if (dizz[dizz.size() - 1] == 8)
                                                                x1 = t;
                                                            else if (dizz[dizz.size() - 1] == 9)
                                                                x1 = k;
                                                            else if (dizz[dizz.size() - 1] == 10)
                                                                x1 = j;
                                                            else
                                                                x1 = i;
                                                        }

                                                        if (dizz[dizz.size()-2] < 0) {
                                                            if (dizz[dizz.size()-2] == -1)
                                                                y1 = ~a+2;
                                                            else if (dizz[dizz.size()-2] == -2)
                                                                y1 = ~o+2;
                                                            else if (dizz[dizz.size()-2] == -3)
                                                                y1 = ~w+2;
                                                            else if (dizz[dizz.size()-2] == -4)
                                                                y1 = ~g+2;
                                                            else if (dizz[dizz.size()-2] == -5)
                                                                y1 = ~e+2;
                                                            else if (dizz[dizz.size()-2] == -6)
                                                                y1 = ~y+2;
                                                            else if (dizz[dizz.size()-2] == -7)
                                                                y1 = ~r+2;
                                                            else if (dizz[dizz.size()-2] == -8)
                                                                y1 = ~t+2;
                                                            else if (dizz[dizz.size()-2] == -9)
                                                                y1 = ~k+2;
                                                            else if (dizz[dizz.size()-2] == -10)
                                                                y1 = ~j+2;
                                                            else
                                                                y1 = ~i+2;
                                                        }
                                                        else {
                                                            if (dizz[dizz.size() - 2] == 1)
                                                                y1 = a;
                                                            else if (dizz[dizz.size() - 2] == 2)
                                                                y1 = o;
                                                            else if (dizz[dizz.size() - 2] == 3)
                                                                y1 = w;
                                                            else if (dizz[dizz.size() - 2] == 4)
                                                                y1 = g;
                                                            else if (dizz[dizz.size() - 2] == 5)
                                                                y1 = e;
                                                            else if (dizz[dizz.size() - 2] == 6)
                                                                y1 = y;
                                                            else if (dizz[dizz.size() - 2] == 7)
                                                                y1 = r;
                                                            else if (dizz[dizz.size() - 2] == 8)
                                                                y1 = t;
                                                            else if (dizz[dizz.size() - 2] == 9)
                                                                y1 = k;
                                                            else if (dizz[dizz.size() - 2] == 10)
                                                                y1 = j;
                                                            else
                                                                y1 = i;
                                                        }

                                                        if (x1 + y1 == 0) {
                                                            count++;
                                                            break;
                                                        }
                                                        dizz.resize(dizz.size()-2);
                                                    }
                                                    if (count > 0)
                                                        ans.push_back(0);
                                                    else {
                                                        return;
                                                    }
                                                    count = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 12) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                for (int a = 0; a < 2; a++) {
                                                    for (int s = 0; s < 2; s++) {
                                                        vector<int>dizz(consty);
                                                        while (dizz.size() > 0) {
                                                            int x1, y1;
                                                            if (dizz[dizz.size()-1] < 0) {
                                                                if (dizz[dizz.size()-1] == -1)
                                                                    x1 = ~s+2;
                                                                else if (dizz[dizz.size()-1] == -2)
                                                                    x1 = ~a+2;
                                                                else if (dizz[dizz.size()-1] == -3)
                                                                    x1 = ~o+2;
                                                                else if (dizz[dizz.size()-1] == -4)
                                                                    x1 = ~w+2;
                                                                else if (dizz[dizz.size()-1] == -5)
                                                                    x1 = ~g+2;
                                                                else if (dizz[dizz.size()-1] == -6)
                                                                    x1 = ~e+2;
                                                                else if (dizz[dizz.size()-1] == -7)
                                                                    x1 = ~y+2;
                                                                else if (dizz[dizz.size()-1] == -8)
                                                                    x1 = ~r+2;
                                                                else if (dizz[dizz.size()-1] == -9)
                                                                    x1 = ~t+2;
                                                                else if (dizz[dizz.size()-1] == -10)
                                                                    x1 = ~k+2;
                                                                else if (dizz[dizz.size()-1] == -11)
                                                                    x1 = ~j+2;
                                                                else
                                                                    x1 = ~i+2;
                                                            }
                                                            else {
                                                                if (dizz[dizz.size() - 1] == 1)
                                                                    x1 = s;
                                                                else if (dizz[dizz.size() - 1] == 2)
                                                                    x1 = a;
                                                                else if (dizz[dizz.size() - 1] == 3)
                                                                    x1 = o;
                                                                else if (dizz[dizz.size() - 1] == 4)
                                                                    x1 = w;
                                                                else if (dizz[dizz.size() - 1] == 5)
                                                                    x1 = g;
                                                                else if (dizz[dizz.size() - 1] == 6)
                                                                    x1 = e;
                                                                else if (dizz[dizz.size() - 1] == 7)
                                                                    x1 = y;
                                                                else if (dizz[dizz.size() - 1] == 8)
                                                                    x1 = r;
                                                                else if (dizz[dizz.size() - 1] == 9)
                                                                    x1 = t;
                                                                else if (dizz[dizz.size() - 1] == 10)
                                                                    x1 = k;
                                                                else if (dizz[dizz.size() - 1] == 11)
                                                                    x1 = j;
                                                                else
                                                                    x1 = i;
                                                            }

                                                            if (dizz[dizz.size()-2] < 0) {
                                                                if (dizz[dizz.size()-2] == -1)
                                                                    y1 = ~s+2;
                                                                else if (dizz[dizz.size()-2] == -2)
                                                                    y1 = ~a+2;
                                                                else if (dizz[dizz.size()-2] == -3)
                                                                    y1 = ~o+2;
                                                                else if (dizz[dizz.size()-2] == -4)
                                                                    y1 = ~w+2;
                                                                else if (dizz[dizz.size()-2] == -5)
                                                                    y1 = ~g+2;
                                                                else if (dizz[dizz.size()-2] == -6)
                                                                    y1 = ~e+2;
                                                                else if (dizz[dizz.size()-2] == -7)
                                                                    y1 = ~y+2;
                                                                else if (dizz[dizz.size()-2] == -8)
                                                                    y1 = ~r+2;
                                                                else if (dizz[dizz.size()-2] == -9)
                                                                    y1 = ~t+2;
                                                                else if (dizz[dizz.size()-2] == -10)
                                                                    y1 = ~k+2;
                                                                else if (dizz[dizz.size()-2] == -11)
                                                                    y1 = ~j+2;
                                                                else
                                                                    y1 = ~i+2;
                                                            }
                                                            else {
                                                                if (dizz[dizz.size() - 2] == 1)
                                                                    y1 = s;
                                                                else if (dizz[dizz.size() - 2] == 2)
                                                                    y1 = a;
                                                                else if (dizz[dizz.size() - 2] == 3)
                                                                    y1 = o;
                                                                else if (dizz[dizz.size() - 2] == 4)
                                                                    y1 = w;
                                                                else if (dizz[dizz.size() - 2] == 5)
                                                                    y1 = g;
                                                                else if (dizz[dizz.size() - 2] == 6)
                                                                    y1 = e;
                                                                else if (dizz[dizz.size() - 2] == 7)
                                                                    y1 = y;
                                                                else if (dizz[dizz.size() - 2] == 8)
                                                                    y1 = r;
                                                                else if (dizz[dizz.size() - 2] == 9)
                                                                    y1 = t;
                                                                else if (dizz[dizz.size() - 2] == 10)
                                                                    y1 = k;
                                                                else if (dizz[dizz.size() - 2] == 11)
                                                                    y1 = j;
                                                                else
                                                                    y1 = i;
                                                            }

                                                            if (x1 + y1 == 0) {
                                                                count++;
                                                                break;
                                                            }
                                                            dizz.resize(dizz.size()-2);
                                                        }
                                                        if (count > 0)
                                                            ans.push_back(0);
                                                        else {
                                                            return;
                                                        }
                                                        count = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 13) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                for (int a = 0; a < 2; a++) {
                                                    for (int s = 0; s < 2; s++) {
                                                        for (int m = 0; m < 2; m++) {
                                                            vector<int>dizz(consty);
                                                            while (dizz.size() > 0) {
                                                                int x1, y1;
                                                                if (dizz[dizz.size()-1] < 0) {
                                                                    if (dizz[dizz.size()-1] == -1)
                                                                        x1 = ~m+2;
                                                                    else if (dizz[dizz.size()-1] == -2)
                                                                        x1 = ~s+2;
                                                                    else if (dizz[dizz.size()-1] == -3)
                                                                        x1 = ~a+2;
                                                                    else if (dizz[dizz.size()-1] == -4)
                                                                        x1 = ~o+2;
                                                                    else if (dizz[dizz.size()-1] == -5)
                                                                        x1 = ~w+2;
                                                                    else if (dizz[dizz.size()-1] == -6)
                                                                        x1 = ~g+2;
                                                                    else if (dizz[dizz.size()-1] == -7)
                                                                        x1 = ~e+2;
                                                                    else if (dizz[dizz.size()-1] == -8)
                                                                        x1 = ~y+2;
                                                                    else if (dizz[dizz.size()-1] == -9)
                                                                        x1 = ~r+2;
                                                                    else if (dizz[dizz.size()-1] == -10)
                                                                        x1 = ~t+2;
                                                                    else if (dizz[dizz.size()-1] == -11)
                                                                        x1 = ~k+2;
                                                                    else if (dizz[dizz.size()-1] == -12)
                                                                        x1 = ~j+2;
                                                                    else
                                                                        x1 = ~i+2;
                                                                }
                                                                else {
                                                                    if (dizz[dizz.size() - 1] == 1)
                                                                        x1 = m;
                                                                    else if (dizz[dizz.size() - 1] == 2)
                                                                        x1 = s;
                                                                    else if (dizz[dizz.size() - 1] == 3)
                                                                        x1 = a;
                                                                    else if (dizz[dizz.size() - 1] == 4)
                                                                        x1 = o;
                                                                    else if (dizz[dizz.size() - 1] == 5)
                                                                        x1 = w;
                                                                    else if (dizz[dizz.size() - 1] == 6)
                                                                        x1 = g;
                                                                    else if (dizz[dizz.size() - 1] == 7)
                                                                        x1 = e;
                                                                    else if (dizz[dizz.size() - 1] == 8)
                                                                        x1 = y;
                                                                    else if (dizz[dizz.size() - 1] == 9)
                                                                        x1 = r;
                                                                    else if (dizz[dizz.size() - 1] == 10)
                                                                        x1 = t;
                                                                    else if (dizz[dizz.size() - 1] == 11)
                                                                        x1 = k;
                                                                    else if (dizz[dizz.size() - 1] == 12)
                                                                        x1 = j;
                                                                    else
                                                                        x1 = i;
                                                                }

                                                                if (dizz[dizz.size()-2] < 0) {
                                                                    if (dizz[dizz.size()-2] == -1)
                                                                        y1 = ~m+2;
                                                                    else if (dizz[dizz.size()-2] == -2)
                                                                        y1 = ~s+2;
                                                                    else if (dizz[dizz.size()-2] == -3)
                                                                        y1 = ~a+2;
                                                                    else if (dizz[dizz.size()-2] == -4)
                                                                        y1 = ~o+2;
                                                                    else if (dizz[dizz.size()-2] == -5)
                                                                        y1 = ~w+2;
                                                                    else if (dizz[dizz.size()-2] == -6)
                                                                        y1 = ~g+2;
                                                                    else if (dizz[dizz.size()-2] == -7)
                                                                        y1 = ~e+2;
                                                                    else if (dizz[dizz.size()-2] == -8)
                                                                        y1 = ~y+2;
                                                                    else if (dizz[dizz.size()-2] == -9)
                                                                        y1 = ~r+2;
                                                                    else if (dizz[dizz.size()-2] == -10)
                                                                        y1 = ~t+2;
                                                                    else if (dizz[dizz.size()-2] == -11)
                                                                        y1 = ~k+2;
                                                                    else if (dizz[dizz.size()-2] == -12)
                                                                        y1 = ~j+2;
                                                                    else
                                                                        y1 = ~i+2;
                                                                }
                                                                else {
                                                                    if (dizz[dizz.size() - 2] == 1)
                                                                        y1 = m;
                                                                    else if (dizz[dizz.size() - 2] == 2)
                                                                        y1 = s;
                                                                    else if (dizz[dizz.size() - 2] == 3)
                                                                        y1 = a;
                                                                    else if (dizz[dizz.size() - 2] == 4)
                                                                        y1 = o;
                                                                    else if (dizz[dizz.size() - 2] == 5)
                                                                        y1 = w;
                                                                    else if (dizz[dizz.size() - 2] == 6)
                                                                        y1 = g;
                                                                    else if (dizz[dizz.size() - 2] == 7)
                                                                        y1 = e;
                                                                    else if (dizz[dizz.size() - 2] == 8)
                                                                        y1 = y;
                                                                    else if (dizz[dizz.size() - 2] == 9)
                                                                        y1 = r;
                                                                    else if (dizz[dizz.size() - 2] == 10)
                                                                        y1 = t;
                                                                    else if (dizz[dizz.size() - 2] == 11)
                                                                        y1 = k;
                                                                    else if (dizz[dizz.size() - 2] == 12)
                                                                        y1 = j;
                                                                    else
                                                                        y1 = i;
                                                                }

                                                                if (x1 + y1 == 0) {
                                                                    count++;
                                                                    break;
                                                                }
                                                                dizz.resize(dizz.size()-2);
                                                            }
                                                            if (count > 0)
                                                                ans.push_back(0);
                                                            else {
                                                                return;
                                                            }
                                                            count = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 14) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                for (int a = 0; a < 2; a++) {
                                                    for (int s = 0; s < 2; s++) {
                                                        for (int m = 0; m < 2; m++) {
                                                            for (int h = 0; h < 2; h++) {
                                                                vector<int>dizz(consty);
                                                                while (dizz.size() > 0) {
                                                                    int x1, y1;
                                                                    if (dizz[dizz.size()-1] < 0) {
                                                                        if (dizz[dizz.size()-1] == -1)
                                                                            x1 = ~h+2;
                                                                        else if (dizz[dizz.size()-1] == -2)
                                                                            x1 = ~m+2;
                                                                        else if (dizz[dizz.size()-1] == -3)
                                                                            x1 = ~s+2;
                                                                        else if (dizz[dizz.size()-1] == -4)
                                                                            x1 = ~a+2;
                                                                        else if (dizz[dizz.size()-1] == -5)
                                                                            x1 = ~o+2;
                                                                        else if (dizz[dizz.size()-1] == -6)
                                                                            x1 = ~w+2;
                                                                        else if (dizz[dizz.size()-1] == -7)
                                                                            x1 = ~g+2;
                                                                        else if (dizz[dizz.size()-1] == -8)
                                                                            x1 = ~e+2;
                                                                        else if (dizz[dizz.size()-1] == -9)
                                                                            x1 = ~y+2;
                                                                        else if (dizz[dizz.size()-1] == -10)
                                                                            x1 = ~r+2;
                                                                        else if (dizz[dizz.size()-1] == -11)
                                                                            x1 = ~t+2;
                                                                        else if (dizz[dizz.size()-1] == -12)
                                                                            x1 = ~k+2;
                                                                        else if (dizz[dizz.size()-1] == -13)
                                                                            x1 = ~j+2;
                                                                        else
                                                                            x1 = ~i+2;
                                                                    }
                                                                    else {
                                                                        if (dizz[dizz.size() - 1] == 1)
                                                                            x1 = h;
                                                                        else if (dizz[dizz.size() - 1] == 2)
                                                                            x1 = m;
                                                                        else if (dizz[dizz.size() - 1] == 3)
                                                                            x1 = s;
                                                                        else if (dizz[dizz.size() - 1] == 4)
                                                                            x1 = a;
                                                                        else if (dizz[dizz.size() - 1] == 5)
                                                                            x1 = o;
                                                                        else if (dizz[dizz.size() - 1] == 6)
                                                                            x1 = w;
                                                                        else if (dizz[dizz.size() - 1] == 7)
                                                                            x1 = g;
                                                                        else if (dizz[dizz.size() - 1] == 8)
                                                                            x1 = e;
                                                                        else if (dizz[dizz.size() - 1] == 9)
                                                                            x1 = y;
                                                                        else if (dizz[dizz.size() - 1] == 10)
                                                                            x1 = r;
                                                                        else if (dizz[dizz.size() - 1] == 11)
                                                                            x1 = t;
                                                                        else if (dizz[dizz.size() - 1] == 12)
                                                                            x1 = k;
                                                                        else if (dizz[dizz.size() - 1] == 13)
                                                                            x1 = j;
                                                                        else
                                                                            x1 = i;
                                                                    }

                                                                    if (dizz[dizz.size()-2] < 0) {
                                                                        if (dizz[dizz.size()-2] == -1)
                                                                            y1 = ~h+2;
                                                                        else if (dizz[dizz.size()-2] == -2)
                                                                            y1 = ~m+2;
                                                                        else if (dizz[dizz.size()-2] == -3)
                                                                            y1 = ~s+2;
                                                                        else if (dizz[dizz.size()-2] == -4)
                                                                            y1 = ~a+2;
                                                                        else if (dizz[dizz.size()-2] == -5)
                                                                            y1 = ~o+2;
                                                                        else if (dizz[dizz.size()-2] == -6)
                                                                            y1 = ~w+2;
                                                                        else if (dizz[dizz.size()-2] == -7)
                                                                            y1 = ~g+2;
                                                                        else if (dizz[dizz.size()-2] == -8)
                                                                            y1 = ~e+2;
                                                                        else if (dizz[dizz.size()-2] == -9)
                                                                            y1 = ~y+2;
                                                                        else if (dizz[dizz.size()-2] == -10)
                                                                            y1 = ~r+2;
                                                                        else if (dizz[dizz.size()-2] == -11)
                                                                            y1 = ~t+2;
                                                                        else if (dizz[dizz.size()-2] == -12)
                                                                            y1 = ~k+2;
                                                                        else if (dizz[dizz.size()-2] == -13)
                                                                            y1 = ~j+2;
                                                                        else
                                                                            y1 = ~i+2;
                                                                    }
                                                                    else {
                                                                        if (dizz[dizz.size() - 2] == 1)
                                                                            y1 = h;
                                                                        else if (dizz[dizz.size() - 2] == 2)
                                                                            y1 = m;
                                                                        else if (dizz[dizz.size() - 2] == 3)
                                                                            y1 = s;
                                                                        else if (dizz[dizz.size() - 2] == 4)
                                                                            y1 = a;
                                                                        else if (dizz[dizz.size() - 2] == 5)
                                                                            y1 = o;
                                                                        else if (dizz[dizz.size() - 2] == 6)
                                                                            y1 = w;
                                                                        else if (dizz[dizz.size() - 2] == 7)
                                                                            y1 = g;
                                                                        else if (dizz[dizz.size() - 2] == 8)
                                                                            y1 = e;
                                                                        else if (dizz[dizz.size() - 2] == 9)
                                                                            y1 = y;
                                                                        else if (dizz[dizz.size() - 2] == 10)
                                                                            y1 = r;
                                                                        else if (dizz[dizz.size() - 2] == 11)
                                                                            y1 = t;
                                                                        else if (dizz[dizz.size() - 2] == 12)
                                                                            y1 = k;
                                                                        else if (dizz[dizz.size() - 2] == 13)
                                                                            y1 = j;
                                                                        else
                                                                            y1 = i;
                                                                    }

                                                                    if (x1 + y1 == 0) {
                                                                        count++;
                                                                        break;
                                                                    }
                                                                    dizz.resize(dizz.size()-2);
                                                                }
                                                                if (count > 0)
                                                                    ans.push_back(0);
                                                                else {
                                                                    return;
                                                                }
                                                                count = 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 15) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    for (int t = 0; t < 2; t++) {
                        for (int r = 0; r < 2; r++) {
                            for (int y = 0; y < 2; y++) {
                                for (int e = 0; e < 2; e++) {
                                    for (int g = 0; g < 2; g++) {
                                        for (int w = 0; w < 2; w++) {
                                            for (int o = 0; o < 2; o++) {
                                                for (int a = 0; a < 2; a++) {
                                                    for (int s = 0; s < 2; s++) {
                                                        for (int m = 0; m < 2; m++) {
                                                            for (int h = 0; h < 2; h++) {
                                                                for (int f = 0; f < 2; f++) {
                                                                    vector<int>dizz(consty);
                                                                    while (dizz.size() > 0) {
                                                                        int x1, y1;
                                                                        if (dizz[dizz.size()-1] < 0) {
                                                                            if (dizz[dizz.size()-1] == -1)
                                                                                x1 = ~f+2;
                                                                            else if (dizz[dizz.size()-1] == -2)
                                                                                x1 = ~h+2;
                                                                            else if (dizz[dizz.size()-1] == -3)
                                                                                x1 = ~m+2;
                                                                            else if (dizz[dizz.size()-1] == -4)
                                                                                x1 = ~s+2;
                                                                            else if (dizz[dizz.size()-1] == -5)
                                                                                x1 = ~a+2;
                                                                            else if (dizz[dizz.size()-1] == -6)
                                                                                x1 = ~o+2;
                                                                            else if (dizz[dizz.size()-1] == -7)
                                                                                x1 = ~w+2;
                                                                            else if (dizz[dizz.size()-1] == -8)
                                                                                x1 = ~g+2;
                                                                            else if (dizz[dizz.size()-1] == -9)
                                                                                x1 = ~e+2;
                                                                            else if (dizz[dizz.size()-1] == -10)
                                                                                x1 = ~y+2;
                                                                            else if (dizz[dizz.size()-1] == -11)
                                                                                x1 = ~r+2;
                                                                            else if (dizz[dizz.size()-1] == -12)
                                                                                x1 = ~t+2;
                                                                            else if (dizz[dizz.size()-1] == -13)
                                                                                x1 = ~k+2;
                                                                            else if (dizz[dizz.size()-1] == -14)
                                                                                x1 = ~j+2;
                                                                            else
                                                                                x1 = ~i+2;
                                                                        }
                                                                        else {
                                                                            if (dizz[dizz.size() - 1] == 1)
                                                                                x1 = f;
                                                                            else if (dizz[dizz.size() - 1] == 2)
                                                                                x1 = h;
                                                                            else if (dizz[dizz.size() - 1] == 3)
                                                                                x1 = m;
                                                                            else if (dizz[dizz.size() - 1] == 4)
                                                                                x1 = s;
                                                                            else if (dizz[dizz.size() - 1] == 5)
                                                                                x1 = a;
                                                                            else if (dizz[dizz.size() - 1] == 6)
                                                                                x1 = o;
                                                                            else if (dizz[dizz.size() - 1] == 7)
                                                                                x1 = w;
                                                                            else if (dizz[dizz.size() - 1] == 8)
                                                                                x1 = g;
                                                                            else if (dizz[dizz.size() - 1] == 9)
                                                                                x1 = e;
                                                                            else if (dizz[dizz.size() - 1] == 10)
                                                                                x1 = y;
                                                                            else if (dizz[dizz.size() - 1] == 11)
                                                                                x1 = r;
                                                                            else if (dizz[dizz.size() - 1] == 12)
                                                                                x1 = t;
                                                                            else if (dizz[dizz.size() - 1] == 13)
                                                                                x1 = k;
                                                                            else if (dizz[dizz.size() - 1] == 14)
                                                                                x1 = j;
                                                                            else
                                                                                x1 = i;
                                                                        }

                                                                        if (dizz[dizz.size()-2] < 0) {
                                                                            if (dizz[dizz.size()-2] == -1)
                                                                                y1 = ~f+2;
                                                                            else if (dizz[dizz.size()-2] == -2)
                                                                                y1 = ~h+2;
                                                                            else if (dizz[dizz.size()-2] == -3)
                                                                                y1 = ~m+2;
                                                                            else if (dizz[dizz.size()-2] == -4)
                                                                                y1 = ~s+2;
                                                                            else if (dizz[dizz.size()-2] == -5)
                                                                                y1 = ~a+2;
                                                                            else if (dizz[dizz.size()-2] == -6)
                                                                                y1 = ~o+2;
                                                                            else if (dizz[dizz.size()-2] == -7)
                                                                                y1 = ~w+2;
                                                                            else if (dizz[dizz.size()-2] == -8)
                                                                                y1 = ~g+2;
                                                                            else if (dizz[dizz.size()-2] == -9)
                                                                                y1 = ~e+2;
                                                                            else if (dizz[dizz.size()-2] == -10)
                                                                                y1 = ~y+2;
                                                                            else if (dizz[dizz.size()-2] == -11)
                                                                                y1 = ~r+2;
                                                                            else if (dizz[dizz.size()-2] == -12)
                                                                                y1 = ~t+2;
                                                                            else if (dizz[dizz.size()-2] == -13)
                                                                                y1 = ~k+2;
                                                                            else if (dizz[dizz.size()-2] == -14)
                                                                                y1 = ~j+2;
                                                                            else
                                                                                y1 = ~i+2;
                                                                        }
                                                                        else {
                                                                            if (dizz[dizz.size() - 2] == 1)
                                                                                y1 = f;
                                                                            else if (dizz[dizz.size() - 2] == 2)
                                                                                y1 = h;
                                                                            else if (dizz[dizz.size() - 2] == 3)
                                                                                y1 = m;
                                                                            else if (dizz[dizz.size() - 2] == 4)
                                                                                y1 = s;
                                                                            else if (dizz[dizz.size() - 2] == 5)
                                                                                y1 = a;
                                                                            else if (dizz[dizz.size() - 2] == 6)
                                                                                y1 = o;
                                                                            else if (dizz[dizz.size() - 2] == 7)
                                                                                y1 = w;
                                                                            else if (dizz[dizz.size() - 2] == 8)
                                                                                y1 = g;
                                                                            else if (dizz[dizz.size() - 2] == 9)
                                                                                y1 = e;
                                                                            else if (dizz[dizz.size() - 2] == 10)
                                                                                y1 = y;
                                                                            else if (dizz[dizz.size() - 2] == 11)
                                                                                y1 = r;
                                                                            else if (dizz[dizz.size() - 2] == 12)
                                                                                y1 = t;
                                                                            else if (dizz[dizz.size() - 2] == 13)
                                                                                y1 = k;
                                                                            else if (dizz[dizz.size() - 2] == 14)
                                                                                y1 = j;
                                                                            else
                                                                                y1 = i;
                                                                        }

                                                                        if (x1 + y1 == 0) {
                                                                            count++;
                                                                            break;
                                                                        }
                                                                        dizz.resize(dizz.size()-2);
                                                                    }
                                                                    if (count > 0) {
                                                                        ans.push_back(0);
                                                                    }
                                                                    else {
                                                                        return;
                                                                    }
                                                                    count = 0;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    int x;
    int y;
    for (int i = 0; i < m; i++) {
        //for (int j = 0; j < n; j++) {
            cin >> x >> y;
            dizz.push_back(x);
            dizz.push_back(y);
            for (int ch = 0; ch < dizz.size()-2; ch=ch+2) {
                if ((dizz[ch] == x && dizz[ch+1] == y) || (dizz[ch] == y && dizz[ch+1] == x)) {
                    dizz.pop_back();
                    dizz.pop_back();
                    break;
                }
            }
        //}
    }
    vector<int>consty(dizz);
    table(n, consty);
    if (ans.size() == pow(2, n)) {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}
