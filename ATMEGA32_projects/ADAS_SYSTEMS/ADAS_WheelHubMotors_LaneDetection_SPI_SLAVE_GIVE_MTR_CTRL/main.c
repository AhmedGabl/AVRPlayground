/*
 * main.c
 * Description: This file implements the main control logic for an automotive ECU responsible for WHM Bluetooth control
 *              and some auxiliary functions.
 * Author: AhmedAbogabl
 * Created on: Oct 17, 2023
 */

// Include necessary header files for bit manipulation and standard types
#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"
#include "APP/ADAS_APP.h"

// SPI communication management variables
u8 Spi_ResponseOnceFlag = NOT_YET;  // Flag indicating if the SPI response has been processed
u8 Spi_Request = NULL;              // Variable to hold the SPI request data

/*
 * Function: Spi_Router
 * Description: Handles SPI communication and processes received data.
 *              Routes SPI data based on specific requests.
 * Parameters:
 *   - Copy_u8RxData: Received SPI data
 */
void Spi_Router(u8 Copy_u8RxData) {
    static u8 GIVE_CONTROL = FALSE;  // Flag to indicate whether control has been given

    // Check for different SPI commands and take appropriate actions
    if (Copy_u8RxData == APP_VEHICLE_ACCESS_INFO_REQUEST) {
        // Check if vehicle access is allowed and update the SPI request accordingly
        if (VehicleAccess == TRUE) {
            Spi_Request = APP_VEHICLE_UNLOCKED;
        }
        Spi_ResponseOnceFlag = NOT_YET;
    }
    else if (Copy_u8RxData == APP_AUXILARY_FUN_STATE) {
        // Check if auxiliary function activation is requested and update the SPI request accordingly
        if (FunctionToACtivate == TRUE)
            Spi_Request = Functoin_Type;
        Functoin_Type = 0;  // Reset the auxiliary function type
        Spi_ResponseOnceFlag = NOT_YET;
    }
    else if (Copy_u8RxData == APP_MOTORS_CONTROL_REQUEST) {
        // Set the flag to give control for motor operations
        GIVE_CONTROL = TRUE;
        Spi_ResponseOnceFlag = NOT_YET;
    } else if (GIVE_CONTROL == TRUE) {
        // Process the received data when control is given
        BT_read_vlaue = Copy_u8RxData;
        ButtonState = 0;          // Reset button state
        GIVE_CONTROL = FALSE;     // Reset control flag
        Spi_Request = APP_SPI_ACK;       // Set a specific response code
        Spi_ResponseOnceFlag = NOT_YET;
    } else {
        // Handle unexpected SPI data
        Spi_ResponseOnceFlag = NOT_YET;
    }
}


int main(void) {
    // Initialize hardware components
    HW_init();

    while (1) {
        // Execute the main control logic
        WHM();
      //  Spi_Handler();  // Assuming there is a Spi_Handler() function, as it's referenced here

        // Check if SPI response flag is not yet processed
        if (Spi_ResponseOnceFlag == NOT_YET) {
            // Transmit SPI request asynchronously
            SPI_voidTransmitAsynchronous(Spi_Request, Spi_Router);

            // Reset SPI request and set the response flag
            Spi_Request = NULL;
            Spi_ResponseOnceFlag = DONE;
        }
    }

    return 0;  // Indicate successful execution
}