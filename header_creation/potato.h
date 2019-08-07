//headers
//header for attributes of potato
//i'll do ifndef guard later
#include<stdio.h>
#include<stdlib.h>

class potato{
    private:
    int size_cm = 10;
    int weight_gram = 150 ;
    float volume_cm3 = 190 ;
    public:
    int quantity;
    int get_weight();
    int get_volume();
};

int potato::get_weight()
{
    int weight = quantity * weight_gram;
    return weight;
}

int potato::get_volume()
{
    int volume = quantity * volume_cm3;
    return volume;
}

