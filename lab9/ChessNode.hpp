#ifndef LA9_CHESSNODE_HPP
#define LA9_CHESSNODE_HPP


struct ChessNode
{
    int x, y, d;

    ChessNode(int x, int y, int d = 0): x(x), y(y), d(d) {}

    bool operator==(const ChessNode& other) const{
        return this->x == other.x && this->y == other.y;
    }

    bool operator<(const ChessNode& other) const{
        return true;
    }

    std::set<ChessNode> possible_next(const std::vector<std::pair<int, int>>& knight_moves) const{
        std::set<ChessNode> out;
        int step = this->d + 1;
        for(auto& move: knight_moves){
            if (0 <= this->x + move.first && 0 <= this->y + move.second && this->x + move.first < 8 && this->y + move.second < 8){
                out.insert({this->x + move.first, this->y + move.second, step});
            }
        }
        return out;
    }
	// Add more methods here
};

#endif //LA9_CHESSNODE_HPP
