#include <iostream>

using namespace std;

enum state
{
  PW_off,
  PW_on,
  PW_sleep,
  PW_hibernation
};


class powerModule
{
public:
  explicit powerModule()
  {
    stateOfModule = PW_on;
  }

  void transit(int voltage)
  {
    if (voltage == 0)
      stateOfModule = PW_off;
    else if (voltage < 5)
    {
      if (stateOfModule == PW_on)
      {
        stateOfModule = PW_sleep;
        cout << "to sleep..\n";
      }
      else if (stateOfModule == PW_sleep)
      {
        stateOfModule = PW_hibernation;
        cout << "to hybernation..\n";
      }
      else if (stateOfModule == PW_hibernation)
        cout << "continue..\n";
      else
        cout << "incorrecrt transit\n";
    }
    else if (voltage >= 5)
    {
      if (stateOfModule == PW_hibernation)
      {
        stateOfModule = PW_on;
        cout << "on..\n ";
      }
      else if (stateOfModule == PW_sleep)
      {
        stateOfModule = PW_on;
        cout << "on..\n";
      }
      else
        cout << "incorrecrt transit\n";
    }
  }

  int get_state() const
  {
    return stateOfModule;
  }


  ~powerModule()
  {

  }

private:
  int stateOfModule;
};

void voltageValue(powerModule* module)
{
  int _value;
  cout << "Enter voltage: ";
  cin >> _value;
  module->transit(_value);
}


void get_state(powerModule* module)
{
  int state = module->get_state();
  if (state == PW_on)
  {
    cout << "on";
  }
  else if (state == PW_off)
  {
    cout << "off";
  }
}

int main()
{
  powerModule a1;
  cout << "corrent state: " << a1.get_state() << "\n";

  voltageValue(&a1);
}
