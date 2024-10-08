#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Player.h"

const char* TILE = "■";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;

	GenerateMap();
}

void Board::Render()
{

	// 최상단 좌측에 커서 배치
	ConsoleHelper::SetCursorPosition(0, 0);
	// 깜박이는 커서 끔
	ConsoleHelper::ShowConsoleCursor(false);

	for (int32 y = 0; y < 25; y++)
	{
		for (int32 x = 0; x < 25; x++)
		{
			ConsoleColor color = GetTileColor(Pos{ y, x });
			ConsoleHelper::SetCursorColor(color);

			cout << TILE;
		}
		cout << endl;
	}
}

// Binary Tree 미로 생성 알고리즘
void Board::GenerateMap()
{
	// 첫 맵 작업, 일정한 간격을 두고 비어있음
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_tile[y][x] = TileType::WALL;
			}
			else
			{
				_tile[y][x] = TileType::EMPTY;
			}
		}
	}

	// 랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				// 벽 일때는 작업 스킵
				continue;
			}
			if (x == _size - 2 && y == _size - 2)
			{
				// 맵 끝부분(출구)도 스킵
				continue;
			}

			if (y == _size - 2)
			{
				// 맨 아래쪽에 왔을땐 우측으로만 길 뚫
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			if (x == _size - 2)
			{
				// 맨 오른쪽에 왔을땐 아래로만 길 뚫
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			const int32 randValue = ::rand() % 2;
			if (randValue == 0)
			{
				// 우측으로 길 뚫
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				// 아래로 길 뚫
				_tile[y + 1][x] = TileType::EMPTY;
			}
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size)
	{
		return TileType::NONE;
	}
	if (pos.y < 0 || pos.y >= _size)
	{
		return TileType::NONE;
	}

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	if (_player && _player->GetPos() == pos)
	{
		return ConsoleColor::YELLOOW;
	}

	if (GetExitPos() == pos)
	{
		return ConsoleColor::BLUE;
	}
	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN;
	case TileType::WALL:
		return ConsoleColor::RED;
	}

	return ConsoleColor::WHITE;
}
