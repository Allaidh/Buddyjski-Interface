enum class AltFunc
{
    GPIO,

    // I2C
    I2C4_SDA,
    I2C4_SCL,
    AP_I2C2_SCL,
    AP_I2C2_SDA,
    AP_I2C3_SCL,
    AP_I2C3_SDA,
    AP_I2C4_SCL,
    AP_I2C4_SDA,
    R_I2C0_SCL,
    R_I2C0_SDA,
    I2C3_SCL,
    I2C3_SDA,

    // UART
    UART1_TXD,
    UART1_RXD,
    UART1_CTS_N,
    UART1_RTS_N,

    UART4_TXD,
    UART4_RXD,
    UART4_CTS_N,

    UART5_TXD,
    UART5_RXD,
    UART5_CTS_N,
    UART5_RTS_N,

    UART8_TXD,
    UART8_RXD,
    UART8_CTSN,
    UART8_RTS_N,

    UART9_TXD,
    UART9_RXD,

    R_UART0_TXD,
    R_UART1_RXD,
    R_UART1_TXD,
    R_UART1_CTS_N,
    R_UART1_RTS_N,

    // SPI
    R_SPI_RXD,
    R_SPI_TXD,
    R_SPI_SCLK,
    R_SPI_FRM,

    SPI2_TXD,
    SPI2_RXD,
    SPI2_SCLK,
    SPI2_FRM,

    SPI3_TXD,
    SPI3_RXD,
    SPI3_SCLK,

    // SPI LCD
    DCLK_SPI_LCD,
    DCX_DOUT1_SPI_LCD,
    DIN_SPI_LCD,
    DOUT0_SPI_LCD,
    CS_SPI_LCD,

    // PWM
    PWM1,
    PWM2,
    PWM3,
    PWM4,
    PWM5,
    PWM7,
    PWM8,
    PWM9,
    PWM16,

    R_PWM0,
    R_PWM1,
    R_PWM4,
    R_PWM5,
    R_PWM6,
    R_PWM7,
    R_PWM8,

    // CAN
    CAN_TX0,
    CAN_RX0,
    R_CAN_TX0,

    // I2S
    R_I2S3_LRCK,
    R_I2S3_SCLK,

    // GMAC
    GMAC1_TX,
    GMAC1_TX_D0,
    GMAC1_TX_D2,
    GMAC1_TX_D3,
    GMAC1_RX_D0,
    GMAC1_RX_D1,
    GMAC1_RX_D2,
    GMAC1_RX_D3,
    GMAC1_RXDV,
    GMAC1_RX_CLK,
    GMAC1_CLK_REF,

    // PCIe
    PCIe0_PERSTN,
    PCIe0_WAKEN,
    PCIe0_CLKREQN,

    PCIe1_PERSTN,
    PCIe1_WAKEN,
    PCIe1_CLKREQN,

    PCIe2_PERSTN,
    PCIe2_WAKEN,
    PCIe2_CLKREQN,

    SPI3_FRM,

    // PRI
    PRI_TDI,
    PRI_TMS,
    PRI_TCK,
    PRI_TDO,

    // Clock / timing
    MN_CLK,
    MN_CLK2,
    VCXO_OUT,
    DSI_TE,
    _32K_OUT,

    // Infrared
    R_IR_RX,

    // One Wire
    ONE_WIRE,

    // Keypad
    KP_MKOUT_2,
    KP_MKOUT_3,
    KP_MKIN_3
};