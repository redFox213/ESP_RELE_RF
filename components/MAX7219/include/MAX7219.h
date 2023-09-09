#define REG_NOP             0x00
#define REG_DIGIT_0         0x01
#define REG_DIGIT_1         0x02
#define REG_DIGIT_2         0x03
#define REG_DIGIT_3         0x04
#define REG_DIGIT_4         0x05
#define REG_DIGIT_5         0x06
#define REG_DIGIT_6         0x07
#define REG_DIGIT_7         0x08
#define REG_DECODE_MODE     0x08
#define REG_INTENSITY       0x0A
#define REG_SCNA_LIMIT      0x0B
#define REG_SHUTDOWN        0x0C
#define REG_DISPLAY_TEST    0x0F

#define GPIO_MOSI           GPIO_NUM_10
#define GPIO_MISO           GPIO_NUM_13
#define GPIO_CS             GPIO_NUM_11
#define GPIO_SCLK           GPIO_NUM_12


void MAX7219_Init(void);
void MAX7219_Clear(void);
void MAX7219_Red_Led(void);
void MAX7219_Blue_Led(void);
void MAX7219_Green_Led(void);