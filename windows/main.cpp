#include "../application.hpp";

#include <windows.h>

int main()
{
    App.Begin();

    
    while (true) {
        //TODO cron.loop modbus.loop 

        Cron.loop();

        Modbus.loop();

        Sleep(10);
    }
}
