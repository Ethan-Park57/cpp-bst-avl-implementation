#include "avlbst.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

struct Rectangle {
    int ID;
    int length;
    int height;
};

// Typedefs for you input and output map. Start with
// std::map but once the backtracking search algorithm is working
// try to use your AVL-tree map implementation by changing these
// typedef's
typedef AVLTree<int, Rectangle> InputMapType;
typedef AVLTree<int, std::pair<int, int>> OutputMapType;

// Allowed global variables: the dimensions of the grid
int n;  // X-dim size
int m;  // Y-dim size

// No other global variables are allowed

// A dummy operator << for Rectangles so the BST and AVL BST will
// compile with their printRoot() implementations
std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << r.ID;
    return os;
}

// A dummy operator << for pairs so the BST and AVL BST will
// compile with their printRoot() implementations
template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << p.first << "," << p.second;
    return os;
}

void printSolution(std::ostream& os, InputMapType& input, OutputMapType& output) {
    for (OutputMapType::iterator it = output.begin(); it != output.end(); ++it) {
        InputMapType::iterator rbit = input.find(it->first);
        os << it->first << " ";
        os << it->second.first << " ";
        os << it->second.second << " ";
        os << rbit->second.length << " ";
        os << rbit->second.height << endl;
    }
}

// Changes the grid entries to their opposite values for the
// rectangle r starting at x1,y1
void flip(int x1, int y1, const Rectangle& r, vector<vector<bool>>& grid) {
    for (int x = x1; x < x1 + r.length; x++) {
        for (int y = y1; y < y1 + r.height; y++)
            grid[x][y] = !grid[x][y];
    }
}

bool isValid(vector<vector<bool>>& grid, Rectangle& r, int x, int y) {
    // curr orientation check
    for (int j = y; j < y + r.height; j++) {
        if (j >= m) {
            return false;
        }
        for (int i = x; i < x + r.length; i++) {
            if (i >= n) {
                return false;
            }
            if (grid[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// TODO: Write your backtracking search function here
bool search(
        InputMapType /* tiles */& t,
        OutputMapType /*solution */& s,
        vector<vector<bool>>& grid,
        int x,
        int y,
        InputMapType::iterator& it) {
    if (it == t.end()) {
        return true;
    }

    InputMapType::iterator tempIt = it;  // to pass around recursive functions
    ++tempIt;

    // looping thru whole grid
    for (int j = y; j < m; j++) {
        for (int i = x; i < n; i++) {
            if (isValid(grid, it->second, i, j)) {
                flip(i, j, it->second, grid);
                s.insert(make_pair(it->first, make_pair(i, j)));

                // if current orientation works
                if (search(t, s, grid, 0, 0, tempIt)) {
                    return true;
                }
                // if not
                s.remove(it->first);
                flip(i, j, it->second, grid);
            }

            // try "sideways" orientation
            int temp = it->second.height;
            it->second.height = it->second.length;
            it->second.length = temp;

            // test this orientation
            if (isValid(grid, it->second, i, j)) {
                flip(i, j, it->second, grid);
                s.insert(make_pair(it->first, make_pair(i, j)));
                // if current orientation works
                if (search(t, s, grid, 0, 0, tempIt)) {
                    return true;
                }
                s.remove(it->first);
                flip(i, j, it->second, grid);
            }
            // reset orientation
            temp = it->second.height;
            it->second.height = it->second.length;
            it->second.length = temp;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "please specify an input and output file";
        return 0;
    }
    ifstream ifile(argv[1]);

    if (ifile.fail()) {
        cout << "No file opened" << endl;
        return 0;
    }

    stringstream ss;
    string line;
    ofstream ofile(argv[2]);
    int x;
    getline(ifile, line);
    ss << line;
    ss >> n;
    ss >> m;
    ss >> x;

    InputMapType input;
    OutputMapType output;
    for (int i = 0; i < x; i++) {
        getline(ifile, line);
        stringstream ss2(line);
        Rectangle r;
        ss2 >> r.ID;
        ss2 >> r.length;
        ss2 >> r.height;
        input.insert(std::make_pair(r.ID, r));
    }
    ifile.close();
    vector<vector<bool>> grid;

    for (int i = 0; i < n; i++) {
        grid.push_back(vector<bool>(m, false));
    }
    InputMapType::iterator it = input.begin();
    bool solution_exists = false;

    // quick checker to see if solution is even possible
    int tileArea = 0;
    for (InputMapType::iterator it2 = input.begin(); it2 != input.end(); ++it2) {
        tileArea += it2->second.length * it2->second.height;
    }

    if (tileArea > n * m) {
        solution_exists = false;
        ;
    } else {
        // TODO:  Call your backtracking search function here
        solution_exists = search(input, output, grid, 0, 0, it);
    }

    if (!solution_exists) {
        ofile << "No solution found.";
    } else {
        printSolution(ofile, input, output);
    }

    ofile.close();
    return 0;
}