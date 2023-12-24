struct Color
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;

  Color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {};
};

#include "territory.h";

class Player
{
  private:
    Territory** owned_territories;
    uint8_t owned_territories_num;

  public:
    uint8_t id;
    Territory* selected_territory;
  
    Player(uint8_t _id, uint8_t* previously_chosen_territories = nullptr, uint8_t amount_of_previously_chosen_territories = 0) : id(_id)
    {
      // Player can have between 0 - TERRITORIES_COUNT territories
      owned_territories = malloc(sizeof(Territory*) * TERRITORIES_COUNT);

      // Assign starting territory
      owned_territories[0] = GetRandomTerritory(previously_chosen_territories, amount_of_previously_chosen_territories);
      owned_territories_num++;

      // The player starts the game with their own territory selected
      selected_territory = owned_territories[0];
    }
    
};

class ADKeyboard
{
  private:
    const static uint8_t NONE_VALUE = 255;
    const static uint8_t TOP_PRESS = 146;
    const static uint8_t RIGHT_PRESS = 238;
    const static uint8_t BOTTOM_PRESS = 50;
    const static uint8_t LEFT_PRESS = 0;
    const static uint8_t ENTER_PRESS = 18;
    
    // After a button is released, it takes a little bit for the ADKeyboard to reset, so after a button is pressed, allow_read = false until a NONE_VALUE is read, ensuring that the button has been reset
    // This prevents accidental false reads and ensures that each button press results in only a single event being fired.
    bool allow_read = true;

    // Keep track of the previous read to prevent the same event from firing twice
    uint8_t previous_val;

    // The OUT pin on the ADKeyboard
    uint8_t pin;

    // The player who's using the keypad
    Player* owner;

    inline bool IsTop(uint8_t &val)
    {
      return (val >= TOP_PRESS - 2 && val <= TOP_PRESS + 2);
    }

    inline bool IsRight(uint8_t &val)
    {
      return (val >= RIGHT_PRESS - 2 && val <= RIGHT_PRESS + 2);
    }

    inline bool IsBottom(uint8_t &val)
    {
      return (val >= BOTTOM_PRESS - 2 && val <= BOTTOM_PRESS + 2);
    }

    inline bool IsLeft(uint8_t &val)
    {
      return val == LEFT_PRESS;
    }

    inline bool IsEnter(uint8_t &val)
    {
      return (val >= ENTER_PRESS - 2 && val <= ENTER_PRESS + 2);
    }

    inline bool IsNone(uint8_t &val)
    {
      return val == NONE_VALUE;
    }

    void TopClicked()
    {
      // Move to the territory above the currently selected territory
      Territory* top_territory = GetTerritory(owner->selected_territory->top);
      if (top_territory != nullptr)
      {
        owner->selected_territory = top_territory;
      }
    }

    void RightClicked()
    {
      // Move to the territory to the right of the currently selected territory
      Territory* top_territory = GetTerritory(owner->selected_territory->right);
      if (top_territory != nullptr)
      {
        owner->selected_territory = top_territory;
      }
    }

    void BottomClicked()
    {
      // Move to the territory below the currently selected territory
      Territory* top_territory = GetTerritory(owner->selected_territory->bottom);
      if (top_territory != nullptr)
      {
        owner->selected_territory = top_territory;
      }
    }

    void LeftClicked()
    {
      // Move to the territory to the left of the currently selected territory
      Territory* top_territory = GetTerritory(owner->selected_territory->left);
      if (top_territory != nullptr)
      {
        owner->selected_territory = top_territory;
      }
    }

    void EnterClicked()
    {
      // TODO: interact with the current territory
      Serial.println(this->owner->selected_territory->name);
    }

  public:
    ADKeyboard(uint8_t _pin, Player* _owner) : pin(_pin), owner(_owner)
    {
      pinMode(pin, OUTPUT);
    }

    // This must be called in every iteration of loop()
    void Check()
    {
      uint8_t val = analogRead(pin);

      if (!allow_read)
      {
        if (IsNone(val)) allow_read = true;
        else return;
      }
      
      if (IsTop(val))
      {
        if (previous_val == 0) return;
        TopClicked();
        previous_val = 0;
      }
      else if (IsRight(val))
      {
        if (previous_val == 1) return;
        RightClicked();
        previous_val = 1;
      }
      else if (IsBottom(val))
      {
        if (previous_val == 2) return;
        BottomClicked();
        previous_val = 2;
      }
      else if (IsLeft(val))
      {
        if (previous_val == 3) return;
        LeftClicked();
        previous_val = 3;
      }
      else if (IsEnter(val))
      {
        if (previous_val == 4) return;
        EnterClicked();
        previous_val = 4;
      }
      else if (IsNone(val))
      {
        // No key pressed, reset previous_val to allow the same key to be pressed again
        previous_val = 5;

        // Allow the same key to be pressed again now that the keyboard has reset
        allow_read = true;
      }
      else
      {
        // Wait until the keyboard resets, as the read value fluctuates following the release of a button
        allow_read = false;
      }
    }
};

// Create players
Player p1(0);
Player p2(1, new uint8_t[1] { p1.selected_territory->id }, 1);
Player p3(2, new uint8_t[2] { p1.selected_territory->id, p2.selected_territory->id }, 2);
Player p4(3, new uint8_t[3] { p1.selected_territory->id, p2.selected_territory->id, p3.selected_territory->id }, 3);

ADKeyboard p1_keyboard(0, &p1);
ADKeyboard p2_keyboard(1, &p2);
ADKeyboard p3_keyboard(2, &p3);
ADKeyboard p4_keyboard(3, &p4);

void setup() {
  Serial.begin(9600);
  pinMode(52, OUTPUT);
}

void loop() {
  p1_keyboard.Check();
  p2_keyboard.Check();
//  p3_keyboard.Check();
//  p4_keyboard.Check();
  delay(10);
}
