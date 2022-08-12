#include <iostream>
#include <vector>

struct Cell
{
  int alives = 0;
  bool live  = false;

  void next()
  {
    if (live && alives <= 1)
      live = false;
    else if (live && (alives == 2 || alives == 3))
      return;
    else if (live && alives >= 4)
      live = false;
    else if (!live && alives == 3)
      live = true;
  }
};

class Life
{
 private:
  std::vector<Cell> cells;
  size_t columns = 0;
  size_t rows    = 0;

 public:
  Life(const size_t row, const size_t column)
      : rows(row), columns(column), cells(row * column, Cell()){};
  ~Life(){};

  Cell& cell(const size_t x, const size_t y) { return cells[x + y * rows]; }

  void iterate()
  {
    for (size_t r = 0; r < rows; r++)
    {
      for (size_t c = 0; c < columns; c++)
      {
        cell(r, c).alives = count_alives(r, c);
      }
    }

    for (size_t i = 0; i < cells.size(); i++)
    {
      cells[i].next();
    }
  };

  int count_alives(const size_t x, const size_t y)
  {
    std::pair<int, int> arounds[] = {{x - 1, y - 1},
                                     {x, y - 1},
                                     {x + 1, y - 1},
                                     {x - 1, y},
                                     {x + 1, y},
                                     {x - 1, y + 1},
                                     {x, y + 1},
                                     {x + 1, y + 1}};

    size_t count = 0;
    for (auto i = std::begin(arounds); i != std::end(arounds); i++)
    {
      int _x = (*i).first;
      int _y = (*i).second;

      if (!(0 <= _x && _x < rows) && !(0 <= _y && _y < columns)) continue;

      if (cell(_x, _y).live)
      {
        count++;
      }
    }

    return count;
  };

  void small_explorer()
  {
    auto row    = rows / 2;
    auto column = columns / 2;

    cell(row, column).live         = true;
    cell(row - 1, column + 1).live = true;
    cell(row, column + 1).live     = true;
    cell(row + 1, column + 1).live = true;
    cell(row - 1, column + 2).live = true;
    cell(row + 1, column + 2).live = true;
    cell(row, column + 3).live     = true;
  };

  void explorer()
  {
    auto row    = rows / 2;
    auto column = columns / 2;

    cell(row - 2, column - 2).live = true;
    cell(row, column - 2).live     = true;
    cell(row + 2, column - 2).live = true;
    cell(row - 2, column - 1).live = true;
    cell(row + 2, column - 1).live = true;
    cell(row - 2, column).live     = true;
    cell(row + 2, column).live     = true;
    cell(row - 2, column + 1).live = true;
    cell(row + 2, column + 1).live = true;
    cell(row - 2, column + 2).live = true;
    cell(row, column - 2).live     = true;
    cell(row + 2, column + 2).live = true;
  }

  void display()
  {
    ::system("tput clear");

    for (size_t c = 0; c < columns; ++c)
    {
      for (size_t r = 0; r < rows; ++r)
      {
        std::cout << (cell(r, c).live ? '*' : ' ');
      }
      std::cout << std::endl;
    }
  }
};
