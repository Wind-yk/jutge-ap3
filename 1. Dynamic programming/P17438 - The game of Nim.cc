#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<vector<int>, bool> M;

// Diu si el jugador que rep aquest configuracio guanya
bool winning(vector<int>& conf) {
    if(M.find(conf) != M.end()) return M[conf];

    int s = 0;
    for(auto& x: conf) s +=x;
    if(s == 0) return M[conf] = false; // Tot zero --> perdedora

    for(uint pos = 0; pos < conf.size(); ++pos) {
        for(int t = 1; t <= conf[pos]; ++t){
            // El moviment consta en treure "t" peces de la posició pos
            conf[pos] -= t;
            if(not winning(conf)) { conf[pos] += t; return M[conf] = true; }
            conf[pos] += t;
            // Observa que hem de sumar tot i que anem a retornar,
            // ja que és possible que usem el valor de conf[pos] de forma recursiva.
        }
    }
    return M[conf] = false;
}

int main() {
    int n;
    cin >> n;
    string jug1, jug2;
    vector<int> conf(6);
    for (int i = 1; i <= n; ++i) {
        cin >> jug1 >> jug2;
        for(int& c : conf) cin >> c;
        cout << "Game #" << i << ": " << (winning(conf) ? jug1:jug2) << endl;
    }
}
