#include <vector>
#include <NeuroWeb/NeuroWeb.hpp>

/// @class Game
/// @brief control game tic-tac-toe.
class Game
{
public:
   /// @brief play a tic-tac-toe between neuron webs
   /// @param[in] first - first player
   /// @param[in] second - second player
   /// @return 1, if first player win, 2 - if second, 0 - otherwise.
   int play(const NeuroWeb &first, const NeuroWeb &second);

private:
   /// @brief check if can make so turn
   /// @param[in] - place to turn
   /// @return True - if can
   bool canTurnHere(const std::pair<int, int> &coord) const noexcept;

   /// @brief check if game is finished
   /// @return True - if finished.
   bool isFinished();

   /// @brief Do next turn
   /// @param[in] playerNumber - number of the next player.
   /// @param[in] coord - chosen place
   void doTurn(const int playerNumber, const std::pair<int, int> &coord);

   /// @brief game field
   std::vector<std::vector<int>> field;
};
