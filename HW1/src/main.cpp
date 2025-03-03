#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "edge_t.h"
const int inf = 1e9 + 7;
const int mxn = 15;
using namespace std;
vector<vector<edge_t>> G;
map<string, int> vname_to_id;
map<int, string> vid_to_name;
int gn = 0;
int mem[mxn][(1 << mxn)];
void print_G() {  // for debugging
    for (int i = 0; i < gn; ++i) {
        if (!vid_to_name.count(i)) {
            continue;
        }
        string u = vid_to_name[i];
        cerr << u << ": " << endl;

        for (auto& nei : G[i]) {
            cerr << "{" << vid_to_name[nei.v] << ", " << nei.w << "}" << endl;
        }
    }
}

int TSP(int i, int mask) {
    if (mem[i][mask] != -1) {
        return mem[i][mask];
    }
    int ans = inf;
    bool check = true;

    for (int j = 0; j < gn; ++j) {
        if (mask & (1 << j)) {
            continue;
        }
        check = false;
    }
    if (i == 0 && check) {
        return mem[i][mask] = 0;
    }
    for (auto& nei : G[i]) {
        int vmask = (1 << nei.v);
        if (vmask & mask) {
            continue;  // visited
        }
        ans = min(ans, TSP(nei.v, mask + vmask) + nei.w);
    }
    return mem[i][mask] = ans;
}
void find_path(int i, int mask, vector<int>& path) {
    path.push_back(i);
    int mn = inf, mn_i = -1;
    for (auto& nei : G[i]) {
        int vmask = (1 << nei.v);
        if (vmask & mask) {
            continue;  // visited
        }
        int val = TSP(nei.v, mask + vmask) + nei.w;
        if (val < mn) {
            mn = val;
            mn_i = nei.v;
        }
    }
    if (mn_i == -1) {
        return;
    }
    int v = mn_i, vmask = (1 << v);
    find_path(v, mask + vmask, path);
}
void read_graph_from_file(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Unable to open the file: " << filename << endl;
        exit(1);
    }
    int c = 0;

    string line;
    while (getline(infile, line)) {
        // ignore the comments
        line = line.substr(0, line.find('#'));
        if (line.empty()) continue;  // skip the empty line
        stringstream ss(line);
        string edge_name, edge_weight_str, u_str, v_str;
        int edge_weight, u, v;
        ss >> edge_name >> edge_weight_str >> u_str >> v_str;
        edge_weight = stoi(edge_weight_str);
        if (ss.fail()) {
            cerr << "The file does not match the format!" << filename << endl;
            exit(1);
        }
        if (!vname_to_id.count(u_str)) {
            vid_to_name[c] = u_str;
            vname_to_id[u_str] = c++;
            gn++;
        }
        if (!vname_to_id.count(v_str)) {
            vid_to_name[c] = v_str;
            vname_to_id[v_str] = c++;
            gn++;
        }
        u = vname_to_id[u_str];
        v = vname_to_id[v_str];
        // cout << u << ", " << v << endl;
        G[u].push_back({v, edge_weight});
        G[v].push_back({u, edge_weight});
    }
    infile.close();
}

int main(int argc, char* argv[]) {
    // Initialization
    G.resize(mxn);
    memset(mem, -1, sizeof(mem));
    // Read input file
    string filename = argv[1];
    read_graph_from_file(filename);
    vector<int> path;
    int res = TSP(0, 0);
    find_path(0, 0, path);
    for (auto& v : path) {
        cout << vid_to_name[v] << " ";
    }
    cout << endl;
}
