
#include "rgb_matrix.h"

RGB_MATRIX_EFFECT(personal_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void personal_effect_init(effect_params_t* params) {
  rgb_matrix_mode(RGB_MATRIX_CUSTOM_personal_effect);
}
static bool personal_effect_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  uint8_t index = g_led_config.matrix_co[0][1];
  rgb_matrix_set_color(index, 255, 255, 255);
  return rgb_matrix_check_finished_leds(led_max);
}
static bool personal_effect(effect_params_t* params) {
  if (params->init) personal_effect_init(params);
  return personal_effect_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
