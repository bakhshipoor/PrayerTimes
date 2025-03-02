![Prayer Times Library](https://github.com/bakhshipoor/PrayerTimes/blob/master/assets/prayer_times_header_image.jpg?raw=true)

<br />
# Prayer Times Calculator

This repository hosts a comprehensive library designed to calculate Muslim prayer times. The core implementation is primarily in C, and features a graphical user interface (UI) for testing the calculations using the [LVGL](https://github.com/lvgl/lvgl) library.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Parameters for Calculation](#parameters-for-calculation)
- [Calculated Times](#calculated-times)
- [Library Files](#library-files)
- [UI for Testing](#ui-for-testing)
- [License](#license)
- [References](#references)

## Features
- **Accurate Calculation**: Provides precise prayer times based on various recognized methods and calculations.
- **Customizable Parameters**: Offers flexibility to adjust parameters like angles and offsets to cater to different geographical locations and preferences.
- **Graphical User Interface**: Includes an LVGL-based graphical interface that allows users to test and validate the prayer time calculations interactively.
- **Comprehensive Method Support**: Supports multiple calculation methods, including those recommended by religious authorities in different countries.
- **High Latitude Adjustments**: Implements methods to adjust prayer times for higher latitudes where the sun does not set or rise for extended periods.
- **Dynamic Time Calculation**: Calculates dynamic times such as day length and night length.

## Installation
To integrate the Prayer Times Calculator library into your project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/bakhshipoor/PrayerTimes.git
    ```

2. Include the necessary files in your project.

## Usage
Include the appropriate headers from the `prayertimes` directory and use the provided functions to calculate prayer times according to your needs. The main calculation functionalities are encapsulated within this directory.

## Parameters for Calculation
The library uses a range of parameters to calculate prayer times accurately:

- **Calculation Method**: Different methods used for calculating prayer times, which can vary based on regions and schools of thought. Examples include methods used in Algeria, North America, Egypt, and more.
- **Prayer Angles**: Specific angles used for calculating the prayer times of Fajr, Maghrib, and Isha. These angles are predefined for each method, but can also be customized.
- **Time Offsets**: Adjustments in minutes that can be applied to the calculated times to account for local variations. Offsets can be set for each prayer time including Imsak, Fajr, Sunrise, Dhuhr, Asr, Sunset, Maghrib, and Isha.
- **Juristic Method**: The method based on Islamic jurisprudence for calculating certain prayer times, such as the Asr prayer. Supported juristic methods include Shafi'i, Maliki, Ja'fari, Hanbali, and Hanafi.
- **Higher Latitude Method**: Methods to handle calculations in regions with higher latitudes where the sun does not set or rise for extended periods. Options include no adjustment, middle of night, angle/60th of night, and 1/7th of night.
- **Midnight Calculation Method**: Methods to determine the time of midnight, either from sunset to sunrise or from sunset to Fajr.
- **Observer Coordinates**: The geographical coordinates (latitude, longitude, and altitude) of the location for which the prayer times are being calculated.
- **Calculation Date**: The specific date for which the prayer times are being calculated.
- **Time Zone Offset**: The difference in hours from UTC for the location.

## Calculated Times
After setting the necessary parameters, the library can calculate the following prayer times:

- **Imsak**: The time to stop eating before the fast begins.
- **Fajr**: The dawn prayer time.
- **Sunrise**: The time of sunrise.
- **Midday**: The astronomical midday time.
- **Dhuhr**: The noon prayer time.
- **Asr**: The afternoon prayer time.
- **Sunset**: The time of sunset.
- **Maghrib**: The evening prayer time.
- **Isha**: The night prayer time.
- **Midnight**: The Islamic midnight time.
- **Day Length**: The duration of the day from sunrise to sunset.
- **Night Length**: The duration of the night from sunset to sunrise.

## Library Files
The core calculation library is located in the `prayertimes` directory. Below are the key files and their functionalities:

- **prayertimes.c**: Implements the core functions for calculating prayer times based on different methods, angles, and offsets. It includes functions for setting and getting various parameters, and for calculating each prayer time (e.g., Fajr, Dhuhr, Asr, etc.).
- **prayertimes.h**: The header file that declares the functions, enums, and structs used in `prayertimes.c`. It includes definitions for calculation methods, juristic methods, higher latitude methods, and midnight methods, as well as structs for storing settings and calculation results.
- **prayertimes_math.c**: Contains mathematical functions used in the calculation of prayer times, such as converting times to and from different formats, calculating the sun's position, and adjusting times for higher latitudes.
- **prayertimes_math.h**: The header file for `prayertimes_math.c`, declaring the mathematical functions used in the core library.

## UI for Testing
A graphical user interface is provided in the `ui` directory, designed using the [LVGL](https://github.com/lvgl/lvgl) library. This UI allows users to interactively test and validate the prayer times calculations.

### UI Components
- **Main Screen**: The main interface of the application where the calculated prayer times are displayed. (`scr_main.c` and `scr_main.h`)
- **Settings Screen**: Allows users to adjust parameters such as calculation methods, angles, and offsets. (`scr_settings.c` and `scr_settings.h`)
- **UI Events**: Handles user interactions and updates the UI accordingly. (`prayer_times_ui_events.c` and `prayer_times_ui_events.h`)
- **UI Texts**: Contains text strings used in the UI for localization and display purposes. (`prayer_times_ui_texts.h`)
- **UI Updates**: Manages dynamic updates to the UI elements based on user input and calculated results. (`prayer_times_ui_update.c` and `prayer_times_ui_update.h`)
- **UI Initialization**: Initializes the UI components and sets up the initial display. (`prayer_times_ui.c` and `prayer_times_ui.h`)

### Screenshots
![Main Screen](https://github.com/bakhshipoor/PrayerTimes/blob/master/assets/prayer_times_ui_main_screen.jpg)

*Main Screen of the Prayer Times UI*

![Settings Screen](https://github.com/bakhshipoor/PrayerTimes/blob/master/assets/prayer_times_ui_settings_screen_01.jpg)

*Settings Screen of the Prayer Times UI*

## License
This project is licensed under the MIT License. Please see the [LICENSE](LICENSE) file for more details.

## References
The calculations and formulas used in this library are based on the methods and guidelines provided by [praytimes.org](https://praytimes.org/calculation).
