#include "rgb_matrix.h"

RGB_MATRIX_EFFECT(personal_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void personal_effect_init(effect_params_t* params) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_personal_effect);
}
static bool personal_effect_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (int row = 0; row < MATRIX_ROWS; row++) {
    for (int col = 0; col < MATRIX_COLS; col++) {
        uint8_t red = (row * 255) / MATRIX_ROWS;
        uint8_t green = (col * 255) / MATRIX_COLS;
        uint8_t blue = 0;
        uint8_t index = g_led_config.matrix_co[row][col];
        rgb_matrix_set_color(index, red, green, blue);
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}
static bool personal_effect(effect_params_t* params) {
  if (params->init) personal_effect_init(params);
  return personal_effect_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
