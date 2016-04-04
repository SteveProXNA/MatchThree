#include "BoardManager.h"
#include "../Engine.h"
#include <fstream>

using namespace std;

namespace MatchThree
{
    void BoardManager::Init()
    {
        Init(BOARD_FILENAME);
    }

    void BoardManager::Init(const char* filename)
    {
        matches.clear();
        transpd.clear();

        std::ifstream myfile;
        myfile.open(filename, std::ifstream::in);

        // Check if board text file used for testing.
        if(myfile.fail())
        {
            // Randomize board here!
            myfile.clear(std::ios::failbit);
            for (char row = 0; row < MAX_ROWS; ++row)
            {
                for (char col = 0; col < MAX_COLS; ++col)
                {
                    board[row * MAX_ROWS + col] = (rand() % MAX_GEMS) + 1;
                }
            }

            return;
        }

        // Otherwise load board directly from text file.
        const char MAX_CHARS = MAX_COLS * 2;
        const char* DELIMITER = ",";

        char row = 0;
        while (!myfile.eof())
        {
            char buffer[MAX_CHARS];
            myfile.getline (buffer, MAX_CHARS);

            char *context = NULL;
            const char* token = strtok_s(buffer, DELIMITER, &context);
            if (!token)
            {
                continue;
            }

            board[row * MAX_ROWS] = atoi(token);
            for (char col = 1; col < MAX_COLS; ++col)
            {
                token = strtok_s(0, DELIMITER, &context);
                board[row * MAX_ROWS + col] = atoi(token);
            }

            row++;
        }

        myfile.close();
    }

    void BoardManager::Render()
    {
        SDL_Surface* screen = Engine::Instance().GetScreen();

        short startY = GEM_STARTY;
        char* board = Engine::Instance().BoardManager().GetBoard();
        for (char row = 0; row < MAX_ROWS; ++row)
        {
            short startX = GEM_STARTX;
            for (char col = 0; col < MAX_COLS; ++col)
            {
                UCHAR index = row * MAX_ROWS + col;
                char value = board[index];

                // Calculate position on screen and add displacement for animation.
                float dispX = Engine::Instance().AnimateManager().GetDisplaceX(index);
                float dispY = Engine::Instance().AnimateManager().GetDisplaceY(index);

                Sint16 x = static_cast<Sint16>(startX + dispX);
                Sint16 y = static_cast<Sint16>(startY + dispY);

                // Offset larger gem.
                if (value > MAX_GEMS)
                {
                    x -= GEM_WIDTH / 9;
                    y -= GEM_HEIGHT / 9;
                }

                SDL_Rect myRect = { x, y, 0, 0 };

                SDL_Surface* image = Engine::Instance().ContentManager().GetGemImage(value);
                SDL_BlitSurface(image, NULL, screen, &myRect);

                startX += GEM_WIDTH;
            }

            startY += GEM_HEIGHT;
        }
    }

    // Brute force scan: not elegant but it works!
    // Transpose is used because gems stored RxC
    // but replace each gem by column first: CxR
    void BoardManager::Scan()
    {
        set<char> mini;
        char num_gems = NUM_MATCH - 1;

        char rows[NUM_MATCH];
        char cols[NUM_MATCH];

        // Scan across.
        for (char row = 0; row < MAX_ROWS; ++row)
        {
            for (char col = 0; col < MAX_COLS - num_gems; ++col)
            {
                memset(rows, 0, sizeof(rows));
                memset(cols, 0, sizeof(cols));

                mini.clear();
                for (char cnt = 0; cnt < NUM_MATCH; ++cnt)
                {
                    cols[cnt] = col + cnt;
                    UCHAR index = (col + cnt) + (MAX_ROWS * row);

                    char gem = board[index];
                    mini.insert(gem);
                }

                if (1 == mini.size())
                {
                    for (char cnt = 0; cnt < NUM_MATCH; ++cnt)
                    {
                        char col = cols[cnt];
                        UCHAR match_index = row * MAX_ROWS + col;
                        UCHAR trans_index = row + MAX_COLS * col;

                        matches.insert(match_index);
                        transpd.insert(trans_index);
                    }
                }
            }
        }

        // Scan down.
        for (char col = 0; col < MAX_COLS; ++col)
        {
            for (char row = 0; row < MAX_ROWS - num_gems; ++row)
            {
                memset(rows, 0, sizeof(rows));
                memset(cols, 0, sizeof(cols));

                mini.clear();
                for (char cnt = 0; cnt < NUM_MATCH; ++cnt)
                {
                    rows[cnt] = row + cnt;
                    UCHAR index = (row + cnt) * MAX_ROWS + col;

                    char gem = board[index];
                    mini.insert(gem);
                }

                if (1 == mini.size())
                {
                    for (char cnt = 0; cnt < NUM_MATCH; ++cnt)
                    {
                        char row = rows[cnt];
                        UCHAR match_index = row * MAX_ROWS + col;
                        UCHAR trans_index = row + MAX_COLS * col;

                        matches.insert(match_index);
                        transpd.insert(trans_index);
                    }
                }
            }
        }

    }

    UCHAR BoardManager::Transpose(UCHAR index)
    {
        UCHAR col = index / MAX_COLS;
        UCHAR row = index % MAX_COLS;

        return row * MAX_ROWS + col;
    }

    void BoardManager::SetGemCell(UCHAR index)
    {
        char gem = board[index];
        if (0 == gem)
        {
            return;
        }

        if (gem > MAX_GEMS)
        {
            gem -= MAX_GEMS;
        }
        else
        {
            gem += MAX_GEMS;
        }

        board[index] = gem;
    }

    void BoardManager::SwapGemCells(UCHAR oneSelect, UCHAR twoSelect)
    {
        char first = board[oneSelect];
        char second = board[twoSelect];

        board[oneSelect] = second;
        board[twoSelect] = first;
    }

    void BoardManager::EmptyGemCells()
    {
        for (iterator = matches.begin(); iterator != matches.end(); ++iterator)
        {
            UCHAR index = *iterator;
            board[index] = EMPTY_GEM;
        }
    }

    void BoardManager::MoveCellsDown(UCHAR currentCell)
    {
        UCHAR cellAbove;
        if (currentCell < MAX_ROWS)
        {
            cellAbove = currentCell;
        }
        else
        {
            while (true)
            {
                cellAbove = currentCell - MAX_ROWS;
                char gem = board[cellAbove];

                board[currentCell] = gem;
                if (cellAbove < MAX_ROWS)
                {
                    break;
                }

                currentCell = cellAbove;
            }
        }

        // Replace empty cell with new random gem.
        board[cellAbove] = (rand() % MAX_GEMS) + 1;
    }

    void BoardManager::RemoveEmptyCell()
    {
        UCHAR index;

        iterator = matches.begin();
        index = *iterator;
        matches.erase(index);

        iterator = transpd.begin();
        index = *iterator;
        transpd.erase(index);
    }

}