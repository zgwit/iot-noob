#include "../application.hpp";

#include <windows.h>

int main()
{
    App.Begin();

    
    while (true) {
        //定时任务
        Cron.loop();
        
        //周期任务
        Wheel.loop();

        //Modbus
        Modbus.loop();

        Sleep(10);
    }
}
