#ifndef TERRITORY_DEF
#define TERRITORY_DEF
#define TERRITORIES_COUNT 38

const uint8_t TERRITORY_STARTING_SOLDIERS = 40;
const float TERRITORY_STARTING_SOLDIERS_GENERATION_RATE = 2.5;

// One territory on the map, for example France or Spain
class Territory
{
  private:
    // The amount of soldiers generated per second
    int soldiersPerSecond;

    // Is the territory being invaded or invading another territory?
    bool isFighting;

    // The "path" to the LED that represents the territory
//    Vector path;

    // Light the LED
    void ToggleLED()
    {
//      for (int i = 0; i < path.length; i++)
//      {
//        if (i == -1) continue;
//        // TODO: code for turning LED on with shift register
//      }
    }

  public:
    // The territory number between (0) to (TERRITORIES_COUNT - 1)
    const uint8_t id;

    // The name of the territory - ex: France, Spain
    const String name;

    // The territory to the left, right, top, and bottom
    const uint8_t left; const uint8_t right; const uint8_t top; const uint8_t bottom;
      
    // The id of the player who controls the territory
    uint8_t owner;

    // The amount of soldiers currently on the territory
    uint32_t soldiers_count;

    // The rate at which soldiers are generated
    float soldiers_per_second;

    Territory(
      uint8_t _id, String _name, uint8_t _left, uint8_t _right, uint8_t _top, uint8_t _bottom,
      uint8_t _owner, uint32_t soldiersCount, float soldiersPerSecond//, Vector _path
    ) :
      id(_id), name(_name), left(_left), right(_right), top(_top), bottom(_bottom), owner(_owner),
      soldiers_count(soldiersCount), soldiers_per_second(soldiersPerSecond), //path(_path),
      isFighting(false) {};
};

#endif

#ifndef TERRITORIES_DEF
#define TERRITORIES_DEF

const Territory** territories = new Territory*[TERRITORIES_COUNT] {
  new Territory(0, "Morocco", NULL, 1, 19, 2,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(1, "Tunisia", 0, NULL, 26, 2,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(2, "Mali", NULL, 3, 0, NULL,        NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(3, "Libya", 2, 4, 25, NULL,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(4, "Egypt", 2, 5, 7, NULL,          NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(5, "Arabia", 4, 6, 7, NULL,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(6, "Persia", 7, NULL, 8, 5,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(7, "Byzantine", 30, 6, 8, 5,        NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(8, "Georgia", 7, NULL, 9, 6,        NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(9, "Russia", 36, NULL, NULL, 8,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(10, "Finland", 11, 36, NULL, 36,    NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(11, "Sweden", 12, 10, NULL, 22,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(12, "Norway", 14, 11, NULL, 13,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(13, "Denmark", 14, 11, 12, 22,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(14, "Scotland", 16, 12, NULL, 15,   NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(15, "England", 16, 13, 14, 21,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(16, "Ireland", NULL, 14, NULL, 19,  NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(17, "Galicia", NULL, 19, 16, 18,    NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(18, "Portugal", NULL, 19, 17, 0,    NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(19, "Spain", 18, 20, 16, 0,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(20, "Catalonia", 19, 21, 21, 0,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(21, "France", 19, 22, 15, 26,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(22, "HRE", 21, 35, 13, 23,          NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(23, "Piedmont", 21, 27, 24, 22,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(24, "Naples", 26, 29, 23, 25,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(25, "Sicily", 1, 30, 24, 3,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(26, "Sardinia", 19, 24, 21, 1,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(27, "Croatia", 23, 28, 22, 28,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(28, "Serbia", 27, 31, 34, 29,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(29, "Bulgaria", 24, 7, 31, 30,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(30, "Greece", 25, 7, 29, 3,         NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(31, "Wallachia", 28, 33, 32, 29,    NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(32, "Transylvania", 34, 33, 37, 31, NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(33, "Moldavia", 32, 37, 37, 31,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(34, "Hungary", 22, 32, 35, 28,      NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(35, "Poland", 22, 36, 11, 34,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(36, "Lithuania", 35, 9, 10, 37,     NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE),
  new Territory(37, "Ukraine", 35, 9, 36, 33,       NULL, TERRITORY_STARTING_SOLDIERS, TERRITORY_STARTING_SOLDIERS_GENERATION_RATE)
};

Territory* GetTerritory(uint8_t id)
{
  return territories[id];
}

// param exclude: array of ids to exclude from the randomizer
Territory* GetRandomTerritory(uint8_t* exclude = nullptr, uint8_t amount_to_exclude = 0)
{
  while (true)
  {
    Territory* random_territory = territories[random(6)];

    // Check if the random territory was meant to be excluded
    // If true, then get another territory by looping again
    for (int i = 0; i < amount_to_exclude; i++)
    {
      if (exclude[i] == random_territory->id) goto loop_again;
    }

    return random_territory;
    loop_again:;
  }
}

#endif
