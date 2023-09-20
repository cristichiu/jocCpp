#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
class coords { public: int x, y; };
class Map {
    public:
        coords Player, PlayerSize, MapSize;
        string mapOut;
        bool aPress, dPress;
        vector<coords> Blocks;
        void init(vector<vector<int>> pattern) {
            aPress = false;
            dPress = false;
            PlayerSize.x = 2;
            PlayerSize.y = 3;
            Player.x = 14;
            Player.y = 3;
            MapSize.x = 30;
            MapSize.y = 20;
            for(int y=0; y<MapSize.y; y++) { for(int x=0; x<MapSize.x; x++) {
                if(pattern[y][x] == 1) {
                    coords Block;
                    Block.x = x;
                    Block.y = y;
                    Blocks.push_back(Block);
                }
            }}
        };
        void update() {
            mapOut = "";
            bool blockFind = false;
            for (const coords& c : Blocks) {
                if ((Player.x<=c.x&&Player.x+PlayerSize.x-1>=c.x) && c.y == Player.y+PlayerSize.y-1+1) {
                    blockFind = true;
                    break;
                }
            }
            if(aPress) Player.x -= 1;
            if(dPress) Player.x += 1;
            if(!blockFind) Player.y += 1;
            for(int y=0; y<MapSize.y; y++) {
                for(int x=0; x<MapSize.x; x++) {
                    blockFind = false;
                    for (const coords& c : Blocks) {
                        if (c.x == x && c.y == y) {
                            blockFind = true;
                            break;
                        }
                    }
                    if(blockFind) {
                        mapOut += "🟥";
                    } else {
                        if((Player.x<=x&&Player.x+PlayerSize.x-1>=x)&&(Player.y<=y&&Player.y+PlayerSize.y-1>=y)) {
                            mapOut += "⬜";
                        } else {
                            mapOut += "⬛";
                        }
                    }
                }
                mapOut += "\n";
            }
            system("cls");
            cout<<mapOut;
        }
        void keyPressDetector() {
            if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState('a') & 0x8000) {
                if (!aPress) {
                    aPress = true;
                    std::cout << "A key pressed" << std::endl;
                }
            } else {
                aPress = false;
            }
            if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState('d') & 0x8000) {
                if (!dPress) {
                    dPress = true;
                    std::cout << "D key pressed" << std::endl;
                }
            } else {
                dPress = false;
            }
        }
};
int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<vector<int>> pattern = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    Map joc;
    joc.init(pattern);
    while(true) {
        joc.keyPressDetector();
        Sleep(250);
        joc.update();
    }
    return 0;
}