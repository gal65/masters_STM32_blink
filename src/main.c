#include "stm32f4xx_hal.h"

#define YELLOW_LED                             GPIO_PIN_13
#define YELLOW_GPIO_PORT                       GPIOC
#define C_GPIO_CLK_ENABLE()                    __HAL_RCC_GPIOC_CLK_ENABLE()
#define RED_LED                                GPIO_PIN_14
#define RED_GPIO_PORT                          GPIOC
#define BLUE_LED                               GPIO_PIN_15
#define BLUE_GPIO_PORT                         GPIOB
#define B_GPIO_CLK_ENABLE()                    __HAL_RCC_GPIOB_CLK_ENABLE()

void LED_Init();

int main(void) {
  HAL_Init();
  LED_Init();

  while (1)
  {
    HAL_GPIO_TogglePin(BLUE_GPIO_PORT, BLUE_LED);
    HAL_GPIO_TogglePin(YELLOW_GPIO_PORT, YELLOW_LED);
    HAL_GPIO_TogglePin(RED_GPIO_PORT, RED_LED);
    HAL_Delay(1000);
  }

  return 0;
}

void LED_Init() {
  B_GPIO_CLK_ENABLE();
  C_GPIO_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct_BLUE;
  GPIO_InitStruct_BLUE.Pin = BLUE_LED;
  GPIO_InitStruct_BLUE.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_BLUE.Pull = GPIO_PULLUP;
  GPIO_InitStruct_BLUE.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(BLUE_GPIO_PORT, &GPIO_InitStruct_BLUE);

  GPIO_InitTypeDef GPIO_InitStruct_YELLOW;
  GPIO_InitStruct_YELLOW.Pin = YELLOW_LED;
  GPIO_InitStruct_YELLOW.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_YELLOW.Pull = GPIO_PULLUP;
  GPIO_InitStruct_YELLOW.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(YELLOW_GPIO_PORT, &GPIO_InitStruct_YELLOW);
  
  GPIO_InitTypeDef GPIO_InitStruct_RED;
  GPIO_InitStruct_RED.Pin = RED_LED;
  GPIO_InitStruct_RED.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_RED.Pull = GPIO_PULLUP;
  GPIO_InitStruct_RED.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(RED_GPIO_PORT, &GPIO_InitStruct_RED);
}

void SysTick_Handler(void) {
  HAL_IncTick();
}
