# My-First-Game
This is my first game in C++.
  It's something simple. It is based on an arena game which is displayed on the console. The player is represented by the 'O' character, and in the arena appears an stationary enemy represented by the 'X' character. The player has to shoot a bomb at the enemy in order to kill it. After killing the enemy, it will be respawned and the cycle continues.
  
  Controls:
  -movement : 'w a s d'
  -shoot bomb: 'spacebar'
  -stop(become stationary): 'e'
  -end game: 'p'
  
  The player dies when he intersects with the enemy or when he touches a border (you can move near the border, you just have to be precise on your movement). To make the game more challenging, I disabled the ability of shooting while being stationary. The speed of the game is proportional to the number of enemies killed. The difficulty can be chosen (the difference is that at a higher difficulty it takes less enemy kills to get up to speed).
  
  Flaws:
  -bombs can be shot in the direction of the player movement
  -unpleaseant appearence
  -there's only one enemy 
  -the enemy is stationary and defenceless
