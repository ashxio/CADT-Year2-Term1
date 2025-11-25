#include "implementation/tournament.cpp"

int main() {
    srand(time(0));
    vector<string> players = {"Anna","Ben","Chou","Dara","Ean","Faye","Gita","Hout"};

    buildBracket(players);
    cout << "Bracket built.\n";

    cout << "Match Results:\n";
    decideWinners(root);

    cout << "\nFinal Bracket:\n";
    printBracket();

    auto meet = wouldMeet("Anna", "Dara");
    cout << "\nwouldMeet(Anna, Dara) => matchId = " << meet.first
         << ", round = " << meet.second << "\n";

    auto path = pathToFinal("Faye");
    cout << "pathToFinal(Faye): ";
    for (int id : path) cout << id << " ";
    cout << "\n";

    cout << "Champion: " << root->winner << "\n";
}