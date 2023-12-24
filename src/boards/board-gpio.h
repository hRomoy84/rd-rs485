#ifndef __GPIO_BOARD_H__
#define __GPIO_BOARD_H__

#include "gpio-def.h"

namespace board {

/*!
 * \brief Initializes the given GPIO object
 *
 * \param [IN] obj    Pointer to the GPIO object
 * \param [IN] pin    Pin name ( please look in pinName-board.h file )
 * \param [IN] mode   Pin mode [PIN_INPUT, PIN_OUTPUT,
 *                              PIN_ALTERNATE_FCT, PIN_ANALOGIC]
 * \param [IN] config Pin config [PIN_PUSH_PULL, PIN_OPEN_DRAIN]
 * \param [IN] type   Pin type [PIN_NO_PULL, PIN_PULL_UP, PIN_PULL_DOWN]
 * \param [IN] value  Default output value at initialization
 */
void GpioInit(Gpio_t *obj,
              PinNames pin,
              PinModes mode,
              PinConfigs config,
              PinTypes type,
              uint32_t value);

void GpioDeInit(Gpio_t *obj);

/*!
 * \brief Sets a user defined object pointer
 *
 * \param [IN] context User defined data object pointer to pass back
 *                     on IRQ handler callback
 */
void GpioSetContext(Gpio_t *obj, void *context);

/*!
 * \brief GPIO IRQ Initialization
 *
 * \param [IN] obj         Pointer to the GPIO object
 * \param [IN] irqMode     IRQ mode [NO_IRQ, IRQ_RISING_EDGE,
 *                                   IRQ_FALLING_EDGE, IRQ_RISING_FALLING_EDGE]
 * \param [IN] irqPriority IRQ priority [IRQ_VERY_LOW_PRIORITY, IRQ_LOW_PRIORITY
 *                                       IRQ_MEDIUM_PRIORITY, IRQ_HIGH_PRIORITY
 *                                       IRQ_VERY_HIGH_PRIORITY]
 * \param [IN] irqHandler  Callback function pointer
 */
void GpioSetInterrupt(Gpio_t *obj,
                      IrqModes irqMode,
                      IrqPriorities irqPriority,
                      GpioIrqHandler *irqHandler);

/*!
 * \brief Removes the interrupt from the object
 *
 * \param [IN] obj Pointer to the GPIO object
 */
void GpioRemoveInterrupt(Gpio_t *obj);

/*!
 * \brief Writes the given value to the GPIO output
 *
 * \param [IN] obj   Pointer to the GPIO object
 * \param [IN] value New GPIO output value
 */
void GpioWrite(Gpio_t *obj, uint32_t value);

/*!
 * \brief Toggle the value to the GPIO output
 *
 * \param [IN] obj   Pointer to the GPIO object
 */
void GpioToggle(Gpio_t *obj);

/*!
 * \brief Reads the current GPIO input value
 *
 * \param [IN] obj Pointer to the GPIO object
 * \retval value   Current GPIO input value
 */
uint32_t GpioRead(Gpio_t *obj);

// Деинициализация выводов.
void GpioDeInit(const PinNames *pins, uint32_t len);
// Деинициализация выводов для низкого потребления (аналоговый вход).
void GpioDeInitLP(Gpio_t *obj);

} // namespace board


#endif // __GPIO_BOARD_H__
