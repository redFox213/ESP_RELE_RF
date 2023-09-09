#define RELE_1 GPIO_NUM_12
#define RELE_2 GPIO_NUM_13
#define RELE_3 GPIO_NUM_16
#define RELE_4 GPIO_NUM_15
#define LOW    0
#define HIGH   1

void Rele_init(void);
void Test_Rele(uint8_t number_rele);
void On_Off_Rele(uint8_t number_rele, uint8_t status_rele);
