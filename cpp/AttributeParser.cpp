#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<string> prefix_tag;
    unordered_map<string, string> m;

    string line, prefix;

    getline(cin, line);

    for (int i = 0; i < N; i++)
    {
        getline(cin, line);

        line.erase(line.end() - 1);
        line.erase(line.begin(), line.begin() + 1);

        if (line[0] == '/')
        {
            line.erase(line.begin(), line.begin() + 1);
            prefix_tag.pop_back();
            continue;
        }

        replace(line.begin(), line.end(), '=', ' ');
        replace(line.begin(), line.end(), '\"', ' ');

        stringstream ss(line);

        ss >> prefix;
        prefix_tag.push_back(prefix);

        string key, value, temp;

        for (auto &element : prefix_tag)
        {
            temp = temp + "." + element;
        }

        while (ss)
        {
            ss >> key >> value;
            m[temp + "~" + key] = value;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        getline(cin, line);
        string temp = "." + line;
        if (m.count(temp) == 1)
        {
            cout << m[temp] << endl;
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}