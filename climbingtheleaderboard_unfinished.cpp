#include <list>
#include <iostream>

struct Player {

    Player(int newScore, int newSpot) :
        score(newScore), spot(newSpot) {}
    int score;
    int spot;
};

class Leaderboard {

    std::list<Player> board;
    std::list<Player>::iterator lastInput;
public:
    Leaderboard() : lastInput(NULL) {}
    void addPlayer(int score) {
        if(board.empty()) {
            Player p(score, 1);
            board.push_back(p);
            lastInput = board.begin();
        }
        else {
            if(score==lastInput->score) {
                Player p(score, lastInput->spot);
                board.push_back(p);
                lastInput = board.end();
                lastInput--;
            }
            else {
                Player p(score, lastInput->spot+1);
                board.push_back(p);
                lastInput = board.end();
                lastInput--;
            }
        }
    }
    int climbBoard(int score) {
        if(score < lastInput->score) {
            addPlayer(score);
            return lastInput->spot;
        }
        else {
            std::list<Player>::iterator i = lastInput;
            for(std::list<Player>::iterator beg=board.begin(); i!=beg; --i) {
                if(score==i->score) {
                    Player p(score, i->spot);
                    board.erase(lastInput);
                    board.insert(i, p);
                    lastInput = i;
                    return lastInput->spot;
                }
                std::list<Player>::iterator iplus = i;
                ++iplus;
                if(score>i->score && score<iplus->score) {
                    Player p(score, i->spot);
                    board.erase(lastInput);
                    board.insert(iplus, p);
                    lastInput = i;
                    for(std::list<Player>::iterator end=board.end(); i!=end; ++i) {
                        i->spot += 1;
                    }
                    return lastInput->spot;
                }
            }
        }
        return 0;
    }
    void displayBoard() {
        for(auto y:board)
            std::cout<<y.spot<<'\t'<<y.score<<std::endl;
    }
};

int main() {

    Leaderboard lb;
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin>>n;
    for(int i=0; i<n; ++i) {
        int a;std::cin>>a;
        lb.addPlayer(a);
    }
    std::cin>>m;
    for(int i=0; i<m; ++i) {
        int a;std::cin>>a;
        std::cout<<"\n"<<lb.climbBoard(a)<<"\n\n";
    }
    return 0;
}
