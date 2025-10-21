#ifndef USECASE_H
#define USECASE_H

/**
 * @brief Displays a welcome message and waits for the user to continue.
 *
 * This function is typically called at the very beginning of the application
 * to introduce the program.
 */
void greet();

/**
 * @brief Displays an exit message and waits for the user to acknowledge.
 *
 * This function is typically called at the very end of the application
 * to prevent the console window from closing immediately.
 */
void bye();

/**
 * @brief Orchestrates the main application logic for adding two fractions.
 *
 * This is the primary use case of the application. It guides the user through:
 * 1. Entering the first fraction (with retry logic).
 * 2. Entering the second fraction (with retry logic).
 * 3. Handling any input failures.
 * 4. Calculating the sum using the Fraction class.
 * 5. Printing the formatted result to the console.
 */
void addFractionsUseCase();

#endif