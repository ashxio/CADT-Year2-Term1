#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node {
    string name;     
    string winner;   
    int matchId;     
    int round;             
    Node* left;
    Node* right;
    Node* parent;
    bool isLeaf;

    Node(string n = "BYE")
        : name(n), winner("?"), matchId(0), round(0),
          left(nullptr), right(nullptr), parent(nullptr),
          isLeaf(true) {}
};

// Global tournament info
Node* root = nullptr;
vector<Node*> matchList;  
int totalRounds = 0;

// 1. Build Bracket (pad BYEs if necessary)
Node* buildBracket(const vector<string>& players) {
    int n = players.size();
    int m = 1;
    while (m < n) m *= 2;

    vector<Node*> leaves;
    for (int i = 0; i < m; i++) {
        leaves.push_back(new Node(i < n ? players[i] : "BYE"));
    }

    matchList.clear();
    int matchCounter = 1;
    int round = 0;

    vector<Node*> curr = leaves;

    while (curr.size() > 1) {
        vector<Node*> next;
        round++;

        for (size_t i = 0; i < curr.size(); i += 2) {
            Node* m = new Node();
            m->isLeaf = false;
            m->left = curr[i];
            m->right = curr[i+1];
            curr[i]->parent = m;
            curr[i+1]->parent = m;
            m->matchId = matchCounter++;
            m->round = round;
            matchList.push_back(m);
            next.push_back(m);
        }
        curr.swap(next);
    }

    totalRounds = round;
    root = curr[0];
    return root;
}

// Find leaf node by player name
Node* findLeaf(Node* node, const string& name) {
    if (!node) return nullptr;
    if (node->isLeaf) return node->name == name ? node : nullptr;
    Node* L = findLeaf(node->left, name);
    return L ? L : findLeaf(node->right, name);
}

// 2. Record Match Result
bool recordResult(int matchId, const string& winnerName) {
    if (matchId <= 0 || matchId > (int)matchList.size()) return false;
    Node* m = matchList[matchId-1];
    if (m->winner != "?") return false;

    string L = m->left->isLeaf ? m->left->name : m->left->winner;
    string R = m->right->isLeaf ? m->right->name : m->right->winner;

    if (L == "?" || R == "?") return false;

    if (L == "BYE") m->winner = R;
    else if (R == "BYE") m->winner = L;
    else if (winnerName == L || winnerName == R) m->winner = winnerName;
    else return false;

    // Push winner up the tree automatically for BYEs
    Node* parent = m->parent;
    while (parent) {
        string a = parent->left->isLeaf ? parent->left->name : parent->left->winner;
        string b = parent->right->isLeaf ? parent->right->name : parent->right->winner;

        if (a == "?" || b == "?") break;
        if (parent->winner != "?") break;

        if (a == "BYE") parent->winner = b;
        else if (b == "BYE") parent->winner = a;
        else break;

        parent = parent->parent;
    }

    return true;
}

// Automatic winner assignment with random scores
void decideWinners(Node* node) {
    if (!node || node->isLeaf) return;

    decideWinners(node->left);
    decideWinners(node->right);

    string L = node->left->isLeaf ? node->left->name : node->left->winner;
    string R = node->right->isLeaf ? node->right->name : node->right->winner;

    if (L == "BYE") recordResult(node->matchId, R);
    else if (R == "BYE") recordResult(node->matchId, L);
    else {
        int scoreL = rand() % 100;
        int scoreR = rand() % 100;
        string winner = (scoreL >= scoreR ? L : R);
        recordResult(node->matchId, winner);
        cout << "Match " << node->matchId << " (Round " << node->round << "): "
             << L << " [" << scoreL << "] vs " << R << " [" << scoreR << "] -> Winner: "
             << winner << "\n";
    }
}

// 3. Path Query (stop at first loss)
vector<int> pathToFinal(const string& player) {
    vector<int> path;
    Node* leaf = findLeaf(root, player);
    if (!leaf) return path;
    Node* cur = leaf->parent;
    while (cur) {
        path.push_back(cur->matchId);
        if (cur->winner != "?" && cur->winner != player) break;
        cur = cur->parent;
    }
    return path;
}

// 4. Meeting Query (LCA logic)
pair<int,int> wouldMeet(const string& p1, const string& p2) {
    Node* a = findLeaf(root, p1);
    Node* b = findLeaf(root, p2);
    if (!a || !b) return {0,0};

    vector<Node*> chainA;
    for (Node* t = a; t; t = t->parent) chainA.push_back(t);

    for (Node* t = b; t; t = t->parent) {
        for (Node* x : chainA) {
            if (x == t && !t->isLeaf) return {t->matchId, t->round};
        }
    }
    return {0,0};
}

// Print bracket (level-order)
void printBracket() {
    vector<vector<Node*>> rounds(totalRounds+1);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* n = q.front(); q.pop();
        if (!n->isLeaf) {
            rounds[n->round].push_back(n);
            q.push(n->left);
            q.push(n->right);
        }
    }

    for (int r = 1; r <= totalRounds; r++) {
        cout << "\nRound " << r << ":\n";
        for (Node* m : rounds[r]) {
            string L = m->left->isLeaf ? m->left->name : m->left->winner;
            string R = m->right->isLeaf ? m->right->name : m->right->winner;
            cout << "  matchId = " << m->matchId
                 << " | " << L << " vs " << R
                 << " -> winner = " << m->winner << "\n";
        }
    }
}

