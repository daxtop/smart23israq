#if !defined(BLUETOOTH_H)
#define BLUETOOTH_H

#include "EpromStruct.h"
#include "Rtc.h"
#include "Buzer.h"
#include "power.h"
#include "DFRobotDFPlayerMini.h"
#include <Arduino.h>
#include <EEPROM.h>
class Bluetooth
{
private:
    EpromObject *parameter;
    Rtc *rtc;
    DFRobotDFPlayerMini *myPlayer;
    Buzer *buzer;
    Power *power;
    enum CMDB
    {
        command_start = 1,
        set_jam,
        set_text,
        set_iqomah,
        set_tarhim,
        set_brightnes,
        set_offsite,
        set_fix,
        set_bt_kota,
        set_adzan,
        play_mp3,
        SET_POWER,
        SET_BUZER,
        RESET_PABRIK,
        command_end,
    };


    const unsigned int TEXT_IQ_SUBUH = 100;
    const unsigned int TEXT_IQ_DUHUR = 200;
    const unsigned int TEXT_IQ_ASHAR = 300;
    const unsigned int TEXT_IQ_MAGHRIB = 400;
    const unsigned int TEXT_IQ_ISYA = 500;
    const unsigned int TEXT_IQ_JUMAT = 600;
    const unsigned int TEXT_RUN = 700;

    volatile unsigned char command;
    unsigned char status;

public:
    Bluetooth();
    ~Bluetooth();
    void setEprom(EpromObject *param);
    void setBuzer(Buzer *buzer);
    void setRtc(Rtc *rtc);
    void setPower(Power *power);
    void loop();
    unsigned char available();
    unsigned char getStatus();
};

#endif // BLUETOOTH_H