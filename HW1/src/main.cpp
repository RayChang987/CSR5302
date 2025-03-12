#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "edge_t.h"
using namespace std;

const int inf = 1e9 + 7;
const int mxn = 15;
vector<vector<edge_t>> G;
map<string, int> vname_to_id;
map<int, string> vid_to_name;
vector<int> path;
int gn = 0;
int tn = 0;
int mn_path = inf;
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

void print_all_path(int i, int mask, int sum) {
    tn++;
    if(sum>=mn_path){
        for(auto& e:path){cout<<vid_to_name[e]<<" ";}
        cout<<" Pruned!";
        cout<<endl;
        return;
    }
    bool end = true, start = true;
    for (int j = 1; j < gn; ++j) {
        if (mask & (1 << j)) {
            start = false;
        }
        else{
            end = false;
        }
    }
    bool fnd = false;
    for (auto& nei : G[i]) {
        int vmask = (1 << nei.v);
        if (vmask & mask) {
            continue;  // visited
        }
        if(nei.v==0&&(end==false)){continue;}
        fnd = true;
        path.push_back(nei.v);
        print_all_path(nei.v, mask + vmask, sum+nei.w);
        path.pop_back();
    }
    if(!fnd){
        if(i==0&&end){mn_path = min(mn_path, sum);}
        for(auto& e:path){cout<<vid_to_name[e]<<" ";}
        cout<<endl;
    }
    return;
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
    // Read input file
    string filename = argv[1];
    read_graph_from_file(filename);
    path.push_back(0);
    print_all_path(0, 0, 0);
    path.pop_back();
    cout<<"Minimum path length: ";
    cout<< mn_path<<endl;
    cout<<"Number of tree node: ";
    cout<< tn<<endl;
}
